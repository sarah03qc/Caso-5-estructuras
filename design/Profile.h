#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include <list>
#include "../socket/contenful.h"

#ifndef PROFILE 
#define PROFILE 1

using namespace std;

class Profile {
    private:
        string nickname; //de 10 a 32 letras, unico
        string password; //max 20 letras
        string registrationDate;
        // por el momento se me ocurre que podría ser una lista, luego vemos si es necesario cambiar el tipo de datos
        // si por cada usuario que haga match le creamos el perfil en nuestro programa seria optimo que sea de tipo profile
        // otro caso seria que fuera de tipo Registered* como en contenful
        list<Profile> matches;
        bool tieneOferta;
        bool tieneDemanda;
        string oferta;
        string demanda;
        string descripcion;
        string queQuiere;
        string queOfrece;
        Contenful* contenful = new Contenful();
        vector<Registered*> usersRegistered;


    public:
        Profile(string pnickname, string password1, string password2, string pComprar, string pVender) {
            // luego optimizamos para que no sea tanto codigo aqui
            usersRegistered = contenful->getRecords();
            bool registered = false;
            if(10 <= pnickname.length() && pnickname.length() <= 32) {
                // se revisa que el nombre de usuario sea unico
                for(Registered* user : usersRegistered){
                    if (user->getNickname() == pnickname){
                        registered = true;
                    }
                }
                if(!registered){
                    this->nickname = pnickname; 
                    // se revisa que la contrasena sea de max 20 letras
                    if (password1.length() <= 20 && password2.length() <= 20){
                        // se revisa que sean iguales
                        if(password1 == password2){
                            this->password = password1;
                            if(pComprar.length() <= 250 && pVender.length() <= 250){
                                time_t now = time(0);
                                tm *current = localtime(&now);
                                contenful->registerUser(pnickname, pVender, pComprar, password1, current->tm_mday, 1 + current->tm_mon, 1900 + current->tm_year);
                                // despues de registrarlo empezamos a buscar matches
                            }
                     
                        }
                        else{
                            cout << "Sus contrasenas no coinciden" << endl;
                        }
                    }
                }
                else{
                    cout << "Este nombre de usuario ya esta registrado" << endl;
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


    bool getTieneOferta(){
        return this->tieneOferta;
    }
    bool getTieneDemanda(){
        return this->tieneDemanda;
    }
    string getDemanda(){
        return this->demanda;

    }

    string getNickname(){
        return this->nickname;
    }

    string getOferta(){
        return this->oferta;
    }
    list<Profile> getMatches(){
        return this->matches;
    }

    void setMatches(Profile pProfile){
        this->matches.push_back(pProfile);
    }
    
    
    
};

#endif