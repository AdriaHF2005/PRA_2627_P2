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

#endif
