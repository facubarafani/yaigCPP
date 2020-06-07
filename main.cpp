// BARAFANI-DUBOWEZ

#include <iostream>
#include <iostream>
#include "Juego.h"

using namespace std;

int main() {
//    int tamTablero;
//    int cantVidas;
//    int cantBombas;
    int accion;
    int sesion = 0;
    int radio;
    char movimiento;
    cout << "YAIG"<<endl;
    
//    cout << "Ingrese el tamaño del tablero a continuación:"<<endl;
//    cin >> tamTablero;
//
//    cout << "Ingrese la cantidad de vidas:"<<endl;
//    cin >> cantVidas;
//
//    cout << "Ingrese la cantidad de bombas:"<<endl;
//    cin >> cantBombas;
    
//    Juego(tamTablero,cantVidas,cantBombas);
    Juego a;
    

    
    while (sesion == 0){
    cout << "Que desea accion desea realizar? "<<endl;
    cout << "1) Mover \n2) Explorar \n >";
    cin >> accion;
        
    if (accion == 1){
        cout << "En que sentido desea moverse? Por ej: Si desea moverse hacia al norte ingrese N a continuacion: \n >";
        cin >> movimiento;
        int resultado = a.mover(movimiento);
        if (resultado == 2){
            sesion = 1;
        }
        if (resultado == 3){
            sesion = 0;
            cout << "Encontraste el tesoro! Ganaste!" << endl;
        }
        if (resultado == -1){
            cout << "Error! No se puede realizar ese movimiento!" << endl;
        }
        else {
            cout << "Estas en la posicion ("<<a.getPosicionX()<<","<<a.getPosicionY()<<")"<<endl;
            cout << "Tiene "<<a.getVidas()<<" vidas restantes"<<endl;
        }
    }
        
    if (accion == 2){
        cout << "Eliga el radio en el cual desea explorar: \n >";
        cin >> radio;
        cout << "En un radio de "<<radio<<" hay "<<a.explorar(radio)<< " bombas"<<endl;
    }
        
    }
}
