#include<stdbool.h>
#include<limits.h> //utilizado para ordenacao

typedef struct no{
      
      int dado;
      struct no *prox;
      
}Celula;

Celula *inserir(int dado , Celula *lista){
	
	Celula *novo= (Celula *) malloc(sizeof(Celula));
      
    novo->dado = dado;
    novo->prox = NULL;
      
    if (!lista){
            
        return novo;
            
    }
      
    Celula *p;
    for(p=lista;p->prox;p = p->prox);
      
    p->prox = novo;
    return lista;
      
}

void exibir_ambas(Celula *lista1, Celula *lista2){
    
    int posicao;
	
	posicao = 0; 
    for (Celula *p = lista1; p ;p=p->prox){
            
        printf("dado da posicao %i na lista 1: %i\n",posicao,p->dado);
        posicao++;
            
    }
    
	printf("\n\n\n");
	  
    posicao = 0; 
    for (Celula *p = lista2; p ;p=p->prox){
            
        printf("dado da posicao %i na lista 2: %i\n",posicao,p->dado);
        posicao++;
            
    }
    
    return;
      
}

void exibir(Celula *lista){
	
	int posicao = 0;
	
	for(Celula *p=lista; p ; p=p->prox){
		
		printf("dado da posicao %i na lista: %i\n",posicao,p->dado);
		posicao++;
		
	}
	
}

Celula *deletar(int dado, Celula *lista){
	
	if (lista->dado==dado){
		
		Celula *p = lista->prox;
		free(lista);
		return p;
		
	}
	
	for (Celula *p=lista; p->prox ;p=p->prox){
		
		if (p->prox->dado==dado){
			
			if (p->prox->prox){
				
				Celula *pR = p->prox;
				p->prox = p->prox->prox;				
				free(pR);
				
				return lista;
				
			}
			Celula *pR = p->prox;
			p->prox = NULL;
			free(pR);
			return lista;	
			
		}
		
	}
	
	return lista;
	
}

Celula *remover_pares(Celula *lista){
	
	Celula *p;
	int condicao;
	int condicao2 = 1;
	
	while (condicao2 == 1){
		
		condicao = 1;
		
		for (p=lista; condicao == 1 ;p=p->prox){
					
			if ((p->dado % 2) == 0 || !p->prox){
				
				if ((p->dado % 2) == 0){
					
					lista = deletar(p->dado,lista);
					
				}
				condicao = 0;
			
			}
			
			if ((p->dado % 2) == 1 && !p->prox) condicao2 = 0;
			
		}
		
	}
	
	return lista;
	
}

Celula *unir_listas(Celula *lista1, Celula *lista2){
		
	Celula *uniao;
	for (uniao = lista1;uniao->prox;uniao=uniao->prox);
	uniao->prox = lista2;
		
	return lista1;
		
}

bool contem(int dado,Celula * lista){
   
   	if (!lista){
   		
   		return false;
   		
   	}
    for(Celula *p=lista; p ;p = p->prox){
       
        if (p->dado==dado){
           
            return true;
           
        }
       
    }
   
    return false;
   
}

Celula *ordenar(Celula *lista){
	
	int menor;
	int contador = 0;
	int flag;	
	Celula *ordenada = NULL;
	
	while (true){
		
		menor = INT_MAX;
		flag = 0;
		
		Celula *p;
		for (p=lista; p ; p=p->prox){
		
			if (!contem(p->dado,ordenada)&&menor>p->dado){
				
				menor = p->dado;
				flag = 1;
				
			}
		
		}
		if (flag == 0){
			
			return ordenada;
	       		
		}
		
		ordenada = inserir(menor,ordenada);
		
	}
		
}

Celula *deletar_lista(Celula *lista){
	
	Celula *temporaria;
	
	while (lista != NULL){ 
		
		temporaria = lista;
        lista = lista->prox;
        free(temporaria);
		
	}
	
	return lista;
	
}
