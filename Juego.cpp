//
//  Juego.cpp
//  yaigFinal
//
//  Created by Facundo Barafani on 28/05/2020.
//  Copyright © 2020 Facundo Barafani. All rights reserved.
//

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
            if (tablero[posJugadorX+1][posJugadorY] == 0){
                posJugadorX+=1;
                tablero[posJugadorX][posJugadorY] = 1;
                dibujarTablero();
                return 0;
            }
            else if (tablero[posJugadorX+1][posJugadorY] == 2){
                if (cantVidas>0){
                    cantVidas-=1;
                    dibujarTablero();
                    return 1;
                }
                else{
                    dibujarTablero();
                    return 2;
                }
            }
            else {
                return 3;
            }
            return 0;
            break;
        case 'S':
            if (tablero[posJugadorX-1][posJugadorY] == 0){
                posJugadorX-=1;
                tablero[posJugadorX][posJugadorY] = 1;
                return 0;
            }
            else if (tablero[posJugadorX-1][posJugadorY] == 2){
                if (cantVidas>0){
                    cantVidas-=1;
                    return 1;
                }
                else{
                    return 2;
                }
            }
            else {
                return 3;
            }
            return 0;
            break;
        case 'E':
            if (tablero[posJugadorX][posJugadorY-1] == 0){
                posJugadorY-=1;
                tablero[posJugadorX][posJugadorY] = 1;
                return 0;
            }
            else if (tablero[posJugadorX][posJugadorY-1] == 2){
                if (cantVidas>0){
                    cantVidas-=1;
                    return 1;
                }
                else{
                    return 2;
                }
            }
            else {
                return 3;
            }
            return 0;
            break;
        case 'O':
            if (tablero[posJugadorX][posJugadorY+1] == 0){
                posJugadorY+=1;
                tablero[posJugadorX][posJugadorY] = 1;
                return 0;
            }
            else if (tablero[posJugadorX][posJugadorY+1] == 2){
                if (cantVidas>0){
                    cantVidas-=1;
                    return 1;
                }
                else{
                    return 2;
                }
            }
            else {
                return 3;
            }
            return 0;
            break;
        default:
            return 1;
    }
}

int Juego::explorar(int r){
    
    int contadorBombas = 0;
    
    for (int i=0;i<=r;i++){
        for (int j=0;j<=r;j++){
            if (tablero[posJugadorX+i][posJugadorY+j] == 2){
                contadorBombas+=1;
            }
        }
    }
    
//        for (int i=-r;i<=r;i++){
//            for (int j=-r;j<=r;j++){
//                if (tablero[posJugadorX+i][posJugadorY+j] == 2 && posJugadorX+i >= 0 && posJugadorY+j >= 0 ){
//                    contadorBombas+=1;
//                }
//            }
//        }
    
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
