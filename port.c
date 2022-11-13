#include <stdio.h>
#include <string.h>

void printInstructions(){
    printf("YOU MOVE TOWARD YOUR HORSE 1 TO 5 STEPS AT A TIME.\n");
    printf("IF YOU MORE THAN HALVE THE SEPERATION HE WILL BOLT!\n");
    printf("HE MAY ALSO BOLT WHEN HE IS CLOSE TO THE RAIL\n");
    printf("WHEN YOU COME WITHIN 2 STEPS HE MAY KICK.  SO LOOKOUT!!\n");
}

int main()
{
    int A[22];
    int S[3][10];
    int data1[10] = {0, 1, 2, 3, 3, 2, 2, 1, 0, -1};
    int data2[10] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};
    char str[4];

    printf("CORRAL\n");
    printf("CREATIVE COMPUTING\n");
    printf("MORRISON, NEW JERSEY\n");

    for(int i = 1;i < 3; i++){
        for(int j = 0; j < 10;j++){
            
        }
    }
    printf("  YOU ARE THE COWBOY.  GO CATCH YOUR HORSE IN THE CORRAL!\n");
    printf("DO YOU WANT FULL INSTRUCTIONS\n");

    fgets(str, 4, stdin);
    fflush(stdin);
    printf("%d", strcmp(str, "yes"));
    for(int i = 0;i<4;i++){
        printf("%c", str[i]);
    }

    return 0;
}