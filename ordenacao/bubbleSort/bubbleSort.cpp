#include <iostream>
using namespace std;

void bubbleSortCrescente(int vetor[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void bubbleSortDecrescente(int vetor[], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[i] < vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

main()
{
    int vetor[6] = {3, 5, 4, 1, 6, 2};
    int n = 6;

    cout << "VETOR DESORDENADO:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << vetor[i];
    }
    cout << "\n";

    bubbleSortCrescente(vetor, n);
    cout << "BUBBLE SORT CRESCENTE:";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }
    cout << "\n";

    bubbleSortDecrescente(vetor, n);
    cout << "BUBBLE SORT DECRESCENTE:";

    for (int i = 0; i < n; ++i)
    {
        cout << " " << vetor[i];
    }
}