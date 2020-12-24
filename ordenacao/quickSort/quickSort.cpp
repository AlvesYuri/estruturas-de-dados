#include <iostream>
using namespace std;



// int particiona(int vetor[], int inicio, int fim){
//     int i, j, pivo;
//     if(fim - inicio < 2) {
//         if((fim - inicio) == 1) {
//             if (vetor[inicio] > vetor[fim]) {
//                 troca(vetor[inicio], vetor[fim]);
//             }
//         }
//     } else {
//         i = inicio;
//         j = fim;
//         pivo = vetor[inicio];
//         while(j > i) {
//             i++;
//             while(vetor[i] < pivo) {
//                 i++;
//             }
//          while (vetor[j] > pivo) {
//             j--;
//         } if (j > i) {
//             troca(vetor[i], vetor[j]);
//             } 
//         } 
//         troca(vetor[inicio], vetor[j]);        
        
//     }
//     return j;
// }

int partition(int vetor[], int inicio, int fim){
    int i = inicio;

    for(int j = inicio; j < fim; j++){
        if(vetor[j] <= vetor[fim]){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;            
        }
    }

    int aux = vetor[i];
    vetor[i] = vetor[fim];
    vetor[fim] = aux;

    return i;
}


void quickSort(int vetor[], int inicio, int fim){
    if(fim > inicio){
        int pivo = partition(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo - 1) ;
        quickSort(vetor, pivo + 1, fim);
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

    quickSort(vetor, 0, n);
    cout << "QUICK SORT:";
    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }

}