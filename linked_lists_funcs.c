#include <stdio.h>
#include <stdlib.h>

// Bağlı liste düğümü için yapı tanımı
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturmak için fonksiyon
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek ayrilirken hata oluştu.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bağlı listeye eleman eklemek için fonksiyon (sona ekleme) (append)
void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // Liste boşsa yeni düğüm baş olur
        *head = newNode;
    } else {
        // Liste doluysa sona ekle
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Listeyi yazdırmak için fonksiyon
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Belleği serbest bırakmak için fonksiyon
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Ana fonksiyon
int main() {
    struct Node* head = NULL;  // Bağlı liste başlangıçta boş

    // Listeye eleman ekleme
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);

    // Listeyi yazdırma
    printf("Bağlı liste: ");
    printList(head);

    // Belleği serbest bırakma
    freeList(head);

    return 0;
}
