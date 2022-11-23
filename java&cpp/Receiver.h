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
            
            while (iter != end) {
                if (iter->length()) {
                    elems.push_back(*iter);  //divide por las comas
                }
                ++iter;
            }  

            nombre = elems[0];
            pass1 = elems[1];
            pass2 = elems[2];
            descrOffer = elems[3];
            descrDem = elems[4];       


            //se genera el perfil con la informacion sacada de los sockets
            //Profile newPerfil = Profile(variables[0], variables[1], variables[1], variables[2], variables[3]);
            cout << "nombre " << nombre << endl;
            cout << "pass1 " << pass1 << endl;
            cout << "pass2 " << pass2 << endl;
            cout << "descrOfer " << descrOfer << endl;
            cout << "descrDem " << descrDem << endl;

        }
};