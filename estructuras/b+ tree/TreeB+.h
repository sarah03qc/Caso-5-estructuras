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
                }
            }
        }

//ALGORITMO SACADO DE: https://www.programiz.com/dsa/insertion-on-a-b-plus-tree
//tutorial y todo en esa pagina
/*        
// Insert Operation
void BPTree::insert(int x) {
  if (root == NULL) {
    root = new Node;
    root->key[0] = x;
    root->IS_LEAF = true;
    root->size = 1;
  } else {
    Node *cursor = root;
    Node *parent;
    while (cursor->IS_LEAF == false) {
      parent = cursor;
      for (int i = 0; i < cursor->size; i++) {
        if (x < cursor->key[i]) {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    if (cursor->size < MAX) {
      int i = 0;
      while (x > cursor->key[i] && i < cursor->size)
        i++;
      for (int j = cursor->size; j > i; j--) {
        cursor->key[j] = cursor->key[j - 1];
      }
      cursor->key[i] = x;
      cursor->size++;
      cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
      cursor->ptr[cursor->size - 1] = NULL;  ////////////////////////////////////////////////////VAMOS POR ACA *******
    } else {
      Node *newLeaf = new Node;
      int virtualNode[MAX + 1];
      for (int i = 0; i < MAX; i++) {
        virtualNode[i] = cursor->key[i];
      }
      int i = 0, j;
      while (x > virtualNode[i] && i < MAX)
        i++;
      for (int j = MAX + 1; j > i; j--) {
        virtualNode[j] = virtualNode[j - 1];
      }
      virtualNode[i] = x;
      newLeaf->IS_LEAF = true;
      cursor->size = (MAX + 1) / 2;
      newLeaf->size = MAX + 1 - (MAX + 1) / 2;
      cursor->ptr[cursor->size] = newLeaf;
      newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
      cursor->ptr[MAX] = NULL;
      for (i = 0; i < cursor->size; i++) {
        cursor->key[i] = virtualNode[i];
      }
      for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) {
        newLeaf->key[i] = virtualNode[j];
      }
      if (cursor == root) {
        Node *newRoot = new Node;
        newRoot->key[0] = newLeaf->key[0];
        newRoot->ptr[0] = cursor;
        newRoot->ptr[1] = newLeaf;
        newRoot->IS_LEAF = false;
        newRoot->size = 1;
        root = newRoot;
      } else {
        insertInternal(newLeaf->key[0], parent, newLeaf);
      }
    }
  }
}
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