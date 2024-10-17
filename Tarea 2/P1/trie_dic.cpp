#include "trie_dic.h"

// Constructor del nodo: inicializo la palabra y reservo espacio para las traducciones en el vector hijos
TrieNode::TrieNode() {
    palabra = nullptr;
    traducciones.reserve(MAX_TRANSLATIONS); // Reservar espacio para las traducciones
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        hijos[i] = nullptr; // Inicializar punteros a los hijos en nullptr (nulo)
    }
}

// Destructor del nodo: libero la memoria de la palabra y las traducciones, y llamo al destructor de los hijos
TrieNode::~TrieNode() {
    if (palabra) {
        delete[] palabra;  // Si la palabra no es nullptr, liberar la memoria
    }
    for (auto& trad : traducciones) {
        delete[] trad; // Recorrer las traducciones y liberar la memoria
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (hijos[i]) {
            delete hijos[i]; // Recorrer todos los hijos del nodo y libera la memoria si no son nullptr
        }
    }
}

// Constructor del trie: inicialzo la raíz del trie
Trie::Trie() {
    raiz = new TrieNode();
}

// Destructor del trie: destruyo la raíz del trie
Trie::~Trie() {
    delete raiz;
}


// borrar_nodo: Borrar nodo y todos sus hijos
void Trie::borrar_nodo(TrieNode* nodo) {
    if (!nodo) return; // Si el nodo es nullptr, no hacer nada
    for (int i = 0; i < ALPHABET_SIZE; ++i) { 
        if (nodo->hijos[i]) {
            borrar_nodo(nodo->hijos[i]); // Recorrer los hijos del nodo recursivamente
        }
    }
    if (nodo->palabra) {
        delete[] nodo->palabra; // Liberar la memoria de la palabra si no es nullptr
    }
    for (auto& trad : nodo->traducciones) {
        delete[] trad; // Recorrer las traducciones (como en el desctructor de TrieNode) y liberar la memoria
    }
    delete nodo;
}

// cmp_strings: Comparador de strings para ordenar lexicográficamente después con qsort
// strcmp compara dos cadenas de carácteres (char*) y retorna un entero mayor, menor o igual a 0
int Trie::cmp_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// ordenar_traducciones: Ordenar traducciones lexicográficamente
void Trie::ordenar_traducciones(vector<char*>& traducciones) {
    qsort(&traducciones[0], traducciones.size(), sizeof(char*), cmp_strings);
}

// agregar_palabra: Agregar palabra y su traducción al trie
void Trie::agregar_palabra(const char* palabra, const char* traduccion) {
    TrieNode* nodo_actual = raiz; 
    int idx;
    // Navego por el trie creando nodos según sea necesario
    for (size_t i = 0; i < strlen(palabra); ++i) {
        idx = palabra[i] - 'a'; // Obtener el índice de la letra en el alfabeto
        if (nodo_actual->hijos[idx] == nullptr) {
            nodo_actual->hijos[idx] = new TrieNode();
        }
        nodo_actual = nodo_actual->hijos[idx]; // Mover el puntero al hijo siguiente
    }
    // Si hay menos de MAX_TRANSLATIONS traducciones, se asigna memoria a una nueva traducción y se añade al vector traducciones
    if (nodo_actual->traducciones.size() < MAX_TRANSLATIONS) {
        char* nueva_traduccion = new char[strlen(traduccion) + 1]; // 
        strcpy(nueva_traduccion, traduccion); // Copiar la traducción a la nueva traducción
        nodo_actual->traducciones.push_back(nueva_traduccion); // Agregar la nueva traducción al vector de traducciones

        ordenar_traducciones(nodo_actual->traducciones); // Ordenar las traducciones lexicográficamente
    } else {
        cout << "Número máximo de traducciones alcanzado para la palabra" << endl;
    }
}

// buscar_palabra: Buscar palabra en el trie
string Trie::buscar_palabra(const char* palabra) {
    TrieNode* nodo_actual = raiz; // Comenzar en la raíz
    int idx;

    for (size_t i = 0; i < strlen(palabra); ++i) {
        idx = palabra[i] - 'a'; // Índice de la letra en el alfabeto (misma lógica que en agregar_palabra)
        if (nodo_actual->hijos[idx] == nullptr) {
            return "None"; // Si no hay un nodo hijo en la posición idx (no existe la palabra en el trie), retornar "None"
        }
        nodo_actual = nodo_actual->hijos[idx]; // Mover el puntero al hijo siguiente si existe
    }

    if (!nodo_actual->traducciones.empty()) { // Comparar si el nodo actual tiene traducciones
        string resultado; // resultado se utilizará para almacenar todas las traducciones concatenadas
        for (size_t i = 0; i < nodo_actual->traducciones.size(); ++i) {
            if (i > 0) {
                resultado += ","; // Si el nodo tiene traducciones, concatenar en cadena separadas por comas
            }
            resultado += nodo_actual->traducciones[i]; // Agregar la traducción al resultado
        }
        return resultado; // Retornar todas las traducciones
    } else {
        return "None";
    }

}