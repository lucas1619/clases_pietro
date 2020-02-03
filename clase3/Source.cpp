#include "CSistema.hpp"
int main(){
    srand(time(0));
    short numero;
    CSistema*sistema = new CSistema();
    while (true)
    {
        system("cls");
        cout<<"********************************************************"<<endl;
        cout<<"Bienvenido/a al sistema de salidas de buses de la UPC"<<endl;
        cout<<"1.- Para mostrar los registros de salidas"<<endl;
        cout<<"2.- Para mostrar los registros de salidas"<<endl;
        cout<<"3.- Para mostrar los registros de salidas"<<endl;
        cout<<"4.- Para mostrar los registros de salidas"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<"********************************************************"<<endl;
        cin>>numero;
        system("cls");
        switch (numero)
        {
        case 1:
            sistema->mostrarRegistros();
            system("pause");
            break;
        case 2:
            sistema->reportePasajerosDiarios();
            system("pause");
            break;
        case 3:
            sistema->reportePasajesVendidos();
            system("pause");
            break;
        case 4:
            sistema->reporteConsumoGasolina();
            system("pause");
            break;
        }
        if (numero == 5)
        {
            break;
        }
        if (numero >= 6 || numero <= 0)
        {
            cout<<"Ingrese una opcion valida"<<endl;
        }
    }
    system("cls");
    return 0;
    delete sistema;
}