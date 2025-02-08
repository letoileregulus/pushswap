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

int is_digit_string(char *str)
{
    if (!str || !*str)
        return (0);
    if (*str == '-')
    {
        if(ft_isdigit(*(str + 1)))
            str++;
        else
            return(0);
    }
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

int is_digit_array(char **str) 
{
    int i;
    i = 0;
    
    if (!str) // !str[0] şartı  sadece ilk girdide "" veya "   " gibi ifadeler için
        exit(1);//return (0);

    while (str[i])
    {
        if (!is_digit_string(str[i]))
            return (0);
        i++;
    }
    return (1);
}

char **fixarg(int ac, char **av)
{
    printf("ac = %d\n", ac);
    int i;
    int j;
    int k;
    i = 0;
    k = 0;
    char **str;
    str = ft_calloc(ac, sizeof(char *));
    if (str == NULL)
        exit(1);
    while (av[++k])
    {
        char *trimmed;
        char **split;
        trimmed = ft_strtrim(av[k], " ");
        if (!trimmed || *trimmed == '\0') // Eğer tamamen boşsa
        {
            free(trimmed);
            printf("Hata: Boş string girdisi tespit edildi!\n");
            exit(1);
        }
        split = ft_split(trimmed, ' ');
        free(trimmed);
        j = 0;
        while (split[j] != NULL) // "" veya "    " gibi ifadeler array'e eklenmiyor
            str[i++] = split[j++];
        free(split);
    }
    str[i] = NULL;
    return (str);
}
