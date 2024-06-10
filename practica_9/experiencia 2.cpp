#include <iostream>
using namespace std;

// Clase Calculadora
class Calculadora {
public:
	int sumar(int a, int b) {
		cout << "Sumando enteros: " << a << " + " << b << endl;
		return a + b;
	}
	
	double sumar(double a, double b) {
		cout << "Sumando flotantes: " << a << " + " << b << endl;
		return a + b;
	}
	
	int sumar(int a, int b, int c) {
		cout << "Sumando tres enteros: " << a << " + " << b << " + " << c << endl;
		return a + b + c;
	}
};

int main() {
	Calculadora calc;
	
	// Llamadas a diferentes métodos sumar
	cout << "Resultado: " << calc.sumar(2, 3) << endl; // Llama a sumar(int, int)
	cout << "Resultado: " << calc.sumar(2.5, 3.7) << endl; // Llama a sumar(double, double)
	cout << "Resultado: " << calc.sumar(2, 3, 4) << endl; // Llama a sumar(int, int, int)
	
	return 0;
}
