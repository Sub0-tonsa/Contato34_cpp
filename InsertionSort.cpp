/*
	Name: InsertionSort.cpp
	Author: Giovanni Tonsa
	Date: 29/09/26 11:02
	Description: Implementação do metodo de ordenação Insertion Sort 
*/

//implementação das bibliotecas
# include <stdio.h>
# include <time.h>
# include <stdlib.h>

//Prototipação
void insertionSort(int *, int);
int trocas, comp; //Variavel global

main()
{
	//int vet[] = {23, 12, 17, -2, 20, 24, 157, 50, 81, 53};
	int vet[500000];
	
	int tam, i;
	trocas = comp = 0;
	tam = sizeof(vet) / sizeof(int);
	
	clock_t inicio, fim;
	double tempo_decorrido;
	
	srand(time(NULL)); //plantação de semente para gerar um numero randomico 
	//Geração randomica de conteudo do vetor
	for(i = 0; i < tam; i++)
		vet[i] = rand() % 1000000;
	
	puts("Vetor Original: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	inicio = clock(); //Captura do tempo inicial
	
	//invoke da função
	insertionSort(vet, tam);
	
	fim = clock(); //Captura do final do tempo
	tempo_decorrido = ((double)fim - inicio) / CLOCKS_PER_SEC; //Mostra o tempo decorrido no metodo de ordernação
	
	puts("\n\nVetor Ordenado pelo Insertion Sort: ");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	printf("\n\nQuantidade de trocas: %d", trocas);
	printf("\nQuantidade de comparacoes: %d", comp);
	printf("\n\n======> Tempo Gasto na Ordenacao: %f", tempo_decorrido);
}//fim do programa

//Função com o codigo do insertion sort
void insertionSort(int *V, int tam)
{
	int i, j, chave;
	
	//Laço para aumentar o I
	for(i = 1; i < tam; i++)
	{
		chave = V[i];
		j = i - 1;
		//Laço para o J voltar (decrementando)
		while(j >= 0 && chave < V[j])
		{
			trocas++;
			comp++;
			V[j + 1] = V[j];
			j--;
		}
	V[j + 1] = chave;
	trocas++;
	}
}
