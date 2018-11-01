#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

/*Constante que irao fazer o tamanho do vetor */
#define v1 10
#define v2 100
#define v3 1000

/*Variaveis auxiliadoras que irao usar em todos metodos de ordenaçao ao longo do programa ... */
int i,j,aux;
/* Aqui fica todas as funções a serem usadas do programa desde a geracao de vetores
   ate suas ordenaçoes ou menus */
int menu_VETOR();  //Opcao onde usuario ira escolher tamanho do Vetor[M] ......
int menu_ORDENACAO(); // Opcao onde usuario qual metodo de ordenacao irá usar .....
void BubbleSort(int vetor[],int tam); // Metodo de ordenação BubbleSort
int main(){

	char resp = 'S';
	do{
		/*Aqui ele ira pegar o valor escolhido na Opcao menu_VETOR e ira gera o vetor
		com tamanho escolhido e mostrando para o usuario */
		system("cls");
		int tam = menu_VETOR();
		int vetor_principial[tam];

		for(i=0;i<tam;i++){
			vetor_principial[i] = rand() %1000;
		}

		for(i=0;i<tam;i++){
			printf("\nV[%d] = %d ",i+1,vetor_principial[i]);
		}
		printf("\n\nPressione qualquer tecla para continuar ......");
		getch();

		do{

			int op_MAIN = menu_ORDENACAO();

			switch(op_MAIN){

				case 1:
					BubbleSort(vetor_principial,tam);
				break;

				case 2:
				break;

				case 3:
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
	printf("\n10");
	printf("\n100");
	printf("\n1000");
	printf("\n-> ");
	fflush(stdin);
	scanf("%d",&op_VETOR);

	if(op_VETOR == 10){
		return v1;
	}

	else if(op_VETOR == 100){
		return v2;
	}

   else if (op_VETOR == 1000){
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
	printf("\n 1 - Buble Sort");
	printf("\n-> ");
	scanf("%d",&op_ORDENACAO);
	return op_ORDENACAO;

}

void BubbleSort(int vetor[],int tam){

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

	  printf("\n\n----- Elementos ordenados -----\n\n");

	for( i = 0; i < tam; i++ ) {
	    printf("\nV[%d] - > %d ",i+1,vetor[i]); // exibe o vetor ordenado
	  }

}



