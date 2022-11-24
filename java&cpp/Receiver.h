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
<<<<<<< HEAD
            
            string fullinfo = cliente.receive(); 
            cout << "paso por el receiver" << endl;
=======
            string fullinfo = cliente.receive(); 
>>>>>>> cb7c5d8ea0305d2ec1e0c56e9e12341f8c7fde7d
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
<<<<<<< HEAD
            cout << "termino regex" << endl;
            
            
            while (iter != end) {
                cout << "entro al while" << endl;
                if (iter->length()) {
                    cout << *iter << endl;
                    elems.push_back(*iter);
=======
            
            while (iter != end) {
                if (iter->length()) {
                    elems.push_back(*iter);  //divide por las comas
>>>>>>> cb7c5d8ea0305d2ec1e0c56e9e12341f8c7fde7d
                }
                ++iter;
            }  

            nombre = elems[0];
            pass1 = elems[1];
            pass2 = elems[2];
<<<<<<< HEAD
            descrDem = elems[3];
            descrOffer = elems[4];       
=======
            descrOffer = elems[3];
            descrDem = elems[4];       
>>>>>>> cb7c5d8ea0305d2ec1e0c56e9e12341f8c7fde7d


            //se genera el perfil con la informacion sacada de los sockets
            //Profile newPerfil = Profile(variables[0], variables[1], variables[1], variables[2], variables[3]);
            cout << "nombre " << nombre << endl;
            cout << "pass1 " << pass1 << endl;
            cout << "pass2 " << pass2 << endl;
            cout << "descrDem " << descrDem << endl;
            cout << "descrOffer " << descrOffer << endl;

        }
};