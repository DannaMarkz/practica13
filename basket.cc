/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Danna Cristina Márquez Martín
 * @date Dec 21 2023
 * @brief Jerarquia de clases en un equipo de baloncesto.
 */

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
class Jugador : public Persona {
protected:
    float altura;
    float peso;
    std::string posicion;
    std::vector<float> estadisticasPartido;
public:
    Jugador(std::string nombre, int edad, std::string DNI, float altura, float peso, std::string posicion)
        : Persona(nombre, edad, DNI), altura(altura), peso(peso), posicion(posicion) {}
    // Constructor por defecto
    Jugador() : Persona("", 0, ""), altura(0.0f), peso(0.0f), posicion("") {}
    float obtenerAltura() const {
        return altura;
    }
    float obtenerPeso() const {
        return peso;
    }
    void mostrarInformacion() const {
        Persona::mostrarInformacion();
        std::cout << "Altura: " << altura << " metros, Peso: " << peso << " kilogramos, Posición: " << posicion << std::endl;
    }
};
class Entrenador : public Persona {
protected:
    std::string licencia;
    std::string fechaInicioContrato;
    std::string fechaFinContrato;
public:
    Entrenador(std::string nombre, int edad, std::string DNI, std::string licencia,
               std::string fechaInicioContrato, std::string fechaFinContrato)
        : Persona(nombre, edad, DNI), licencia(licencia), fechaInicioContrato(fechaInicioContrato),
          fechaFinContrato(fechaFinContrato) {}

    // Constructor por defecto
    Entrenador() : Persona("", 0, ""), licencia(""), fechaInicioContrato(""), fechaFinContrato("") {}
    void mostrarInformacion() const {
        Persona::mostrarInformacion();
        std::cout << "Licencia: " << licencia << ", Inicio Contrato: " << fechaInicioContrato
                  << ", Fin Contrato: " << fechaFinContrato << std::endl;
    }
};
class Ayudante : public Persona {
protected:
    std::string fechaInicioContrato;
    std::string fechaFinContrato;
public:
    Ayudante(std::string nombre, int edad, std::string DNI, std::string fechaInicioContrato,
             std::string fechaFinContrato)
        : Persona(nombre, edad, DNI), fechaInicioContrato(fechaInicioContrato),
          fechaFinContrato(fechaFinContrato) {}
    //Constructor
    Ayudante() : Persona("", 0, ""), fechaInicioContrato(""), fechaFinContrato("") {}
    void mostrarInformacion() const {
        Persona::mostrarInformacion();
        std::cout << "Inicio Contrato: " << fechaInicioContrato << ", Fin Contrato: " << fechaFinContrato << std::endl;
    }
};
class Equipo_Baloncesto {
protected:
    std::string nombre;
    std::string ciudad;
    std::vector<Jugador> jugadores;
    Entrenador entrenadorPrincipal;
    std::vector<Ayudante> ayudantes;
public:
    Equipo_Baloncesto(std::string nombre, std::string ciudad)
        : nombre(nombre), ciudad(ciudad), jugadores(12), entrenadorPrincipal("Entrenador Principal", 40, "12345678A", "UEFA Pro", "01/01/2023", "31/12/2025"), ayudantes(3) {}
//
     Equipo_Baloncesto() {}
    void mostrarInformacionEquipo() const {
        std::cout << "Equipo: " << nombre << ", Ciudad: " << ciudad << std::endl;
        std::cout << "Jugadores:" << std::endl;
        for (const auto &jugador : jugadores) {
            jugador.mostrarInformacion();
        }
        std::cout << "Entrenador Principal:" << std::endl;
        entrenadorPrincipal.mostrarInformacion();
        std::cout << "Ayudantes:" << std::endl;
        for (const auto &ayudante : ayudantes) {
            ayudante.mostrarInformacion();
        }
    }
    float calcularAlturaPromedio() const {
        float sumaAlturas = 0.0f;
        for (const Jugador &jugador : jugadores) {
            sumaAlturas += jugador.obtenerAltura();
        }
        return jugadores.empty() ? 0.0f : sumaAlturas / jugadores.size();
    }
    float calcularPesoPromedio() const {
        float sumaPesos = 0.0f;
        for (const Jugador &jugador : jugadores) {
            sumaPesos += jugador.obtenerPeso();
        }
        return jugadores.empty() ? 0.0f : sumaPesos / jugadores.size();
    }
    // Método para agregar un jugador al equipo
    void agregarJugador(const Jugador& jugador) {
        jugadores.push_back(jugador);
    }
    // Método para establecer el entrenador principal
    void setEntrenadorPrincipal(const Entrenador& entrenador) {
        entrenadorPrincipal = entrenador;
    }
    // Método para agregar un ayudante al equipo
    void agregarAyudante(const Ayudante& ayudante) {
        ayudantes.push_back(ayudante);
    }
    // Métodos para mostrar el quinteto en juego y jugadores en el banquillo
    void mostrarQuintetoEnJuego() const {
        // Implementación pendiente
    }
    void mostrarJugadoresEnBanquillo() const {
        // Implementación pendiente
    }
};
int main() {
    std::string nombreEquipo, ciudadEquipo;
    
    std::cout << "Ingrese el nombre del equipo: ";
    std::getline(std::cin, nombreEquipo);

    std::cout << "Ingrese la ciudad del equipo: ";
    std::getline(std::cin, ciudadEquipo);

    // Crear un equipo de baloncesto
    Equipo_Baloncesto equipo(nombreEquipo, ciudadEquipo);

    // Ingresar datos para los jugadores
    for (int i = 0; i < 12; ++i) {
        std::string nombreJugador, DNIJugador, posicionJugador;
        int edadJugador;
        float alturaJugador, pesoJugador;

        std::cout << "\nDatos del Jugador " << i + 1 << ":\n";
        std::cout << "Nombre: ";
        std::getline(std::cin, nombreJugador);

        std::cout << "Edad: ";
        std::cin >> edadJugador;

        std::cin.ignore();  // Para consumir el salto de línea pendiente

        std::cout << "DNI: ";
        std::getline(std::cin, DNIJugador);

        std::cout << "Altura (metros): ";
        std::cin >> alturaJugador;

        std::cout << "Peso (kilogramos): ";
        std::cin >> pesoJugador;

        std::cin.ignore();  // Para consumir el salto de línea pendiente

        std::cout << "Posición: ";
        std::getline(std::cin, posicionJugador);

        Jugador jugador(nombreJugador, edadJugador, DNIJugador, alturaJugador, pesoJugador, posicionJugador);
        equipo.agregarJugador(jugador);
    }

    // Calcular y mostrar el peso y altura promedio de los jugadores
    std::cout << "\nAltura promedio de los jugadores: " << equipo.calcularAlturaPromedio() << " metros" << std::endl;
    std::cout << "Peso promedio de los jugadores: " << equipo.calcularPesoPromedio() << " kilogramos" << std::endl;


    return 0;
}
