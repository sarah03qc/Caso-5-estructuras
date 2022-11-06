#ifndef _GRAFO_
#define _GRAFO_ 1
#include <vector>
#include "NodoGrafo.h"
#include "INodo.h"
#include <map>
#include <queue>
#include "Arco.h"
#include <iostream>
#define INFINITO 99999999

using namespace std;

class Grafo {
    private:
        vector<NodoGrafo*> listaNodos;
        bool esDirigido = true;
        std::map<int,NodoGrafo*> hashNodos;


        void resetNodes() {
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                actual->setProcessed(false);
                actual->setVisited(false);
            }
        }

        NodoGrafo* findNotVisited() {
            NodoGrafo* result = nullptr;
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                if (!actual->getVisited()) {
                    result = actual;
                    break;
                }
            }
            return result;
        }

    public:
        Grafo(bool pDirigido) {
            this->esDirigido =  pDirigido;
        }

        int getSize() {
            return this->listaNodos.size();
        }

        void addNode(INodo* pNodo) {
            NodoGrafo* nuevoNodo = new NodoGrafo(pNodo);
            this->listaNodos.push_back(nuevoNodo);
            hashNodos.insert(pair<int,NodoGrafo*>(pNodo->getId(),nuevoNodo));
        }

        void addArc(NodoGrafo* pOrigen, NodoGrafo* pDestino) {
            this->addArc(pOrigen, pDestino, 0);
        }

        void addArc(NodoGrafo* pOrigen, NodoGrafo* pDestino, int pPeso) {
            Arco* newArc = new Arco(pOrigen, pDestino, pPeso);

            pOrigen->addArc(newArc);
            if (!this->esDirigido) {
                Arco* reverseArc =  new Arco(pDestino, pOrigen , pPeso);
                pDestino->addArc(reverseArc);
            }
        }

        void addArc(INodo* pOrigen, INodo* pDestino) {
            this->addArc(pOrigen->getId(), pDestino->getId(), 0);
        }

        void addArc(INodo* pOrigen, INodo* pDestino, int pPeso) {
            this->addArc(pOrigen->getId(), pDestino->getId(), pPeso);
        }

        void addArc(int pOrigen, int pDestino) {
            this->addArc(pOrigen, pDestino, 0);
        }

        void addArc(int pOrigen, int pDestino, int pPeso) {
            this->addArc(this->getNodo(pOrigen), this->getNodo(pDestino), pPeso);
        }

        NodoGrafo* getNodo(int pId) { 
            return hashNodos.at(pId);
        }

        vector<INodo> deepPath(INodo* pOrigen) {  //recorrido en profundidad
            vector<INodo> result;

            return result;
        } 

        vector<INodo*> broadPath(INodo* pOrigen) {
            vector<INodo*> result;
            queue<NodoGrafo*> nodosProcesados;
            int visitados = 0;
            
            resetNodes();

            NodoGrafo* puntoPartida = this->getNodo(pOrigen->getId());
            nodosProcesados.push(puntoPartida);
            puntoPartida->setProcessed(true);
            
            do {
                while (!nodosProcesados.empty()) {
                    NodoGrafo* actual = nodosProcesados.front();
                    nodosProcesados.pop();

                    actual->setVisited(true);
                    visitados++;
                    result.push_back(actual->getInfo());

                    vector<Arco*> *adyacentes = actual->getArcs();

                    for (int indiceArcos=0; indiceArcos<adyacentes->size(); ++indiceArcos) {
                        Arco* arco = adyacentes->at(indiceArcos);
                        NodoGrafo* adyacente = (NodoGrafo*)arco->getDestino();
                        if (!adyacente->getProcessed()) {
                            nodosProcesados.push(adyacente);
                            adyacente->setProcessed(true);
                        }
                    }
                }

                if (visitados<this->getSize()) {
                    puntoPartida = this->findNotVisited();
                    nodosProcesados.push(puntoPartida);
                    puntoPartida->setProcessed(true);
                }
            } while (visitados<this->getSize()); 

            return result;
        }


        vector<INodo> path(INodo* pOrigen, INodo* pDestino) { // debe retornar un camino, el primero que encuentre estre el nodo oriegn y destino
            // en caso de que no haya camino, result se retorna vacío
            vector<INodo> result;

            return result;
        }

        void dijkstra() {
            vector<NodoGrafo*> visited;
            vector<NodoGrafo*> unvisited;
            for(int i = 0; i < listaNodos.size(); i ++) {
                if(i != 0) {
                    //dejar la primera en cero
                    //el resto a infinito
                    listaNodos[i]->setDistance(INFINITO);
                }
                listaNodos[i]->setVisited(false);
                unvisited.push_back(listaNodos[i]);
            }
            NodoGrafo *start;
            NodoGrafo *current;
            Arco* smallest = start->getArcs()->at(0); 
            Arco* arcActual;
            int distancia = 0;
            while(unvisited.size() > 0) {
                int cont = 0;
                for(std::map<int, NodoGrafo *>::iterator es=hashNodos.begin(); es!=hashNodos.end(); ++es) {
                    if(cont == 0) {
                        start = es->second;  //para tomar el primer valor del map, o sea el mas pequenio
                        cont++;
                    } else {
                        break;
                    }
                }
                for(int i = 0; i < start->getArcs()->size(); i++) {
                    arcActual = smallest;
                    smallest = start->getArcs()->at(i);
                    if(smallest->getPeso() > arcActual->getPeso()) {
                        smallest = arcActual;   //para tomar el de menor peso 
                        current = static_cast<NodoGrafo*> (smallest->getDestino());  
                    }    
                } 
                for(int i = 0; i < current->getArcs()->size(); i++) {
                    NodoGrafo *temporal;
                    if(!(static_cast<NodoGrafo*> (current->getArcs()->at(i)->getDestino())->getVisited())) {
                        //aca hay que ir hacia atras calculando las distancias de cada de los nodos que acabamos
                        //de recorrer e ir sumando dichas distancias en variable local distancia
                        //when temporal == start, si variable distancia es menor que la distancia actual del nodo
                        //(que en muchos casos puede ser infinito) then la variable distancia se le asigna al 
                        //vecino de current (current->getArcs()->at(i)->getDestino())
                        //en setDistance 
                    }
                }
                current->setDistance(min(current->getDistance(), smallest->getPeso())); //cuando ya tenemos el mas pequeno lo asignamos  
                //pero preguntando si es menor que la distancia actual, que aveces va a ser infinito y sera reemplazado
            }
        }

        void printCounters() {
            for (std::vector<NodoGrafo*>::iterator current = listaNodos.begin() ; current != listaNodos.end(); ++current) {
                NodoGrafo* actual = (*current);
                cout << actual->getInfo()->getId() << " tiene " << actual->getArcs()->size() << endl;
            }
        }
};

#endif