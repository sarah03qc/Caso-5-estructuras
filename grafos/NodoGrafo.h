#ifndef _NODOGRAFO_
#define _NODOGRAFO_ 1
#include "Arco.h"
#include <vector>
#include "INodo.h"

using namespace std;

class NodoGrafo {
    private:
        INodo* dato;
        vector<Arco*>* listaArcos;
        int distance = 0;
        bool visitado = false;
        bool procesado = false;

    public:
        NodoGrafo(INodo* pDato) {
            this->dato = pDato;
            this->listaArcos = new vector<Arco*>();
        }

        NodoGrafo() {
            this->listaArcos = new vector<Arco*>();            
        }

        void setInfo(INodo* pDato) {
           this->dato = pDato; 
        }

        INodo* getInfo() {
            return dato;
        }

        void addArc(Arco* pArco) {
            this->listaArcos->push_back(pArco);
        }

        vector<Arco*>* getArcs() {
            return this->listaArcos;
        }

        bool getVisited() {
            return visitado;
        }

        bool getProcessed() {
            return procesado;
        }

        void setVisited(bool value) {
            this->visitado = value;
        }

        void setProcessed(bool value) {
            this->procesado = value;
        }

        int getDistance() {
            return distance;
        }

        void setDistance(int valor) {
            this->distance = valor;
        }
};

#endif