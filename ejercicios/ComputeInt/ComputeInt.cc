/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Informática Básica 2023-2024
* @file Computeint.cc
* @author Danna Cristina Márquez Martín alu0101648408@ull.edu.es
* @date Dic 14 2023
* @brief calcular el factorial, la suma de una serie, verificar 
*        si un número es primo y determinar si dos números son mutuamente primos.
*/

#include <iostream>

class ComputeInt {
private:
    int num1;
    int num2;
public:
    // Constructor
    ComputeInt(int a, int b) : num1(a), num2(b) {}
    // Método para calcular el factorial de un número
    long long Factorial(int n) {
        if (n < 0) {
            return -1;  // Factorial no definido para números negativos
        } else if (n == 0 || n == 1) {
            return 1;
        } else {
            return n * Factorial(n - 1);
        }
    }
    // Método para calcular la suma de los primeros n términos de la serie: 1 + 2 + 3 + ... + n
    int SumSerie(int n) {
        return (n * (n + 1)) / 2;
    }
    // Método para determinar si un número es primo
    bool IsPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    // Método para determinar si un número es un primo perfecto
    bool IsPerfectPrime(int n) {
        return IsPrime(n) && IsPrime((1 << n) - 1);
    }
    // Método para determinar si dos números son mutuamente primos
    bool AreRelativePrimes() {
        int a = num1;
        int b = num2;

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a == 1;
    }
};
int main() {
    ComputeInt compute_integer{10, 7};
    std::cout << "Factorial: " << compute_integer.Factorial(5) << std::endl;
    std::cout << "SumSerie: " << compute_integer.SumSerie(5) << std::endl;
    std::cout << "IsPrime: " << compute_integer.IsPrime(11) << std::endl;
    std::cout << "AreRelativePrimes: " << compute_integer.AreRelativePrimes() << std::endl;
    return 0;
}