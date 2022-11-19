#include <iostream>
#include "grafo/grafo.h"
#include <regex>
#include "Profile.h"
#include "../estructuras/b+ tree/TreeB+.h"
#include "../socket/contenful.h"

#define OFERTA 0
#define DEMANDA 1

// una idea de match

// hay que resolver lo de contenful para ver como obtener todos los perfiles
//vector<Registered*> allrecords

//string oferta = "conciertos a estadio lleno de gente escuchando pum pum con el mismo acorde por 2 horas";
//string demanda = "transporte y seguridad en todos los paises que visita y mucha fiesta tambien";

//string oferta2 = "servicio de transporte de bus para 50 pasajeros";
//string demanda2 = "llantas de gran tamaño";

class Match{
    private:
        Contenful* contenful = new Contenful();
        vector<Registered*> usersRegistered;
    public:
    /*
        vector<string> strKeyWords(string pString){
            // se recibe el string de oferta o demanda y se acorta eliminando las palabras que sean menores o iguales
            // a tres letras, dejando asi palabras que sean significantes para el match
            vector<string> dividedStr;
            vector<string> shortedString;
            regex re("\\s+");
            
            sregex_token_iterator iter(pString.begin(), pString.end(), re, -1);
            sregex_token_iterator end;
            
            while (iter != end) {
                if (iter->length()) {
                    dividedStr.push_back(*iter);  //divide la descripcion por palabras, y las almacena, hay que analizarlas
                }
                ++iter;
            }

            for(string word : dividedStr){
                if(word.length() > 3){
                    shortedString.push_back(word);
                }
            }
            return shortedString;
        }

        bool isMatch(vector<string> textOne, vector<string> textTwo){
            int matches = 0;
            bool esMatch = true;
            for(string wordText1 : textOne){
                for(string wordText2 : textTwo){
                    if(wordText1 == wordText2){
                        ++ matches;
                    }
                }
            }
            if(matches == 0){
                esMatch = false;
            }
            return esMatch;
        }

    void matcher(Profile* perfil){
        // se compara primero la oferta de este perfil con todas las demandas de todos los usuarios registrados
        // si se hace match entonces en cada perfil se agrega el match correspondiente
        // lo mismo oara la demanda
        /*
        if(perfil->getTieneOferta()){
            vector<string> oferta = strKeyWords(perfil->getOferta());
        }
        if(perfil->getTieneDemanda()){
            vector<string> demanda = strKeyWords(perfil->getDemanda());
        }
            for(int index = 0; index < allrecords.size(); ++ index){
                // se recorre cada usuario para revisar
                if(perfil->getTieneOferta){
                    string strDemanda = allrecords.at(index)->getDemand();
                    vector<string> demandaVec = strKeyWords(strDemanda);
                    if(isMatch(oferta, demandaVec)){
                        // hay que definir si le vamos a crear el perfil en nuestro programa o no
                        perfil->setMatches();
                    }
                }
                else if(perfil->getTieneDemanda) {
                    string strOferta = allrecords.at(index)->getOffer();
                    vector<string> ofertaVec = strKeyWords(strOferta);
                    if(isMatch(demanda, ofertaVec)){
                        // hay que definir si le vamos a crear el perfil en nuestro programa o no
                        perfil->setMatches();
                    }

                }
                
            }

        
    }
    */

   void comercioCircular(){
    /*
    comercio circular, se debe visualizar gráficamente, aquellos negocios de más de 3 participantes que generen una economía circular a partir de un nickname, es decir, que ese nickname inicie vendiendo o comprando a otra persona y que transitivamente el beneficio llegue al mismo nickname de partida. debe mostrar un diagrama graph de todos los posibles comercios circulares
    */

   
   }

    list<string> strKeyWords(string pString){
        // se recibe el string de oferta o demanda y se acorta eliminando las palabras que sean menores o iguales
        // a tres letras, dejando asi palabras que sean significantes para el match
        list<string>  dividedStr;
        list<string>  shortedString;
        regex re("\\s+");
        
        sregex_token_iterator iter(pString.begin(), pString.end(), re, -1);
        sregex_token_iterator end;
        
        while (iter != end) {
            if (iter->length()) {
                dividedStr.push_back(*iter);  //divide la descripcion por palabras, y las almacena, hay que analizarlas
            }
            ++iter;
        }

        for(string word : dividedStr){
            if(word.length() > 3){
                shortedString.push_back(word);
            }
        }
        return shortedString;
    }

    bool isMatch(TreeBp<string>* pArbolB){
        bool esMatch = false;
        vector<Node<string>>* nodes;
        nodes = pArbolB->getNodes(pArbolB->getRoot(), nodes);
        for(int index = 0; index > nodes->size(); ++index){
            for(int counter = 0; counter > nodes->size(); ++counter){
                if(nodes->at(index).getData() == nodes->at(counter).getData()){
                    esMatch = true;
                }
            }
        }
    return esMatch;
  
        
        
        
        return esMatch;
    }

    Registered* findNickName(string pNickname){
        Registered* userFound;
        for(Registered* user : usersRegistered){
            if(user->getNickname() == pNickname){
                userFound = user;
            }

        }
        return userFound;

    }


    list<string> match(string pNickname){
        // toma un nickname de partida que se recibe por parametro
        list<string> posibleMatches;
        Registered* currentUser = findNickName(pNickname);
        // determina si va a analizar oferta o demanda de dicho nickname
        if(currentUser->getDemand() != ""){
            list<string> demanda = strKeyWords(currentUser->getDemand());
            // se mete al arbol cada oferta de cada registro para ver quien hace match con la demanda del usuario actual
            for(Registered* user : usersRegistered){
                TreeBp<string>* arbolB = new TreeBp<string>();
                // luego procede a crear un árbol B+ de orden M usando como índice fracciones de las palabras presentes en el texto
                for(string word : demanda){
                    arbolB->insert(word);
                }
                // oferta del usuario actual 
                list<string> oferta = strKeyWords(user->getOffer());
                for(string word : oferta){
                    arbolB->insert(word);
                }
                // se busca el match
                if(isMatch(arbolB)){
                    posibleMatches.push_back(user->getNickname());
                }
            }
        }
        else if (currentUser->getOffer() != ""){
            list<string> oferta = strKeyWords(currentUser->getOffer());
            // se mete al arbol cada oferta de cada registro para ver quien hace match con la demanda del usuario actual
            for(Registered* user : usersRegistered){
                TreeBp<string>* arbolB = new TreeBp<string>();
                // luego procede a crear un árbol B+ de orden M usando como índice fracciones de las palabras presentes en el texto
                for(string word : oferta){
                    arbolB->insert(word);
                }
                // demanda del usuario actual 
                list<string> demanda = strKeyWords(user->getDemand());
                for(string word : demanda){
                    arbolB->insert(word);
                }
                // se busca el match
                if(isMatch(arbolB)){
                    posibleMatches.push_back(user->getNickname());
                }
            }
        }

    }
     




};







