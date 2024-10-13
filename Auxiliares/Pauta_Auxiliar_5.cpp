#include <iostream>
#include <clocale>


struct Nodo {
    int valor;
    Nodo* siguiente;
};


class ListaEnlazada {
private:
    // Atributos de la clase
    Nodo* cabeza;

public:
    // Constructores
    ListaEnlazada() {
        cabeza = nullptr;
    }

    ListaEnlazada(int valor) {
        cabeza = new Nodo{ valor, nullptr };
    }

    // Destructor
    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        Nodo* siguiente;

        while (actual != nullptr) {
            siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    // Métodos
    void insertarCabeza(int valor) {
        Nodo* nuevaCabeza = new Nodo{ valor, cabeza };
        cabeza = nuevaCabeza;
    }

    void insertarCola(int valor) {
        if (cabeza == nullptr) {
            insertarCabeza(valor);
        } else {
            Nodo* cola = new Nodo{ valor, nullptr };
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }

            temp->siguiente = cola;
        }
    }

    void eliminarNodo(int valor) {
        // Se chequea si la cabeza tiene información,
        // o si el valor a eliminar está en la cabeza
        if (cabeza == nullptr) {
            return;
        } else if (cabeza->valor == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Nodo* actual = cabeza->siguiente;
        Nodo* anterior = cabeza;
        bool eliminado = false;
        while(!eliminado) {
            // Primero verifica si el nodo tiene información
            if (actual == nullptr) {
                return;
            }

            // Si el nodo tiene información, chequea si es un nodo
            // distinto al que queremos eliminar
            if (actual->valor != valor) {
                anterior = actual;
                actual = actual->siguiente;
                continue;
            }

            // Si es el nodo a eliminar, mueve los punteros
            // y libera la memoria
            anterior->siguiente = actual->siguiente;
            delete actual;
            return;
        }

    }
    
    void print() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "■" << std::endl;
    }
};


int main() {
    // Cambia el encoding a UTF8 para realizar print de
    // caracteres Unicode en Windows sin problemas
    setlocale(LC_ALL, ".UTF8");

    ListaEnlazada lista;
    lista.print();
    lista.insertarCola(5);
    lista.print();
    lista.insertarCola(17);
    lista.print();
    lista.insertarCabeza(42);
    lista.print();
    lista.insertarCola(-7);
    lista.print();
    lista.eliminarNodo(17);
    lista.print();

    return 0;
}