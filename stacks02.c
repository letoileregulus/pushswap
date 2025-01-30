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
    iter = root;
    bastir(iter);

    // printf("%d\n", iter -> x);
    // iter = iter -> next;
    // printf("%d\n",iter -> x);
    // iter = iter -> next;
    // printf("%d\n",iter -> x);

}
