#include "trie_rut.h"

int main() {
    Trie trie;
    string linea;

    // Agregar RUTs al trie y marcarlos como no deudores
    trie.numero_no_deudor("12345678", "John Lennon", "Hey Jude 68", "18/08/1969");
    trie.numero_no_deudor("17657401", "Elizabeth Woolridge Grant", "The Greatest A&W 2023", "21/07/1985");
    trie.numero_no_deudor("21284954", "Thom Yorke", "Karma Police 123", "07/10/1968");

    // Buscar RUTs en el trie
    cout << trie.buscar_RUT("12345678") << endl; // Imprime info de John Lennon
    cout << trie.buscar_RUT("17657401") << endl; // Imprime info de Elizabeth Woolridge Grant (Lanita del Rey)
    cout << trie.buscar_RUT("21284954") << endl; // Imprime info del mejor cantautor de la historia (Thom Yorke)
    cout << trie.buscar_RUT("101010101") << endl; // Imprime "RUT no encontrado" (no existe en la base de datos)

    // Eliminar un RUT del trie
    trie.borrar_RUT("12345678"); // Borro a John Lennon de la base de datos
    cout << trie.buscar_RUT("12345678") << endl; // Imprime "RUT no encontrado"

    return 0;
}

// Compilar con: g++ main.cpp trie_rut.cpp -o trie_rut_program 
// -> trie_rut_program.exe
// Ejecutar en terminal: ./trie_rut_program 