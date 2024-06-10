#include <iostream>
#include <vector>
using namespace std;

class Figura {
public:
	virtual double calcularArea() = 0; // Método virtual puro
};

class Circulo : public Figura {
private:
	double radio;
	
public:
	Circulo(double r) : radio(r) {}
	double calcularArea() override {
		return 3.14159 * radio * radio;
	}
};

class Rectangulo : public Figura {
private:
	double ancho, alto;
	
public:
	Rectangulo(double a, double h) : ancho(a), alto(h) {}
	double calcularArea() override {
		return ancho * alto;
	}
};

class Triangulo : public Figura {
private:
	double base, altura;
	
public:
	Triangulo(double b, double h) : base(b), altura(h) {}
	double calcularArea() override {
		return 0.5 * base * altura;
	}
};

int main() {
	vector<Figura*> figuras;
	
	figuras.push_back(new Circulo(3.0));
	figuras.push_back(new Rectangulo(4.0, 5.0));
	figuras.push_back(new Triangulo(6.0, 7.0));
	
	for (Figura* f : figuras) {
		cout << "Área: " << f->calcularArea() << endl;
		delete f; // Liberar memoria
	}
	
	return 0;
}
