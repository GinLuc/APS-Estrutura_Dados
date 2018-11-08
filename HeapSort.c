#include<stdlib.h>
#include<stdio.h>
#include <math.h>


void peneira(int p, int m, int v[]);

int main() {
    int vetor10_2[20], i;
    int posicao = 0, m, x, tam_vetor = sizeof(vetor10_2) / 4;


    printf("\n\n-------------Metodo HeapSort-------------\n\n");

    //Criação e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<tam_vetor;i++) {
        vetor10_2[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }

    printf("Tamanho do Vetor: %d",tam_vetor);

    printf("\n\n\nOrdenando...\n\n");
    for (posicao = tam_vetor/2; posicao >= 1; --posicao) {
        peneira(posicao, tam_vetor, vetor10_2);
    }

    for (m=tam_vetor; m>=2; --m) {
        x = vetor10_2[1];
        vetor10_2[1] = vetor10_2[m];
        vetor10_2[m] = x;

        peneira(1, m-1, vetor10_2);


    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }




    return 0;
    system("PAUSE");
}

void peneira(int p, int m, int v[]) {
    int vl_inicial = v[p], i;


    while (2*p < m) {
        int f = 2*p;
        if (f<m && v[f]<v[f+1])   {
            ++f;
        }

        if (vl_inicial >= v[f]) {
            break;
        }


        printf("\n%d\t %d\n",  v[p], v[f]);
        v[p] = v[f];
        p = f;


    }

    v[p] = vl_inicial;




}
