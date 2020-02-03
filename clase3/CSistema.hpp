#include "CAgente.hpp"
#include "recursos.hpp"
class CSistema
{
private:
    CAgente**agentesSeguridad = new CAgente*[nagentes];
    CBus**busSistema = new CBus*[nbuses];
    CConductor**conductorSistema = new CConductor*[nchoferes];
    CSede**sedeSistema = new CSede*[4];
    void simular(){
        for (short i = 0; i < 24; i++)
        {
            //ida
            for (short j = 0; j < 3; j++)
            {
                this->agentesSeguridad[0]->registrar(new CRegistro(obtenerfecha(i), obtenerHoraMa(), this->busSistema[j], npasajerosaleatorio(), this->sedeSistema[0], this->sedeSistema[j+1]));
            }
            //vuelta
            for (short j = 0; j < 3; j++)
            {
                this->agentesSeguridad[j + 1]->registrar(new CRegistro(obtenerfecha(i), obtenerHoraTa(), this->busSistema[j], npasajerosaleatorio(), this->sedeSistema[j + 1], this->sedeSistema[0]));
            }
            
        }
    }
public:
    CSistema(){
        iniciarestructuras();
        for (short i = 0; i < nagentes; i++)
        {
            agentesSeguridad[i] = new CAgente(agente[i].nombre, agente[i].dni);
        }
        for (short i = 0; i < nchoferes; i++)
        {
            conductorSistema[i] = new CConductor(chofer[i].nombre, chofer[i].dni);
        }
        
        for (short i = 0; i < nbuses; i++)
        {
            busSistema[i] = new CBus(bus[i].placa, this->conductorSistema[i], 0, bus[i].maxPasajeros);
        }
        for (short i = 0; i < 4; i++)
        {
            sedeSistema[i] = new CSede(sede[i].id, sede[i].nombre, sede[i].direccion);
        }
        this->simular();
    };
    ~CSistema(){
        for (short i = 0; i < nagentes; i++)
        {
            delete[] this->agentesSeguridad[i];
        }
        for (short i = 0; i < nbuses; i++)
        {
            delete[] this->busSistema[i];
        }
        for (short i = 0; i < nchoferes; i++)
        {
            delete[] this->conductorSistema[i];
        }
        for (short i = 0; i < 4; i++)
        {
            delete[] this->sedeSistema[i];
        }
        delete this->agentesSeguridad;
        delete this->busSistema;
        delete this->conductorSistema;
        delete this->sedeSistema;
    };
    void mostrarRegistros(){
        for (short i = 0; i < nagentes; i++)
        {
            cout<<"************************************"<<endl;
            cout<<"Registros de el agente: "<<this->agentesSeguridad[i]->getNombre()<<endl;
            cout<<"De la sede: "<<this->agentesSeguridad[i]->getpos(0)->getSedeOrigen()->getNombre()<<endl<<endl;
            this->agentesSeguridad[i]->mostrar();
            cout<<"************************************"<<endl;
        }
    }
    void reportePasajerosDiarios(){
        int npasajeros[3] = {0, 0, 0};
        
        //villa monte 0
        //villa sani 1
        //villa sanmi 2 

        //0 villa
        //1 monte
        //2 sani
        //3 sanmi
        for (short i = 0; i < nagentes; i++)
        {
            for (short j = 0; j < this->agentesSeguridad[i]->getTamanio(); j++)
            {
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[1]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[1] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[0] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[2]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[2] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[1] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[3]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[3] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[2] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                
            }
            
        }
        for (short i = 0; i < 24; i++)
        {
            short villa_monte, villa_sani, villa_sanmi;
            villa_monte = villa_sani = villa_sanmi = 0;
            cout<<"************************************"<<endl<<endl;
            cout<<"Dia: "<<obtenerfecha(i)<<endl<<endl;
            for (short j = 0; j < nagentes; j++)
            {
                if (this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[0]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[1]
                    ||this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[1]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[0])
                {
                    villa_monte += this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getNpasajeros();
                }
                if (this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[0]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[2]
                    ||this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[2]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[0])
                {
                    villa_sani += this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getNpasajeros();
                }
                if (this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[0]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[3]
                    ||this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeOrigen() == this->sedeSistema[3]
                    && this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getSedeDestino() == this->sedeSistema[0])
                {
                    villa_sanmi += this->agentesSeguridad[j]->registro_por_fecha(obtenerfecha(i))->getNpasajeros();
                }
            }
            cout<<"Ruta villa-monte o visceversa: "<<villa_monte<<endl;
            cout<<"Ruta villa-sani o visceversa: "<<villa_sani<<endl;
            cout<<"Ruta villa-sanmi o visceversa: "<<villa_sanmi<<endl<<endl;
            cout<<"************************************"<<endl;
        }
        
        cout<<"Cantidad de pasajeros mensuales de la ruta villa-monte o visceversa: "<<npasajeros[0]<<endl;
        cout<<"Cantidad de pasajeros mensuales de la ruta villa-sani o visceversa: "<<npasajeros[1]<<endl;
        cout<<"Cantidad de pasajeros mensuales de la ruta villa-sanmi o visceversa: "<<npasajeros[2]<<endl;
        
    }
    void reportePasajesVendidos(){
        int npasajeros[3] = {0, 0, 0};
        for (short i = 0; i < nagentes; i++)
        {
            for (short j = 0; j < this->agentesSeguridad[i]->getTamanio(); j++)
            {
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[1]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[1] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[0] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[2]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[2] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[1] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[3]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[3] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    npasajeros[2] += this->agentesSeguridad[i]->getpos(j)->getNpasajeros();
                }
                    
            }
                
        }
        cout<<"***************************************************************************************" << endl;
        cout<<"Pasajes mensuales vendidos de la ruta villa-monte o visceversa: " << npasajeros[0] * 2.5 << endl;
        cout<<"Pasajes mensuales vendidos de la ruta villa-sani o visceversa: " << npasajeros[1] * 2.5 << endl;
        cout<<"Pasajes mensuales vendidos de la ruta villa-sanmi o visceversa: " << npasajeros[2] * 2.5 << endl;
        cout<<"***************************************************************************************"<< endl;
    }
    void reporteConsumoGasolina(){
        int nviajes[3] = {0, 0, 0};
        for (short i = 0; i < nagentes; i++)
        {
            for (short j = 0; j < this->agentesSeguridad[i]->getTamanio(); j++)
            {
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[1]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[1] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    nviajes[0] += 1;
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[2]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[2] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    nviajes[1] += 1;
                }
                if (this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[0] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[3]
                    || this->agentesSeguridad[i]->getpos(j)->getSedeOrigen() == this->sedeSistema[3] 
                    && this->agentesSeguridad[i]->getpos(j)->getSedeDestino() == this->sedeSistema[0])
                {
                    nviajes[2] += 1;
                }
                    
            }
                
        }
        cout<<"***************************************************************************************" << endl;
        cout<<"Consumo de gasolina mensual de la ruta villa-monte o visceversa: " << nviajes[0] * 50 << endl;
        cout<<"Consumo de gasolina mensual de la ruta villa-sani o visceversa: " << nviajes[1] * 60 << endl;
        cout<<"Consumo de gasolina mensual de la ruta villa-sanmi o visceversa: " << nviajes[2] * 70 << endl;
        cout<<"***************************************************************************************"<< endl;
    }
};
