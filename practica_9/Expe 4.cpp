/*4. EXPERIENCIA DE PRÁCTICA N° 4: FUNCIONES VIRTUALES Y REDEFINICIÓN DE MÉTODOS
1. Descripción: En esta experiencia, los estudiantes profundizarán en el uso de funciones virtuales y la
redefinición de métodos en clases derivadas para lograr un comportamiento polimórfico.
2. Implementación:
▪ Cree una clase base Animal con un método virtual hacerSonido().
▪ Cree clases derivadas de Animal, como Perro, Gato y Vaca.
▪ Redefina el método hacerSonido() en cada clase derivada para que cada animal emita su
sonido característico.
▪ En la función main, cree un arreglo de punteros a Animal y almacene objetos de diferentes
tipos de animales en él.
▪ Recorra el arreglo y llame al método hacerSonido() para cada objeto. Observe cómo se
ejecuta la versión correcta del método en función del tipo real del objeto en tiempo de
ejecución.*/

#include <iostream>

// Clase base Animal con método virtual hacerSonido()
class Animal {
public:
    virtual void hacerSonido() = 0; // método abstracto
};

// Clase derivada Perro
class Perro : public Animal {
public:
    void hacerSonido() override {
        std::cout << "El perro ladra." << std::endl;
    }
};

// Clase derivada Gato
class Gato : public Animal {
public:
    void hacerSonido() override {
        std::cout << "El gato maúlla." << std::endl;
    }
};

// Clase derivada Vaca
class Vaca : public Animal {
public:
    void hacerSonido() override {
        std::cout << "La vaca muge." << std::endl;
    }
};

int main() {
    // Crear un arreglo de punteros a Animal
    Animal* animales[3];

    // Almacenar objetos de diferentes tipos de animales en el arreglo
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();

    // Recorrer el arreglo y llamar al método hacerSonido() para cada objeto
    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();
    }

    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }

    return 0;
}