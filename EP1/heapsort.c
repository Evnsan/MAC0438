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
/**      04/04/2016                                               **/
/*******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heapsort.h"


void geraValoresVetor (int *v) {

	int i;
	
	srand(time(NULL));
	
	for (i = 0; i < 10; i++)
		v[i] = rand()%100;

	
	printf("Vetor gerado aleatoriamente: \n");
	for (i = 0; i < 10; i++)
		printf("v[%d] = %d\n", i, v[i]);

}


void troca(int a, int b) {
	
	int t;

	t = a; 
	a = b; 
	b = t;

}


/*********************************************************/
/*O código abaixo tem por base o heapsort do site do pf*/

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void constroiHeap (int m, int v[]) {
   int k, f;
   
   for (k = 1; k < m; ++k) {                   
      // v[1..k] é um heap
      f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  // 5
         troca (v[f/2], v[f]);          // 6
         f /= 2;                        // 7
      }
   }
}


// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.

static void peneira (int m, int v[]) { 
   
   int p = 1, f = 2, t = v[1];
   
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      if (t >= v[f]) break;
      v[p] = v[f];
      p = f, f = 2*p;
   }
   v[p] = t;
}


// Rearranja os elementos do vetor v[1..n] 
// de modo que fiquem em ordem crescente.

void  heapsort (int n, int v[]) {
   int m;
   constroiHeap (n, v);
   for (m = n; m >= 2; --m) {
      troca (v[1], v[m]);
      peneira (m-1, v);
   }
}



int main() {

	int v[15];

	geraValoresVetor(v);

	return 0;
}