#include <string>
#include <iostream>
#include "../design/Profile.h"
#include <regex>
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
            //regex re("\\s+");
            regex re(",");
            
            sregex_token_iterator iter(fullinfo.begin(), fullinfo.end(), re, -1);
            sregex_token_iterator end;
            cout << "termino regex" << endl;
            
            
            while (iter != end) {
                cout << "entro al while" << endl;
                if (iter->length()) {
                    cout << *iter << endl;
                    elems.push_back(*iter);
                }
                ++iter;
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
            cout << "descrDem " << descrDem << endl;
            cout << "descrOffer " << descrOffer << endl;

        }
};