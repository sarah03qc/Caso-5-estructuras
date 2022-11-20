#include <iostream>
#include "../estructuras/b+ tree/TreeB+.h"
#include "../socket/contenful.h"

using namespace std;

#define LIMIT 5

Contenful* contenful = new Contenful();
vector<Registered*> usersRegistered;

list<string>separateWords(string pString){
        // se recibe el string de oferta o demanda y se acorta eliminando las palabras que sean menores o iguales
        // a tres letras, dejando asi palabras que sean significantes para el match
        list<string>  dividedStr;
        regex re("\\s+");
        
        sregex_token_iterator iter(pString.begin(), pString.end(), re, -1);
        sregex_token_iterator end;
        
        while (iter != end) {
            if (iter->length()) {
                dividedStr.push_back(*iter);  //divide la descripcion por palabras, y las almacena, hay que analizarlas
            }
            ++iter;
        }
        return dividedStr;
}

list<string> strKeyWords(string pString){
        list<string>  shortedString = separateWords(pString);
        while(shortedString.size() < LIMIT){
            for(string word : shortedString){
                for(string word2 : shortedString){
                    if(word.length() > word2.length() && word.length() > 3){
                        shortedString.push_back(word);
                    }
                    else if (word2.length() > word.length() && word2.length() > 3){
                        shortedString.push_back(word);
                    }
                }
            }
        }
        return shortedString;
    }

    bool isMatch(TreeBp<string>* pArbolB){
        bool esMatch = false;
        vector<Node<string>>* nodes;
        nodes = pArbolB->getNodes(pArbolB->getRoot(), nodes);
        nodes->at(0);
        for(int index = 0; index > nodes->size(); ++index){
            for(int counter = 0; counter > nodes->size(); ++counter){
                if(nodes->at(index).getData() == nodes->at(counter).getData()){
                    esMatch = true;
                }
            }
        }
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

int main(){
    for(Registered* user : usersRegistered){
        cout << "Nombre: " << user->getNickname() << endl;
        cout << "Oferta: " << user->getOffer() << endl;
        cout << "Demanda: " << user->getDemand() << endl;
    }

}