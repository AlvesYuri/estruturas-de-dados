#include <iostream>
using namespace std;

void intercalar(int vetor[], int inicio, int fim, int meio) {
    int aux[6], 
    posLivre = inicio, 
    left = inicio, 
    right = meio + 1;

    while(left <= meio && right <= fim) {
        if (vetor[left] > vetor[right]) {
            aux[posLivre] = vetor[right];
            right++;
        } else {
            aux[posLivre] = vetor[left];
            left++;
        }
        posLivre++;
    } for (int i = left; i <= meio; i++){
        aux[posLivre] = vetor[i];
        posLivre++;
    } for (int i = right; i <= fim; i++){
        aux[posLivre] = vetor[i];
        posLivre++;
    } for (int i = inicio; i <= fim; i++){
        vetor[i] = aux[i];
    }

}


void mergeSort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        intercalar(vetor, inicio, fim, meio);
    }

}


main(){

    int vetor[6] = {3, 5, 4, 1, 6, 2};
    int n = 6;

    cout << "VETOR DESORDENADO:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << vetor[i];
    }
    cout << "\n";

    mergeSort(vetor, 0, n);
    cout << "MERGE SORT:";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }



}