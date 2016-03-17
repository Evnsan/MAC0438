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
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "process3.h"

/*Static valors*/
#define DEBUG 1
#define MAXVALUES 25000
#define MINVALUES 1
#define PIX2 6.28318530718  /*Aproximadamente 2 * PI*/


/**process - P3 Buffon's needle**/
/*int p3(int r){*/
int main() {
	
	/*t é o número de vezes que a agulha cruza uma linha*/
	int t, i, j;
	int r;
	double result, retorno;
	double *info[2];

	r = 10;


	printf("===> P3 começou!\n\n");

	/***/
	if (DEBUG)
		printf("   P3 recebeu %d\n", r);
	/***/
		

	info[0] = (double *) malloc(r * sizeof(double));
	info[1] = (double *) malloc(r * sizeof(double));

	srand(time(NULL));
	
	
	for (i = 0; i < r; i++) {
		info[0][i] = ((double)rand() / (double)((unsigned)RAND_MAX + 1));   /*Valor de d*/
		info[1][i] = ((double)rand() / (double)((unsigned)RAND_MAX + 1)) * PIX2; /*Valor de theta*/
		
	}

	t = 0;
    for (i = 0; i < r; i++) {
		result = info[0][i] + sin(info[1][i]);

		if (result < 0 || result > 1)
			t++;
    }


	for (i = 0; i < 2; i++) {
		for (j = 0; j < r; j++) {
			printf("info[%d][%d] = %lf\n", i, j, info[i][j]);  
		}
	}

	retorno = (double)t/r;

	printf("r = %d t = %d\n", t, r);
	printf("t\\r = %lf\n", retorno);

    
	
	printf("===> P3 terminou\n");
	


    return (int) (retorno * 100);
}

/*******************************/