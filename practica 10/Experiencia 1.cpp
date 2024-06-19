#include <iostream>
#include <cmath>
#include <string>
using namespace std;

template <typename T>
T calcularDistancia(T x1, T y1, T x2, T y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

template <typename T>
T calcularTiempoEntrega(T distancia, T velocidad) {
    return distancia / velocidad;
}

template <typename T>
void generarInforme(T distancia, T tiempoEntrega, const string& unidadDistancia, const string& unidadTiempo) {
    cout << "Informe de Entrega:" << endl;
    cout << "Distancia: " << distancia << " " << unidadDistancia << endl;
    cout << "Tiempo Estimado de Entrega: " << tiempoEntrega << " " << unidadTiempo << endl;
}

int main() {
    double x1, y1, x2, y2, velocidad;

    cout << "Ingrese las coordenadas del primer punto (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Ingrese las coordenadas del segundo punto (x2 y2): ";
    cin >> x2 >> y2;
    cout << "Ingrese la velocidad media (km/h): ";
    cin >> velocidad;

    double distancia = calcularDistancia(x1, y1, x2, y2);
    double tiempoEntrega = calcularTiempoEntrega(distancia, velocidad);

    generarInforme(distancia, tiempoEntrega, "km", "horas");

    return 0;
}






