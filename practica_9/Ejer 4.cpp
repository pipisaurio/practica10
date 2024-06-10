/*Juego de Rol (RPG): Diseñe un juego de rol simple en el que los personajes (guerreros, magos,
arqueros) tengan habilidades y atributos diferentes. Utilice el polimorfismo para implementar
acciones comunes, como atacar, defender y usar habilidades especiales, y personalice estas
acciones para cada tipo de personaje.*/

#include <iostream>
#include <string>

using namespace std;

// Clase base Personaje
class Personaje {
protected:
    string nombre;
    int vida;
    int fuerza;
    int defensa;

public:
    Personaje(string n, int v, int f, int d) : nombre(n), vida(v), fuerza(f), defensa(d) {}

    virtual void atacar(Personaje* objetivo) = 0;
    virtual void defender(int dano) = 0;
    virtual void usarHabilidadEspecial(Personaje* objetivo) = 0;

    string getNombre() { return nombre; }
    int getVida() { return vida; }
};

// Clase derivada Guerrero
class Guerrero : public Personaje {
public:
    Guerrero(string n, int v, int f, int d) : Personaje(n, v, f, d) {}

    void atacar(Personaje* objetivo) override {
        cout << nombre << " ataca a " << objetivo->getNombre() << " con su espada!" << endl;
        objetivo->defender(fuerza);
    }

    void defender(int dano) override {
        vida -= dano;
        cout << nombre << " defiende y pierde " << dano << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial(Personaje* objetivo) override {
        cout << nombre << " usa su habilidad especial: Golpe Critico!" << endl;
        objetivo->defender(fuerza * 2);
    }
};

// Clase derivada Mago
class Mago : public Personaje {
public:
    Mago(string n, int v, int f, int d) : Personaje(n, v, f, d) {}

    void atacar(Personaje* objetivo) override {
        cout << nombre << " lanza un hechizo a " << objetivo->getNombre() << "!" << endl;
        objetivo->defender(fuerza);
    }

    void defender(int dano) override {
        vida -= dano;
        cout << nombre << " defiende y pierde " << dano << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial(Personaje* objetivo) override {
        cout << nombre << " usa su habilidad especial: Hechizo de Fuego!" << endl;
        objetivo->defender(fuerza * 3);
    }
};

// Clase derivada Arquero
class Arquero : public Personaje {
public:
    Arquero(string n, int v, int f, int d) : Personaje(n, v, f, d) {}

    void atacar(Personaje* objetivo) override {
        cout << nombre << " dispara una flecha a " << objetivo->getNombre() << "!" << endl;
        objetivo->defender(fuerza);
    }

    void defender(int dano) override {
        vida -= dano;
        cout << nombre << " defiende y pierde " << dano << " puntos de vida." << endl;
    }

    void usarHabilidadEspecial(Personaje* objetivo) override {
        cout << nombre << " usa su habilidad especial: Tiro Multiple!" << endl;
        objetivo->defender(fuerza * 2);
        objetivo->defender(fuerza * 2);
    }
};

int main() {
    Guerrero guerrero("Guerrero", 100, 20, 10);
    Mago mago("Mago", 80, 30, 15);
    Arquero arquero("Arquero", 90, 25, 12);

    Personaje* personajes[] = {&guerrero, &mago, &arquero};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                personajes[i]->atacar(personajes[j]);
                personajes[j]->defender(10);
                personajes[i]->usarHabilidadEspecial(personajes[j]);
                cout << endl;
            }
        }
    }

    return 0;
}
