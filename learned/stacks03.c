#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    struct n * next;
};

typedef struct n node;

void bastir(node *iter)
{
    while (iter != NULL)
    {
        printf ("%d \n", iter -> x);
        iter = iter -> next;
    }
}

void ekle(node *iter,int x)
{
    while (iter -> next != NULL)
    {
        iter = iter -> next;
    }
    iter -> next = (node *)malloc(sizeof(node));
    iter -> next -> x = x;
    iter -> next -> next = NULL;
}

int main()
{
    node * root;
    root = (node *)malloc(sizeof(node));
    root -> x = 500;
    root -> next = NULL;
    /*Bu linked listi bastırmak isterken döngünün linked listin sonuna geldiğinde 
    NULL gördüğünü garantilemek için  -> next'ine  NULL yazmalıyız. 
    Çünkü normalde -> next RAM'de herhangi bir noktayı işaret ediyor. 
    NULL'ı işaret ettiğinin bir garantisi yok*/ 
    node * iter;
    iter = root;
    int i;
    i = 0;
    while (i < 5)
    {
        ekle(iter,i*10);
        i++;
    }

    i = 0;
    iter = root;
    while (++i < 4)
        iter = iter -> next;
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = iter-> next;
    iter -> next = temp;
    temp -> x = 333;

    iter = root;
    bastir(iter);

    // printf("%d\n", iter -> x);
    // iter = iter -> next;
    // printf("%d\n",iter -> x);
    // iter = iter -> next;
    // printf("%d\n",iter -> x);

}

    // Bu kısım main.c 'den alındı.
    // // Liste a'ya düğüm ekleme
    // append(&a, 10);
    // append(&a, 20);
    // append(&a, 30);

    // printf("\033[32mListe a başlangıç durumu:\033[0m\n");
    // printList(a);

    // printf("\033[32mListe b başlangıç durumu:\033[0m\n");
    // printList(b);

    // // a'nın son düğümünü b'ye taşıma
    // printf("\n\033[36mSon düğüm a'dan b'ye taşınıyor...\033[0m\n");
    // push(&a, &b);

    // printf("\n\033[31mListe a güncel durumu:\033[0m\n");
    // printList(a);

    // printf("\033[31mListe b güncel durumu:\033[0m\n");
    // printList(b);

    // // Belleği serbest bırakma
    // freeList(a);
    // freeList(b);
