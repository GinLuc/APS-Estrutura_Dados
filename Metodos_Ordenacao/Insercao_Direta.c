#include<stdlib.h>
#include<stdio.h>
#include <math.h>


/* M�todo Inser��o Direta*/

int main() {
    int vetor10_2[100], contador = 0;
    int j,aux,i;

    printf("\n\n-------------Metodo Insercao Direta-------------\n\n");

//Cria��o e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<100;i++) {
        vetor10_2[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<100;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }


//Implementa��o do M�todo Inser��o Direta

    printf("\nOrdenando...\n\n");
	
//Pega-se o valor de um elemento e compara com seu/seus elementos antecessores, esses j� ordenados
    for(i=1;i<100;i++) {
        aux=vetor10_2[i]; //Representa inicialmente o segundo elemento capturado pelo �ndice i, sendo esse igual a 1
        j=i-1; //Representa o �ndice anterior ao �ndice i, valendo esse um n�mero antes de i, sendo o elemento que o representa como antecessor ao analisado
        
		//Verifica��o do �ndice anterior ao selecionado
		while((j>=0)&&(aux<vetor10_2[j])) { //Caso o �ndice seja maior ou igual a 0(ainda est� no vetor), e o elemento que o representa seja menor que o elemento analisado...
            vetor10_2[j+1]=vetor10_2[j]; //Ocorre a substitui��o do valor do elemento posterior(este analisado) pelo valor do elemento antecessor a ele
            j--;
            contador++;
        }
		
		// Caso o valor do elemento que representa o �ndice anterior n�o seja menor que o posterior, ou o �ndice anterior seja menor que 0
		//o elemento posterior deve receber o seu valor de volta, ordenando o vetor do menor valor at� que o �ltimo/maior valor seja atribu�do. 
        vetor10_2[j+1] = aux;
        
    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<100;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }
    printf("\nContagem de Ciclos: %d", contador);



    return 0;
    system("PAUSE");
}
