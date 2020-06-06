
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
    int cambiarPosicion(int,int);
public:
    Juego();
    Juego(int,int,int);
    Juego(const Juego&);
    void operator=(Juego);
    int mover(char);
    int explorar(int);
    int getVidas();
    int getTamTablero();
    int getPosicionX();
    int getPosicionY();
    ~Juego();
};

#endif /* Juego_h */
