// BARAFANI-DUBOWEZ

#include <stdio.h>
#include <stdlib.h>
#include "Juego.h"
#include <time.h>
#include <math.h>
#include <iostream>

using namespace std;

Juego::Juego(){
    tamTablero = 10;
    cantVidas = 3;
    cantBombas = 25;
    posJugadorX = 0;
    posJugadorY = 0;
    
    tablero = new int* [tamTablero];
    
    for (int i=0;i<tamTablero;i++){
        tablero[i] = new int[tamTablero];
    }
    
    generarTablero();
}

Juego::Juego(int tamTablero, int cantVidas, int cantBombas){
    this->tamTablero = tamTablero;
    this->cantVidas = cantVidas;
    this->cantBombas = cantBombas;
    posJugadorX = 0;
    posJugadorY = 0;
    tablero = new int* [tamTablero];
    
    for (int i=0;i<tamTablero;i++){
        tablero[i] = new int[tamTablero];
    }
    
    generarTablero();
    
}

int Juego::getVidas(){
    return cantVidas;
}

int Juego::getTamTablero(){
    return tamTablero;
}

int Juego::getPosicionX(){
    return posJugadorX;
}

int Juego::getPosicionY(){
    return posJugadorY;
}

void Juego::generarTablero(){
    
    for (int i=0;i<tamTablero;i++){
        for (int j=0;j<tamTablero;j++){
            
            tablero[i][j] = 0;
            
        }
    }
    
    tablero[posJugadorX][posJugadorY] = 1;
    
    llenarTablero();
    
}

void Juego::llenarTablero(){
    srand(time(NULL));
    
    int tx = (rand()%tamTablero);
    int ty = (rand()%tamTablero);
    tablero[tx][ty] = 3;
    
    for (int i=0;i<=cantBombas;i++){
        int x = rand()%(tamTablero);
        int y = rand()%(tamTablero);
        
        if (tablero[x][y] != 1 && tablero[x][y] != 3){
            tablero[x][y] = 2;
        }else {
            i-=1;
        }
    }
    
    dibujarTablero();
    
}

int Juego::mover(char d){
    switch(toupper(d)) {
        case 'N':
            return cambiarPosicion(-1, 0);
            break;
        case 'S':
            return cambiarPosicion(1, 0);
            break;
        case 'E':
            return cambiarPosicion(0, 1);
            break;
        case 'O':
            return cambiarPosicion(0, -1);
            break;
        default:
            return 0;
            break;
    }
}

int Juego::cambiarPosicion(int pX,int pY){
    
    if (tablero[posJugadorX+pX][posJugadorY+pY] == 0){
        tablero[posJugadorX][posJugadorY] = 0;
        posJugadorX+=pX;
        posJugadorY+=pY;
        tablero[posJugadorX][posJugadorY] = 1;
        dibujarTablero();
        return 0;
    }
    if (tablero[posJugadorX+pX][posJugadorY+pY] == 2){
        if (cantVidas>0){
            cantVidas-=1;
            tablero[posJugadorX+pX][posJugadorY+pY] = 0;
            dibujarTablero();
            return 1;
        }
        else{
            dibujarTablero();
            return 2;
        }
    }
    if (posJugadorX+pX <0 || posJugadorY+pY <0 || posJugadorX+pX > tamTablero || posJugadorY+pY > tamTablero ){
        return -1;
    }
    else {
        dibujarTablero();
        return 0;
    }
}

int Juego::explorar(int r){
    
    int contadorBombas = 0;
    
    for (int i=0;i<=r;i++){
        if (posJugadorX+i <= tamTablero && posJugadorY+i <= tamTablero) {
            if (tablero[posJugadorX+i][posJugadorY] == 2){
                contadorBombas+=1;
            }
            if (tablero[posJugadorX][posJugadorY+i] == 2){
                contadorBombas+=1;
            }
        }
        if (posJugadorX-i >= 0  && posJugadorY-i >= 0) {
            if (tablero[posJugadorX-i][posJugadorY] == 2){
                contadorBombas+=1;
            }
            if (tablero[posJugadorX][posJugadorY-i] == 2){
                contadorBombas+=1;
            }
        }
    }
    
    return contadorBombas;
}


void Juego::dibujarTablero(){
    for (int i=0;i<tamTablero;i++){
        for (int j=0;j<tamTablero;j++){
            
            cout << tablero[i][j];
            
        }
        cout << endl;
    }
}

Juego::Juego(const Juego& z){
    tamTablero = z.tamTablero;
    cantVidas = z.cantVidas;
    cantBombas = z.cantBombas;
    posJugadorX = z.posJugadorX;
    posJugadorY = z.posJugadorY;
    
    tablero = new int* [tamTablero];
    
    for (int i=0;i<=tamTablero;i++){
        for (int j=0;j<=tamTablero;j++){
            
            tablero[i][j] = z.tablero[i][j];
            
        }
    }
    
}

void Juego::operator=(Juego z ){
    tamTablero = z.tamTablero;
    cantVidas = z.cantVidas;
    cantBombas = z.cantBombas;
    
    tablero = new int* [tamTablero];
    
    for (int i=0;i<=tamTablero;i++){
        for (int j=0;j<=tamTablero;j++){
            
            tablero[i][j] = z.tablero[i][j];
            
        }
    }
    
}

Juego::~Juego(){
    delete [] tablero;
}
