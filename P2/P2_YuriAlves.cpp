#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;

int menu();
void incluir(noPtr*, noPtr*, int*);
void retirar(noPtr*, noPtr*, int*);
void listar(noPtr, int);
bool isListaVazia(int);



main(){
    noPtr topo = NULL;
    noPtr fim = NULL;
    int op, qtd = 0;
    do{    
        op = menu();
        switch(op){
            case 1: incluir(&topo, &fim, &qtd);
            cout << "\nA lista possui " << qtd << " no(s)." << endl;
            break;
            case 2: retirar(&topo, &fim, &qtd);
            break;
            case 3: listar(topo, qtd);
            break;
        }
    } while(op != 0);
}


int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - Incluir; 2 - Retirar; 3 - Listar; 0 - Sair" << endl;
 cin >> op;

 if(op > 3){
     cout << "Opcao invalida" << endl;
     
 }

 return op;
}

bool isListaVazia(int qtd){
    return (qtd == 0);
}

void listar(noPtr topo, int qtd){
    if(!isListaVazia(qtd)){
        for(int i = 0; i < qtd; i++){            
            
            if(i == 0){
                cout << topo->info <<" (" << topo << ")" << " -> ";
            } else if(i == (qtd - 1)) {
                cout << topo->info <<" (" << topo->prox << ")" << ".";
            } else {
                cout << topo->info << " -> ";
            }
            
            topo = topo->prox;
        }
    } else {
        cout <<"\n\nLista vazia!";
    }
}

void incluir(noPtr * topo, noPtr * fim, int * qtd){
    noPtr p = new no;
    cout << "\nDigite o valor do elemento: ";
    cin >> p->info;
    if(isListaVazia(*qtd)){
        *topo = p;
        p->prox = *topo;
        *fim = p;
    }else{
        p->prox = *topo;
        (*fim)->prox = p;
        *fim = p;
    }

    cout << "\nNo inserido no endereco: " << p << endl;
    *qtd = *qtd + 1;    
}

void retirar(noPtr * topo, noPtr * fim, int * qtd){
    noPtr ant, aux = *topo;
    int valor;
    bool achei = false;

    if(!isListaVazia(*qtd)){
        cout << "\nInforme o elemento a ser retirado: ";
        cin >> valor;        
        
        do{
            if(valor == aux->info){
                if(*qtd == 1){
                    *topo = NULL;
                    *fim = NULL; 
                }

                else if(aux->info == (*topo)->info){
                    *topo = aux->prox;
                    (*fim)->prox = aux->prox;                      
                }
                    
                else if(aux->info == (*fim)->info){                        
                    *fim = ant;
                    ant->prox = aux->prox;
                }else{                    
                    ant->prox = aux->prox;                        
                } 

                achei = true;
                break;                   
            } 
                
                ant = aux;
                aux = aux->prox;     

            } while (aux != *topo && achei == false);

            if(achei){            
                delete(aux);
                *qtd = *qtd - 1;
                
                if(*qtd == 0){
                    if(*topo == NULL)
                        cout << "Ponteiro principal apontando para NULL";
                } 
            } else {
                cout << "Elemento nao se encontra na lista circular";
            }         
        
    }else{
        cout << "\nLista circular se encontra vazia" << endl;        

    } 
               
}







