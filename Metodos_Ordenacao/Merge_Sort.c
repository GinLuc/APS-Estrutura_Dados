#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mergesort(int e, int d, int v[]);
void intercala(int e, int meio, int d, int v[]);

int contador = 0;

int main() {
    int vetor[10], posinicial = 0, tam_vetor=(sizeof(vetor)/4), i;

    printf("\n\n-------------Metodo Merge Sort-------------\n\n");

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




//Implementação do Método Merge Sort

    printf("\nOrdenando...\n\n");
    mergesort(posinicial,tam_vetor,vetor);


	printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam_vetor;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }

	printf("\n\nNumero de Ciclos: %d\n", contador);

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
        contador++;
    }

    while (i<meio) {
        w[k++] = v[i++];
        contador++;
    }
    while (j<d) {
        w[k++] = v[j++];
        contador++;
    }
    for (i=e;i<d;++i) {
        v[i] = w[i-e];
        contador++;
    }

    free(w);
}
