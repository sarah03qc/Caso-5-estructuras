#include <iostream>
#include "../estructuras/b+ tree/TreeB+.h"
#include "../socket/contenful.h"
#include "../estructuras/grafo/grafo.h"

using namespace std;
#define LIMIT 4

// ponerlo a la hora de iniciar la clase match
/*
Contenful* contenful = new Contenful();
vector<Registered*> usersRegistered = contenful->getRecords();
*/

class match{
    private:
        Contenful* contenful;
        vector<Registered*> usersRegistered;
        int amountUsers;

    public:

        match(){
            this->contenful = new Contenful(); 
            this->usersRegistered = contenful->getRecords();
            this->amountUsers = this->usersRegistered.size();

        }

        void comercioCircular(string pNickname){
        /*
        comercio circular, se debe visualizar gráficamente, aquellos negocios de más de 3 participantes que generen una economía circular a partir de un nickname, es decir, que ese nickname inicie vendiendo o comprando a otra persona y que transitivamente el beneficio llegue al mismo nickname de partida. debe mostrar un diagrama graph de todos los posibles comercios circulares
        */
        // en donde vamos a guardar todos los nicknames de los posibles comercios circulares
            vector<vector<string>> *comerciosCirculares = new vector<vector<string>>();
            vector<vector<Registered*>> allPosibleMatches;
            // se crea un grafo por cada relacion entre los usuarios
            Grafo* grafoDeMatches = new Grafo(true);
            // se toman todos los posibles matches
            for(int current = 0; current < usersRegistered.size(); ++current){
                INodo *node = new INodo();
                node->setId(current);
                grafoDeMatches->addNode(node);
                vector<Registered*> posibleMatches = searchMatches(usersRegistered.at(current)->getNickname());
                allPosibleMatches.push_back(posibleMatches);
            }
            connectNodes(grafoDeMatches, allPosibleMatches);
            //cerraduraTransitiva(grafoDeMatches, comerciosCirculares);


            // la matriz va tomando forma
            

        // se crea una matriz de adyacencia por cada match de todos los usuarios
        // con esa matriz buscamos con el algoritmo de warshall (cerradura transitiva)
        // y asi sacamos el comercio circular

        // luego ver como mostralo en un diagrama graph
        // queda pendiente ver como pasar de string a date
        }

        void connectNodes(Grafo* grafoDeMatches, vector<vector<Registered*>> allPosibleMatches){
            // en el vector de allPosibleMatches el orden que se indexa es el orden en que estan 
            // los users en el registro
            for(int lista = 0; lista < allPosibleMatches.size(); ++lista){
                for(int index = 0; index < allPosibleMatches.at(lista).size(); ++index){
                    int id = findIndex(allPosibleMatches.at(lista).at(index)->getNickname());
                    grafoDeMatches->addArc(grafoDeMatches->getNodo(lista), grafoDeMatches->getNodo(id));
                }
            }
        }

        // no usar la matriz, usar la misma representacion de relaciones del grafo
        //hashtable para guardar los nodos
        // para que asi sea mas facil de indexar y conseguir nodos

        void cerraduraTransitiva(Grafo* grafoDeMatches, vector<vector<string>> *comerciosCirculares){
            vector<NodoGrafo*> listaNodos = grafoDeMatches->getListaNodos();
            for(int index = 0; index < listaNodos.size(); ++index){
                NodoGrafo* mainNode = listaNodos.at(index);
                // se ve cada conexion del nodo para ver si se devuelve a si mismo
                


            }

        }




        // Matriz no
        int ** crearMatriz(Grafo* grafoDeMatches){
            int matrizMatches[usersRegistered.size()][usersRegistered.size()];
            vector<NodoGrafo*> listaNodos = grafoDeMatches->getListaNodos();
            for(int nodo = 0; nodo < listaNodos.size(); ++nodo){
                    vector<Arco*>* listaArcos = listaNodos[nodo]->getArcs();
                    for(int arco = 0; arco < listaArcos->size(); ++arco){
                        Arco* arcoActual = listaArcos->at(arco);
                        int id = arcoActual->getDestino()->getInfo()->getId();




                    }
                }
            }

        int findIndex(string pNickname){
            for(int contador = 0; contador < usersRegistered.size(); ++contador){
                if(usersRegistered.at(contador)->getNickname() == pNickname){
                    return contador;
                }
            }
            cout << "No se encontró el nombre" << endl;

        }
        
        bool findInList(vector<vector<Registered*>> allPosibleMatches, string pNickname){
            for(vector<Registered*> lista : allPosibleMatches){
                for(Registered* user : lista){
                    if(pNickname == user->getNickname()){
                        return true;
                    }
                }
            }
            return false;


        }

    

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

            while(shortedString.size() < LIMIT && shortedString.size() < separatedWords.size()){
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


        vector<Registered*> searchMatches(string pNickname, string rangeOne = "", string rangeTwo = ""){
            Contenful* contenful = new Contenful();
            vector<Registered*> usersRegistered = contenful->getRecords();
            // toma un nickname de partida que se recibe por parametro
            vector<Registered*> posibleMatches;
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
                                posibleMatches.push_back(user);
                            }
                        }                    
                    }
                }
            }
            if (currentUser->getOffer() != ""){
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
                                posibleMatches.push_back(user);
                            }
                        }
                        
                    }
                }
            }
            return posibleMatches;
        }
    


};


int main(){
    //match* matcher = new match();
    //vector<Registered*> posibleMatches = matcher->searchMatches("CompuYankeeDev129");
    //cout << "---------------------------------------" << endl;
    //cout << "POSIBLES MATCHES" << endl;
    //for(Registered* nombre : posibleMatches){
    //    cout << nombre->getPostdate() << endl;
    //}
    vector<string> prueba;
    prueba.push_back("primero");
    prueba.push_back("segundo");
    cout << prueba.at(0) << endl;

    /*
    for(Registered* user : usersRegistered){
        cout << "Nombre: " << user->getNickname() << endl;
        cout << "Oferta: " << user->getOffer() << endl;
        cout << "Demanda: " << user->getDemand() << endl;

    }
    */

}