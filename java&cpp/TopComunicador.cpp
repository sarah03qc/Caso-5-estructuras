#include <string>
#include <iostream>
#include "../design/match.h"
#include "client.h"


using namespace std;

class TopComunicador {
 
    public: 

        void sendTopInfo() {
            string fullstr;
            vector<string> elems;
            match* matcher = new match();
            map<string, int> topProductos = matcher->getMostRepeatedStrings();
            for(auto itr = topProductos.begin(); itr != topProductos.end(); ++itr){
                string clave = itr->first;
                elems.push_back(clave);
                int valor = itr->second;
                cout << clave << " " << valor << endl;
            }
            fullstr = elems[0] + "," + elems[1] + "," + elems[2] + "," + elems[3] + "," + elems[4] + "," + elems[5] + "," + elems[6] + "," + elems[7] + "," + elems[8] + "," + elems[9] + "," + elems[10];
            Client cliente ;
            cliente.send(fullstr);
    
        }
};


int main(){
    TopComunicador comtop;
    comtop.sendTopInfo();
}