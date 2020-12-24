#include <iostream>

using namespace std;

void insertionSort(int vetor[], int n) {
    n = 6;

    for (int i = 1; i < n; i++) {

        int aux = vetor[i];
        int j = i-1;

            while (j >= 0 && aux < vetor[j]) {
                vetor[j+1] = vetor[j];
                j--;
            }
            vetor[j+1] = aux;
        }

    }





int main() {
    int vetor[6] = {22, 78, 49, 13, 55, 67};
    int n = 6;

    cout << "ANTES DO INSERTION SORT:";
    for (int i = 0; i < n; i++) {
        cout << " " << vetor[i];
    }
    cout << "\n";

    insertionSort(vetor, n);
    cout << "DEPOIS DO INSERTION SORT:";


    for (int i = 0; i < n; ++i) {
        cout << " " << vetor[i];
    }

    return 0;
}