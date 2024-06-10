#include <iostream> 
#include <string> 
using namespace std; 

class Animal { 
public: 
    virtual void hacerSonido() { 
        cout << "Sonido de animal" << endl; 
    } 
}; 

class Perro : public Animal { 
public: 
    void hacerSonido() override { 
        cout << "Ladrido" << endl; 
    } 
}; 


int main() { 
    Animal* animal = new Perro(); 
    animal->hacerSonido();   
    delete animal; 
    return 0; 
} 
