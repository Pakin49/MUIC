#include<stdio.h>

void main()
{
    int ans ;
    printf("What is the colour of banana?\n");
    printf("1. Red\n2. Pink\n3. Blue\n4. Yellow\n5. White\n");
    printf("Choose 1-5\n");
    printf("Ans: ");
    scanf("%d",&ans);

    switch (ans)
    {
        case 4: printf("Right");
            break;
        case 1: case 2: case 3: case 5: printf("Wrong");
        default : printf("Error");
    }
}
