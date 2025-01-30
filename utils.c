#include "pushswap.h"
#include "./libft/libft.h"

// Yeni düğüm oluşturmak için fonksiyon
t_node *makeNode(int data)
{
    t_node *newNode;
    newNode = (t_node *)malloc(sizeof(t_node));
    if (newNode == NULL)
    {
        printf("Error.\n");
        return (NULL);
    }
    newNode->num = data;
    newNode->next = NULL;
    return newNode;
}

void append(t_node **head, int data)
{
    t_node *newNode;
    newNode = makeNode(data);

    if (*head == NULL)
    {
        // Liste boşsa yeni düğüm baş olur
        *head = newNode;
    }
    else
    {
        // Liste doluysa sona ekle
        t_node *temp;
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Bir listenin son düğümünü başka bir listeye taşıma
void push(t_node **fromList, t_node **toList)
{
    if (*fromList == NULL)
    {
        printf("Kaynak liste boş, aktarılacak düğüm yok.\n");
        return;
    }

    t_node *temp;
    temp = *fromList;
    t_node *prev;
    prev = NULL;

    // Listenin son düğümüne kadar ilerle
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Son düğümü kaynak listeden çıkar
    if (prev == NULL)
    {
        // Eğer listede tek bir düğüm varsa
        *fromList = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    // Düğümü hedef listeye ekle
    temp->next = *toList;
    *toList = temp;
}

// Listeyi yazdırmak için fonksiyon
void printList(t_node *head)
{
    t_node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Belleği serbest bırakmak için fonksiyon
void freeList(t_node *head)
{
    t_node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// void control(int ac, char **av)
// {
//     printf("ac = %d\n", ac);
//     int i;
//     int j;
//     int k;
//     i = 0;
//     k = 1;
//     char **str;
//     str = ft_calloc(sizeof(char **), 1);

//     while (av[k])
//     {
//         j = 0;
//        // printf("---\n");
//         while (ft_split(av[k], ' ')[j] != NULL)
//         {
//             str[i] = ft_split(av[k], ' ')[j];
//            // printf("%s \n", str[i]);
//             j++;
//             i++;
//         }
//         k++;
//     }
// }


void control(int ac, char **av)
{
    printf("ac = %d\n", ac);
    int i;
    int j;
    int k;
    i = 0;
    k = 0;
    char **str;
    str = ft_calloc(sizeof(char **), 1);

    while (av[++k])
    {
        j = 0;
        while (ft_split(av[k], ' ')[j] != NULL)
            str[i++] = ft_split(av[k], ' ')[j++];
    }

    i = 0;
    while (str[i])
    {
        j=0;
        while(str[i][j] != '\0')
        {
            ft_isdigit(str[i][j]);
         //printf("str [%d] = %c\n", i, str[i][j]);
         j++;  
        }
        i++;
    }
}
