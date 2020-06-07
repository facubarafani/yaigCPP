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
    int repeticion = 0;
    do {
    cout << "YAIG"<<endl;
    cout << "Ingrese el tamaño del tablero a continuación:"<<endl;
    do{
    cin >> tamTablero;
        if (tamTablero <= 1) cout << "Error! Tamaño del tablero muy pequeño! \n Ingrese un valor nuevamente: "<<endl;
    }while(tamTablero<=1);
    cout << "Ingrese la cantidad de vidas:"<<endl;
    do{
    cin >> cantVidas;
         if (cantVidas < 1) cout << "Error! No puedes jugar con menos de una vida! \n Ingrese un valor nuevamente: "<<endl;
    }while(cantVidas<1);
    cout << "Ingrese la cantidad de bombas:"<<endl;
    do {
    cin >> cantBombas;
        if (cantBombas < 1) cout << "Error! No puedes jugar con menos de una bombas! \n Ingrese un valor nuevamente: "<<endl;
    }while(cantBombas<1);
    
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
        cout << "Desea volver a jugar? Ingrese 1 \n Si desea salir ingrese 0"<<endl;
        cin >> repeticion;
        if (repeticion == 0){
            cout << "Hasta la proxima!"<<endl;
            break;
        }
    }while (repeticion = 1);
}
