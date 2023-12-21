/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica 2023-2024
* @file racional.cc
* @author Danna Cristina Márquez Martín alu0101648408@ull.edu.es
* @date Dic 16 2023
* @brief  realiza operaciones aritméticas y comparaciones entre 
*         pares de números racionales proporcionados en un archivo de 
*         entrada, generando un archivo de salida que contiene los 
*         resultados de las operaciones realizadas, como sumas, restas, 
*         multiplicaciones, divisiones y comparaciones.
*/

#include "racional.h"
#include <fstream>
#include <iostream>
#include <string>

void realizarOperaciones(const Racional& racional1, const Racional& racional2, std::ofstream& outFile) {
    racional1.imprimir();
    outFile << " + ";
    racional2.imprimir();
    outFile << " = ";
    (racional1.sumar(racional2)).imprimir();
    outFile << "\n";
    // Realiza y muestra otras operaciones como resta, multiplicación, división y comparación
    // ...

    outFile << "\n";
}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "./racionales -- Números Racionales\n"
                  << "Modo de uso: ./racionales fichero_entrada fichero_salida\n"
                  << "Pruebe ./racionales --help para más información\n";
        return 1;
    }
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    if (inputFile == "--help") {
        std::cout << "./racionales -- Números Racionales\n"
                  << "Modo de uso: ./racionales fichero_entrada fichero_salida\n"
                  << "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales: a/b c/d separados por un espacio\n"
                  << "fichero_salida: Fichero de texto que contendrá líneas con las operaciones realizadas: a/b + c/d = n/m\n";
        return 0;
    }
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
    if (!inFile || !outFile) {
        std::cerr << "Error al abrir los archivos de entrada o salida.\n";
        return 1;
    }
    int num1, den1, num2, den2;
    while (inFile >> num1 >> den1 >> num2 >> den2) {
        Racional racional1(num1, den1);
        Racional racional2(num2, den2);

        realizarOperaciones(racional1, racional2, outFile);
    }
    inFile.close();
    outFile.close();
    return 0;
}
Racional::racional()
{
}
