#include <iostream>

#include "bst.h"


// Definición de métodos usando el namespace de la clase
ArbolBusquedaBinaria::ArbolBusquedaBinaria() {
    raiz = nullptr;
}

ArbolBusquedaBinaria::~ArbolBusquedaBinaria() {
    dealloc(raiz);
}

void ArbolBusquedaBinaria::dealloc(Nodo* nodo) {
    if (nodo != nullptr) {
        dealloc(nodo->izq);
        dealloc(nodo->der);
        delete nodo;
    }
}

void ArbolBusquedaBinaria::insertar(int valor) {
    if (raiz == nullptr) {
        raiz = new Nodo{valor, nullptr, nullptr};
    } else {
        insertar(raiz, valor);
    }
}

void ArbolBusquedaBinaria::insertar(Nodo* nodo, int valor) {
    if (valor < nodo->valor) {
        if (nodo->izq == nullptr) {
            nodo->izq = new Nodo{valor, nullptr, nullptr};
        } else {
            insertar(nodo->izq, valor);
        }
    } else {
        if (nodo->der == nullptr) {
            nodo->der = new Nodo{valor, nullptr, nullptr};
        } else {
            insertar(nodo->der, valor);
        }
    }
}

bool ArbolBusquedaBinaria::buscar(int valor) {
    return buscar(raiz, valor);
}

bool ArbolBusquedaBinaria::buscar(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return false;
    }
    if (nodo->valor == valor) {
        return true;
    } else if (valor < nodo->valor) {
        return buscar(nodo->izq, valor);
    } else {
        return buscar(nodo->der, valor);
    }
}

void ArbolBusquedaBinaria::remover(int valor) {
    raiz = remover(raiz, valor);
}

Nodo* ArbolBusquedaBinaria::remover(Nodo* nodo, int valor) {
    if (nodo == nullptr) {
        return nodo;
    }
    if (valor < nodo->valor) {
        nodo->izq = remover(nodo->izq, valor);
    } else if (valor > nodo->valor) {
        nodo->der = remover(nodo->der, valor);
    } else {
        // Caso en que el nodo a eliminar tiene menos de 2 hijos
        if (nodo->izq == nullptr) {
            Nodo* temp = nodo->der;
            delete nodo;
            return temp;
        } else if (nodo->der == nullptr) {
            Nodo* temp = nodo->izq;
            delete nodo;
            return temp;
        }

        // Nodo a eliminar tiene 2 hijos. Se obtiene el valor más pequeño
        // del subarbol derecho con raiz valor
        int minValor = minimoValor(nodo->der);
        nodo->valor = minValor;
        nodo->der = remover(nodo->der, minValor);
    }
    return nodo;
}

int ArbolBusquedaBinaria::minimoValor(Nodo* nodo) {
    while (nodo->izq != nullptr) {
        nodo = nodo->izq;
    }
    return nodo->valor;
}

void ArbolBusquedaBinaria::recorridoInOrden() {
    recorridoInOrden(raiz);
    std::cout << std::endl;
}

void ArbolBusquedaBinaria::recorridoInOrden(Nodo* nodo) {
    if (nodo != nullptr) {
        recorridoInOrden(nodo->izq);
        std::cout << nodo->valor << " ";
        recorridoInOrden(nodo->der);
    }
}

// Si alguno de los valores no está se retorna -1
int ArbolBusquedaBinaria::ancestroMasCercano(int valor1, int valor2) {
    Nodo* actual = raiz;

    while (actual != nullptr) {
        // Si ambos valores son menores al nodo actual,
        // el ancestro en común debe estar a la izquierda
        if (valor1 < actual->valor && valor2 < actual->valor) {
            actual = actual->izq;
        } else if (valor1 > actual->valor && valor2 > actual->valor) {
            actual = actual->der;
        } else {
            return actual->valor;
        }
    }
    return -1;
}
