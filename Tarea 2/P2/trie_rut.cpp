#include "trie_rut.h"

// Constructor del nodo: inicializa los hijos y el estado de deudor
TrieNode::TrieNode() {
    rut = nullptr;
    deudor_status = DeudorStatus::NO_DEUDOR;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        hijos[i] = nullptr;
    }
}

// Destructor del nodo: libera la memoria ocupada por el RUT y los hijos
TrieNode::~TrieNode() {
    if (rut) {
        delete[] rut;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (hijos[i]) {
            delete hijos[i];
        }
    }
}

// Constructor del trie: crea un nodo raíz vacío
Trie::Trie() {
    raiz = new TrieNode();
}

// Destructor del trie: libera todos los nodos del trie
Trie::~Trie() {
    borrar_nodo(raiz);
}

// Función para borrar un nodo y todos sus descendientes
void Trie::borrar_nodo(TrieNode* nodo) {
    if (!nodo) return;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (nodo->hijos[i]) {
            borrar_nodo(nodo->hijos[i]);
        }
    }
    if (nodo->rut) {
        delete[] nodo->rut;
    }
    delete nodo;
}

// numero_no_deudor_begin
// Agrega un RUT al trie y lo marca como no deudor
void Trie::numero_no_deudor(const char* rut, const string& nombre, const string& direccion, const string& fecha_nacimiento) {
    TrieNode* nodo_actual = raiz;
    int idx;

    // Navegamos por el trie creando nodos según sea necesario
    for (size_t i = 0; i < strlen(rut); ++i) {
        idx = rut[i] - '0';  // Obtenemos el índice basado en el dígito actual (0-9)
        if (nodo_actual->hijos[idx] == nullptr) {
            nodo_actual->hijos[idx] = new TrieNode(); // Creamos un nuevo nodo si no existe
        }
        nodo_actual = nodo_actual->hijos[idx]; // Avanzamos al siguiente nodo
    }

    // Al llegar al nodo final, almacenamos la información del RUT
    if (nodo_actual->rut) {
        delete[] nodo_actual->rut;
    }
    nodo_actual->rut = new char[strlen(rut) + 1]; // Almacenamos el RUT
    strcpy(nodo_actual->rut, rut); // Copiamos el RUT al nodo
    // Almacenamos el nombre, dirección y fecha de nacimiento
    nodo_actual->nombre = nombre;
    nodo_actual->direccion = direccion;
    nodo_actual->fecha_nacimiento = fecha_nacimiento;
    nodo_actual->deudor_status = DeudorStatus::NO_DEUDOR;  // Marcamos el RUT como no deudor
}
// numero_no_deudor_end


// borrar_RUT_begin
// Busca y elimina un RUT del trie
void Trie::borrar_RUT(const char* rut) {
    TrieNode* nodo_actual = raiz;
    int idx;

    // Navegamos por el trie buscando el RUT
    for (size_t i = 0; i < strlen(rut); ++i) {
        idx = rut[i] - '0';
        if (nodo_actual->hijos[idx] == nullptr) {
            cout << "RUT no encontrado." << endl;
            return;
        }
        nodo_actual = nodo_actual->hijos[idx];
    }

    // Si el nodo contiene el RUT, lo eliminamos
    if (nodo_actual->rut) {
        delete[] nodo_actual->rut; // Liberamos la memoria ocupada por el RUT
        // Limpiamos los campos de información
        nodo_actual->rut = nullptr;
        nodo_actual->nombre.clear();
        nodo_actual->direccion.clear();
        nodo_actual->fecha_nacimiento.clear();
        nodo_actual->deudor_status = DeudorStatus::NO_DEUDOR; // Marcamos el RUT como no deudor
        cout << "RUT eliminado." << endl;
    } else {
        cout << "RUT no encontrado." << endl;
    }
}
// borrar_RUT_end

// buscar_RUT_begin
// Busca la información del RUT en el trie
string Trie::buscar_RUT(const char* rut) {
    TrieNode* nodo_actual = raiz;
    int idx;

    // Navegamos por el trie buscando el RUT
    for (size_t i = 0; i < strlen(rut); ++i) {
        idx = rut[i] - '0'; // Índice basado en el dígito actual
        if (nodo_actual->hijos[idx] == nullptr) {
            return "RUT no encontrado"; // Si no existe el nodo, devolvemos un mensaje
        }
        nodo_actual = nodo_actual->hijos[idx]; // Avanzamos al siguiente nodo
    }

    // Si el nodo contiene la información del RUT, devolvemos la información
    if (nodo_actual->rut) {
        string resultado = "Nombre: " + nodo_actual->nombre + "\n";
        resultado += "Direccion: " + nodo_actual->direccion + "\n";
        resultado += "Fecha de Nacimiento: " + nodo_actual->fecha_nacimiento + "\n";
        resultado += "Deudor: " + string(nodo_actual->deudor_status == DeudorStatus::DEUDOR ? "Sí" : "No");
        return resultado;
    } else {
        return "RUT no encontrado";
    }
}
// buscar_RUT_end