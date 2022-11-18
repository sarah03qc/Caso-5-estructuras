#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>
#include <list>

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

    public:
        Profile(string pnickname, string password1, string password2) {
            //se debe chequear que el nickname sea unico, pero como? debemos tener esa info

            // con contenful se podria conseguir todos los registros y verificar que sea correcto
            // luego de ser correcto, le asignamos al perfil todos sus datos correspondientes
            if(10 <= pnickname.length() && pnickname.length() <= 32) {
                this->nickname = pnickname; 
                if(password1 == password2) {
                    this->password = password1;

                    // luego de verificar los datos del usuario, llamamos al metodo de matcher para
                    // que busque los
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