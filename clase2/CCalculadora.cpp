#include "CCalculadora.hpp"
CCalculadora::CCalculadora(int numero1, int numero2){
    this->numero1 = numero1;
    this->numero2 = numero2;
    this->suma = new CResultado();
    this->resta = new CResultado();
    this->division = new CResultado();
    this->multiplicacion = new CResultado();
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
    cout<<this->suma->mostrar();
}
//hacemos que almacene cada vez que ejecute la operacion --> 9 (pasar a CCalculadora.hpp)
int CCalculadora::suma(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 + this->numero2;
    //almacenamos el valor del resultado en el array
    this->suma->almacenar(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::resta(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 - this->numero2;
    //almacenamos el valor del resultado en el array
    this->resta->almacenar(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::multiplicacion(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 * this->numero2;
    //almacenamos el valor del resultado en el array
    this->multiplicacion->almacenar(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::division(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 / this->numero2;
    //almacenamos el valor del resultado en el array
    this->division->almacenar(resultado);
    //retornamos el valor del resultado
    return resultado;
}
//hacemos la funcionalidad para aumentar el tamaño de los arrays --> 7
    void CCalculadora::CResultado::aumentar(){
        //creamos una variable temporal del tamaño actual del array + 1
        int *provisional = new int[this->CResultado::tamaño + 1];
        //pasamos los datos de los resultados a la variable temporal
        for (short i = 0; i < this->CResultado::tamaño; i++)
        {
            provisional[i] = this->CResultado::resultados[i];
        }
        //eliminamos de la memoria el array
        delete this->CResultado::resultados;
        //pasamos la direccion de la memoria de la variable temporal al array
        this->CResultado::resultados = provisional;
        //aumentamos en uno el tamaño del vector
        this->CResultado::tamaño++;
    };
    void CCalculadora::CResultado::almacenar(int resul){
        this->CResultado::aumentar();
        this->CResultado::resultados[this->CResultado::tamaño - 1] = resul;
    };
    CCalculadora::CResultado::CResultado(/* args */)
    {
        this->CResultado::tamaño = 0;
        this->~CResultado::resultados = new int[this->CResultado::tamaño];
    }
    string CCalculadora::CResultado::mostrar(){
        string retornar;
        for (short i = 0; i < this->CResultado::tamaño; ++i)
        {
            retornar += to_string(this->CResultado::resultados[i]) + "\t": 
        }
        return retornar;
    }
    CCalculadora::CResultado::~CResultado()
    {
        delete this->CResultado::resultados;
    }
CCalculadora::~CCalculadora(){};