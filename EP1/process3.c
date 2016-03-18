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
#include <limits.h>
#include "process3.h"

/*Static valors*/
#define DEBUG 0
#define PIX2 6.28318530718  /*Aproximadamente 2 * PI*/


/**process - P3 Buffon's needle**/
int p3(int r){
/*int main() {*/
	
	/*t é o número de vezes que a agulha cruza uma linha*/
	int t, i, j;
	double result, retorno;
	double *info[2];

	printf("===> P3: Iniciando.\n");
	printf("===> P3: Será(ão) executado(s) %d lançamento(s).\n",r);

	/***DEBUG***/
	if (DEBUG){
		printf("===> P3: Recebido r = %d\n", r);
    }
	/***DEBUG***/

    info[0] = (double *) malloc(r * sizeof(double));
    info[1] = (double *) malloc(r * sizeof(double));

	srand(time(NULL));
	
	/*gerando numeros aleatorios para posicao d e angulo theta de cada
      lancamento*/
    for (i = 0; i < r; i++) {
        info[0][i] = ((double)rand() 
                      / (double)((unsigned)RAND_MAX + 1)
                     );   /*Valor de d*/
        info[1][i] = ((double)rand() 
                      / (double)((unsigned)RAND_MAX + 1)
                     ) * PIX2; /*Valor de theta*/
    }
    /*contabilizando resultados de interesse (agulha cruza uma linha)*/
	t = 0;
    for (i = 0; i < r; i++) {
		result = info[0][i] + sin(info[1][i]);

		if (result < 0 || result > 1)
			t++;
    }

	/***DEBUG***/
	if (DEBUG){
        for (i = 0; i < 2; i++) {
            for (j = 0; j < r; j++) {
                printf("info[%d][%d] = %f\n", i, j, info[i][j]);  
            }
        }
    }
	/***DEBUG***/

	retorno = (double)t/r;

    /**Saida**/
	printf("===> P3: r = %d, t = %d\n", r, t);
	printf("===> P3: t/r = %f\n", retorno);
	printf("===> P3: Probabilidade estimada: %f \n", retorno);

	printf("===> P3: Finalizado.\n");
	
    
    free(info[0]);
    free(info[1]);
    
    return (int) (retorno * 100);
}


/*para testar*/
int main(int argc, char** argv){
    printf("The maximum value of INT = %d\n", INT_MAX);
    if(argc > 1){
        p3(atoi(argv[1]));
    }
    return 0;
}

/*******************************/
