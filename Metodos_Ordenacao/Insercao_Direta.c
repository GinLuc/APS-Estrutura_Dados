#include<stdlib.h>
#include<stdio.h>
#include <math.h>


/* Método Inserção Direta*/

int main() {
    int vetor[100], contador = 0, tam_vetor=(sizeof(vetor)/4;
    int j,aux,i;

    printf("\n\n-------------Metodo Insercao Direta-------------\n\n");

//Criação e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<tam_vetor;i++) {
        vetor[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }


//Implementação do Método Inserção Direta

    printf("\nOrdenando...\n\n");

//Pega-se o valor de um elemento e compara com seu/seus elementos antecessores, esses já ordenados
    for(i=1;i<tam_vetor;i++) {
        aux=vetor[i]; //Representa inicialmente o segundo elemento capturado pelo índice i, sendo esse igual a 1
        j=i-1; //Representa o índice anterior ao índice i, valendo esse um número antes de i, sendo o elemento que o representa como antecessor ao analisado

		//Verificação do índice anterior ao selecionado
		while((j>=0)&&(aux<vetor[j])) { //Caso o índice seja maior ou igual a 0(ainda está no vetor), e o elemento que o representa seja menor que o elemento analisado...
            vetor10_2[j+1]=vetor[j]; //Ocorre a substituição do valor do elemento posterior(este analisado) pelo valor do elemento antecessor a ele
            j--;
            contador++;
        }

		// Caso o valor do elemento que representa o índice anterior não seja menor que o posterior, ou o índice anterior seja menor que 0
		//o elemento posterior deve receber o seu valor de volta, ordenando o vetor do menor valor até que o último/maior valor seja atribuído.
        vetor10_2[j+1] = aux;

    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", contador);



    return 0;
    system("PAUSE");
}
