#include <stdio.h>
#include <stdlib.h>

// Bağlı liste düğümü için yapı tanımı
struct Node {
    int data;
    struct Node* next;
};

// Yeni düğüm oluşturma
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Bellek ayrılırken hata oluştu.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bağlı listeye düğüm ekleme (sona ekleme)
void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Bir listenin son düğümünü başka bir listeye taşıma
void transferLastNode(struct Node** fromList, struct Node** toList) {
    if (*fromList == NULL) {
        printf("Kaynak liste boş, aktarılacak düğüm yok.\n");
        return;
    }

    struct Node* temp = *fromList;
    struct Node* prev = NULL;

    // Listenin son düğümüne kadar ilerle
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Son düğümü kaynak listeden çıkar
    if (prev == NULL) {
        // Eğer listede tek bir düğüm varsa
        *fromList = NULL;
    } else {
        prev->next = NULL;
    }

    // Düğümü hedef listeye ekle
    temp->next = *toList;
    *toList = temp;
}

// Listeyi yazdırma fonksiyonu
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Belleği serbest bırakma
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Ana program
int main() {
    struct Node* a = NULL;  // İlk liste (a)
    struct Node* b = NULL;  // İkinci liste (b)

    // Liste a'ya düğüm ekleme
    addNode(&a, 10);
    addNode(&a, 20);
    addNode(&a, 30);

    printf("Liste a başlangıç durumu:\n");
    printList(a);

    printf("Liste b başlangıç durumu:\n");
    printList(b);

    // a'nın son düğümünü b'ye taşıma
    printf("\nSon düğüm a'dan b'ye taşınıyor...\n");
    transferLastNode(&a, &b);

    printf("\nListe a güncel durumu:\n");
    printList(a);

    printf("Liste b güncel durumu:\n");
    printList(b);

    // Belleği serbest bırakma
    freeList(a);
    freeList(b);

    return 0;
}
