#include <iostream>
#include "grafo.h"
#include "Persona.h"
#include "WebApp.h"
#include "NodoGrafo.h"
#include "INodo.h"
#include <vector>

using namespace std;

int main() {

    Grafo grafo1(true);

    INodo *node1 = new INodo();
    INodo *node2 = new INodo();
    INodo *node3 = new INodo();
    INodo *node4 = new INodo();

    node1->setId(8);
    node2->setId(2);
    node3->setId(5);
    node4->setId(1);

    grafo1.addNode(node1);
    grafo1.addNode(node2);
    grafo1.addNode(node3);
    grafo1.addNode(node4);

    grafo1.addArc(node1, node2, 7);
    grafo1.addArc(node2, node3, 5);
    grafo1.addArc(node3, node4, 15);
    grafo1.addArc(node4, node2, 3);
    grafo1.addArc(node1, node4, 2);

    grafo1.dijkstra();

/*
    // Ejercicio #1: 
    Grafo grafo1(true);

    Persona ana;
    ana.setNombre("Ana");

    Persona juan;
    juan.setNombre("Juan");

    grafo1.addNode(&ana);
    grafo1.addNode(&juan);

    grafo1.addArc(&ana, &juan);

    cout << "Ejercio de recorrido en anchura testeando creacion de arcos" << endl;

    WebApp ig = WebApp(5, "IG");
    WebApp twi = WebApp(10, "Twitter");
    WebApp flu = WebApp(4, "Flutter");
    WebApp of = WebApp(7, "Onlyfans");
    WebApp face = WebApp(15, "Facebook");
    WebApp allapps[] = {ig, twi, flu, of, face};

    Grafo grafoApps(true);

    for(int i=0; i<5; i++) {
        grafoApps.addNode(&allapps[i]);
    }

    NodoGrafo* origen = grafoApps.getNodo(5);
    NodoGrafo* destino = grafoApps.getNodo(10);

    grafoApps.addArc(origen, destino, 3);
    grafoApps.addArc(10, 15, 9);
    grafoApps.addArc(&of, &ig, 1); 
    grafoApps.addArc(7, 10, 4);
    grafoApps.addArc(10, 7, 3);
    grafoApps.addArc(7, 4, 6);
    grafoApps.addArc(&face, &flu, 8);

    vector<INodo*> result = grafoApps.broadPath(&ig);

    for(int i=0; i<result.size(); i++) {
        WebApp dato = *((WebApp*)(void*)result[i]);
        cout << dato.getId() << " " << dato.getNombre() << endl;
    }


    /// segundo grafo

    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
    Grafo grafoNoConexo(true);

    for(int i=0; i<5; i++) {
        grafoNoConexo.addNode(&allapps[i]);
    }

    grafoNoConexo.addArc(&flu, &ig, 3);
    grafoNoConexo.addArc(&ig, &flu , 4);
    grafoNoConexo.addArc(&ig, &of , 3);
    grafoNoConexo.addArc(&twi, &of , 4);
    grafoNoConexo.addArc(&twi, &face , 6);
    grafoNoConexo.addArc(&face, &twi , 2);
    grafoNoConexo.addArc(&face, &of , 1);

    result.clear();
    result = grafoNoConexo.broadPath(&face);

    for(int i=0; i<result.size(); i++) {
        WebApp dato = *((WebApp*)(void*)result[i]);
        cout << dato.getId() << " " << dato.getNombre() << endl;
    }

    cout << "termino bien" << endl;
*/

}