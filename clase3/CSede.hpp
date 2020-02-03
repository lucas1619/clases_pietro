#include<iostream>
#include<string>
using namespace std;
class CSede
{
private:
    int ID;
    string nombre;
    string direccion;
public:
    CSede(int ID, string nombre, string direccion){
        this->ID = ID;
        this->nombre = nombre;
        this->direccion = direccion;
    };
    ~CSede(){};
    int getID(){
        return this->ID;
    };
    string getNombre(){
        return this->nombre;
    };
    string getDireccion(){
        return this->direccion;
    };
    void setID(int ID){
        this->ID = ID;
    };
    void setNombre(string nombre){
        this->nombre = nombre;
    };
    void setDireccion(string direccion){
        this->direccion = direccion;
    };
};