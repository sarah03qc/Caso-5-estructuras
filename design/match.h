#include <iostream>
#include "grafo/grafo.h"
#include <regex>
#include <vector>
#include "Profile.h"
#include "../estructuras/b+ tree/TreeB+.h"

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

    // este algoritmo es mas como lo que pide el profe
    void match(Profile* pPerfil){
        // nickname de partida
        string nickName = pPerfil->getNickname();
        // determina si va a analizar oferta o demanda de dicho nickname
        if(pPerfil->getTieneOferta()){
            /*
             luego procede a crear un árbol B+ de orden M usando como índice fracciones de las palabras 
             presentes en el texto, insertando en el bloque de datos la referencia al nickname respectivo
            */
           TreeBp arbolB = new TreeBp();

        }
        else if (pPerfil->getTieneDemanda()){

        }

    }
     




};







