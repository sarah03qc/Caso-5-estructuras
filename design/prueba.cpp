#include <iostream>
#include "../estructuras/b+ tree/TreeB+.h"
#include "../socket/contenful.h"

using namespace std;
#define LIMIT 4


vector<string>separateWords(string pString){
        // se recibe el string de oferta o demanda y se acorta eliminando las palabras que sean menores o iguales
        // a tres letras, dejando asi palabras que sean significantes para el match
        vector<string>  dividedStr;
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
        vector<string> separatedWords = separateWords(pString);
        vector<int> separatedWordsSize;
        list<string> shortedString;
        for(int index = 0; index < separatedWords.size(); ++ index){
            separatedWordsSize.push_back(separatedWords.at(index).length());
        } 
        while(shortedString.size() < LIMIT){
            int bigger = 0;
            int counter = 0;
            for(int index = 0; index < separatedWords.size(); ++ index){
                if(separatedWordsSize.at(index) > bigger){
                    bigger = separatedWordsSize.at(index);
                    counter = index;
                }
            }
            if(separatedWords.at(counter).length() > 3){
                shortedString.push_back(separatedWords.at(counter));
            }else{
                break;
            }
            separatedWordsSize.at(counter) = 0;
        }
        return shortedString;
    }



    bool isMatch(TreeBp<string>* pArbolB){
        //cout << "LLEGA A MATCH" << endl;
        bool esMatch = false;
        int matchCounter = 0;
        int contador = 0;
        vector<string>* nodes = new vector<string>();
        nodes = pArbolB->getNodes(pArbolB->getRoot(), nodes);
        //cout << "---------------------------" << endl;
        for(int index = 0; index < nodes->size(); ++index){
            for(int counter = 0; counter < nodes->size(); ++counter){
                //cout << nodes->at(index) << " CON " << nodes->at(counter) << endl;
                if(nodes->at(index) == nodes->at(counter)){
                    ++ contador;
                    cout << "ES MATCH " << nodes->at(index) << " CON " << nodes->at(counter) << endl;
                }
            }
            cout << "contador " << contador << endl;
            if(contador > 1){
                ++ matchCounter;
            }
            contador = 0;
        }
        //cout << "-----------aaaaaaaaa-----------" << endl;
        cout << "match counter " << matchCounter << endl;
        if(matchCounter >= 1){
            esMatch = true;
        }
        cout << esMatch << endl;
        return esMatch;
    }

        


    Registered* findNickName(string pNickname, vector<Registered*> usersRegistered){
        Registered* userFound;
        int userIndex;
        for(int index = 0; index > usersRegistered.size(); ++index){
            if(usersRegistered.at(index)->getNickname() == pNickname){
                userIndex = index;
            }
        }
        for(Registered* user : usersRegistered){
            if(user->getNickname() == pNickname){
                userFound = user;
                break;
            }

        }
        return userFound;

    }


    list<string> match(string pNickname, vector<Registered*> usersRegistered){
        // toma un nickname de partida que se recibe por parametro
        list<string> posibleMatches;
        Registered* currentUser = findNickName(pNickname, usersRegistered);
        // determina si va a analizar oferta o demanda de dicho nickname
        if(currentUser->getDemand() != ""){
            list<string> demanda = strKeyWords(currentUser->getDemand());
            // se mete al arbol cada oferta de cada registro para ver quien hace match con la demanda del usuario actual
            for(Registered* user : usersRegistered){
                cout << "----------------------------------" << endl;
                if(user->getNickname() != currentUser->getNickname()){
                    TreeBp<string>* arbolB = new TreeBp<string>();
                    // luego procede a crear un árbol B+ de orden M usando como índice fracciones de las palabras presentes en el texto
                    for(string word : demanda){
                        arbolB->insert(word);
                    }
                    // oferta del usuario actual 
                    if(user->getOffer() != ""){
                        list<string> oferta = strKeyWords(user->getOffer());
                        for(string word : oferta){
                            arbolB->insert(word);
                        }
                        //se busca el match
                        if(isMatch(arbolB)){
                            posibleMatches.push_back(user->getNickname());
                        }
                    }                    
                }
            }
        }
        if (currentUser->getOffer() != ""){
            cout << "NO DEBERIA DE ENTRAR AQUI" << endl;
            list<string> oferta = strKeyWords(currentUser->getOffer());
            // se mete al arbol cada oferta de cada registro para ver quien hace match con la demanda del usuario actual
            for(Registered* user : usersRegistered){
                if(user->getNickname() != currentUser->getNickname()){
                    TreeBp<string>* arbolB = new TreeBp<string>();
                    // luego procede a crear un árbol B+ de orden M usando como índice fracciones de las palabras presentes en el texto
                    for(string word : oferta){
                        arbolB->insert(word);
                    }
                    if(user->getDemand() != ""){
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
    }
    return posibleMatches;
}
    

int main(){
    Contenful* contenful = new Contenful();
    vector<Registered*> usersRegistered = contenful->getRecords();
    list<string> posibleMatches = match("CompuYankeeDev129", usersRegistered);
    cout << "---------------------------------------" << endl;
    cout << "POSIBLES MATCHES" << endl;
    for(string nombre : posibleMatches){
        cout << nombre << endl;
    }
    /*
    for(Registered* user : usersRegistered){
        cout << "Nombre: " << user->getNickname() << endl;
        cout << "Oferta: " << user->getOffer() << endl;
        cout << "Demanda: " << user->getDemand() << endl;

    }
    */

}