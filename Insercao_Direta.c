#include<stdlib.h>
#include<stdio.h>
#include <math.h>

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
    for(i=1;i<100;i++) {
        aux=vetor10_2[i];
        j=i-1;
        while((j>=0)&&(aux<vetor10_2[j])) {
            vetor10_2[j+1]=vetor10_2[j]; //Deslocando
            j--;
            contador++;
        }
        vetor10_2[j+1] = aux; //Inserindo
        
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
