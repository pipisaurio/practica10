#include <iostream>
#include <vector>
#include <functional>

// Clase Ubicacion
class Ubicacion {
public:
	double latitud;
	double longitud;
};

// Clase Entrega
class Entrega {
public:
	Ubicacion direccion;
	std::string descripcion;
};

// Clase Ruta
class Ruta {
public:
	std::vector<Entrega> entregas;
	
	// Template de m�todo para asignar veh�culos a rutas
	template <typename Criterio>
	void asignarVehiculos(const Criterio& criterio) {
		// C�digo para asignar veh�culos a las entregas de la ruta
		// utilizando el criterio especificado
		std::cout << "Asignando veh�culos a la ruta seg�n el criterio: " << criterio.descripcion() << std::endl;
	}
};

// Ejemplo de criterio basado en distancia total
class CriterioDistancia {
public:
	std::string descripcion() const {
		return "Distancia total";
	}
};

// Ejemplo de criterio basado en n�mero de entregas
class CriterioNumeroEntregas {
public:
	std::string descripcion() const {
		return "N�mero de entregas";
	}
};

int main() {
	Ruta ruta1;
	// Agregar entregas a ruta1
	Entrega entrega1, entrega2, entrega3;
	ruta1.entregas.push_back(entrega1);
	ruta1.entregas.push_back(entrega2);
	ruta1.entregas.push_back(entrega3);
	
	// Asignar veh�culos basados en la distancia total
	ruta1.asignarVehiculos(CriterioDistancia());
	
	// Asignar veh�culos basados en el n�mero de entregas
	ruta1.asignarVehiculos(CriterioNumeroEntregas());
	
	return 0;
}
