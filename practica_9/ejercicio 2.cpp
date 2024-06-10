#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Animal {
public:
	virtual void comer() = 0;
	virtual void dormir() = 0;
	virtual void moverse() = 0;
	virtual ~Animal() {}
};

class Perro : public Animal {
public:
	void comer() override { cout << "El perro come croquetas." << endl; }
	void dormir() override { cout << "El perro duerme en su camita." << endl; }
	void moverse() override { cout << "El perro corre y camina." << endl; }
};

class Gato : public Animal {
public:
	void comer() override { cout << "El gato come atún." << endl; }
	void dormir() override { cout << "El gato duerme en el sofá." << endl; }
	void moverse() override { cout << "El gato camina y salta." << endl; }
};

class Aguila : public Animal {
public:
	void comer() override { cout << "El águila caza presas." << endl; }
	void dormir() override { cout << "El águila duerme en su nido." << endl; }
	void moverse() override { cout << "El águila vuela y camina." << endl; }
};


class Cocodrilo : public Animal {
public:
	void comer() override { cout << "El cocodrilo caza presas acuáticas." << endl; }
	void dormir() override { cout << "El cocodrilo duerme al sol." << endl; }
	void moverse() override { cout << "El cocodrilo nada y camina." << endl; }
};

int main() {
	vector<Animal*> animales;
	
	animales.push_back(new Perro());
	animales.push_back(new Gato());
	animales.push_back(new Aguila());
	animales.push_back(new Cocodrilo());
	
	for (Animal* a : animales) {
		a->comer();
		a->dormir();
		a->moverse();
		cout << endl;
	}
	
	for (Animal* a : animales) {
		delete a;
	}
	
	return 0;
}
