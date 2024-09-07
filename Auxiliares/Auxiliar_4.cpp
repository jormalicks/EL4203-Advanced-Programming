#include <iostream> // Incluimos la librería iostream

//std::cout << "Hola mundo desde C++" << "\n";

int main() {
    float arreglo[4] = { 1.0, 2.0, 3.0, 4.0 };
    float valorMaximo = arreglo[0]; // Inicializamos la variable valorMaximo con el primer elemento del arreglo
    for(int i = 0; i < 4; i++) {
        if(arreglo[i] > valorMaximo) {
            valorMaximo = arreglo[i];
        }
    }

    std::cout << "El valor máximo del arreglo es: " << valorMaximo << "\n";

    return 0; 

}