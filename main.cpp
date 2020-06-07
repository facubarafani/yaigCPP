// BARAFANI-DUBOWEZ

#include <iostream>
#include <iostream>
#include "Juego.h"

using namespace std;

int main() {
    int tamTablero;
    int cantVidas;
    int cantBombas;
    int accion;
    int sesion = 0;
    int radio;
    char movimiento;
    cout << "YAIG"<<endl;
    cout << "Ingrese el tamaño del tablero a continuación:"<<endl;
    do{
    cin >> tamTablero;
        if (tamTablero <= 1) cout << "Error! Tamaño del tablero muy pequeño! \n Ingrese un valor nuevamente: "<<endl;
    }while(tamTablero<=1);
    cout << "Ingrese la cantidad de vidas:"<<endl;
    cin >> cantVidas;

    cout << "Ingrese la cantidad de bombas:"<<endl;
    cin >> cantBombas;
    
    Juego a(tamTablero,cantVidas,cantBombas);
    
    while (sesion == 0){
    cout << "Que accion desea realizar? "<<endl;
    cout << "1) Mover \n2) Explorar \n >";
    cin >> accion;
        
    if (accion == 1){
        cout << "En que sentido desea moverse? Por ej: Si desea moverse hacia al norte ingrese N a continuacion: \n >";
        cin >> movimiento;
        int resultado = a.mover(movimiento);
        if (resultado == 2){
            cout << "Perdiste! :C"<<endl;
            sesion = 1;
            break;
        }
        if (resultado == 3){
            cout << "Encontraste el tesoro! Ganaste! :D" << endl;
            sesion = 0;
            break;
        }
        if (resultado == -1){
            cout << "Error! No se puede realizar ese movimiento!" << endl;
        }
        else {
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
