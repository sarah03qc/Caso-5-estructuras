#include <string>
#include <iostream>
#include "../design/Profile.h"
#include <cstring>
#include "client.h"

using namespace std;

class Receiver {
 
    public: 

        void getProfileInfo() {
            Client cliente ;
            
            string fullinfo = cliente.receive(); 
            cout << "paso por el receiver" << endl;

            string nombre;
            string pass1;
            string pass2;
            string descrOffer;
            string descrDem;   

            vector<string> elems;
            stringstream ss(fullinfo);
            
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                elems.push_back(substr);
            }
            
            for(int i = 0; i < elems.size(); i++) {
                cout << elems[i] << endl;
            }

            nombre = elems[0];
            pass1 = elems[1];
            pass2 = elems[2];
            descrDem = elems[3];
            descrOffer = elems[4];       


            //se genera el perfil con la informacion sacada de los sockets
            //Profile newPerfil = Profile(variables[0], variables[1], variables[1], variables[2], variables[3]);
            cout << "nombre " << nombre << endl;
            cout << "pass1 " << pass1 << endl;
            cout << "pass2 " << pass2 << endl;
            cout << "descrOffer " << descrOffer << endl;
            cout << "descrDem " << descrDem << endl;
            cout << "descrOffer " << descrOffer << endl;

        }
};