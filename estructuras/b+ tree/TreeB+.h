#include "Node.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <boost/lexical_cast.hpp>

#ifndef TREEBP 

#define TREEBP 1

template <class T>
class TreeBp {   //BASADO EN EL AVL TREE, ESTAMOS INTENTANDO ADAPTARLO A SER B+
    private:
        Node<T> *root;
        int quantity;

    public:
        TreeBp() {
            root = NULL;
            quantity = 0;
        }

        void insert(T data) {   //NOS ESTAMOS BASANDO EN EL ALGORITMO COMENTADO ABAJO
            if(root == NULL) {
                root = new Node<T>();
                root->getKeys()[0] = data;
                root->setSize(1);
            } else {
                Node<T> *temp = root;
                Node<T> *parent;
                while(temp->getIsLeaf() == false) {
                    parent = temp;
                    for(int i = 0; i < temp->getSize(); i++) {
                        if(data < temp->getKeys()[i]) {
                            temp = temp->getPtr()[i];
                            break;
                        }
                        if(i == temp->getSize() - 1) {
                            temp = temp->getPtr()[i + 1];
                            break;
                        }
                    }
                }
                if(temp->getSize() < M) {
                    int i = 0;
                    while(data > temp->getKeys()[i] && i < temp->getSize()) {
                        i++;
                    }
                    for(int j = temp->getSize(); j > i; j--) {
                        temp->getKeys()[j] = temp->getKeys()[j - 1];
                    }
                    temp->getKeys()[i] = data;
                    temp->setSize(temp->getSize() + 1);
                    temp->getPtr()[temp->getSize()] = temp->getPtr()[temp->getSize() - 1];
                    temp->getPtr()[temp->getSize() - 1] = NULL;
                } else {
                  Node<T> *newLeaf = new Node<T>();
                  T virtualNode[M + 1];
                  for(int i = 0; i < M; i++) {
                    virtualNode[i] = temp->getKeys()[i];
                  }
                  int i = 0;
                  while(data > virtualNode[i] && data < boost::lexical_cast<T>(M)) {
                    i++;
                  }
                  for(int j = M + 1; j > i; j--) {
                    virtualNode[j] = virtualNode[j - 1];
                  }
                  virtualNode[i] = data;
                  newLeaf->setIsLeaf(true);
                  temp->setSize((M + 1)/2);
                  newLeaf->setSize(M + 1 - (M + 1)/2);
                  temp->getPtr()[temp->getSize()] = newLeaf;
                  newLeaf->getPtr()[newLeaf->getSize()] = temp->getPtr()[M];
                  temp->getPtr()[M] = NULL;
                  for(int i = 0; i < temp->getSize(); i++) {
                    temp->getKeys()[i] = virtualNode[i];
                  }
                  for(int i = 0, j = temp->getSize(); i < newLeaf->getSize(); i++, j++) {
                    newLeaf->getKeys()[i] = virtualNode[j];
                  }
                  if(temp == root) {
                    Node<T> *newRoot = new Node<T>();
                    newRoot->getKeys()[0] = newLeaf->getKeys()[0];
                    newRoot->getPtr()[0] = temp;
                    newRoot->getPtr()[1] = newLeaf;
                    newRoot->setSize(1);
                    root = newRoot;
                  } else {
                    insertInternal(newLeaf->getKeys()[0], parent, newLeaf);
                  }
                }
            }
        }

        void insertInternal(T data, Node<T> *temp, Node<T> *child) {
          if(temp->getSize() < M) {
            int i = 0;
            while(data > temp->getKeys()[i] && i < temp->getSize()) {
              i++;
            }
            for(int j = temp->getSize(); j > i; j--) {
              temp->getKeys()[j] = temp->getKeys()[j - 1];
            }
            for(int j = temp->getSize() + 1; j > i; j--) {
              temp->getPtr()[j] = temp->getPtr()[j - 1];
            }
            temp->getKeys()[i] = data;
            temp->setSize(temp->getSize() + 1);
            temp->getPtr()[i + 1] = child;
          } else {
            Node<T> *newInternal = new Node<T>();
            T virtualKey[M + 1];
            Node<T> *virtualPtr[M + 2];
            for(int i = 0; i < M; i++) {
              virtualKey[i] = temp->getKeys()[i];
            }
            for(int i = 0; i < M + 1; i++) {
              virtualPtr[i] = temp->getPtr()[i];
            }
            int i = 0, j;
            while(data > virtualKey[i] && i < M) {
              i++;
            }
            for(int j = M + 1; j > i; j--) {
              virtualKey[j] = virtualKey[j - 1];
            }
            for(int j = M + 2; j > i + 1; j--) {
              virtualPtr[j] = virtualPtr[j - 1];
            }
            virtualPtr[i + 1] = child;
            newInternal->setIsLeaf(false);
            temp->setSize((M + 1)/2);
            newInternal->setSize(M - (M + 1)/2);
            for(int i = 0, j = temp->getSize() + 1; i < newInternal->getSize(); i++, j++) {
              newInternal->getKeys()[i] = virtualKey[j];
            }
            for(int i = 0, j = temp->getSize() + 1; i < newInternal->getSize() + 1; i++, j++) {
              newInternal->getPtr()[i] = virtualPtr[j];
            }
            if(temp == root) {
              Node<T> *newRoot = new Node<T>;
              newRoot->getKeys()[0] = temp->getKeys()[temp->getSize()];
              newRoot->getPtr()[0] = temp;
              newRoot->getPtr()[1] = newInternal;
              newRoot->setIsLeaf(false);
              newRoot->setSize(1);
              root = newRoot;
            } else {
              insertInternal(temp->getKeys()[temp->getSize()], findParent(root, temp), newInternal);
            }
          }
        }

        Node<T>* findParent(Node<T> *temp, Node<T> *child) {
          Node<T> *parent;
          if(temp->getIsLeaf() || (temp->getPtr()[0])->getIsLeaf()) {
            return NULL;
          }
          for(int i = 0; i < temp->getSize() + 1; i++) {
            if(temp->getPtr()[i] == child) {
              parent = temp;
              return parent;
            } else {
              parent = findParent(temp->getPtr()[i], child);
              if(parent != NULL) {
                return parent;
              }
            }
          } 
          return parent;
        }

//ALGORITMO SACADO DE: https://www.programiz.com/dsa/insertion-on-a-b-plus-tree
//tutorial y todo en esa pagina
/*        

*/
        Node<T>* getRoot() {
            return this->root;
        }

        int getSize() {
            return quantity;
        }

        bool isEmpty() {
            return !quantity;
        }

        void inorder(Node<T> *temp) {
            //recibe root de param
            if(temp != NULL) {
                inorder(temp->getLeft());
                cout << "Elemento: " << *temp->getData() << endl;
                inorder(temp->getRight());
            }
        }

        void destroy(Node<T> *toDestroy) {
            if(toDestroy != NULL) {
                destroy(toDestroy->getLeft());
                destroy(toDestroy->getRight());
                cout << "Destruyendo " << *toDestroy->getData() << endl;
                delete toDestroy;
            }
        }
};

#endif