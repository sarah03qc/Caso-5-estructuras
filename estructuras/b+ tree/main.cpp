
#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "TreeB+.h"


using namespace std;


int main() {

    //SOLO DE PRUEBA
    TreeBp<int>* arbol = new TreeBp<int>();

    arbol->insert(8);
    arbol->insert(55);
    arbol->insert(23);
    arbol->insert(60);
    arbol->insert(15);
    arbol->insert(32);

    
    arbol->recorrer(arbol->getRoot());
    arbol->find(23);
/*
    arbol->insert("g");
    arbol->insert("a");
    arbol->insert("d");
    arbol->insert("b");
    arbol->insert("t");
    arbol->insert("s");
*/
    return 0;
}