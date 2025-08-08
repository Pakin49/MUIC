#include<stdio.h>

void main ()
{
    char aeiou;
    printf("In put a character: ");
    scanf(" %c",&aeiou);

    switch (aeiou)
    {
        case 'a': printf("a=apple \n");
            break;
        case 'e': printf("e=egg \n");
            break;
        case 'i': printf("i=ink \n");
            break;
        case 'o': printf("o=ox \n");
            break;
        case 'u': printf("u=umbrella \n");
            break;
        default: printf("Don't know");
    }
    printf("End.");
}
