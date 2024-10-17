#include "trie_dic.h"

int main() {

    Trie trie;
    string linea;

    // Prueba 1: Agregar palabras al trie
    trie.agregar_palabra("like", "gustar");
    trie.agregar_palabra("like", "amar");
    trie.agregar_palabra("apple", "manzana");
    trie.agregar_palabra("banana", "platano");

    // Buscar palabras en el trie
    cout << trie.buscar_palabra("like") << endl;  // Debe imprimir las traducciones en orden lexicográfico
    cout << trie.buscar_palabra("apple") << endl;  // Debe imprimir "manzana"
    cout << trie.buscar_palabra("banana") << endl;  // Debe imprimir "platano"

    // Buscar palabra no existente
    cout << trie.buscar_palabra("orange") << endl;  // Debe imprimir "None"
    cout << "---- Fin de la Prueba 1 ----\n" << endl;

    // Prueba 2: Ingresar palabras y traducciones manualmente por consola
    cout << "Ingrese palabras y traducciones (palabra traduccion), linea por linea. Ingrese una linea vacia para finalizar:" << endl;
    while (true) {
        getline(cin, linea);
        if (linea.empty()) {
            break;
        }

        size_t espacio = linea.find(' ');
        if (espacio == string::npos) {
            cout << "Formato incorrecto. Debe ingresar una palabra y al menos una traduccion." << endl;
            continue;
        }

        string palabra = linea.substr(0, espacio);
        string traduccion = linea.substr(espacio + 1);

        trie.agregar_palabra(palabra.c_str(), traduccion.c_str());
    }

    cout << "\nIngrese palabras para buscar sus traducciones. Ingrese una linea vacia para finalizar:" << endl;
    while (true) {
        getline(cin, linea);
        if (linea.empty()) {
            break;
        }

        cout << trie.buscar_palabra(linea.c_str()) << endl;
    }

    return 0;
}

// Compilar con: g++ main.cpp trie_dic.cpp -o trie_dic_program -> trie_dic_program.exe
// Ejecutar en terminal: ./trie_dic_program