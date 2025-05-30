#include<stdbool.h>

typedef struct no{
      
      int dado;
      struct no *prox;
      
}Celula;

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

//Celula *deletar(int dado, Celula *lista){
//	
//	if (lista->dado==dado){
//		
//		Celula *p = lista->prox;
//		free(lista);
//		return p;
//		
//	}
//	
//	for (; lista->prox ;lista=lista->prox){
//		
//		if (lista->prox->dado==dado){
//			
//			if (lista->prox->prox){
//				
//				Celula *pR = lista->prox;
//				lista->prox = lista->prox->prox;
//				
//				free(pR);
//				
//				return lista;
//				
//			}
//			Celula *pR = lista->prox;
//			lista->prox = NULL;
//			free(pR);
//			return lista;	
//			
//		}
//		
//	}
//	
//}

//Celula *remover_pares(Celula *lista){
//	
//	Celula *p;
//	for (p=lista; p ;p=p->prox){
//				
//		if ((p->dado % 2) == 0){
//			
//			lista = deletar(p->dado,lista);
//		
//		}
//		
//	}
//	
//	return lista;
//	
//}

Celula *unir_listas(Celula *lista1, Celula *lista2){
		
	Celula *uniao;
	for (uniao = lista1;uniao->prox;uniao=uniao->prox);
	uniao->prox = lista2;
		
	return lista1;
		
}

Celula *ordenar(int tamanho,Celula *lista){
	
	int menor = lista->dado;
	int parar = 1;
	int contador = 0;
	
	Celula *p;
	Celula *p1 = NULL;
	
	while (parar == 1){
		
		for (p=lista->prox; p ; p=p->prox){
		
			if (menor>p->dado&&!contem(p->dado,p1)) menor = p->dado;
		
		}
		
		p1 = inserir(menor,p1);
		
		for (Celula *pAux=p1; pAux ; pAux=pAux->prox){
			
			contador++;
			
		}
		
		if (contador == tamanho) parar =0;
		
		if (parar == 1){
			
			for (p=lista->prox; p ;p=p->prox){
				
				if (!contem(p->dado,p1)){
					
					menor = p->dado;
					
				}
				
			}
			
		}
		
	}
	
	return p1;
		
}
