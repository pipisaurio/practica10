#include <iostream>
using namespace std;

class Forma {
public:
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrarInformacion() const = 0;
    virtual ~Forma() {}
};

class Circulo : public Forma {
    double radio;
    static constexpr double pi = 3.1416;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() const override {
        return pi * radio * radio;
    }
    double calcularPerimetro() const override {
        return 2 * pi * radio;
    }
    void mostrarInformacion() const override {
        cout << "Círculo - Radio: " << radio << ", Área: " << calcularArea() << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

class Rectangulo : public Forma {
    double ancho;
    double alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    double calcularArea() const override {
        return ancho * alto;
    }
    double calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }
    void mostrarInformacion() const override {
        cout << "Rectángulo - Ancho: " << ancho << ", Alto: " << alto << ", Área: " << calcularArea() << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

class Triangulo : public Forma {
    double base;
    double altura;
    double lado1;
    double lado2;
    double lado3;
public:
    Triangulo(double b, double h, double l1, double l2, double l3) : base(b), altura(h), lado1(l1), lado2(l2), lado3(l3) {}
    double calcularArea() const override {
        return (base * altura) / 2;
    }
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
    void mostrarInformacion() const override {
        cout << "Triángulo - Base: " << base << ", Altura: " << altura << ", Lados: " << lado1 << ", " << lado2 << ", " << lado3 << ", Área: " << calcularArea() << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

class Cuadrado : public Forma {
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double calcularArea() const override {
        return lado * lado;
    }
    double calcularPerimetro() const override {
        return 4 * lado;
    }
    void mostrarInformacion() const override {
        cout << "Cuadrado - Lado: " << lado << ", Área: " << calcularArea() << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

class Pentagono : public Forma {
    double lado;
    static constexpr double apotema = 0.69;
public:
    Pentagono(double l) : lado(l) {}
    double calcularArea() const override {
        return (5 * lado * (lado * apotema)) / 2;
    }
    double calcularPerimetro() const override {
        return 5 * lado;
    }
    void mostrarInformacion() const override {
        cout << "Pentágono - Lado: " << lado << ", Área: " << calcularArea() << ", Perímetro: " << calcularPerimetro() << endl;
    }
};

class GestorFormas {
    Forma** formas;
    int capacidad;
    int cantidad;
public:
    GestorFormas(int cap) : capacidad(cap), cantidad(0) {
        formas = new Forma*[capacidad];
    }

    void agregarForma(Forma* forma) {
        if (cantidad < capacidad) {
            formas[cantidad++] = forma;
        } else {
            cout << "No se puede agregar más formas, capacidad máxima alcanzada." << endl;
        }
    }

    void mostrarFormas() const {
        for (int i = 0; i < cantidad; ++i) {
            formas[i]->mostrarInformacion();
        }
    }

    ~GestorFormas() {
        for (int i = 0; i < cantidad; ++i) {
            delete formas[i];
        }
        delete[] formas;
    }
};

void agregarFormas(GestorFormas& gestor) {
    while (true) {
        int opcion;
        cout << "Seleccione la forma a agregar:\n1. Círculo\n2. Rectángulo\n3. Triángulo\n4. Cuadrado\n5. Pentágono\n6. Salir\n";
        cin >> opcion;

        if (opcion == 6) break;

        switch (opcion) {
            case 1: {
                double radio;
                cout << "Ingrese el radio del círculo: ";
                cin >> radio;
                gestor.agregarForma(new Circulo(radio));
                break;
            }
            case 2: {
                double ancho, alto;
                cout << "Ingrese el ancho y alto del rectángulo: ";
                cin >> ancho >> alto;
                gestor.agregarForma(new Rectangulo(ancho, alto));
                break;
            }
            case 3: {
                double base, altura, lado1, lado2, lado3;
                cout << "Ingrese la base y altura del triángulo: ";
                cin >> base >> altura;
                cout << "Ingrese los tres lados del triángulo: ";
                cin >> lado1 >> lado2 >> lado3;
                gestor.agregarForma(new Triangulo(base, altura, lado1, lado2, lado3));
                break;
            }
            case 4: {
                double lado;
                cout << "Ingrese el lado del cuadrado: ";
                cin >> lado;
                gestor.agregarForma(new Cuadrado(lado));
                break;
            }
            case 5: {
                double lado;
                cout << "Ingrese el lado del pentágono: ";
                cin >> lado;
                gestor.agregarForma(new Pentagono(lado));
                break;
            }
            default:
                cout << "Opción no válida." << endl;
        }
    }
}

int main() {
    int capacidad;
    cout << "Ingrese la capacidad máxima de formas: ";
    cin >> capacidad;

    GestorFormas gestor(capacidad);

    agregarFormas(gestor);

    cout << "\nFormas agregadas:\n";
    gestor.mostrarFormas();

    return 0;
}
