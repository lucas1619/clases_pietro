#include<iostream>
#include<string>
using namespace std;
class CConductor
{
private:
    string nombre;
    short dni;
public:
    CConductor(string nombre, int dni){
        this->nombre = nombre;
        this->dni = dni;
    }
    ~CConductor(){};
    string getNombre(){
        return this->nombre;
    }
    int getDni(){
        return this->dni;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setDni(int dni){
        this->dni = dni;
    }
};