#include <iostream> 
#include <string> 
using namespace std; 

class Animal { 

public: 
    void hacerSonido() { 
        cout << "Sonido del Animal" << endl; 
    } 
}; 

class Perro : public Animal { 
public: 
    void hacerSonido() { 
        cout << "Ladrido" << endl; 
    } 
}; 

int main() { 

    Animal* animal = new Perro(); 
    animal->hacerSonido();  
    delete animal; 
    return 0; 

} 