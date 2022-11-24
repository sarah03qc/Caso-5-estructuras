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
        vector<vector<Registered*>>* allPosibleMatches;

    public:

        match(){
            this->contenful = new Contenful(); 
            this->usersRegistered = contenful->getRecords();
            this->amountUsers = this->usersRegistered.size();
            allPosibleMatches = new vector<vector<Registered*>>();

        }

        void findAllPosibleMatches(){
            for(int current = 0; current < usersRegistered.size(); ++current){
                vector<Registered*> posibleMatches = searchMatches(usersRegistered.at(current)->getNickname());
                allPosibleMatches->push_back(posibleMatches);
            }
        }
/*
        void comercioCircular(string pNickname){
        comercio circular, se debe visualizar gráficamente, aquellos negocios de más de 3 participantes que generen una economía circular a partir de un nickname, es decir, que ese nickname inicie vendiendo o comprando a otra persona y que transitivamente el beneficio llegue al mismo nickname de partida. debe mostrar un diagrama graph de todos los posibles comercios circulares
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


        void cerraduraTransitiva(Grafo* grafoDeMatches, vector<vector<NodoGrafo*>*> *comerciosCirculares){
            vector<NodoGrafo*> listaNodos = grafoDeMatches->getListaNodos();
            // se recorre cada nodo del grafo
            // por cada nodo se recorre sus adyacentes 
            for(int currentNode = 0; currentNode < listaNodos.size(); ++currentNode){
                vector<NodoGrafo*>* newList;
                // guardamos el nodo actual que estamos revisando
                NodoGrafo* mainNode = listaNodos.at(currentNode);
                newList->push_back(mainNode);
                if(mainNode->getArcs() != NULL){
                    vector<NodoGrafo*>* neighbourList;
                    addElementsToList(newList, neighbourList);
                    // recorremos cada nodo vecino
                    for(int neighbourNode = 0; neighbourNode < mainNode->getArcs()->size(); ++ neighbourNode){
                        NodoGrafo* newCurrent = mainNode->getArcs()->at(neighbourNode)->getDestino();
                        transitive(newCurrent, mainNode, comerciosCirculares, neighbourList);
                    }
                }
                // se ve cada conexion del nodo para ver si se devuelve a si mismo
                


            }

        }
        // por cada nodo vecino corremos este metodo

        void transitive(NodoGrafo* currentNode, NodoGrafo* destinyNode, vector<vector<NodoGrafo*>*> *comerciosCirculares, vector<NodoGrafo*>* list){
            
            if(currentNode->getInfo()->getId() == destinyNode->getInfo()->getId()){
                comerciosCirculares->push_back(list);
            }
            else{
                for(int neighbourNode = 0; neighbourNode < currentNode->getArcs()->size(); ++ neighbourNode){
                    vector<NodoGrafo*>* newList = new vector<NodoGrafo*>();
                    addElementsToList(list, newList);
                    NodoGrafo* newCurrent = currentNode->getArcs()->at(neighbourNode)->getDestino();
                    newList->push_back(newCurrent);
                    transitive(currentNode, destinyNode, comerciosCirculares, newList);

                }


            }
            
        }

        // se empieza desde un el primer nodo 
        // se agrega el primer nodo a la lista
        // por cada vecino creando otra lista con el camino ya recorrido + el vecino
        // iteramos lo anterior hasta que encuentre al primer nodo o llegue a un nodo que no tenga vecinos
        // y asi vamos construyendo las relaciones transtitivas

        // -----
        // es lo mismo solo que uno es con una lista y el otro con un hastable
        // -----

        // se crea un hashtable de los nodos del grafo
        // se revisa uno por uno indexando en el hashtable los vecinos 
        // seguimos indexando hasta que haya uno que llegue a al nodo inicial


        // metodo para ir agregando los elementos ya recorridos a una lista nueva
        void addElementsToList(vector<NodoGrafo*>* toAdd, vector<NodoGrafo*>* list){
            for(int index = 0; index < toAdd->size(); ++index){
                list->push_back(toAdd->at(index));
            }

        }
*/

        map<string, int> getMostRepeatedStrings(){
            vector<string>* mostRepeated = new vector<string>();
            // de los usuarios top sacamos los temas que mas se repiten
            map<string, int>  topUsers = top10_Users();
            map<string, int> topProductos;
            map<string, int> words;
            for(auto itr = topUsers.begin(); itr != topUsers.end(); ++itr){
                int index = findRegisterIndex(itr->first);
                Registered* currentUser = usersRegistered.at(index);
                if(currentUser->getDemand() != ""){
                    list<string> demanda = strKeyWords(currentUser->getDemand());
                    for(string word : demanda){
                        words[word]++;
                    }
                }
                else if(currentUser->getOffer() != ""){
                    list<string> oferta = strKeyWords(currentUser->getOffer());
                    for(string word : oferta){
                        words[word]++;
                    }
                }
            }
            topProductos = getTenHighest(words, topProductos);
            return topProductos;
        }



        
        int findRegisterIndex(string pNickname){
            for(int index = 0; index < usersRegistered.size(); ++index){
                if(usersRegistered.at(index)->getNickname() == pNickname){
                    return index;
                }
            }
        }



        map<string, int>  top10_Users(){
            // si queremos los top 10 usuarios con mas matches
            map<string, int> mapaHash;
            map<string, int> topTen;
            // se agrega todos los nombres
            for(Registered* usuario : usersRegistered){
                mapaHash[usuario->getNickname()] = 0;
            }
            findAllPosibleMatches();
            // se aumenta el conteo
            for(int vector = 0; vector < allPosibleMatches->size(); ++vector ){
                for(int vectorMatches = 0; vectorMatches < allPosibleMatches->at(vector).size(); ++vectorMatches){
                    mapaHash[allPosibleMatches->at(vector).at(vectorMatches)->getNickname()]++;
                }
            }

            topTen = getTenHighest(mapaHash, topTen);
            return topTen;
        }


        map<string, int> getTenHighest(map<string, int> mapaHash, map<string, int> topTen){
            for(int contador = 0; contador < 10 ; ++contador ){
                // se busca el mas alto
                string highest = findHighest(mapaHash);
                // lo agregamos en el top 10
                topTen[highest] = mapaHash[highest];
                // lo seteamos del mapaHash para que ya no sea tomado en cuenta
                mapaHash[highest] = 0;
            }
            return topTen;

        }

        string findHighest(map<string, int> mapaHash){
            // first tiene la clave, second el valor
            int contador = 0;
            string clave;
            for(auto itr = mapaHash.begin(); itr != mapaHash.end(); ++itr){
                // first tiene la clave, second el valor
                if(itr->second > contador){
                    contador = itr->second;
                    clave = itr->first;
                }
            }
            return clave;
        }

        void findPosibleMatches(){
            // se crea un grafo por cada relacion entre los usuarios
            // se toman todos los posibles matches
            for(int current = 0; current < usersRegistered.size(); ++current){
                vector<Registered*> posibleMatches = searchMatches(usersRegistered.at(current)->getNickname());
                allPosibleMatches->push_back(posibleMatches);
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
            bool esMatch = false;
            int matchCounter = 0;
            int contador = 0;
            vector<string>* nodes = new vector<string>();
            nodes = pArbolB->getNodes(pArbolB->getRoot(), nodes);
            for(int index = 0; index < nodes->size(); ++index){
                for(int counter = 0; counter < nodes->size(); ++counter){
                    if(nodes->at(index) == nodes->at(counter)){
                        ++ contador;
                    }
                }
                if(contador > 1){
                    ++ matchCounter;
                }
                contador = 0;
            }
            if(matchCounter >= 1){
                esMatch = true;
            }
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
            // toma un nickname de partida que se recibe por parametro
            vector<Registered*> posibleMatches;
            Registered* currentUser = findNickName(pNickname, usersRegistered);
            // determina si va a analizar oferta o demanda de dicho nickname
            if(currentUser->getDemand() != ""){
                list<string> demanda = strKeyWords(currentUser->getDemand());
                // se mete al arbol cada oferta de cada registro para ver quien hace match con la demanda del usuario actual
                for(Registered* user : usersRegistered){
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
