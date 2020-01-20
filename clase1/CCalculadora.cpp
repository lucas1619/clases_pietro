#include "CCalculadora.hpp"
CCalculadora::CCalculadora(){
    this->numero1 = numero1;
    this->numero2 = numero2;
    //inicializamos el tamaño de los arrays en 0 --> 3
    this->tamaño_resul_suma = this->tamaño_resul_resta = this->tamaño_resul_multi = this->tamaño_resul_divi = 0;
    //inicializamos los arrays --> 4 (ir a CCalculadora.hpp)
    this->resultados_suma = new int[this->tamaño_resul_suma];
    this->resultados_resta = new int[this->tamaño_resul_resta];
    this->resultados_multi = new int[this->tamaño_resul_multi];
    this->resultados_divi = new int[this->tamaño_resul_divi];
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
//hacemos que almacene cada vez que ejecute la operacion --> 9 (pasar a CCalculadora.hpp)
int CCalculadora::suma(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 + this->numero2;
    //almacenamos el valor del resultado en el array
    this->almacenar_resul_suma(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::resta(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 - this->numero2;
    //almacenamos el valor del resultado en el array
    this->almacenar_resul_resta(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::multiplicacion(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 * this->numero2;
    //almacenamos el valor del resultado en el array
    this->almacenar_resul_multi(resultado);
    //retornamos el valor del resultado
    return resultado;
}
int CCalculadora::division(){
    //le asignamos el resultado de la operacion a una variable
    int resultado = this->numero1 / this->numero2;
    //almacenamos el valor del resultado en el array
    this->almacenar_resul_divi(resultado);
    //retornamos el valor del resultado
    return resultado;
}
//hacemos la funcionalidad para aumentar el tamaño de los arrays --> 7
    void CCalculadora::aumentar_resul_suma(){
        //creamos una variable temporal del tamaño actual del array + 1
        int *provisional = new int[this->tamaño_resul_suma + 1];
        //pasamos los datos de los resultados a la variable temporal
        for (short i = 0; i < this->tamaño_resul_suma; i++)
        {
            provisional[i] = this->resultados_suma[i];
        }
        //eliminamos de la memoria el array
        delete this->resultados_suma;
        //pasamos la direccion de la memoria de la variable temporal al array
        this->resultados_suma = provisional;
        //aumentamos en uno el tamaño del vector
        this->tamaño_resul_suma++;
    };
    void CCalculadora::aumentar_resul_resta(){
        //creamos una variable temporal del tamaño actual del array + 1
        int *provisional = new int[this->tamaño_resul_resta + 1];
        //pasamos los datos de los resultados a la variable temporal
        for (short i = 0; i < this->tamaño_resul_resta; i++)
        {
            provisional[i] = this->resultados_resta[i];
        }
        //eliminamos de la memoria el array
        delete this->resultados_resta;
        //pasamos la direccion de la memoria de la variable temporal al array
        this->resultados_resta = provisional;
        //aumentamos en uno el tamaño del vector
        this->tamaño_resul_resta++;
    };
    void CCalculadora::aumentar_resul_multi(){
        //creamos una variable temporal del tamaño actual del array + 1
        int *provisional = new int[this->tamaño_resul_multi + 1];
        //pasamos los datos de los resultados a la variable temporal
        for (short i = 0; i < this->tamaño_resul_multi; i++)
        {
            provisional[i] = this->resultados_multi[i];
        }
        //eliminamos de la memoria el array
        delete this->resultados_multi;
        //pasamos la direccion de la memoria de la variable temporal al array
        this->resultados_multi = provisional;
        //aumentamos en uno el tamaño del vector
        this->tamaño_resul_multi++;
    };
    void CCalculadora::aumentar_resul_divi(){
        //creamos una variable temporal del tamaño actual del array + 1
        int *provisional = new int[this->tamaño_resul_divi + 1];
        //pasamos los datos de los resultados a la variable temporal
        for (short i = 0; i < this->tamaño_resul_divi; i++)
        {
            provisional[i] = this->resultados_divi[i];
        }
        //eliminamos de la memoria el array
        delete this->resultados_divi;
        //pasamos la direccion de la memoria de la variable temporal al array
        this->resultados_divi = provisional;
        //aumentamos en uno el tamaño del vector
        this->tamaño_resul_divi++;
    };
    //hacemos la funcionalidad para almacenar las variables en el arreglo --> 8 (ir a la funcion suma)
    void CCalculadora::almacenar_resul_suma(int resul){
        //aumentamos en uno el tamaño del array
        this->aumentar_resul_suma();
        //pasamos el resultado a la ultima posicion del array
        this->resultados_suma[this->tamaño_resul_suma - 1] = resul;
    };
    void CCalculadora::almacenar_resul_resta(int resul){
        //aumentamos en uno el tamaño del array
        this->aumentar_resul_resta();
        //pasamos el resultado a la ultima posicion del array
        this->resultados_resta[this->tamaño_resul_resta - 1] = resul;
    };
    void CCalculadora::almacenar_resul_multi(int resul){
        //aumentamos en uno el tamaño del array
        this->aumentar_resul_multi();
        //pasamos el resultado a la ultima posicion del array
        this->resultados_multi[this->tamaño_resul_multi - 1] = resul;
    };
    void CCalculadora::almacenar_resul_divi(int resul){
        //aumentamos en uno el tamaño del array
        this->aumentar_resul_divi();
        //pasamos el resultado a la ultima posicion del array
        this->resultados_divi[this->tamaño_resul_divi - 1] = resul;
    };
CCalculadora::~CCalculadora(){};