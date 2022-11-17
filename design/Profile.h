#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#ifndef PROFILE 
#define PROFILE 1

using namespace std;

class Profile {
    private:
        string nickname; //de 10 a 32 letras, unico
        string password; //max 20 letras
        bool oferta;
        bool demanda;
        string descripcion;
        string queQuiere;
        string queOfrece;

    public:
        Profile(string pnickname, string password1, string password2) {
            //se debe chequear que el nickname sea unico, pero como? debemos tener esa info
            if(10 <= pnickname.length() && pnickname.length() <= 32) {
                this->nickname = pnickname; 
                if(password1 == password2) {
                    this->password = password1;
                } else {
                    cout << "Sus contrasenas no coinciden" << endl;
                }
            } else{
                cout << "Verifique que su nombre de usuario este en el rango de longitud" << endl;
            }
        }

        void setPurpose(bool compra, bool ofrece, string desc) {
            oferta = ofrece;
            demanda = compra;
            descripcion = desc;
            this->checkPurpose();
        }

        void checkPurpose() {
            //usando expresiones regulares
            vector<string> elems;
            regex re("\\s+");
            
            sregex_token_iterator iter(descripcion.begin(), descripcion.end(), re, -1);
            sregex_token_iterator end;
            
            while (iter != end) {
                if (iter->length()) {
                    elems.push_back(*iter);  //divide la descripcion por palabras, y las almacena, hay que analizarlas
                }
                ++iter;
            }

            for(int i = 0; i < elems.size(); i++) {
                if(elems[i] == "quiero" ||
                elems[i] == "requiero" ||
                elems[i] == "necesito" ||
                elems[i] == "solicito" ||
                elems[i] == "busco") {

                    queQuiere = elems[i];
                    if(elems[i+1] != "un" &&
                    elems[i+1] != "una" &&
                    elems[i+1] != "unos" &&
                    elems[i+1] != "unas") {

                        queQuiere = queQuiere + " " + elems[i+1];
                    } else {
                        queQuiere = queQuiere + " " + elems[i+2];
                    }
                }
            }
            cout << queQuiere << endl;  //su demanda 


            //falta la ofrenda, y tambien que sea mas optimo
        }
    
    
};

#endif