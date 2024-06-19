#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Plantilla de clase para gestionar las rutas
template <typename T>
class GestorDeRutas {
private:
	vector<T> rutas;
	
	// Método para ordenar las rutas manualmente
	void ordenarRutas() {
		for (size_t i = 0; i < rutas.size() - 1; ++i) {
			for (size_t j = i + 1; j < rutas.size(); ++j) {
				if (rutas[i] > rutas[j]) {
					swap(rutas[i], rutas[j]);
				}
			}
		}
	}
	
	// Método para calcular la distancia simulada entre dos rutas
	int calcularDistancia(const T& inicio, const T& fin) const {
		// Simulación de la distancia entre dos rutas basada en la longitud de las cadenas
		return static_cast<int>(inicio.length()) - static_cast<int>(fin.length());
	}
	
public:
		// Método de plantilla para añadir una ruta
		void agregarRuta(const T& ruta) {
			rutas.push_back(ruta);
		}
		
		// Método de plantilla para eliminar una ruta
		void eliminarRuta(const T& ruta) {
			for (auto it = rutas.begin(); it != rutas.end(); ++it) {
				if (*it == ruta) {
					rutas.erase(it);
					break;
				}
			}
		}
		
		// Método de plantilla para mostrar las rutas
		void mostrarRutas() const {
			for (const auto& ruta : rutas) {
				cout << ruta << endl;
			}
		}
		
		// Método de plantilla para optimizar las rutas alfabéticamente
		void optimizarRutas() {
			ordenarRutas();
		}
		
		// Método para optimizar el tiempo y recursos utilizados
		void optimizarTiempoYRecursos() {
			if (rutas.empty()) return;
			
			vector<T> rutasOptimizadas;
			T ubicacionActual = rutas[0];
			rutasOptimizadas.push_back(ubicacionActual);
			
			for (size_t i = 1; i < rutas.size(); ++i) {
				T rutaSiguiente = rutas[i];
				for (size_t j = i + 1; j < rutas.size(); ++j) {
					if (calcularDistancia(ubicacionActual, rutas[j]) < calcularDistancia(ubicacionActual, rutaSiguiente)) {
						rutaSiguiente = rutas[j];
					}
				}
				ubicacionActual = rutaSiguiente;
				rutasOptimizadas.push_back(ubicacionActual);
			}
			rutas = rutasOptimizadas;
		}
};

// Clase principal del sistema de gestión de rutas
class SistemaDeEntrega {
private:
	GestorDeRutas<string> gestorDeRutas;
	
public:
	// Función para añadir una ruta de entrega
	void agregarRutaDeEntrega(const string& ruta) {
		gestorDeRutas.agregarRuta(ruta);
	}
	
	// Función para eliminar una ruta de entrega
	void eliminarRutaDeEntrega(const string& ruta) {
		gestorDeRutas.eliminarRuta(ruta);
	}
	
	// Función para optimizar las rutas de entrega
	void optimizarRutasDeEntrega() {
		gestorDeRutas.optimizarRutas();
	}
	
	// Función para optimizar el tiempo y los recursos de entrega
	void optimizarTiempoYRecursosDeEntrega() {
		gestorDeRutas.optimizarTiempoYRecursos();
	}
	
	// Función para mostrar las rutas de entrega
	void mostrarRutasDeEntrega() const {
		gestorDeRutas.mostrarRutas();
	}
};

// Función para mostrar el menú principal
void mostrarMenu() {
	cout << "Sistema de Entrega" << endl;
	cout << "1. Agregar ruta de entrega" << endl;
	cout << "2. Eliminar ruta de entrega" << endl;
	cout << "3. Mostrar rutas de entrega" << endl;
	cout << "4. Optimizar rutas de entrega (alfabéticamente)" << endl;
	cout << "5. Optimizar tiempo y recursos de entrega" << endl;
	cout << "6. Salir" << endl;
	cout << "Ingrese su opción: ";
}

int main() {
	SistemaDeEntrega sistemaDeEntrega;
	int opcion;
	string ruta;
	
	do {
		mostrarMenu();
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese la ruta de entrega: ";
			cin >> ruta;
			sistemaDeEntrega.agregarRutaDeEntrega(ruta);
			break;
		case 2:
			cout << "Ingrese la ruta de entrega a eliminar: ";
			cin >> ruta;
			sistemaDeEntrega.eliminarRutaDeEntrega(ruta);
			break;
		case 3:
			cout << "Rutas de entrega:" << endl;
			sistemaDeEntrega.mostrarRutasDeEntrega();
			break;
		case 4:
			sistemaDeEntrega.optimizarRutasDeEntrega();
			cout << "Rutas optimizadas alfabéticamente." << endl;
			break;
		case 5:
			sistemaDeEntrega.optimizarTiempoYRecursosDeEntrega();
			cout << "Rutas optimizadas por tiempo y recursos." << endl;
			break;
		case 6:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción inválida. Intente nuevamente." << endl;
		}
	} while (opcion != 6);
	
	return 0;
}
