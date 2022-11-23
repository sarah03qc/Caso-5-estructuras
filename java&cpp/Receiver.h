#include <string>
#include <iostream>
#include "../design/Profile.h"
#include "client.h"

using namespace std;

class Receiver {
 
    public: 

        void getProfileInfo() {
            Client cliente ;
            string nombre = cliente.receive();
            string pass1 = cliente.receive();
            string pass2 = cliente.receive();
            string descrOfer = cliente.receive();
            string descrDem = cliente.receive();            
            //se genera el perfil con la informacion sacada de los sockets
            //Profile newPerfil = Profile(variables[0], variables[1], variables[1], variables[2], variables[3]);
            cout << "nombre " << nombre << endl;
            cout << "pass1 " << pass1 << endl;
            cout << "pass2 " << pass2 << endl;
            cout << "descrOfer " << descrOfer << endl;
            cout << "descrDem " << descrDem << endl;

        }
};