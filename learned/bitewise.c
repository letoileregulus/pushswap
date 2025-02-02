#include <stdio.h>

int main()
{
    int num;


    num =36;
    printf("%d\n", num>>2);
    num =8;
    printf("%d\n", num>>1);
    num=5;
    printf("%d\n", num>>2);
    num =2;
    printf("%d\n", num>>4);
    num =87;
    printf("%d\n", num>>3);
    

    printf("%d\n", 6&5);
    //      6 -> 0000 0000 0000 0110 
    //      5 -> 0000 0000 0000 0100
    //  6 & 5 -> 0000 0000 0000 0100 -> 4

}
