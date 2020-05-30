//
//  Juego.h
//  yaigFinal
//
//  Created by Facundo Barafani on 28/05/2020.
//  Copyright © 2020 Facundo Barafani. All rights reserved.
//

#ifndef Juego_h
#define Juego_h

class Juego {
private:
    int **tablero;
    int tamTablero;
    int cantVidas;
    int cantBombas;
    int posJugadorX;
    int posJugadorY;
    void generarTablero();
    void llenarTablero();
    void dibujarTablero();
public:
    Juego();
    Juego(int,int,int);
    Juego(const Juego&);
    void operator=(Juego);
    int mover(char);
    int explorar(int);
    int getVidas();
    int getTamTablero();
    ~Juego();
};

#endif /* Juego_h */
