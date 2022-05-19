#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; 
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		if(vet[i] <= pivo)
		{
			troca(vet, i, pivo_indice);
	
			pivo_indice++;
		}
	}
	
	troca(vet, pivo_indice, fim);
	
	return pivo_indice;
}

int particiona_random(int vet[], int inicio, int fim)
{
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	troca(vet, pivo_indice, fim);
	
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int main()
{
	int vet[100000];
	int tam_vet = sizeof(vet) / sizeof(int);
	int i;
	
	srand(time(NULL));
	
    	for(i=tam_vet-1; i>=0; i--){
        	vet[i] = i;
   	}
    
	quick_sort(vet, 0, tam_vet - 1);

	for(i = 0; i < tam_vet; i++)
		printf("%d ", vet[i]);
	
	return 0; 
}
