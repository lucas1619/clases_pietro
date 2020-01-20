#include <iostream>
using namespace std;
class calculadora
{
private:
    //atributo = variable
    //metodo = funcion
    int numero1;
    int numero2;
    int suma(){
        return this->numero1 + this->numero2;
    }
    int resta(){
        return this->numero1 - this->numero2;
    }
    int multiplicacion(){
        return this->numero1 * this->numero2;
    }
    int division(){
        return this->numero1 / this->numero2;
    }
public:
    calculadora(int numero1, int numero2){
        this->numero1 = numero1;
        this->numero2 = numero2;
    };//constructor
    ~calculadora(){};//destructor
    void resultado(){
        std::cout<<"Suma: " << this->suma();
        std::cout<<"Resta: " << this->resta();
        std::cout<<"Multi: " << this->multiplicacion();
        std::cout<<"Divi: " << this->division();
    }
    int getNumero1(){
        return numero1;
    }
    int getNumero2(){
        return numero2;
    }
    void setNumero1(int numero1){
        this->numero1 = numero1;
    }
    void setNumero2(int numero2){
        this->numero2 = numero2;
    }
};
int main(){
    calculadora *casio = new calculadora(20,10);
    std::cout << casio->resultado();
}