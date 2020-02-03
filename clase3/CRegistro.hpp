#include "CSede.hpp"
#include "CBus.hpp"
class CRegistro
{
private:
    string fecha;
    string hora;
    CBus* bus;
    int npasajeros;
    CSede* sedeOrigen;
    CSede* sedeDestino;
public:
    CRegistro(string fecha, string hora, CBus* bus, int npasajeros, CSede* sedeOrigen, CSede* sedeDestino){
        this->fecha = fecha;
        this->hora = hora;
        this->bus = bus;
        this->npasajeros = npasajeros;
        this->sedeOrigen = sedeOrigen;
        this->sedeDestino = sedeDestino;
    };
    ~CRegistro(){
        delete this->bus;
        delete this->sedeOrigen;
        delete this->sedeDestino;
    };
    string getFecha(){
        return this->fecha;
    };
    string getHora(){
        return this->hora;
    };
    CBus* getBus(){
        return this->bus;
    };
    int getNpasajeros(){
        return this->npasajeros;
    };
    CSede* getSedeOrigen(){
        return this->sedeOrigen;
    };
    CSede* getSedeDestino(){
        return this->sedeDestino;
    };
    void setFecha(string fecha){
        this->fecha = fecha;
    };
    void setHora(string hora){
        this->hora = hora;
    };
    void setBus(CBus* bus){
        this->bus = bus;
    };
    void setNpasajeros(int npasajeros){
        this->npasajeros = npasajeros;
    };
    void setSedeOrigen(CSede* sedeOrigen){
        this->sedeOrigen = sedeOrigen;
    };
    void setSedeDestino(CSede* sedeDestino){
        this->sedeDestino = sedeDestino;
    };
};