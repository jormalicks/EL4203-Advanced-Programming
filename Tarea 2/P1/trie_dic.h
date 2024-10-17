#ifndef TRIE_DIC_H // Guardar para evitar incluir el archivo dos veces
#define TRIE_DIC_H 

#include <iostream>
#include <cstring>
#include <vector>

#define MAX_TRANSLATIONS 10 // Máximo de traducciones por palabra
#define ALPHABET_SIZE 26 // Tamaño del alfabeto

using namespace std;

// Defino un nodo del trie
struct TrieNode {
    char* palabra;  // Almacena la palabra (si es una palabra completa) en el nodo actual
    vector<char*> traducciones;  // Vector para almacenar traducciones
    TrieNode* hijos[ALPHABET_SIZE];  // Punteros a los hijos (26 letras del alfabeto)

    // Constructor del nodo
    TrieNode();
    ~TrieNode();
};

// Defino la clase Trie
class Trie {
public:
    // Constructor del trie
    Trie();
    // Destructor del trie
    ~Trie();
    // Agregar palabra y su traducción al trie
    void agregar_palabra(const char* palabra, const char* traduccion);
    // Buscar palabra en el trie y velvoler sus traducciones
    string buscar_palabra(const char* palabra);

private:
    TrieNode* raiz;  // Puntero a la raíz del trie
    static int cmp_strings(const void* a, const void* b); // Comparador de strings para qsort
    void ordenar_traducciones(vector<char*>& traducciones); // Ordenar traducciones lexicográficamente
    void borrar_nodo(TrieNode* nodo); // Borrar nodo y sus hijos

};

#endif // TRIE_DIC_H
