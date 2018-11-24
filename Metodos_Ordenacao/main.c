#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#ifdef linux
#include <ncurses.h>
#include <curses.h>
#endif
#ifdef __WIN32
#include <conio.h>
#endif

long int particiona(long int e, long int d);
void quicksort(long int e, long int d);
void bubblesort();
void insertionsort();
void selectionsort();
void shakesort();
void mergesort(long int e, long int d);
void intercala(long int e, long int d, long int m);
void heapsort();
void heapficar(long int i, long int f);

void trocapos(long int *x, long int *y);
void ordenacoes(int op);
long int geravet();
long int cpvetor();
void menuOp();
int isNull();
void clearBuffer();

long int *v, tam, *cpvet, contador;

int main() {
	setlocale(LC_ALL,"Portuguese");
    menuOp();
    return 1;
}

void clearBuffer() {
#ifdef linux
    __fpurge(stdin);
#else
    fflush(stdin);
#endif
}

void menuOp() {
    int esc, pot;
    printf("\n\t---------------------------------------------\n");
    printf("\t'                     MENU                    '\n");
    printf("\t' (1) - GERAR UM VETOR                        '\n");
    printf("\t' (2) - ORDENA (BUBBLESORT)                   '\n");
    printf("\t' (3) - ORDENA (QUICKSORT)                    '\n");
    printf("\t' (4) - ORDENA (INSERTION SORT)               '\n");
    printf("\t' (5) - ORDENA (SELECTION SORT)               '\n");
    printf("\t' (6) - ORDENA (SHAKESORT)                    '\n");
    printf("\t' (7) - ORDENA (MERGESORT)                    '\n");
    printf("\t' (8) - ORDENA (HEAPSORT)                     '\n");
    printf("\t'---------------------------------------------'\n");
    printf("\n\tDigite a opção: ");
    scanf("%d", &esc);
    switch (esc) {
        case 1:
            printf("\nDigite a qual potencia deseja elevar o vetor(10): ");
            scanf("%d", &pot);
            tam = pow(10, pot);
            if (geravet() == 1) {
                printf("\nVetor gerado com sucesso! Retornando ao menu");
            } else {
                printf("\nMemória insuficiente para alocar a memoria... retornando ao menu");
            }
            menuOp();
        default:
            ordenacoes(esc);
            break;
    }
    clearBuffer();
}

/**
    Zera o contador e aciona a função de ordenação escolhida
**/
void ordenacoes(int op){
    contador = 0;
    clearBuffer();
    long int i;
    if(isNull()){
        printf("\nAinda nao foi gerado um vetor, retornando ao menu");
    } else {
    	printf("\nAguarde, gerando cópia do vetor...");
        if(cpvetor()){
            printf("\nCópia gerada com sucesso, ordenando vetor... AGUARDE\n");
            switch(op){
                case 2:
                    bubblesort();
                    break;
                case 3:
                    quicksort(0, tam-1);
                    break;
                case 4:
                    insertionsort();
                    break;
                case 5:
                    selectionsort();
                    break;
                case 6:
                    shakesort();
                    break;
                case 7:
                    mergesort(0, tam-1);
                    break;
                case 8:
                    heapsort();
                    break;
                default:
                    printf("\nNenhuma opção válida");
                    break;
            }
            printf("\nVetor ordenado em %ld iterações, pressione <ENTER> para imprimir...",contador);
            getchar();
            for(i = 0; i < tam; i ++){
                printf("\n%ld",cpvet[i]);
            }
            free(cpvet);
        }else{
            printf("\nCópia do vetor não gerada, falta de memória");
        }
    }
    menuOp();
}

void trocapos(long int *x, long int *y){
    long int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int isNull() {
    return (v == NULL);
}

void mergesort(long int e, long int d){
    long int meio;
    if(e < d){
        meio = floor((e+d)/2);
        mergesort(e, meio);
        mergesort(meio+1, d);
        intercala(e, meio, d);
    }
}

void intercala(long int e, long int meio, long int d){
    long int i,j,k;
    long int n1 = meio - e +1;
    long int n2 = d-meio;
    long int *l, *r;
    //long int l[n1], r[n2];
    l = (long int*)malloc(n1*sizeof(long int));
    r = (long int*)malloc(n2*sizeof(long int));
    for(i = 0 ; i < n1; i++){
        l[i] = cpvet[e+i];
    }
    for(j = 0; j< n2; j++){
        r[j] = cpvet[meio+1+j];
    }
    i = 0;
    j = 0;
    k = e;
    while((i<n1) &&(j<n2)){
        contador++;
        if(l[i] <= r[j]){
            cpvet[k] = l[i];
            i++;
        }else{
            cpvet[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        contador++;
        cpvet[k] = l[i];
        i++;
        k++;
    }
    
    //copia elementos do r[], se tiver algum
    while(j < n2){
        contador++;
        cpvet[k] = r[j];
        j++;
        k++;
    }
    free(l);
    free(r);
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
}


void shakesort(){
    long int i, ready;
    do{
        ready = 0;
        for(i = tam-1; i > 0; i--){
            if(cpvet[i-1] > cpvet[i]){
            	contador++;
                trocapos(&cpvet[i-1], &cpvet[i]);
                ready = 1;
            }
        }
		
        for(i = 1; i < tam; i++){
            if(cpvet[i-1]>cpvet[i]){
            	contador++;
                trocapos(&cpvet[i-1], &cpvet[i]);
                ready = 1;
            }
        }
    }while(ready);
}

void selectionsort(){
    long int menor, aux, i, j;
    for(i = 0; i< tam-1; i++){
        menor = i;
        for(j = i+1; j<tam; j++){
            contador++;
            if(cpvet[j] < cpvet[menor]){
                menor = j;
            }
        }
        trocapos(&cpvet[i], &cpvet[menor]);
    }
}

void insertionsort(){
    long int aux, i, j;
    for(i = 1; i<tam; ++i){
        aux = cpvet[i];
        j = i-1;
        contador++;
        while((j>=0) && (aux<cpvet[j])){
            cpvet[j+1] = cpvet[j];
            j--;
        }
        cpvet[j+1] = aux;
    }
}

void quicksort(long int e, long int d) {
    long int i;
    if (d > e) {
        i = particiona(e, d);
        quicksort(e, i - 1);
        quicksort(i + 1, d);

    }
}

long int particiona(long int e, long int d) {
    long int pivo, esq, dir, aux;
    pivo = cpvet[d];
    esq = e - 1;
    dir = d;
    do {
        do {
            esq++;
            contador++;
        } while ((cpvet[esq] < pivo) && (esq < d));

        do {
            dir--;
            contador++;
        } while ((cpvet[dir] > pivo) &&(dir > 0));
        aux = cpvet[esq];
        cpvet[esq] = cpvet[dir];
        cpvet[dir] = aux;
    } while (dir > esq);
    cpvet[dir] = cpvet[esq];
    cpvet[esq] = cpvet[d];
    cpvet[d] = aux;
    return (esq);

}

void bubblesort() {
    long int i, j, aux;
    for (i = 0; i < tam; i++) {
        for (j = 0; j < (tam - 1); j++) {
        	contador++;
            if (cpvet[j] > cpvet[j + 1]) {
                aux = cpvet[j];
                cpvet[j] = cpvet[j + 1]; 
                cpvet[j + 1] = aux;
            }
        }
    }
}

long int geravet() {
    printf("\nAguarde, gerando o vetor de %ld posicoes",tam);
    long int i;
    v = (long int*) malloc(sizeof (long int)*tam);
    for (i = 0; i < tam; i++) {
        v[i] = rand() % tam;
    }
    if (v == NULL) {
        return 0;
    } else {
        return 1;
    }
}

long int cpvetor() {
	long int i;
    cpvet = (long int*) malloc(sizeof (long int)*tam);
    for (i = 0; i < tam; i++) {
        cpvet[i] = v[i];
    }
    if (cpvet != NULL) {
        return 1;
    } else {
        return 0;
    }

}
