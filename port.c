#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

int C = 1;
int L = 1;
int K = 0;
int H = 0;
int N = 0;
int M = 0;
int D = 1;
int R;
int P;
int Q;
int T;
int X;
int E;//выбрать локальные
int G;
char B[] = {"            "};
char A[22];
int S[2][10] = {{0, 1, 2, 3, 3, 2, 2, 1, 0, -1}, 
                { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0}};



void printInstructions(){
    printf("YOU MOVE TOWARD YOUR HORSE 1 TO 5 STEPS AT A TIME.\n");
    printf("IF YOU MORE THAN HALVE THE SEPERATION HE WILL BOLT!\n");
    printf("HE MAY ALSO BOLT WHEN HE IS CLOSE TO THE RAIL\n");
    printf("WHEN YOU COME WITHIN 2 STEPS HE MAY KICK.  SO LOOKOUT!!\n\n");
}

int sgn(int x){
    return (x > 0) - (x < 0);
}

void setPQ(){
    R = rand() % 10;
    P = S[0][R];
    Q = S[1][R];
}

void setH(){
    if(H < 1)
        H = 1;
    if(H > 21)
        H = 21;
}

int checkAnotherRound(char answer){
    return answer == 'Y';
}

void printKickedEnd(){
    printf("THOSE KICKS LANDED YOU IN THE HOSPITAL!");
}

void printGetSoon(){
    printf(" GET WELL SOON!!");
}

void printEnought(){
    printf("ENOUGH!! YOU'D DO BETTER AS CAMP COOK!");
}

void rewriteB(char str[13]){
    strncpy(&B, str, 30);
}

int checkMove(){
    E = C + L * D;
    return D > 0 && D < 6 || E < 1 || E > 21;
}

void inputMove(){
     while(1){
        scanf("%d", &D);

        if(!checkMove()){
            printf("ILLEGAL MOVE. TRY AGAIN");
        }
        else{
            printf("Breacked");
            break;
        }
    }
}

char Round(){
    int C = 1;
    int L = 1;
    int K = 0;
    int H = 0;
    int N = 0;
    int M = 0;
    s300:rewriteB("            ");
    setPQ();

    if(R > 5){
        Q = -Q;
    }

    H = 13 + Q;
    setH();
    T = 2 + P;
    printf("\n");

    for(int j = 0; j < 20; j++)
        A[j] = ' ';

    A[C] = 'C';
    A[H] = 'H';

    printf(" %-12d %c", N, 'I');

    for(int j = 0;j < 20 ; j++)
        printf("%c", A[j]);

    printf("%c%-12s", 'I', B);
    
    X = abs(H - C);
    L = sgn(H - C);
    N = N + 1;
   //ну и говно разобраться
    if(K > 0){
        if(M > T){
            printKickedEnd();
            printGetSoon();
            return 'K';
        }
        K = K - 1;
        setPQ();
    }
    if(N > 100){
        printEnought();
        printGetSoon();
        return 'E';
    }
    
    //Ввод и валидация игрового значения
    inputMove();
    C = E;
    setPQ();
    G = P;
    H = H + L * G;
    setH();

    if(X < 2 * D && D > 1){
        G = 9 + 2 * P;
        H = H - L * G;
        L = -L;
        setH();
    }
    if(!H > 1 && H < 20){
        setPQ();
        if(R > 2)
            goto s600;
        if(X < 7)
            goto s300;
        
    }

    s600: if (!abs(H - C) > 1){
        H = H - 3*L;
        setH();
    }

    rewriteB("BOLTED      ");
    

    return 'K';
}

int main()
{
    char answer;
    srand(time(NULL));

    printf("CORRAL\n");
    printf("CREATIVE COMPUTING\n");
    printf("MORRISON, NEW JERSEY\n\n\n");
    printf("  YOU ARE THE COWBOY.  GO CATCH YOUR HORSE IN THE CORRAL!\n");
    printf("DO YOU WANT FULL INSTRUCTIONS\n");

    answer = fgetc (stdin);
    fflush(stdin);

    if(answer != 'N'){
        printInstructions();
    }

    printf("AFTER '?' TYPE IN DIGIT FROM 1 TO 5 FOR COWBOY'S NEXT MOVE\n");
    do{
        char res = Round();
    }while(!checkAnotherRound(fgetc (stdin)));

    
    
    
    return 0;
}