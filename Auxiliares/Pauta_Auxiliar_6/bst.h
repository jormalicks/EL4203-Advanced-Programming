#pragma once

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
};

class ArbolBusquedaBinaria {
private:
    // El atributo raiz solo se puede manejar dentro de la clase
    Nodo* raiz;

    // Métodos auxiliares no accesibles por el usuario
    void dealloc(Nodo* nodo);
    void insertar(Nodo* nodo, int valor);
    bool buscar(Nodo* nodo, int valor);
    Nodo* remover(Nodo* nodo, int valor);
    void recorridoInOrden(Nodo* nodo);

public:
    // Constructor y destructor son públicos
    ArbolBusquedaBinaria();
    ~ArbolBusquedaBinaria();

    // Métodos que el usuario puede usar
    void insertar(int valor);
    bool buscar(int valor);
    void remover(int valor);
    int minimoValor(Nodo* nodo);
    void recorridoInOrden();
    int ancestroMasCercano(int valor1, int valor2);
};
