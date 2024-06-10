#include <iostream>
using namespace std;

const float PI = 3.1416;

class Figura {
public:
    virtual float calcularArea() const = 0;
};

class Circulo : public Figura {
private:
    float radio;
public:
    Circulo(double r) : radio(r) {}

    float calcularArea() const override {
        return PI * radio * radio;
    }
};

class Rectangulo : public Figura {
private:
    float base;
    float altura;
public:
    Rectangulo(float b, float h) : base(b), altura(h) {}

    float calcularArea() const override {
        return base * altura;
    }
};

class Triangulo : public Figura {
private:
    float base;
    float altura;
public:
    Triangulo(float b,float h) : base(b), altura(h) {}

    float calcularArea() const override {
        return (base * altura) / 2;
    }
};

int main() {

    Figura* figuras[] = {
        new Circulo(5),
        new Rectangulo(4, 6),
        new Triangulo(3, 8)
    };

    for (int i = 0; i < 3; ++i) {
        cout << "Área de la figura " << i+1 << ": " << figuras[i]->calcularArea() << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete figuras[i];
    }

    return 0;
}

