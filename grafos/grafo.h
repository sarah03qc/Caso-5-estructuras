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
            //1. Mark all nodes as unvisited.
            for(int i = 0; i < listaNodos.size(); i ++) {
                if(i != 0) {
                    //2. Mark the initially selected node with the current distance of 0 and the rest with infinity.
                    listaNodos[i]->setDistance(INFINITO);
                }
                listaNodos[i]->setVisited(false);
            }
            //3. Set the initial node as the current node.
            NodoGrafo *currentNode;
            currentNode = hashNodos.begin()->second;
            
            //4. For the current node, consider all of its unvisited neighbors and calculate their distances by 
            //adding the current distance of the current node to the weight of the edge that connects the current 
            //node to the neighboring node.
            for(int i = 0; i < listaNodos.size(); i++) {
                for(int j = 0; j < currentNode->getArcs()->size(); i++) {
                    int newDistance = 0;
                    if(!(static_cast<NodoGrafo*> (currentNode->getArcs()->at(j)->getDestino())->getVisited())) {
                        newDistance = currentNode->getDistance() + currentNode->getArcs()->at(j)->getPeso();

                        //5. Compare the newly calculated distance to the current distance assigned to the neighboring 
                        //node. If it is smaller, set it as the new current distance of the neighboring node otherwise, 
                        //keep the previous weight.
                        if(newDistance < (static_cast<NodoGrafo*> (currentNode->getArcs()->at(j)->getDestino()))->getDistance()) {
                            (static_cast<NodoGrafo*> (currentNode->getArcs()->at(j)->getDestino()))->setDistance(newDistance);
                        }
                    }
                }
                //6. When you’re done considering all of the unvisited neighbors of the current node, mark the current 
                //node as visited.
                currentNode->setVisited(true);

                //7. Select the unvisited node that is marked with the smallest distance, set it as the new current node, 
                //and go back to step 4.
                Arco* smallest = currentNode->getArcs()->at(0); 
                Arco* arcActual;
                for(int p = 0; p < currentNode->getArcs()->size(); p++) {
                    arcActual = smallest;
                    smallest = currentNode->getArcs()->at(p);
                    if((static_cast<NodoGrafo*> (smallest->getDestino()))->getDistance() > (static_cast<NodoGrafo*> (arcActual->getDestino()))->getDistance()) {
                        smallest = arcActual;   
                    }    
                }
                currentNode = static_cast<NodoGrafo*> (smallest->getDestino());
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