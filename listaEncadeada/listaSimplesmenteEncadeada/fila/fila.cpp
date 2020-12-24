#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};
typedef struct no* noPtr;

noPtr topo = NULL, ultimo = NULL;

int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - enfileirar; 2 - desenfileirar; 3 - Listar; 0 - Sair" << endl;
 cin >> op;

 if(op > 3){
     cout << "Opcao invalida" << endl;
     
 }

 return op;
}

bool isListaVazia(){
    return (topo == NULL);
}

void enfileirar(){    
    noPtr aux, p = new no;

    cout << "\nDigite o valor do elemento: ";
    cin >> p->info; 
    p->prox = NULL;    

    if(isListaVazia()){
        topo = p;
    } else {
        aux = topo;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
            aux->prox = p;
    }
}

void enfileirarComDoisPonteiros(){
    noPtr p = new no;

    cout << "\nDigite o valor do elemento: ";
    cin >> p->info;
    p->prox = NULL;    

    if(isListaVazia()){
        topo = p;
        ultimo = p;
    } else {
        ultimo->prox = p;
        ultimo = p;
    }
}


void listar(){
    noPtr p;
    p = topo;
    int contador = 0;

    while(p != NULL) {
        cout << "info: " << p->info << endl;
        p = p->prox;
        contador++;
        
    }

    cout << "tamanho da fila: " << contador << endl;
}

void desenfileirar(){
    noPtr p;
    if(isListaVazia()){
        cout << "\nFila Vazia!";
    } else {
        p = topo;
        topo = p->prox;
        cout << "\nO elemento " << p->info << " foi retirado da fila." << endl;
        delete p;
    }
}

main(){
    int op;
do{    
    op = menu();
    switch(op){
        case 1: enfileirarComDoisPonteiros();
        break;
        case 2: desenfileirar();
        break;
        case 3: listar();
        break;
    }
} while(op != 0);

}