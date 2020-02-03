#include <iostream>
#include<string>
using namespace std;
class CCalculadora
{
private:
    class CResultado
    {
    private:
        int* resultados;
        int tamaño;
        void aumentar();
    public:
        CResultado();
        ~CResultado();
        void almacenar(int);
        string mostrar();
    };
    //atributo = variable
    //metodo = funcion
    CResultado *suma;
    CResultado *resta;
    CResultado *division;
    CResultado *multiplicacion;
    int numero1;
    int numero2;
    //declaramos las funciones para almacenar las variables en el arreglo --> 6 (ir a CCalculadora.cpp)
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