#include<stdlib.h>
#include<stdio.h>
#include <math.h>



void peneira(int p, int m, int v[]);
//void heapsort (int n, int v[]);
int contador = 0;

int main() {
    int vetor10_2[10];
    int i;
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

    //heapsort(tam_vetor, vetor10_2);

    for (posicao = (tam_vetor-1)/2; posicao >= 0; --posicao) {
        peneira(posicao, tam_vetor, vetor10_2);
    }

    for (m=tam_vetor-1; m>=1; m--) {
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

	printf("Contagem de Ciclos: %d.\n", contador);



    return 0;
    system("PAUSE");
}



//Método implementado por Fábio e sua equipe:

/*void trocapos(long int *x, long int *y){
    long int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void heapsort(){
    long int i;
    for(i = (tam-1)/2; i >=0; i--){
        heapficar(i, tam-1);
    }
    for(i = tam-1; i>=1; i--){
        trocapos(&cpvet[0], &cpvet[i]);
        heapficar(0, i-1);
    }
}

void heapficar(long int i, long int f ){
    long int aux, j;
    aux = cpvet[i];
    j = i*2+1;
    while(j <=f){
        contador++;
        if(j<f){
            if(cpvet[j] < cpvet[j+1]){
                j++;
            }
        }
        if(aux < cpvet[j]){
            cpvet[i] = cpvet[j];
            i = j;
            j = 2*i+1;
        }else
        j = f+1;
    }
    cpvet[i] = aux;
} */


void peneira (int p, int m, int v[]) {
    int x = v[p];
    int f = 2*p + 1;

    while (f <= m) {
        contador++;
        if (v[f] < v[f+1])
            f++;
        if (x < v[f]) {
            v[p] = v[f];
            p = f;
            f = 2*p+1;
        } else
            f = m+1;
    }
    v[p] = x;
}


/*void heapsort (int n, int v[]) {
    int p, m, x;
    for (p = n/2; p >= 1; --p)
        peneira (p, n, v);
    for (m = n; m >= 2; --m) {
        x = v[1];
        v[1] = v[m];
        v[m] = x;
        peneira (1, m-1, v);
    }

} */


