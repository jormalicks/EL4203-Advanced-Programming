#include "trie_rut.h"

int main() {
    Trie trie;
    string linea;

    // Agregar RUTs al trie y marcarlos como no deudores
    trie.numero_no_deudor("12345678", "Juan Perez", "Calle Falsa 123", "01/01/1980");
    trie.numero_no_deudor("87654321", "Maria Gomez", "Avenida Siempre Viva 456", "15/05/1975");

    // Buscar RUTs en el trie
    cout << trie.buscar_RUT("12345678") << endl; //
    cout << trie.buscar_RUT("87654321") << endl;
    cout << trie.buscar_RUT("11111111") << endl;

    // Eliminar un RUT del trie
    trie.borrar_RUT("12345678");
    cout << trie.buscar_RUT("12345678") << endl;

    return 0;
}

// Compilar con: g++ main.cpp trie_rut.cpp -o trie_rut_program -> trie_rut_program.exe
// Ejecutar en terminal: ./trie_rut_program 