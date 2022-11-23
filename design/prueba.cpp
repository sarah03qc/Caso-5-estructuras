#include "match.h"
int main(){
    
    match* matcher = new match();
    matcher->top10();
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