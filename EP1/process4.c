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
#ifndef DEBUG
    #define DEBUG 0
#endif

#define SEC1 1.85081571768 


/**process - P4 Integrate by simulation**/
double p4(int s){
	
	/*s é o número de pontos sorteados*/
	/*t é o número de pontos no interior da regiao entre a curva (sec(x)) e o
      eixo x)*/
	int t, i, j;
	double retorno;
	double *info[2];

	printf("===> P4: Iniciando.\n");
	printf("===> P4: Será(ão) sorteado(s) %d ponto(s).\n",s);

	/***DEBUG***/
	if (DEBUG){
		printf("===> P4: Recebido s = %d\n", s);
    }
	/***DEBUG***/

    /*info guardara os pontos gerados
      (ie. info[0][5]= 3 e info[1][5] = 4 <=> p5 = (3,4))
      obs p5 - sexto ponto gerado (x,y)*/

    info[0] = (double *) malloc(s * sizeof(double));
    info[1] = (double *) malloc(s * sizeof(double));

	srand(time(NULL));
	
	/*gerando numeros aleatoriamente para eixos x e y de cada ponto*/
    for (i = 0; i < s; i++) {
        info[0][i] = ((double)rand() 
                      / (double)((unsigned)RAND_MAX + 1)
                     );
        info[1][i] = ((double)rand() 
                      / (double)((unsigned)RAND_MAX + 1)
                     ) * SEC1;
    }
    /*contabilizando resultados de interesse (agulha cruza uma linha)*/
	t = 0;
    for (i = 0; i < s; i++) {
		if (info[1][i] < 1/cos(info[0][i]))
			t++;
    }

	/***DEBUG***/
	if (DEBUG){
        for (i = 0; i < 2; i++) {
            for (j = 0; j < s; j++) {
                printf("info[%d][%d] = %f\n", i, j, info[i][j]);  
            }
        }
    }
	/***DEBUG***/

	retorno = (double)t/s * SEC1;

    /**Saida**/
	printf("===> P4: s = %d, t = %d\n", s, t);
	printf("===> P4: t/s * sec(1) = %f\n", retorno);
	printf("===> P4: Área estimada: %f \n", retorno);

	printf("===> P4: Finalizado.\n");
	
    free(info[0]);
    free(info[1]);

    return retorno;
}


/*para testar*/
/*
int main(int argc, char** argv){
    if(argc > 1){
        p4(atoi(argv[1]));
    }
    return 0;
}
*/
/*******************************/
