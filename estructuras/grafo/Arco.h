#ifndef _ARCO_
#define _ARCO_ 1

#include "INodo.h"

using namespace std;

class Arco {
    private:
        NodoGrafo* origen;
        NodoGrafo* destino;
        int peso;

    public:
        Arco(NodoGrafo* pOrigen, NodoGrafo* pDestino, int pPeso) {
            this->origen = pOrigen;
            this->destino = pDestino;
            this->peso = pPeso;
        }

        void* getOrigen() {
            return this->origen;
        }

        void* getDestino() {
            return this->destino;
        }

        int getPeso() {
            return this->peso;
        }
};

#endif