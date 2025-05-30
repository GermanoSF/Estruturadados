#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"lista.h"

#define TAM_LISTA1 30
#define TAM_LISTA2 30

int main(){
      
      int num_1a100;
      
      Celula *lista1 = NULL;
      Celula *lista2 = NULL;
      
      srand(time(NULL));
      
      for (int i=0;i<TAM_LISTA1;i++){
      	
      	num_1a100=rand()%101;
      	while(num_1a100 == 0){    //garante que a variavel com o numero que sera armazenado na lista1 esteja no intervalo de 1 a 100
      		
      		num_1a100=rand()%101;
      	
    	}
      	
      	lista1 = inserir(num_1a100,lista1);
      	
      }
      
      for (int i=0;i<TAM_LISTA2;i++){
      	
      	num_1a100=rand()%101;
      	while(num_1a100 == 0){    //garante que a variavel com o numero que sera armazenado na lista2 esteja no intervalo de 1 a 100
      		
      		num_1a100=rand()%101;
      	
    	}
      	
      	lista2 = inserir(num_1a100,lista2);
      	
      }
      
      printf("Listas criadas:\n\n");
      
      exibir_ambas(lista1,lista2);
      
      lista1 = remover_pares(lista1);
     
      printf("\nLista 1 sem pares:\n");
      
      exibir(lista1);
      
      Celula *lista3 = unir_listas(lista1,lista2);
      
      printf("\n\n\nUniao:\n\n");
      
      exibir(lista3);
      
      lista3 = ordenar(lista3);
      
      printf("\n\nUniao das listas de forma ordenada (nao repete numeros iguais):\n\n");
      
      exibir(lista3);
      
      lista3 = deletar_lista(lista3);
      
      if (!lista3) printf("\n\nLista de uniao removida com sucesso");

	return 0;
      
  }
