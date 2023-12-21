#include <iostream>
#include <vector>

class Persona {
protected:
    std::string nombre;
    int edad;
    std::string DNI;

public:
    Persona(std::string nombre, int edad, std::string DNI)
        : nombre(nombre), edad(edad), DNI(DNI) {}

    void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << ", DNI: " << DNI << std::endl;
    }
};

