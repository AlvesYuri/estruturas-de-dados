#include <iostream>
using namespace std;

struct no {
    int info;
    struct no* prox;
    struct no* ant;
};

//implementar uma fila (O1)
//listagem do ultimo pro 1º nó


typedef struct no* noPtr;

int menuGeral();

void menuPilha(noPtr*);
void inserirPilha(noPtr*);
void retirarPilha(noPtr*);

void menuFila(noPtr*, noPtr*);
void inserirFila(noPtr*, noPtr*);
void retirarFila(noPtr*);

void listarPrimeiroAteUltimo(noPtr);
void listarUltimoAtePrimeiro(noPtr);
bool isListaVazia(noPtr);

main(){
    noPtr topo = NULL;
    noPtr ultimo = NULL;
    int menu;
    
    do{    
    menu = menuGeral();
    switch(menu){
        case 1: menuPilha(&topo);
        break;
        case 2: menuFila(&topo, &ultimo);
        break;        
    }
} while(menu != 0);   
}

int menuGeral(){
    int menu;
    cout << "\nEscolha o menu desejado: 1 - Menu Pilha; 2 - Menu Fila; 0 - SAIR" << endl;
    cin >> menu;

    if(menu > 2){
        cout << "opcao invalida" << endl;
    }
    return menu;
}


void menuPilha(noPtr * topo) {
    int op;   
   
    do{
    cout << "\nEscolha o numero da operacao: 1 - Inserir na Pilha; 2 - Retirar da Pilha; 3 - Listar do Primeiro ao Ultimo; 4 - Listar do Ultimo ao Primeiro; 0 - SAIR" << endl;
    cin >> op;

    if(op > 4){
        cout << "Opcao invalida" << endl;     
    }
        switch(op){
        case 1: inserirPilha(topo);
        break;
        case 2: retirarPilha(topo);
        break;
        case 3: listarPrimeiroAteUltimo(*topo);
        break;
        case 4: listarUltimoAtePrimeiro(*topo);
    }
} while(op != 0);
}

void inserirPilha(noPtr * topo){
    noPtr p = new no;

    cout <<"\nDigite o valor do elemento: ";
    cin >> p->info;

    p->ant = NULL;

    if (isListaVazia(*topo)){
        p->prox = NULL;
    } else {
        p->prox = *topo;
        (*topo)->ant = p;
    }
    *topo = p;
}


void retirarPilha(noPtr * topo){
    noPtr p = *topo;
    if (!isListaVazia(*topo)){
        if(p->prox == NULL){
            *topo = NULL;
        } else {
            *topo = p->prox;
            (*topo)->ant = NULL;
        }
        cout << "\nO elemento " << p->info << " foi retirado da pilha!\n";
        delete(p);
    } else {
        cout << "\n\nPilha está Vazia!\n";
    }
}


void menuFila(noPtr * topo, noPtr * ultimo) {
    int op;   

    do{
    cout << "\nEscolha o numero da operacao: 1 - Inserir na Fila; 2 - Retirar da Fila; 3 - Listar do Primeiro ao Ultimo; 4 - Listar do Ultimo ao Primeiro; 0 - SAIR" << endl;
    cin >> op;

    if(op > 4){
        cout << "Opcao invalida" << endl;     
    }
        switch(op){
        case 1: inserirFila(topo, ultimo);
        break;
        case 2: retirarFila(topo);
        break;
        case 3: listarPrimeiroAteUltimo(*topo);
        break;
        case 4: listarUltimoAtePrimeiro(*topo);
    }
} while(op != 0);
}

void inserirFila(noPtr * topo, noPtr * ultimo){
    noPtr p = new no;
    cout <<"\nDigite o valor do elemento: ";
    cin >> p->info;
    p->prox = NULL;

    if(isListaVazia(*topo)){
        
    }   

}

void retirarFila(noPtr * topo){

}


void listarPrimeiroAteUltimo(noPtr p){
    if(!isListaVazia(p)){
        cout << "\nElementos da lista: \n";
        cout << "TOPO";
        while(p != NULL){
            cout << " --> " << p->info;
            p = p->prox;
        }
        cout << " --> NULL";
    }
    else{
        cout <<"\n\nLista está Vazia!\n"; 
    }
}

void listarUltimoAtePrimeiro(noPtr p){
    if(!isListaVazia(p)){
        cout << "\nElementos da lista: \n";
        cout << "NULL";
        while(p != NULL){
            cout << " --> " << p->info;
            p = p->ant;
        }
        cout << " --> TOPO";
    }
    else{
        cout <<"\n\nLista está Vazia!\n"; 
    }
}


bool isListaVazia(noPtr topo){
    return (topo == NULL);
}

