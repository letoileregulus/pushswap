#include "./libft/libft.h"
#include "pushswap.h"



int main(int ac, char **av)
{
    // i = 0;
    t_node* a = NULL;  // İlk liste (a)
    t_node* b = NULL;  // İkinci liste (b)
    char **str;
    int i;


    if (ac == 1)
        exit(1);
    
    str = fixarg(ac, av);
    if (is_digit_array(str))
        printf("Geçerli: Tüm argümanlar sadece rakamlardan oluşuyor.\n");
    else
        printf("Geçersiz: En az bir argüman rakam olmayan karakter içeriyor.\n");

    i = -1;
    while (str[++i])
        printf("str[%d] = %s\n", i, str[i]);
    free(str);
    return 0;
}
