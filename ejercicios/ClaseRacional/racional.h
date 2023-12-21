/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica 2023-2024
* @file racional.h
* @author Danna Cristina Márquez Martín alu0101648408@ull.edu.es
* @date Dic 16 2023
* @brief  realiza operaciones aritméticas y comparaciones entre 
*         pares de números racionales proporcionados en un archivo de 
*         entrada, generando un archivo de salida que contiene los 
*         resultados de las operaciones realizadas, como sumas, restas, 
*         multiplicaciones, divisiones y comparaciones. (CABECERA)
*/

#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

class Racional {
private:
    int numerador;
    int denominador;
public:
    Racional(); 
    Racional(int num, int den);
    void imprimir() const;
    void leer();
    Racional sumar(const Racional& otro) const;
    Racional restar(const Racional& otro) const;
    Racional multiplicar(const Racional& otro) const;
    Racional dividir(const Racional& otro) const;
    bool comparar(const Racional& otro) const;
};
#endif // RACIONAL_H