#include <iostream>
using namespace std;
class CCalculadora
{
private:
    //atributo = variable
    //metodo = funcion
    int numero1;
    int numero2;
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