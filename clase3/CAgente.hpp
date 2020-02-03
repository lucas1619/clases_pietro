#include "CRegistro.hpp"
class CAgente
{
private:
    int tamanio;
    CRegistro** arrRegistro = new CRegistro*[0];
    string nombre;
    int dni;
public:
    CAgente(string nombre, int dni){
        this->tamanio = 0;
        this->nombre = nombre;
        this->dni = dni;
    };
    ~CAgente(){
        for (short i = 0; i < this->tamanio; i++)
        {
            delete[] this->arrRegistro[i];
        }
        delete this->arrRegistro;
    };
    void registrar(CRegistro* registroNuevo){
        CRegistro**provisional = new CRegistro*[this->tamanio + 1];
        for (short i = 0; i < this->tamanio; i++)
        {
            provisional[i] = this->arrRegistro[i];
        }
        provisional[this->tamanio] = registroNuevo;
        delete this->arrRegistro;
        this->arrRegistro = provisional;
        ++this->tamanio;
    }
    void mostrar(){
        for (short i = 0; i < this->tamanio; i++)
        {
            cout << "Registro nro: " << i + 1 << endl;
            cout << "Agente responsable: " << this->nombre << endl;
            cout << "Fecha de salida: " << arrRegistro[i]->getFecha() << endl;
            cout << "Hora de salida: " << arrRegistro[i]->getHora() << endl;
            cout << "Sede de origen: " << arrRegistro[i]->getSedeOrigen()->getNombre() << endl;
            cout << "Sede de destino: " << arrRegistro[i]->getSedeDestino()->getNombre() << endl;
            cout << "Placa del bus: " << arrRegistro[i]->getBus()->getPlaca() << endl;
            cout << "Nombre del conductor: " << arrRegistro[i]->getBus()->getConductor()->getNombre() << endl;
            cout << "Número de pasajeros: " << arrRegistro[i]->getNpasajeros() << endl<<endl;
        }
    }
    void eliminar(){
        for (short i = 0; i < this->tamanio; i++)
        {
            delete[] this->arrRegistro[i];
        }
        delete this->arrRegistro;
        this->tamanio = 0;
    }
    CRegistro* getpos(short pos){
        return this->arrRegistro[pos];
    }
    CRegistro* registro_por_fecha(string fecha){
        CRegistro* retornar;
        for (short i = 0; i < this->tamanio; i++)
        {
            if (this->arrRegistro[i]->getFecha() == fecha)
            {
                retornar = this->arrRegistro[i];
                break; 
            }
        }
        return retornar;
    }
    string getNombre(){
        return this->nombre;
    };
    int getDni(){
        return this->dni;
    };
    void setNombre(string nombre){
        this->nombre = nombre;
    };
    void setDni(int dni){
        this->dni = dni;
    };
    int getTamanio(){
        return this->tamanio;
    }
};