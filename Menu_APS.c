#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


/*Constante que irao fazer o tamanho do vetor */
#define v1 10
#define v2 100
#define v3 10000
#define v4 1000000
#define v5 100000000
#define v6 1000000000

/*Variaveis auxiliadoras que irao usar em todos metodos de ordena√ßao ao longo do programa ... */
int i,j,aux,contador=0,menor,posmenor,r,k,posInicial;
/* Aqui fica todas as fun√ß√µes a serem usadas do programa desde a geracao de vetores
   ate suas ordena√ßoes ou menus */
int menu_VETOR();  //Opcao onde usuario ira escolher tamanho do Vetor[M] ......
int menu_ORDENACAO(); // Opcao onde usuario qual metodo de ordenacao ir√° usar .....
void BubbleSort(int vetor[],int tam); // Metodo de ordenacao BubbleSort
void Insercao_Direta(int vetor[],int tam);
void Selecao_Direta(int vetor[],int tam);
void Shake_Sort(int vetor[],int tam);
void Merge_Sort(int e, int d, int v[]);
void intercala (int e, int meio, int d, int v[]);
int main(){

	char resp = 'S';
	do{
		/*Aqui ele ira pegar o valor escolhido na Opcao menu_VETOR e ira gera o vetor
		com tamanho escolhido e mostrando para o usuario */
		system("cls");
		int tam = menu_VETOR();
		int *vetor_principal = (int *) calloc(tam,sizeof(int));
		int *c1 = (int *) calloc(tam,sizeof(int));
		int *c2 = (int *) calloc(tam,sizeof(int));
		int *c3 = (int *) calloc(tam,sizeof(int));
		int *c4 = (int *) calloc(tam,sizeof(int));
		int *c5 = (int *) calloc(tam,sizeof(int));
		int *c6 = (int *) calloc(tam,sizeof(int));
		

		for(i=0;i<tam;i++){
			vetor_principal[i] = rand();							
		}
		
		c1=c2=c3=c4=c5=c6=vetor_principal;
		
		/*
		Obs para meu amigo Gian : Caro Gian deixei essas 2 alternativas para vocÍ escolher
		qual sera a melhor opcao a primeira esta em comentario ele mostra todos os valores
		do Vetor gerado porem quando vamos gerar um vetor de 10^8 ate ele escrever todas as
		posicoes demora de mais, por isso deixei a outra opcao que nao esta em comentarios
		teste qual vc acha que ira agradar o senhor FDP....Obg tenha um bom dia =)
		PS : teste com a opcao 5 so ira fazer diferenca nela.....
		*/

		/*
		for(i=0;i<tam;i++){
			printf("\nV[%d] = %d ",i+1,vetor_principal[i]);
		}*/
		printf("\t---------------------------------");
		printf("\n\n\t|\tVetor Gerado !!!!!\t|\t\n\n");
		printf("\t---------------------------------");
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

				case 5:
				
				break;
				
				case 6:
					Merge_Sort(0,tam,c4);
					system("cls");
					printf("\nOk !! Voce escolheu ....... \n");
				
					printf("\n----------- Merge Sort -----------\n");
					
				    printf("\nIndice:\t Valor:\n");
				    for(i=0;i<tam;i++) {
				        printf("%d\t %d\n", i+1, c4[i]);
				    }
				break;
				
				case 7:
					// Heap em ManutenÁ„o ="(
				break ;
				
				default:
				    printf("\n\nNao foi digitado uma opcao de ordenacao valida!!!\n\n");
				break;
			}

			/*Aqui fica a validacao do usuario do que ele deseja fazer assim que escolher seu vetor e fazer
			  a ordenacao dele onde ele pode escolher entre voltar pro Menu de ordena√ß√£o, caso ele nao queria
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

	return 0;
}

int menu_VETOR(){

	int op_VETOR;
	printf("\nDigite a opcao do vetor que deseja :\n");
	printf("\n 1 - Vetor de 10 posicoes 	\n");
	printf("\n 2 - Vetor de 100 posicoes 	\n");
	printf("\n 3 - Vetor de 10000 posicoes 	\n");
	printf("\n 4 - Vetor de 1000000 posicoes 	\n");
	printf("\n 5 - Vetor de 100000000 posicoes 	\n");
	printf("\n 6 - Vetor de 1000000000 posicoes 	\n");
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
	}
	else if(op_VETOR == 4){
		return v4;
	} 
	else if(op_VETOR == 5){
		return v5;
	}
	else if(op_VETOR == 6){
		return v6;
	}else {
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
	printf("\n 7 - Heap  Sort	(Nao-Feito)	\n");
	printf("\n-> ");

	scanf("%d",&op_ORDENACAO);
	
	printf("\nAguarde o termino da ordenacao ......\n\n");
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
		{ // sempre 1 elemento √† frente{
	      // se o (x > (x+1)) ent√£o o x passa pra frente (ordem crescente)
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
	
	int cont = 0;
	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");

	printf("\n----------- Insercao Direta -----------\n");
    for(i=1;i<tam;i++) {
        aux=vetor[i];
        j=i-1;
        while((j>=0)&&(aux<vetor[j])) {
            vetor[j+1]=vetor[j]; //Deslocando
            j--;
            cont++;
        }
        vetor[j+1] = aux; //Inserindo
        
    }

    printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", cont);
}

void Selecao_Direta(int vetor[],int tam){
	
	int cont = 0;
	system("cls");
	printf("\nOk !! Voce escolheu ....... \n");

	printf("\n----------- Selecao Direta -----------\n");
	
	for(i=0;i<tam;i++){
        menor=vetor[i];
        posmenor=i;
        //printf("\nMenor = %d",menor);

        for(j=i+1;j<tam;j++) {
        // VerificaÁ„o do valor ser menor que o primeiro capturado, a partir do elemento seguinte em diante
       // printf("\nMenor 2no J = %d ",menor);
       // printf("\nValor vetor principal = %d",vetor10_2[i]);
            if(vetor[j]<menor) {
                menor=vetor[j];
                posmenor=j;
            }
            cont++;
           
        }
        
            vetor[posmenor]=vetor[i];
            vetor[i]=menor;
    }
	
	printf("\n\nVetor Ordenado:\n");
    printf("\nIndice:\t Valor:\n");
    for(i=0;i<tam;i++) {
        printf("%d\t %d\n", i+1, vetor[i]);
    }
    printf("\nContagem de Ciclos: %d", cont);
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

void Merge_Sort(int e, int tam, int vetor[]){
	
	int meio;

    if(e<tam-1) {
        meio = (e+tam)/2;
        Merge_Sort(e,meio,vetor);
        Merge_Sort(meio,tam,vetor);
        intercala(e,meio,tam,vetor);        
    }

}

void intercala (int e, int meio, int tam, int vetor[]) {
    int i,j,k,*w;

    w = (int*) malloc ((tam-e) * sizeof(int));

    i=e;
    j=meio;
    k=0;

    while(i<meio && j<tam) {
        if (vetor[i] < vetor[j]) {
            w[k++] = vetor[i++];
        }
        else {
            w[k++] = vetor[j++];
        }
        contador++;
    }

    while (i<meio) {
        w[k++] = vetor[i++];
        contador++;
    }
    while (j<tam) {
        w[k++] = vetor[j++];
        contador++;
    }
    for (i=e;i<tam;++i) {
        vetor[i] = w[i-e];
        contador++;
    }

    free(w);
}





