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
    this->tamTablero = 10;
    this->cantVidas = 3;
    this->cantBombas = 25;
    
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
    llenarTablero();
    
}

void Juego::llenarTablero(){
    srand(time(NULL));
    
    int tx = (rand()%tamTablero);
    int ty = (rand()%tamTablero);
    tablero[tx][ty] = 3;
    
    for (int i=0;i<=cantBombas;i++){
        int x = (rand()%tamTablero);
        int y = (rand()%tamTablero);
        tablero[x][y] = 1;
    }
    
    dibujarTablero();
    
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
