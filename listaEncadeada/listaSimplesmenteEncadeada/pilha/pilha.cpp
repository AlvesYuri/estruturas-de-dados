#include <iostream>
using namespace std;

struct no{
    int info;
    struct no* prox;
};

typedef struct no* noPtr;
noPtr topo = NULL;



int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - Empilhar; 2 - Desempilhar; 3 - Listar; 0 - Sair" << endl;
 cin >> op;

 if(op > 3){
     cout << "Opcao invalida" << endl;
     
 }

 return op;
}

bool isListaVazia(){
    return (topo == NULL);
}

void empilhar(){
    noPtr p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p -> info;
    p -> prox = topo;
    topo = p;    
}

void desempilhar(){
    noPtr p = topo;
    if (!isListaVazia()){
        topo = topo -> prox;
        cout << "\nO elemento " << p->info << " foi retirado da pilha." << endl;
        delete(p);        

    } else{
        cout << "\nPilha vazia!" << endl;
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

    cout << "tamanho da pilha: " << contador << endl;
    }

main(){
    int op;
do{    
    op = menu();
    switch(op){
        case 1: empilhar();
        break;
        case 2: desempilhar();
        break;
        case 3: listar();
        break;
    }
} while(op != 0);

}