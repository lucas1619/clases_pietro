#include<iostream>
#include<string>
#include<ctime>
//van a haber 4 agentes, uno por cada sede
//3 buses y 3 choferes
const short nagentes = 4;
const short nbuses = 3;
const short nchoferes = 3;
struct agentes
{
    string nombre;
    int dni;
}agente[nagentes];
struct buses
{
    string placa;
    int maxPasajeros;
}bus[nbuses];
struct choferes
{
    string nombre;
    short dni;
}chofer[nchoferes];
struct sedes
{
    int id;
    string nombre;
    string direccion;
}sede[4];
void iniciarestructuras(){
    string nombresAgentes[nagentes] ={ "Juanito Alimaña", "Pedro Navaja", "Harry Potter", "Ron Weasley"};
    for (short i = 0; i < nagentes; i++)
    {
        agente[i].nombre = nombresAgentes[i];
        agente[i].dni = rand()%(100000000 - 10000000 + 1) + 10000000;
    }
    for (short i = 0; i < nbuses; i++)
    { 
        string letras;
        for (short i = 0; i < 3; i++)
        {
            letras.push_back(char(rand()%(90-65+1) + 65));
        }
        string numeros = to_string(rand()%(1000-100+1) + 100);
        bus[i].placa = letras + "-" + numeros;
        bus[i].maxPasajeros = 50;
    }
    string nombresChoferes[nchoferes] = { "Paolinlinlin Guerrero", "Jefferson Cachos Farfan", "Cristian Borracho Cueva" };
    for (short i = 0; i < nchoferes; i++)
    {
        chofer[i].nombre = nombresChoferes[i];
        agente[i].dni = rand()%(100000000 - 10000000 + 1) + 10000000;
    }
    string nombreSedes[4] = { "Villa", "Monterrico", "San Isidro", "San Miguel" };
    string direccionSedes[4] = { "Direccion Villa", "Direccion Monte", "Direccion San Isidro", "Direccion San Miguel" };
    for (short i = 0; i < 4; i++)
    {
        sede[i].id = i+1;
        sede[i].nombre = nombreSedes[i];
        sede[i].direccion = direccionSedes[i];
    }
}
string obtenerfecha(short indice){
    string fecha;
    if(indice >= 0 && indice<= 5){
        fecha = to_string(indice + 1) +  "/02/2020";
    }
    else if(indice >= 6 && indice<= 11)
    {
        fecha = to_string(indice + 2) +  "/02/2020";
    }
    else if(indice >= 12 && indice<= 17)
    {
        fecha = to_string(indice + 3) +  "/02/2020";
    }
    else if(indice >= 18 && indice<= 23)
    {
        fecha = to_string(indice + 4) +  "/02/2020";
    }
    else
    {
        fecha = "fecha fuera del rango";
    }
    
    return fecha;
}
string obtenerHoraMa(){
    short horas = rand()%(14 - 9 + 1) + 9;
    short minutos = rand()%(60 - 0 + 1) + 0;
    short segundos = rand()%(60 - 0 + 1) + 0;
    string hora = to_string(horas) + ":" + to_string(minutos) + ":" + to_string(segundos);
    return hora;
}
string obtenerHoraTa(){
    short horas = rand()%(22 - 17 + 1) + 17;
    short minutos = rand()%(60 - 0 + 1) + 0;
    short segundos = rand()%(60 - 0 + 1) + 0;
    string hora = to_string(horas) + ":" + to_string(minutos) + ":" + to_string(segundos);
    return hora;
}
short npasajerosaleatorio(){
    return rand()%(50-5+1)+5;
}