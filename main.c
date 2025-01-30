#include "./libft/libft.h"
#include "pushswap.h"



int main(int ac, char **av)
{
    // i = 0;
    t_node* a = NULL;  // İlk liste (a)
    t_node* b = NULL;  // İkinci liste (b)


    if (ac == 1)
        exit(1);
    
    control(ac, av);
    

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

    return 0;
    
}