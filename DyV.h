#ifndef DYV_H
#define DYH_H

#include <vector>

template<typename T>

int busquedaBinaria(T X, const std::vector<T>& V, int ini, int fin){
    if (ini > fin)
    {
        std::cout << "No se encuentra en el array" << endl;
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (V[medio] == X){
        return medio;

    }else if (V[medio] > X){
        return busquedaBinaria(X, V, ini, medio - 1);

    }else{
        return busquedaBinaria(X, V, medio + 1, fin);
    }
}


template<typename T>

int Particion(std::vector<T>& V, int ini, int fin){
    T x = V[fin];
    int i = ini;

    for (int j = ini; j < fin; j++){
        if (V[j] <= x){
            T aux = V[i];
            V[i] = V[j];
            V[j] = aux;

            i = i + 1;
        }
    }

    T aux = V[i];
    V[i] = V[fin];
    V[fin] = aux;

    return i;
}

template<typename T>

void quicksort(std::vector<T>& V, int ini, int fin){
    if (ini < fin){
        int pivot = Particion(V, ini, fin);

        quicksort(V, ini, pivot - 1);
        quicksort(V, pivot + 1, fin);
    }
}

#endif
