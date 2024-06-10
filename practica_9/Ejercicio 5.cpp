#include <iostream> 
#include <string> 
using namespace std; 

class Producto { 
public: 
    Producto(const string& nombre, double precio, int cantidad) 
        : nombre(nombre), precio(precio), cantidad(cantidad) {} 
    virtual ~Producto() {} 

    virtual double calcularValor() const { 
        return precio * cantidad; 
    } 
    virtual void aplicarDescuento(double porcentaje) = 0; 
    const string& getNombre() const { 
        return nombre; 
    } 

    int getCantidad() const { 
        return cantidad; 
    } 

    double getPrecio() const { 
        return precio; 
    } 

protected: 

    string nombre; 
    double precio; 
    int cantidad; 
}; 

class Electronico : public Producto { 
public: 
    Electronico(const string& nombre, double precio, int cantidad) 
        : Producto(nombre, precio, cantidad) {} 

    void aplicarDescuento(double porcentaje) override { 
        precio -= precio * (porcentaje / 100); 
    } 
}; 


class Ropa : public Producto { 
public: 
    Ropa(const string& nombre, double precio, int cantidad) 
        : Producto(nombre, precio, cantidad) {} 
    void aplicarDescuento(double porcentaje) override { 
        precio -= precio * (porcentaje / 100); 
    } 
}; 

class Alimento : public Producto { 
public: 
    Alimento(const string& nombre, double precio, int cantidad) 
        : Producto(nombre, precio, cantidad) {} 
    void aplicarDescuento(double porcentaje) override { 
        precio -= precio * (porcentaje / 100); 
    } 
}; 

class Inventario { 
public: 
    Inventario() : productos(nullptr), cantidadProductos(0) {} 
    ~Inventario() { 
        for (int i = 0; i < cantidadProductos; ++i) { 
            delete productos[i]; 
        } 
        delete[] productos; 
    } 
    void agregarProducto(Producto* producto) { 
        Producto** nuevosProductos = new Producto*[cantidadProductos + 1]; 
        for (int i = 0; i < cantidadProductos; ++i) { 
            nuevosProductos[i] = productos[i]; 
        } 
        nuevosProductos[cantidadProductos] = producto; 
        delete[] productos; 
        productos = nuevosProductos; 
        ++cantidadProductos; 
    } 

    double calcularValorTotal() const { 
        double valorTotal = 0.0; 
        for (int i = 0; i < cantidadProductos; ++i) { 
            valorTotal += productos[i]->calcularValor(); 
        } 
        return valorTotal; 
    } 

    void aplicarDescuentoGlobal(double porcentaje) { 
        for (int i = 0; i < cantidadProductos; ++i) { 
            productos[i]->aplicarDescuento(porcentaje); 
        } 
    } 

    void mostrarInventario() const { 
        for (int i = 0; i < cantidadProductos; ++i) { 
            cout << "Producto: " << productos[i]->getNombre()  
                      << ", Precio: " << productos[i]->getPrecio()  
                      << ", Cantidad: " << productos[i]->getCantidad()  
                      << ", Valor: " << productos[i]->calcularValor() << std::endl; 
        } 
    } 

 

private: 
    Producto** productos; 
    int cantidadProductos; 
}; 

int main() { 
    
    Inventario inventario; 
    int opcion; 
    string nombre; 
    double precio; 
    int cantidad; 
    double porcentajeDescuento; 

    do { 
        cout << "Seleccione el tipo de producto para agregar al inventario:\n"; 
        cout << "1. Electronico\n"; 
        cout << "2. Ropa\n"; 
        cout << "3. Alimento\n"; 
        cout << "4. Salir\n"; 
        cout << "Opcion: "; 
        cin >> opcion; 

        if (opcion >= 1 && opcion <= 3) { 
            cout << "Ingrese el nombre del producto: "; 
            cin >> nombre; 
            cout << "Ingrese el precio del producto: "; 
            cin >> precio; 
            cout << "Ingrese la cantidad del producto: "; 
            cin >> cantidad; 
            switch (opcion) { 
                case 1: 
                    inventario.agregarProducto(new Electronico(nombre, precio, cantidad)); 
                    break; 
                case 2: 
                    inventario.agregarProducto(new Ropa(nombre, precio, cantidad)); 
                    break; 
                case 3: 
                    inventario.agregarProducto(new Alimento(nombre, precio, cantidad)); 
                    break; 
            } 
        } 
    } while (opcion != 4); 
    
    cout << "\nInventario antes del descuento:\n"; 
    inventario.mostrarInventario(); 

    cout << "\nValor total del inventario: " << inventario.calcularValorTotal() << endl; 

    cout << "\nIngrese el porcentaje de descuento a aplicar: "; 
    cin >> porcentajeDescuento; 
    
    inventario.aplicarDescuentoGlobal(porcentajeDescuento); 
    
    cout << "\nInventario después del descuento:\n"; 
    inventario.mostrarInventario(); 
    
    cout << "\nValor total del inventario después del descuento: " << inventario.calcularValorTotal() << endl; 

    return 0; 
} 
