#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int vetor[1000000], menor, posmenor, i, j, contador = 0;
    int tam_vetor=sizeof(vetor)/4;



    printf("\n\n-------------Metodo Selecao Direta-------------\n\n");

//Criação e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<tam_vetor;i++) {
        vetor[i] = rand() %100;
    }

    printf("\n\nVetor Criado!!!\n");
    if (tam_vetor < 10000) {
        printf("\nIndice:\t Valor:\n");
        for(i=0;i<tam_vetor;i++) {
            printf("%d\t %d\n", i+1, vetor[i]);
        }
    }


//Implementação do Método Seleção Direta

    printf("\nOrdenando...\n\n");
    for(i=0;i<tam_vetor;i++){
        menor=vetor[i];
        posmenor=i;
        //printf("\nMenor = %d",menor);

        for(j=i+1;j<tam_vetor;j++) {
        // Verificação do valor ser menor que o primeiro capturado, a partir do elemento seguinte em diante
       // printf("\nMenor 2no J = %d ",menor);
       // printf("\nValor vetor principal = %d",vetor10_2[i]);
            if(vetor[j]<menor) {
                menor=vetor[j];
                posmenor=j;
            }
            contador++;

        }

            vetor[posmenor]=vetor[i];
            vetor[i]=menor;
    }

    printf("\nContagem de Voltas: %d", contador);
    getch();
    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }




    return 0;
    system("PAUSE");
}
