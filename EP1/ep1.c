/*******************************************************************/
/**   MAC 438  - Programacao Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercicio-Programa                                 **/
/**   Arquivo: EP1.c                                              **/
/**                                                               **/
/**   <nome do(a) aluno(a)>                <numero USP>           **/
/**   Evandro Augusto Nunes Sanches          5388861              **/
/**   Fernanda de Camargo Magano             8536044              **/
/**                                                               **/
/**   <data de entrega>                                           **/
/**      08/03/2016                                               **/
/*******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


/*Static valors*/
#define DEBUG 1
#define MAXVALUES 25000
#define MINVALUES 1


/*****Auxiliary fuctions******************************************************/

/**Limiarized value**/
int limiarize(int arg){
    if( MINVALUES < arg && arg < MAXVALUES ){
        return arg;
    }
    return -1;
}
/*********************/

/**process - P1 heapSort**/
int p1(char* arg){
    printf(" P1 recebeu %s\n", arg);
    return 0;
}
/*************************/

/**process - P2 Fibonacci Numbers**/
int p2(char* arg){
    printf(" P2 recebeu %s\n", arg);
    return 0;
}

/**********************************/

/**process - P3 Buffon's needle**/
int p3(char* arg){
    printf(" P3 recebeu %s\n", arg);
    return 0;
}

/********************************/

/**process - P4 Integration by simulation**/
int p4(char* arg){
    printf(" P4 recebeu %s\n", arg);
    printf("Vai terminar com ERRO o processo de pid = %d \n", getpid());
    exit(1);
    return 1;
}

/******************************************/

/*****************************************************************************/



/*****Main program************************************************************/
int main(int argc, char **argv){
    /*Local variables*/
    int i;
    int status = 0;
    pid_t child_pid, wpid;
    /*****************/

    /***DEBUG***/
    if(DEBUG){
        printf("Recebidos %d argumentos!\n", argc);
        for(i = 0; i < argc; i++){
            printf("Argumento n.%2d => %s\n", i, argv[i]);
        }
    }
    /***********/

    printf("parent_pid = %d\n", getpid());

    for(i = 1; i < 5; i++){
        printf("i = %d\n", i);
        if ((child_pid = fork()) == 0){
            printf("Processo filho (pid = %d) iniciou.\n", getpid());
            switch(i){
                case 1:
                    p1("arg1");
                break;
                case 2:
                    p2("arg2");
                break;
                case 3:
                    p3("arg3");
                break;
                case 4:
                    p4("arg4");
                break;
            }
            printf("Vai terminar processo de pid = %d \n", getpid());
            exit(0);
        }
    }
    while ((wpid = wait(&status)) > 0){
        printf("Exit status of %d was %d (%s)\n", (int)wpid, status,
                (status > 0) ? "reject":"accept" );
    }
    printf("FINALIZANDO\n");
    return 0;
}
/*****************************************************************************/
