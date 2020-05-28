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
    int cantVidas;
    int cantBombas;
public:
    Juego();
    Juego(int **,int,int);
    Juego(const Juego&);
    void operator=(Juego);
    int Mover(char);
    int Explorar(int r);
    ~Juego();
};

#endif /* Juego_h */
