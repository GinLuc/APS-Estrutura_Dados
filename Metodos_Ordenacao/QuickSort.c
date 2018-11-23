#include <stdio.h>
#include <stdlib.h>

int a[10], t=0 ,i=0, cont=0;


void quicksort(int e, int d);
int particao(int e, int d);

int main(){
	
	
	
	printf("\n\n------------------------ Metodo de QuickSort ------------------------");
	
	for(i=0;i<10;i++){
		a[i] = rand() %10;
	}
	
	printf("\nVetor Gerado :\n");
	for(i=0;i<10;i++){
		printf("\n%d",a[i]);
	}
	
	quicksort(0,10-1);
	
	printf("\n\nVetor Ordenado :\n\n");
		for(i=0;i<10;i++){
		printf("\n%d",a[i]);
	}
	printf("\n\ncontador - > %d",cont);
	printf("\n\n");
	system("PAUSE");
	return 0;
}
void quicksort(int e, int d){
	
	int i;
	
	if(d > e){
		i= particao(e,d); //importante
		quicksort(e,i-1);
		quicksort(i+1,d);
	}
}

int particao(int e, int d){
	
	int v,i,j;
	
	v = a[d];
	i = e -1;
	j = d;
	
	do{
		
		
		do{
			i = i+1; // esquerda
			cont++;
		}while((a[i] < v) && (i < d)); //Percorre todos os índices até que encontre um valor maior que o do pivô
		
		do{
			j = j-1; //direita
			cont++;
		}while((a[j] > v ) && (j > 0)); //Percorre todos os índices da direita até que encontre um valor menor que o pivô  
		
		
		//Realizando a troca dos valores menor(para a esquerda) e maior(para a direita) que o pivô 
		t = a[i];
		a[i] =a[j];
		a[j] = t;		
		
				
	}while(j > i);
	
	//colocando o pivor [d] em seu lugar
	a[j] = a[i];
	a[i] = a[d];
	a[d] = t;
	return(i);
}
