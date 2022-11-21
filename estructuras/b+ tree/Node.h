#include <iostream>
#include <string>
#include <sstream>
#ifndef NODE 
#define NODE 1
#define M 8

using namespace std;

template <class T>
class Node {
    private:
        bool isLeaf;
        Node **ptr;
        T *key;
        int size;
    
    public:
        Node() {
            key = new T[M];
            ptr = new Node<T> *[M + 1];
        }

        T* getKeys() { 
            return key;
        }

        int getSize() {
            return size;
        }

        void setSize(int size) {
            this->size = size;
        }

        Node** getPtr() {    
            return ptr;     
        }

        void setPtr(Node<T> **pValue) {
            this->ptr = ptr;
        }

        bool getIsLeaf() {
            return isLeaf;
        }

        void setIsLeaf(bool is) {
            this->isLeaf = is;
        }
};

#endif