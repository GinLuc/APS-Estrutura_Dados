#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int main(){

  int vetor[1000000],
      tam_vetor=(sizeof(vetor)/4),
      i = 0,
      j = 0,
      aux = 0,
	  contador = 0;

    printf("\n\n------------------------ Metodo de BubbleSort ------------------------");


  printf("\n\n----- Vetor Gerado -----\n\n");
  for( i = 0; i < tam_vetor; i++ )
  {
	vetor[i] = rand() %100;
	printf("\nV[%d] - > %d ",i,vetor[i]);
  }


  for( i = 0; i < tam_vetor; i++ )
  {
    for( j = i + 1; j < tam_vetor; j++ )
	{ // sempre 1 elemento à frente{
      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
      if ( vetor[i] > vetor[j] )
      {
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
      }
      contador++;
    }
   }// fim da ordenação


  // exibe elementos ordenados
  printf("\n\n----- Elementos ordenados -----\n\n");

  for( i = 0; i < tam_vetor; i++ )
  {
    printf("\nV[%d] - > %d ",i,vetor[i]); // exibe o vetor ordenado
  }

  printf("\nNumero de Ciclos: %d", contador);

  printf("\n\n");
  	getch();
  	return 0;



}

