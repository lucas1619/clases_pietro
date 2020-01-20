#include "CCalculadora.hpp"
CCalculadora::CCalculadora(){
    this->numero1 = numero1;
    this->numero2 = numero2;
}
int CCalculadora::getNumero1(){
    return this->numero1;
}
int CCalculadora::getNumero2(){
    return this->numero2;
}
void CCalculadora::setNumero1(int numero1){
    this->numero1 = numero1;
}
void CCalculadora::setNumero2(int numero2){
    this->numero2 = numero2;
}
void CCalculadora::resultado(){
    cout<<"Suma: " << this->suma();
    cout<<"Resta: " << this->resta();
    cout<<"Multi: " << this->multiplicacion();
    cout<<"Divi: " << this->division();
}
int CCalculadora::suma(){
    return this->numero1 + this->numero2;
}
int CCalculadora::resta(){
    return this->numero1 - this->numero2;
}
int CCalculadora::multiplicacion(){
    return this->numero1 * this->numero2;
}
int CCalculadora::division(){
    return this->numero1 / this->numero2;
}
CCalculadora::~CCalculadora(){};