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
#include "process2.h"


/*Static valors*/
#define DEBUG 1
#define MAXVALUES 25000
#define MINVALUES 1


/**process - P2 Fibonacci Numbers**/
int p2(int n){
    //./ep1 m n p r
	int x;

	x = Fibonacci(n);

	printf("   P2 recebeu %d\n", n);
	printf("   Fibonacci %d\n", x);
	
    return 0;
}

int Fibonacci(int n) {
		
	if (n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);

}