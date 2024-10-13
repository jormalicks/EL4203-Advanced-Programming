#include <iostream>
using namespace std; // Para no tener que escribir std::cout, std::endl, etc.
#include <clocale>

/**
 * @file Pauta_Auxiliar_4.cpp
 * @brief This program demonstrates how to find the maximum values in each row of a 2x4 matrix.
 * 
 * The program initializes a 2x4 matrix with predefined float values. It then iterates through each row
 * to find the maximum value in that row and stores these maximum values in an array. Finally, it prints
 * the original matrix and the array of maximum values.
 * 
 * The program also sets the locale to UTF-8 to handle Unicode characters in Windows.
 * 
 * @return int Returns 0 upon successful execution.
 */

int main() {
    // Cambia el encoding a UTF8 para realizar print de
    // caracteres Unicode en Windows sin problemas
    setlocale(LC_ALL, ".UTF8");

    float matriz[2][4] = {
        {-0.730757f, 3.577920f, 1.466167f, 0.710437f},
        {1.568149f, 0.731046f, -0.913783f, 2.201392f}
    };

    int valoresMaximos[2];
    for (int i = 0; i < 2; i++) {
        valoresMaximos[i] = (int)matriz[i][0];
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > valoresMaximos[i]) {
                valoresMaximos[i] = (int)matriz[i][j]; // Casting explícito a int
            }
        }
    }

    std::cout << "Matriz de 2*4" << "\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nArray con valores máximos" << "\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << valoresMaximos[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}
