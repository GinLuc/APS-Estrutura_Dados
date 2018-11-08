#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int vetor10_2[10],menor, posmenor, i, j, contador = 0;



    printf("\n\n-------------Metodo Selecao Direta-------------\n\n");

//Criação e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<10;i++) {
        vetor10_2[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<10;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }


//Implementação do Método Seleção Direta

    printf("\nOrdenando...\n\n");
    for(i=0;i<10;i++){
        menor=vetor10_2[i];
        posmenor=i;
        //printf("\nMenor = %d",menor);

        for(j=i+1;j<10;j++) {
        // Verificação do valor ser menor que o primeiro capturado, a partir do elemento seguinte em diante
       // printf("\nMenor 2no J = %d ",menor);
       // printf("\nValor vetor principal = %d",vetor10_2[i]);
            if(vetor10_2[j]<menor) {
                menor=vetor10_2[j];
                posmenor=j;
            }
            contador++;
           
        }
        
            vetor10_2[posmenor]=vetor10_2[i];
            vetor10_2[i]=menor;
    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<10;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }
    printf("\nContagem de Voltas: %d", contador);



    return 0;
    system("PAUSE");
}
