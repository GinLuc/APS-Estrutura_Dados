#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/*Constante que irao fazer o tamanho do vetor */
#define v1 10
#define v2 100
#define v3 1000
#define v4 10000

/*Variaveis auxiliadoras que irao usar em todos metodos de ordenaçao ao longo do programa ... */
int i,j,aux,contador=0,menor,posmenor,r,k,posInicial;
/* Aqui fica todas as funções a serem usadas do programa desde a geracao de vetores
   ate suas ordenaçoes ou menus */
int menu_VETOR();  //Opcao onde usuario ira escolher tamanho do Vetor[M] ......
int menu_ORDENACAO(); // Opcao onde usuario qual metodo de ordenacao irá usar .....
void BubbleSort(int vetor[],int tam); // Metodo de ordenacao BubbleSort
void Insercao_Direta(int vetor[],int tam);
void Selecao_Direta(int vetor[],int tam);
void Shake_Sort(int vetor[],int tam);
int main(){

	char resp = 'S';
	do{
		/*Aqui ele ira pegar o valor escolhido na Opcao menu_VETOR e ira gera o vetor
		com tamanho escolhido e mostrando para o usuario */
		system("cls");
		int tam = menu_VETOR();
		int vetor_principal[tam];
		int c1[tam],c2[tam],c3[tam],c4[tam],c5[tam],c6[tam];

		for(i=0;i<tam;i++){
			vetor_principal[i] = rand() %1000;
			c1[i] = vetor_principal[i];
			c2[i] = vetor_principal[i];
			c3[i] = vetor_principal[i];
			c4[i] = vetor_principal[i];
			c5[i] = vetor_principal[i];
			c6[i] = vetor_principal[i];			
		}

		for(i=0;i<tam;i++){
			printf("\nV[%d] = %d ",i+1,vetor_principal[i]);
		}
		printf("\n\nPressione qualquer tecla para continuar ......");
		getch();

		do{

			int op_MAIN = menu_ORDENACAO();

			switch(op_MAIN){

				case 1:
					BubbleSort(vetor_principal,tam);
				break;

				case 2:
					Insercao_Direta(c1,tam);
				break;

				case 3:
					Selecao_Direta(c2,tam);
				break;
				
				case 4:
					Shake_Sort(c3,tam);
				break;

				default:
				    printf("\n\nNao foi digitado uma opcao de ordenacao valida!!!\n\n");
				break;
			}

			/*Aqui fica a validacao do usuario do que ele deseja fazer assim que escolher seu vetor e fazer
			  a ordenacao dele onde ele pode escolher entre voltar pro Menu de ordenação, caso ele nao queria
			  vai para segunda pergunta que seria voltar para o Menu principal caso contrario o programa sera
			  ecenrrado */
			printf("\nDeseja fazer uma nova Ordenacao com mesmo vetor ? <S/N>\n");
			resp = toupper(getch());
				while(resp != 'S' && resp != 'N'){
					printf("\nOpcao Invalida !! Tente novamente !!!");
					printf("\nSomente 'S'  ou  'N'");
					printf("\n-> ");
					fflush(stdin);
					resp = toupper(getche());
				}

		}while(resp == 'S');

			printf("\nDeseja voltar ao Menu dos Vetores ? <S/N>\n");
			resp = toupper(getch());
				while(resp != 'S' && resp != 'N'){
					printf("\nOpcao Invalida !! Tente novamente !!!");
					printf("\nSomente 'S'  ou  'N'");
					printf("\n-> ");
					fflush(stdin);
					resp = toupper(getche());
				}
	}while(resp == 'S');

}

int menu_VETOR(){

	int op_VETOR;
	printf("\nDigite a opcao do vetor que deseja :\n");
	printf("\n 1 - Vetor de 10 posicoes 	\n");
	printf("\n 2 - Vetor de 100 posicoes 	\n");
	printf("\n 3 - Vetor de 1000 posicoes 	\n");
	printf("\n-> ");
	fflush(stdin);
	scanf("%d",&op_VETOR);

	if(op_VETOR == 1){
		return v1;
	}

	else if(op_VETOR == 2){
		return v2;
	}

   else if (op_VETOR == 3){
		return v3;
	} else {
	    system("cls");
	    printf("\Nao foi digitado um valor valido!!!\n\n");
	    menu_VETOR();
	}

}

int menu_ORDENACAO(){

	system("cls");
	int op_ORDENACAO;
	printf("\nDigite a opcao da ordenacao desejada :\n");
	printf("\n 1 - Bubble Sort		\n");
	printf("\n 2 - Insercao Direta 	\n");
	printf("\n 3 - Selecao Direta 	\n");
	printf("\n 4 - Shake Sort 		\n");
	printf("\n 5 - Quick Sort 		\n");
	printf("\n 6 - Merge Sort		\n");
	printf("\n-> ");
	scanf("%d",&op_ORDENACAO);
	return op_ORDENACAO;

}

void BubbleSort(int vetor[],int tam){
	
	contador=0;
	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");

	printf("\n----------- Metodo BubbleSort -----------\n");

	for( i = 0; i < tam; i++ )
	{
	    for( j = i + 1; j < tam; j++ )
		{ // sempre 1 elemento à frente{
	      // se o (x > (x+1)) então o x passa pra frente (ordem crescente)
	      if ( vetor[i] > vetor[j] )
	      {
	         aux = vetor[i];
	         vetor[i] = vetor[j];
	         vetor[j] = aux;
	      }
	    }
	}

	printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", contador);

}

void Insercao_Direta(int vetor[],int tam){
	
	contador = 0;
	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");

	printf("\n----------- Insercao Direta -----------\n");
    for(i=1;i<tam;i++) {
        aux=vetor[i];
        j=i-1;
        while((j>=0)&&(aux<vetor[j])) {
            vetor[j+1]=vetor[j]; //Deslocando
            j--;
            contador++;
        }
        vetor[j+1] = aux; //Inserindo
        
    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", contador);
}

void Selecao_Direta(int vetor[],int tam){
	
	contador = 0;
	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");

	printf("\n----------- Selecao Direta -----------\n");
	
	for(i=0;i<tam;i++){
        menor=vetor[i];
        posmenor=i;
        //printf("\nMenor = %d",menor);

        for(j=i+1;j<tam;j++) {
        // Verifica��o do valor ser menor que o primeiro capturado, a partir do elemento seguinte em diante
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
	
	printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", contador);
}

void Shake_Sort(int vetor[],int tam){
	

	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");
	
	posInicial=1;
    r=k=tam-1;

	printf("\n----------- Shake Sort -----------\n");
	
	do {

    //Varredura da Direita(tamVetor-1) para a Esquerda(PosInicial)
        for(j=r;j>=posInicial;j--){
		 
            if(vetor[j-1]>vetor[j]) {
                aux=vetor[j-1];
                vetor[j-1]=vetor[j];
                vetor[j]=aux;
                k=j;
            }
            contador++;
          
    	}

       posInicial=k+1;

    //Varredura da Esquerda(posInicial) para Direita(tamVetor-1)
        for(j=posInicial;j<=r;j++){ 
            if(vetor[j-1]>vetor[j]){
                aux=vetor[j-1];
                vetor[j-1]=vetor[j];
                vetor[j]=aux;
                k=j;
            }
             contador++;
             
    	}

        r=k-1;
    } while(posInicial<=r);
	
	
	printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    
    printf("\nContagem de Ciclos: %d", contador);
	
	
}






