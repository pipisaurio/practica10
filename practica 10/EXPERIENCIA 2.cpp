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
	
	// Template de método para asignar vehículos a rutas
	template <typename Criterio>
	void asignarVehiculos(const Criterio& criterio) {
		// Código para asignar vehículos a las entregas de la ruta
		// utilizando el criterio especificado
		std::cout << "Asignando vehículos a la ruta según el criterio: " << criterio.descripcion() << std::endl;
	}
};

// Ejemplo de criterio basado en distancia total
class CriterioDistancia {
public:
	std::string descripcion() const {
		return "Distancia total";
	}
};

// Ejemplo de criterio basado en número de entregas
class CriterioNumeroEntregas {
public:
	std::string descripcion() const {
		return "Número de entregas";
	}
};

int main() {
	Ruta ruta1;
	// Agregar entregas a ruta1
	Entrega entrega1, entrega2, entrega3;
	ruta1.entregas.push_back(entrega1);
	ruta1.entregas.push_back(entrega2);
	ruta1.entregas.push_back(entrega3);
	
	// Asignar vehículos basados en la distancia total
	ruta1.asignarVehiculos(CriterioDistancia());
	
	// Asignar vehículos basados en el número de entregas
	ruta1.asignarVehiculos(CriterioNumeroEntregas());
	
	return 0;
}
