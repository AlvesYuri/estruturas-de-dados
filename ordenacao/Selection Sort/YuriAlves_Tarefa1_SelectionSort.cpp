#include <iostream>

using namespace std;

void selectionSortCrescente(int vetor[], int n) {
    n = 6;
    int aux;

    for (int i = 0; i < n; ++i) {

        int m = i;

        for (int j = i + 1; j < n; ++j) {
            if (vetor[j] < vetor[m]) {
                m = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[m];
        vetor[m] = aux;
    }
}

void selectionSortDecrescente(int vetor[], int n) {
    n = 6;
    int aux;

    for (int i = 0; i < n; ++i) {

        int m = i;

        for (int j = i + 1; j < n; ++j) {
            if (vetor[j] > vetor[m]) {
                m = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[m];
        vetor[m] = aux;
    }
}


main() {
   int vetor[6] = {3, 5, 4, 1, 6, 2};
    int n = 6;

    cout << "VETOR DESORDENADO:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << vetor[i];
    }
    cout << "\n";

    selectionSortCrescente(vetor, n);
    cout << "SELECTION SORT CRESCENTE:";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }
    cout << "\n";

    selectionSortDecrescente(vetor, n);
    cout << "SELECTION SORT DECRESCENTE:";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }
}