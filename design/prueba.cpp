#include "match.h"

int main(){
    
    match* matcher = new match();
    map<string, int> topProductos = matcher->getMostRepeatedStrings();
    for(auto itr = topProductos.begin(); itr != topProductos.end(); ++itr){
        string clave = itr->first;
        int valor = itr->second;
        cout << clave << " " << valor << endl;
    }
    /*
    vector<Registered*> posibleMatches = matcher->searchMatches("CompuYankeeDev129");
    cout << "---------------------------------------" << endl;
    cout << "POSIBLES MATCHES" << endl;
    for(Registered* nombre : posibleMatches){
        cout << nombre->getNickname() << endl;
    }
    */
    //vector<string> prueba;
    //prueba.push_back("primero");
    //prueba.push_back("segundo");
    //cout << prueba.at(0) << endl;

    /*
    for(Registered* user : usersRegistered){
        cout << "Nombre: " << user->getNickname() << endl;
        cout << "Oferta: " << user->getOffer() << endl;
        cout << "Demanda: " << user->getDemand() << endl;

    }
    */

}