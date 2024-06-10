#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Empleado {
protected:
	string nombre;
	
public:
	Empleado(const string& nombre) : nombre(nombre) {}
	virtual double calcularSalario() = 0;
	string getNombre() const { return nombre; }
	virtual ~Empleado() {}
	
};
	
class EmpleadoAsalariado : public Empleado {
private:
	double salarioMensual;
public:
	EmpleadoAsalariado(const string& nombre, double salarioMensual) : Empleado(nombre), salarioMensual(salarioMensual) {}
	double calcularSalario() override { return salarioMensual; }
	
};


class EmpleadoPorHora : public Empleado {
private:
	double tarifaHora;
	double horasTrabajadas;
	
public:
	EmpleadoPorHora(const string& nombre, double tarifaHora, double horasTrabajadas) : Empleado(nombre), tarifaHora(tarifaHora), horasTrabajadas(horasTrabajadas) {}
	double calcularSalario() override { return tarifaHora * horasTrabajadas; }
};

class EmpleadoComisionista : public Empleado {
private:
	double ventasRealizadas;
	double comision;
	
public:
	EmpleadoComisionista(const string& nombre, double ventasRealizadas, double comision) : Empleado(nombre), ventasRealizadas(ventasRealizadas), comision(comision) {}
	double calcularSalario() override { return ventasRealizadas * comision; }
};

int main() {
	vector<Empleado*> empleados;
	
	empleados.push_back(new EmpleadoAsalariado("Juan Pérez", 3000));
	empleados.push_back(new EmpleadoPorHora("María González", 15, 160));
	empleados.push_back(new EmpleadoComisionista("Pedro Ramírez", 25000, 0.05));
	
	for (Empleado* e : empleados) {
		cout << "Salario de " << e->getNombre() << ": $" << e->calcularSalario() << endl;
	}
	
	for (Empleado* e : empleados) {
		delete e;
	}
	
	return 0;
}
