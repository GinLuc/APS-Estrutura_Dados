#include<stdlib.h>
#include<stdio.h>
#include <math.h>

int main() {
    int vetor10_2[100],menor, posmenor, i, j, contador = 1;



    printf("\n\n-------------Metodo Selecao Direta-------------\n\n");

//Criação e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<100;i++) {
        vetor10_2[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<100;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }


//Implementação do Método Seleção Direta

    printf("\nOrdenando...\n\n");
    for(i=0;i<100;i++){
        menor=vetor10_2[i];
        posmenor=i;

        for(j=i+1;j<100;j++) {
            if(vetor10_2[j]<menor) {
                menor=vetor10_2[j];
                posmenor=j;
            }
            vetor10_2[posmenor]=vetor10_2[i];
            vetor10_2[i]=menor;
        }
    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<100;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }
    printf("\nContagem de Voltas: %d", contador);



    return 0;
    system("PAUSE");
}
