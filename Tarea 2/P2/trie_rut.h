#ifndef TRIE_RUT_H  // Guarda para evitar incluir el archivo dos veces
#define TRIE_RUT_H 

#include <iostream>
#include <cstring>
#include <vector>

#define ALPHABET_SIZE 10  // Cambiamos el tamaño del alfabeto para almacenar dígitos (0-9)

using namespace std;

// Enumeración para indicar si el RUT es deudor o no
enum class DeudorStatus { NO_DEUDOR, DEUDOR };

// Definición de un nodo en el trie
struct TrieNode {
    char* rut;  // Almacena el RUT completo si es un nodo final
    string nombre;  // Nombre del usuario asociado al RUT
    string direccion;  // Dirección del usuario
    string fecha_nacimiento;  // Fecha de nacimiento del usuario
    DeudorStatus deudor_status;  // Estado de deudor del usuario
    TrieNode* hijos[ALPHABET_SIZE];  // Punteros a los hijos (cada uno corresponde a un dígito del RUT)

    // Constructor del nodo: inicializa los hijos a nullptr y el RUT a nullptr
    TrieNode();
    ~TrieNode();
};

// Definición de la clase Trie
class Trie {
public:
    Trie();  // Constructor del trie
    ~Trie();  // Destructor del trie

    // Agrega un RUT al trie y lo marca como no deudor
    void numero_no_deudor(const char* rut, const string& nombre, const string& direccion, const string& fecha_nacimiento);
    // Busca y elimina un RUT del trie
    void borrar_RUT(const char* rut);
    // Buscar información del RUT
    string buscar_RUT(const char* rut);

private:
    TrieNode* raiz;  // Nodo raíz del trie
    void borrar_nodo(TrieNode* nodo);  // Borra un nodo y todos sus descendientes
};

#endif // TRIE_RUT_H