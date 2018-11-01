#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mergesort(int e, int d, int v[]);
void intercala(int e, int meio, int d, int v[]);


int main() {
    int vetor10_2[10], posinicial = 0, tamvetor = 10, i;

    printf("\n\n-------------Metodo Merge Sort-------------\n\n");

    //Cria��o e Mostragem do Vetor
    printf("\nCriando Vetor...\n");
    for(i=0;i<10;i++) {
        vetor10_2[i] = rand() %100;
    }

    printf("\n\nVetor Criado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<10;i++) {
        printf("%d\t %d\n", i+1, vetor10_2[i]);
    }


//Implementa��o do M�todo Merge Sort

    printf("\nOrdenando...\n\n");
    mergesort(posinicial,tamvetor,vetor10_2);


    printf("\n\nVetor Ordenado:\n");
        printf("\nIndice:\t Valor:\n");
        for(i=0;i<10;i++) {
            printf("%d\t %d\n", i+1, vetor10_2[i]);
        }

    return 0;
    system("PAUSE");
}

void mergesort(int e, int d, int v[]) {
    int meio;

    if(e<d-1) {
        meio = (e+d)/2;
        mergesort(e,meio,v);
        mergesort(meio,d,v);
        intercala(e,meio,d,v);
    }
}


void intercala (int e, int meio, int d, int v[]) {
    int i,j,k,*w;

    w = (int*) malloc ((d-e) * sizeof(int));

    i=e;
    j=meio;
    k=0;

    while(i<meio && j<d) {
        if (v[i] < v[j]) {
            w[k++] = v[i++];
        }
        else {
            w[k++] = v[j++];
        }
    }

    while (i<meio) {
        w[k++] = v[i++];
    }
    while (j<d) {
        w[k++] = v[j++];
    }
    for (i=e;i<d;++i) {
        v[i] = w[i-e];
    }

    free(w);
}