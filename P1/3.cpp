#include <iostream>
using namespace std;

struct processo {
    int cod;
    struct processo* prox;
};

typedef struct processo* processoPtr;
processoPtr topo = NULL, ultimo = NULL;

int menu();
void incluirProcesso();
void retirarProcesso();
bool isSemProcesso();
void listar();

main(){
    
    int op;
do{    
    op = menu();
    switch(op){
        case 1: incluirProcesso();
        break;
        case 2: retirarProcesso();
        break;
        case 3: listar();
        break;
    }
} while(op != 0);


}


void incluirProcesso(){
    processoPtr p = new processo;

    cout << "\nDigite o codigo do processo a ser inserido: ";
    cin >> p->cod;
    p->prox = NULL;    

    if(isSemProcesso()){
        topo = p;
        ultimo = p;
    } else {
        ultimo->prox = p;
        ultimo = p;
    }

    listar();
}

void retirarProcesso(){
    processoPtr p;
    if(isSemProcesso()){
        cout << "\nNenhum processo em execucao!";
    } else {
        p = topo;
        topo = p->prox;
        cout << "\nO processo de codigo " << p->cod << " foi retirado." << endl;
        delete p;
    }
}


void listar(){
    processoPtr p;
    p = topo;
    int contador = 0;

    while(p != NULL) {
        cout << "Codigo do processo " << contador + 1 <<": " << p->cod << endl;
        p = p->prox;
        contador++;
        
    }

    if(!isSemProcesso()){
        cout << "Processos aguardando para serem executados..." << endl;
        cout << "Quantidade de processos: " << contador << endl;
    }
}

int menu() {
 int op;   
 cout << "\nEscolha o numero da operacao: 1 - Incluir processo; 2 - Retirar processo; 0 - Sair" << endl;
 cin >> op;

 if(op > 2){
     cout << "Opcao invalida" << endl;
     
 }
 return op;
}

bool isSemProcesso(){
    return (topo == NULL);
}