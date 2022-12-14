#include "Node.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

#ifndef TREEBP 

#define TREEBP 1

template <class T>
class TreeBp {  
    private:
        Node<T> *root;

    public:
        TreeBp() {
            root = NULL;
        }

        void insert(T data) {   
            if(root == NULL) {
                root = new Node<T>();
                root->getKeys()[0] = data;
                root->setSize(1);
                root->setIsLeaf(true);
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
                  int i = 0, j;
                  while(data > virtualNode[i] && i < M) {
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
                    newRoot->setIsLeaf(false);
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
            virtualKey[i] = data;
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

        void recorrer(Node<T> *temp) {
          if(temp != NULL) {
            for(int i = 0; i < temp->getSize(); i++) {
              cout << temp->getKeys()[i] << " ";
            }
            cout << "\n";
            if(temp->getIsLeaf() != true) {
              for(int i = 0; i < temp->getSize() + 1; i++) {
                recorrer(temp->getPtr()[i]);
              }
            }
          }
        }

        vector<string>* getNodes(Node<T> *temp, vector<string>* pNodes){
          if(temp != NULL){
            for(int i = 0; i < temp->getSize(); i++) {
              pNodes->push_back(temp->getKeys()[i]);
            }
            if(temp->getIsLeaf() != true) {
              for(int i = 0; i < temp->getSize() + 1; i++) {
                getNodes(temp->getPtr()[i], pNodes);
              }
            }
          }
          return pNodes;
        }

        Node<T>* find(T data) {
          if(root == NULL) {
            cout << "El arbol se encuentra vacio" << endl;
          } else {
            Node<T> *temp = root;
            while(temp->getIsLeaf() == false) {
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
            for(int i = 0; i < temp->getSize(); i++) {
              if(temp->getKeys()[i] == data) {
                cout << "Se encontro: " << temp->getKeys()[i] << endl;
                return temp;
              }
            }
            cout << "No se encontro" << endl;
            return NULL;
          }
        }

        Node<T>* getRoot() {
            return this->root;
        }
};

#endif