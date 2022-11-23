#include <string>
#include <iostream>
#include "../design/Profile.h"
#include "client.h"

using namespace std;

class Receiver {
	
    public: 

        void getProfileInfo() {
            Client cliente;
            vector<string> variables;
            for(int i = 0; i < 4; i++) {
                variables.push_back(cliente.receive());
            } 
            //se genera el perfil con la informacion sacada de los sockets
            //Profile newPerfil = Profile(variables[0], variables[1], variables[1], variables[2], variables[3]);
            for(int i = 0; i < 4; i++) {
                cout << variables[i] << endl;
            } 
        }
};