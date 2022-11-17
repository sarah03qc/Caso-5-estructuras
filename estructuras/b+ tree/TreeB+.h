#include "Node.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

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

        void insert(T *data) {   //NOS ESTAMOS BASANDO EN EL ALGORITMO COMENTADO ABAJO
            if(root == NULL) {
                root = new Node<T>();
                root->getKeys()[0] = data;
                root->setSize(1);
            } else {
                Node<T> *temp = root;
                Node<T> *parent;
                while(temp->isLeaf == false) {
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
                  int virtualNode[M + 1];
                  for(int i = 0; i < M; i++) {
                    virtualNode[i] = temp->getKeys()[i];
                  }
                  int i = 0;
                  while(data > virtualNode[i] && data < M) {
                    i++;
                  }
                  for(int j = M + 1; j > i; j--) {
                    virtualNode[j] = virtualNode[j - 1];
                  }
                  virtualNode[i] = data;
                  newLeaf->isLeaf = true;
                  temp->setSize((M + 1)/2);
                  newLeaf->setSize(M + 1 - (M + 1)/2);
                  temp->getPtr()[temp->getSize()] = newLeaf;
                  newLeaf->getPtr()[newLeaf->getSize()] = temp->getPtr()[M];
                  temp->getPtr()[M] = NULL;
                  for(int i = 0; i < temp->getSize(); i++) {
                    temp->getKeys()[i] = virtualNode[i];
                  }
                  for(int i = 0, int j = temp->getSize(); i < newLeaf->getSize(); i++, j++) {
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

//ALGORITMO SACADO DE: https://www.programiz.com/dsa/insertion-on-a-b-plus-tree
//tutorial y todo en esa pagina
/*        
// Insert Operation
      


      
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