#include <stdio.h>
#include <stdlib.h>

#define KKK 100000000

void View (int vetor[],int tam);
struct vetor{
	
	int vetor
};

int main (){
	
	int tam;
	int i;
	//int v[KKK];
	
	
	int *p  = (int *) calloc(KKK,sizeof(int));
	
	printf("%d",*p);
	
	
	for(i=0;i<KKK;i++){
		p[i] = rand();
		printf("\nIndice : %d \t Valor : %d",i+1,p[i]);
		
	}
	
	
	
	
	/*
	printf("\nDigite o Tamanho do vetor   -> ");
	scanf("%d",&tam);
	
	int vetor[tam];
	
	for(i=0;i<tam;i++){
	
	vetor[i] = i;
	//printf("\nDigite os Valores do Vetor Escolhido ->");
	//scanf("%d",&vetor[i]);
	
	}
	
	View(vetor,tam);
	
	*/
	getch();
}

void View (int vetor[],int tam){
	
	
	int i = 0;	
	for(i=0;i<tam;i++){
		
		printf("\nVetor = %d",vetor[i]);
		
	}
}

