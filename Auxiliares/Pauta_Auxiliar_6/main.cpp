#include <iostream>
#include <clocale>

#include "bst.h"

int main() {
    // Cambia el encoding a UTF8 para realizar print de
    // caracteres Unicode en Windows sin problemas
    setlocale(LC_ALL, ".UTF8");

    ArbolBusquedaBinaria bst;
    bst.insertar(61);
    bst.insertar(49);
    bst.insertar(74);
    bst.insertar(33);
    bst.insertar(57);
    bst.insertar(65);
    bst.insertar(82);

    std::cout << "¿Está el número 7 en el árbol?: ";
    std::cout << (bst.buscar(7)? "True" : "False") << "\n";
    bst.insertar(7);
    std::cout << "¿Está el número 7 en el árbol?: ";
    std::cout << (bst.buscar(7)? "True" : "False") << "\n";
    
    bst.insertar(41);
    bst.insertar(50);
    bst.insertar(60);
    bst.insertar(63);
    bst.insertar(71);
    bst.insertar(79);
    bst.insertar(98);
    bst.recorridoInOrden();

    std::cout << "¿Cuál es el ancestro más cercano entre 63 y 79? ";
    std::cout << bst.ancestroMasCercano(63, 79) << std::endl;

    bst.remover(82);
    bst.recorridoInOrden();

    return 0;
}
