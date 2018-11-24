#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main() {
    int vetor10_2[10];
    int j,k,posInicial,r,aux,i;
    int contador = 0;

    posInicial=1;
    r=k=10-1;


    printf("\n\n-------------Metodo Shake Sort-------------\n\n");

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

//Implementação do Método Shake Sort

    printf("\nOrdenando...\n\n");
    do {

    //Varredura da Direita(tamVetor-1) para a Esquerda(PosInicial)
        for(j=r;j>=posInicial;j--){

            if(vetor10_2[j-1]>vetor10_2[j]) {
                aux=vetor10_2[j-1];
                vetor10_2[j-1]=vetor10_2[j];
                vetor10_2[j]=aux;
                k=j;
            }
            contador++;

    	}

       posInicial=k+1;

    //Varredura da Esquerda(posInicial) para Direita(tamVetor-1)
        for(j=posInicial;j<=r;j++){
            if(vetor10_2[j-1]>vetor10_2[j]){
                aux=vetor10_2[j-1];
                vetor10_2[j-1]=vetor10_2[j];
                vetor10_2[j]=aux;
                k=j;
            }
             contador++;

    	}

        r=k-1;
    } while(posInicial<=r);


    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<10;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }

    printf("\nContagem de Voltas: %d", contador);



    return 0;
    system("PAUSE");
}
