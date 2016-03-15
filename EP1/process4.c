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
#include "process4.h"


/*Static valors*/
#define DEBUG 1
#define MAXVALUES 25000
#define MINVALUES 1


/******************************************/
/**process - P4 Integration by simulation**/
int p4(int s){
    printf("   P4 recebeu %d\n", s);
    printf("  Vai terminar com ERRO o processo de pid = %d \n", getpid());
    exit(1);
    return 1;
}

