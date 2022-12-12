#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int sgn(int x){
    return (x > 0) - (x < 0);
}

void setPQ(int* R, int* P, int* Q, int S[2][10]){//800 строка в оригинальном коде
        *R = rand() % 10;
        *P = S[0][*R];
        *Q = S[1][*R];
}

void setH(int* H){//810 строка в оригинальном коде
    if(*H < 1){
        *H = 1;
    }
    if(*H>21){
        *H = 21;
    }
}

int main(){
    printf("CORRAL\n");
    printf("CREATIVE COMPUTING\n");
    printf("MORRISON, NEW JERSEY\n\n\n");
    printf("  YOU ARE THE COWBOY.  GO CATCH YOUR HORSE IN THE CORRAL!\n");
    printf("DO YOU WANT FULL INSTRUCTIONS\n");

    int R = 0;
    int P = 0;
    int Q = 0;
    int E;
    int G;
    int X;
    int T;
    int K = 0;
    int M = 0;
    int C, L, H, N;
    int D;
    char A[22];
    int S[2][10] = {{0, 1, 2, 3, 3, 2, 2, 1, 0, -1}, 
                { 1, 2, 3, 4, 5, 4, 3, 2, 1, 0}};
    
    char answer[50];
    fgets(answer, 50, stdin);

    if(answer[0] != 'N'){//Анализ ответа игрока, и вывод инструкций к игре
        printf("YOU MOVE TOWARD YOUR HORSE 1 TO 5 STEPS AT A TIME.\n");
        printf("IF YOU MORE THAN HALVE THE SEPERATION HE WILL BOLT!\n");
        printf("HE MAY ALSO BOLT WHEN HE IS CLOSE TO THE RAIL\n");
        printf("WHEN YOU COME WITHIN 2 STEPS HE MAY KICK.  SO LOOKOUT!!\n\n");
    }

    printf("AFTER '?' TYPE IN DIGIT FROM 1 TO 5 FOR COWBOY'S NEXT MOVE\n");

    s200: ;
    C = 1;
    L = 1;
    K = 0;
    H = 0;
    N = 0;
    setPQ(&R, &P, &Q, S);

    if(R > 5){
        Q = -Q;
    }
    H = 13 + Q;
    setH(&H);

    T = 2 + P;
    s300: ;
    char B[] = "           ?";

    s310: ;
    for(int j = 0; j < 20; j++){
        A[j] = ' ';
    }
    
    A[C] = 'C';
    A[H] = 'H';

    printf(" %-12d %c", N, 'I');//Вывод на экран игровой строки
    for(int j = 0;j < 20 ; j++){
        printf("%c", A[j]);
    }
    printf("%c%-12s", 'I', B);

    X = abs(H - C);
    L = sgn(H - C);

    N += 1;
    if(K > 0){goto s640;}
    s390: ;
    if(N > 100){goto s980;}
    scanf("%d", &D);//Ввод игрового значения
    if(D > 0 && D < 6){goto s450;}

    s420: printf("ILLEGAL MOVE. TRY AGAIN");
    goto s390;

    s450: ;
    E = C + L * D;
    if(E < 1 || E > 21){goto s420;}
    C = E;
    setPQ(&R, &P, &Q, S);

    G = P;
    H += L * G;
    setH(&H);

    if(X < 2* D && D > 1){goto s570;}
    if(H > 1 && H < 20){goto s600;}
    setPQ(&R, &P, &Q, S);

    if(R > 2){goto s600;}
    if(X > 7){goto s300;}

    s570: ;
    G = 9 + 2 * P;
    H -= L * G;
    L = -L;
    setH(&H);

    if (abs(H - C) > 1){goto s590;}
    H -= 3 * L;
    setH(&H);

    s590: ;
    strncpy(B, "BOLTED     ?", 30);
    goto s310;
    s600: ;
    if(abs(H - C) > 2){goto s300;}
    setPQ(&R, &P, &Q, S);
    if(R > 3){goto s700;}
    setPQ(&R, &P, &Q, S);

    K = P + 2;
    M += 1;
    H -= 5 * L;
    setH(&H);
    strncpy(B, "KICKED", 30);
    goto s310;
    s640: ;
    if(M > T){goto s900;};

    K -= 1;
    printf("\n");
    setPQ(&R, &P, &Q, S);
    
    H+=L*(P+1);
    setH(&H);
    goto s300;

    s700: ;
    if(H == C){goto s930;}
    goto s300;

    s900: printf("THOSE KICKS LANDED YOU IN THE HOSPITAL!");
    printf(" GET WELL SOON!!");
    goto s960;

    s930: ;
    for(int j = 0;j<20;j++){
        A[j] = ' ';
    }
    A[C] = '#';
    printf("I");
    for(int j = 0;j<20;j++){
        printf("%c", A[j]);
    }
    printf("I");
    printf("\n");
    printf("YIPPEE!!  NOW SEE IF YOU CAN CATCH HIM IN FEWER MOVES");
    s960: ;
    printf("ANOTHER ROUNDUP");
    fgets(answer, 50, stdin);

    if(answer[0] == 'Y'){goto s200;}
    goto s999;
    s980: ;
    printf("\n");
    printf("ENOUGH!! YOU'D DO BETTER AS CAMP COOK!\n");
    goto s960;

    s999: ;
    printf("Port by TheElderRoll;)");
    return 0;
}