#include <iostream>
using namespace std;
class CCalculadora
{
private:
    //atributo = variable
    //metodo = funcion
    int numero1;
    int numero2;
    //declaramos los arrays en memoria dinamica --> 1
    int* resultados_suma;
    int* resultados_resta;
    int* resultados_multi;
    int* resultados_divi;
    //declaramos el tamaño de los arreglos --> 2 (ir a CCalculadora.cpp)
    short tamaño_resul_suma;
    short tamaño_resul_resta;
    short tamaño_resul_multi;
    short tamaño_resul_divi;
    //declaramos las funciones para aumentar el tamaño de los arrays --> 5
    void aumentar_resul_suma();
    void aumentar_resul_resta();
    void aumentar_resul_multi();
    void aumentar_resul_divi();
    //declaramos las funciones para almacenar las variables en el arreglo --> 6 (ir a CCalculadora.cpp)
    void almacenar_resul_suma(int);
    void almacenar_resul_resta(int);
    void almacenar_resul_multi(int);
    void almacenar_resul_divi(int);
    int suma();
    int resta();
    int multiplicacion();
    int division();
public:
    CCalculadora(int, int);//constructor
    ~CCalculadora();//destructor
    void resultado();
    int getNumero1();
    int getNumero2();
    void setNumero1(int);
    void setNumero2(int);
};