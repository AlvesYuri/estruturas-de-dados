#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
noPtr topo = NULL;

int menu();
bool isListaVazia();
void inserir();
void retirar();
int length();
void crescente();
void decrescente();

main(){
    int op;
    do{    
        op = menu();
        switch(op){
            case 1: inserir();
            break;
            case 2: retirar();
            break;
            case 3: crescente();
            break;
            case 4: decrescente();
            break;
        }
    } while(op != 0);

}




int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - Inserir; 2 - Retirar; 3 - Listar de forma crescente; 4- Listar de forma decrescente; 0 - Sair" << endl;
 cin >> op;

 if(op > 4){
     cout << "Opcao invalida" << endl;
     
 }

 return op;
}

bool isListaVazia(){
    return (topo == NULL);
}

void inserir(){
    noPtr aux, ant, p = new no;
    
    cout << "Digite o valor do elemento: ";
    cin >> p -> info;
    
    if(isListaVazia()){
        p->prox = topo;
        topo = p;
    } else {
        aux = topo;
        while(aux != NULL && p->info > aux->info){
            ant = aux;
            aux = aux->prox;
        }
        if (aux == topo){
            p->prox = aux;
            topo = p;
        }else {
            p->prox = aux;
            ant->prox = p;
        }
    }    
    
    cout << "Elemento inserido no endereco de memoria: " << p;    
}

void retirar(){
    noPtr ant, aux = topo;
    int valor;
    bool achei = false;

    if(!isListaVazia()){
        cout << "Escolha um elemento para ser retirado: ";
        cin >> valor;
        if(valor == aux->info){
            topo = aux->prox;
            delete(aux);  
        } else{
            while(aux != NULL){
                ant = aux;
                aux = aux -> prox; 
                if(valor == aux->info){
                    achei = true;
                    break;
                }                      
        }        
        
        if(achei){
            ant->prox = aux->prox;
            delete(aux);
        } else {
            cout << "Elemento nao se encontra na lista ordenada";
            }         
         }
    
    } else {
        cout << "\nLista ordenada se encontra vazia" << endl; 
    }    
}

int length(){
    noPtr aux = topo;
    int contador = 0;
    
        while(aux != NULL) {            
            aux = aux->prox;
            contador++;        
        } 
    return contador;  
}

void crescente(){
    noPtr aux = topo;    

    while(aux != NULL) {
        cout << "info: " << aux->info << endl;
        aux = aux->prox;
    }   

    cout << "tamanho da lista ordenada: " << length() << endl;
}


void decrescente(){
    noPtr aux = topo;
    int vetor[length()];

    for(int i = 0; i < length(); i++){
        vetor[i] = aux->info;
        aux = aux->prox;
    }

    for(int i = length() - 1; i >= 0; i--){
        cout << "info: " << vetor[i] << endl;
    }

    cout << "tamanho da lista ordenada: " << length() << endl;
}