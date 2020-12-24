#include <iostream>
using namespace std;

void buscaBinaria(int vetor[], int num, int inicio, int fim);
void listarVetor(int vetor[], int n);

main(){

    int num, n = 20;
    int vetor[n] = {1, 5, 16, 20, 24, 25, 29, 30, 33, 36, 37, 40, 53, 57, 61, 63, 65, 67, 69, 74};    

    listarVetor(vetor, n);

    cout << "\n\nNumero a ser buscado: ";
    cin >> num;

    buscaBinaria(vetor, num, 0, n);
}




void buscaBinaria(int vetor[], int num, int inicio, int fim){
    int meio = (inicio + fim) / 2;

    if (inicio < fim){
        if (num == vetor[meio]){
            cout << "O numero " << num << " esta na posicao: " << meio + 1;
        }
        else{
            if (num < vetor[meio]){
                buscaBinaria(vetor, num, inicio, meio);
            }
            else{
                buscaBinaria(vetor, num, meio + 1, fim);
            }
        }
    }
    else{
        cout << "Numero nao encontrado na lista";
    }
}

void listarVetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        cout << vetor[i] << " ";
    }
}