#include <iostream>
using namespace std;

struct no{
  int info;
  int alt;
  struct no * esq, * dir;
};
typedef struct no * noPtr;

noPtr * raiz;

int menu();
int inserir(noPtr *, int);
int remover(noPtr *, int);
int alturaNo(noPtr);
int calcularFatorBalanceamento(noPtr);
void rotacaoSE(noPtr *);
void rotacaoSD(noPtr *);
void rotacaoDE();
void rotacaoDD(noPtr *);
void listarEmOrdem(noPtr);
int menor(int, int);
noPtr procuraMenor(noPtr);
bool enderecoVazio(noPtr);

int main(){
  int op, x;
  bool achei;
  noPtr raiz = NULL;

  do{
    op = menu();
    switch(op){
      case 1: cout << "\nElemento a inserir: ";
        cin >> x;
        inserir(&raiz, x);
        break;
      case 2: cout << "\nElemento para remover: ";
        cin >> x;
        remover(&raiz, x);
        break;
      case 3: listarEmOrdem(raiz);
        break; 
    }

  } while(op != 0);
}

int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - Inserir; 2 - Remover; 3 - Listar em Ordem; 0 - Sair" << endl;
 cin >> op;

 if(op > 3){
     cout << "Opcao invalida" << endl;
     
 }

 return op;
}


// Complexidade: O(1)
void listarEmOrdem(noPtr p){
  if (!enderecoVazio(p)){
    listarEmOrdem(p->esq);
    cout << "\t" << p->info;
    listarEmOrdem(p->dir);
  }
}


// Complexidade: O(1)
bool enderecoVazio(noPtr p){
  return (p == NULL);
}


// Complexidade: O(1)
int alturaNo(noPtr no){
  if(no == NULL){
    return -1;
  } else{
    return no->alt;
  }
}


// Complexidade: O(1)
int calcularFatorBalanceamento(noPtr no){
  return (alturaNo(no->esq) - alturaNo(no->dir));
}

// Complexidade: O(1)
void rotacaoSD(noPtr * raiz){
  noPtr no;
  no = (*raiz)->esq;
  (*raiz)->esq = no->dir;
  no->dir = *raiz;
  (*raiz)->alt = menor(alturaNo((*raiz)->esq), alturaNo((*raiz)->dir)) + 1;
  
  no->alt = menor(alturaNo(no->esq), (*raiz)->alt) + 1;
  
  *raiz = no;
}

// Complexidade: O(1)
void rotacaoSE(noPtr * raiz){
  noPtr no;
  no = (*raiz)->dir;
  (*raiz)->dir = no->esq;
  no->esq = (*raiz);
  (*raiz)->alt = menor(alturaNo((*raiz)->esq), alturaNo((*raiz)->dir)) + 1;

  no->alt = menor(alturaNo(no->dir), (*raiz)->alt) + 1;

  (*raiz) = no;
}

// Complexidade: O(1)
void rotacaoDD(noPtr * raiz){
  rotacaoSD(&(*raiz)->esq);
  rotacaoSE(raiz);
}

// Complexidade: O(1)
void rotacaoDE(noPtr * raiz){
  rotacaoSD(&(*raiz)->dir);
  rotacaoSE(raiz);
}

// Complexidade: O(log n)
int inserir(noPtr * raiz, int valor){
  int x;

  if(*raiz == NULL){
    noPtr novo = new no;
    if(novo == NULL)
      return 0;

    novo->info = valor;
    novo->alt = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
    }

    noPtr atual = *raiz;
    if(valor < atual->info){
      if((x = inserir(&(atual->esq), valor)) == 1){
        if(calcularFatorBalanceamento(atual) >= 2){
          if(valor < (*raiz)->esq->info){
            rotacaoSD(raiz);
          } else {
            rotacaoDD(raiz);
          }
        }
        
      }
    } else {
      if(valor > atual->info){
        if((x = inserir(&(atual->dir), valor)) == 1){
          if(calcularFatorBalanceamento(atual) >= 2){
            if((*raiz)->dir->info < valor) {
              rotacaoSE(raiz);
            } else{
              rotacaoDE(raiz);
            }
          }
        }
      } else {
        return 0;
      }
    }
    
    atual->alt = menor(alturaNo(atual->esq), alturaNo(atual->dir)) +1;

    return x;
}

// Complexidade: O(log n)
int remover(noPtr * raiz, int valor){
  if(*raiz == NULL){
    return 0;
  }

  int x;
  if(valor < (*raiz)->info){
    if((x = remover(&(*raiz)->esq, valor))==1){
      if(calcularFatorBalanceamento(*raiz) >= 2){
        if(alturaNo((*raiz)->dir->esq) <= alturaNo((*raiz)->dir->dir))
          rotacaoSE(raiz);
        else
          rotacaoDE(raiz);
      }
    }
  }

  if((*raiz)->info < valor){
    if((x = remover(&(*raiz)->dir, valor)) == 1){
      if(calcularFatorBalanceamento(*raiz) >= 2){
        if(alturaNo((*raiz)->esq->dir) <= alturaNo((*raiz)->esq->esq))
          rotacaoSD(raiz);
        else
          rotacaoDD(raiz); 
      }
    }
  }



  if((*raiz)->info == valor){
    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
      noPtr noVelho = (*raiz);
      if((*raiz)->esq != NULL)
        *raiz = (*raiz)->esq;
      else
        *raiz = (*raiz)->dir;      
    } else {
      noPtr temp = procuraMenor((*raiz)->dir);
      (*raiz)->info = temp->info;
      remover(&(*raiz)->dir, (*raiz)->info);
      
      if(calcularFatorBalanceamento(*raiz) >= 2){
        if(alturaNo((*raiz)->esq->dir) <= alturaNo((*raiz)->esq->esq))
          rotacaoSD(raiz);
        else
          rotacaoDD(raiz);
      }
    }
    if (*raiz != NULL)
      (*raiz)->alt = menor(alturaNo((*raiz)->esq), alturaNo((*raiz)->dir)) +1;

    return 1;
  }

  (*raiz)->alt = menor(alturaNo((*raiz)->esq), alturaNo((*raiz)->dir)) +1;

  return x;
}

//Complexidade: O(n)
noPtr procuraMenor(noPtr atual){
  noPtr no1 = atual;
  noPtr no2 = atual->dir;

  while(no2 != NULL){
    no1 = no2;
    no2 = no2->dir;
  }

  return no1;
}


// Complexidade: O(1)
int menor(int x, int y){
  if(x < y){
    return x;
  } else{
    return y;
  } 
} 
