#include"CConductor.hpp"
class CBus
{
private:
    string placa;
    CConductor* conductor;
    int kilometros;
    short maxPasajeros;
public:
    CBus(string placa, CConductor* conductor, int kilometros, short maxPasajeros){
        this->placa = placa;
        this->conductor = conductor;
        this->kilometros = kilometros;
        this->maxPasajeros = maxPasajeros;
    };
    ~CBus(){
        delete conductor;
    };
    string getPlaca(){
        return this->placa;
    };
    CConductor* getConductor(){
        return this->conductor;
    };
    int getKilometros(){
        return this->kilometros;
    };
    short getMaxPasajeros(){
        return this->maxPasajeros;
    };
    void setPlaca(string placa){
        this->placa = placa;
    };
    void setConductor(CConductor* conductor){
        this->conductor = conductor;
    };
    void setKilometros(int kilometros){
        this->kilometros = kilometros;
    };
    void setMaxPasajeros(short maxPasajeros){
        this->maxPasajeros = maxPasajeros;
    };
};