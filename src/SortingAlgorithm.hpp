#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v){

const unsigned int n = v.size();

for (size_t i = 0; i < n - 1; ++i) // ciclo per il numero di passaggi
    {
        for (size_t j = 0; j < n - i - 1; ++j) // lascio invariati gli elementi che già sono stati confrontati
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

template<typename T>
void heapify(std::vector<T>& v, size_t n, size_t i) // deve essere mantenuta la struttura di heap
{
    size_t largest = i;           // nodo più grande finora
    size_t left = 2 * i + 1;      // figlio sinistro
    size_t right = 2 * i + 2;     // figlio destro

    // Se il figlio sinistro è più grande del padre
    if (left < n && v[left] > v[largest])
        largest = left;

    // Se il figlio destro è più grande del più grande finora
    if (right < n && v[right] > v[largest])
        largest = right;

    // Se il più grande non è il padre
    if (largest != i)
    {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);  // Ricorsione sul sottoalbero
    }
}

template<typename T>
void HeapSort(std::vector<T>& v)
{
    size_t n = v.size();

    // Costruzione dell'heap max
    for (int i = n / 2 - 1; i >= 0; --i) // devo prendere i nodi con dei figli
        heapify(v, n, i);

    // Estrai uno a uno gli elementi dalla heap
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(v[0], v[i]);        // Sposta il massimo alla fine
        heapify(v, i, 0);             // Ricostruisci l'heap sul resto
    }
}

