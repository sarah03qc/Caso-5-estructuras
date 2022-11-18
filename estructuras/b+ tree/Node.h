#include <iostream>
#include <string>
#include <sstream>
#ifndef NODE 
#define NODE 1
#define M 3

using namespace std;

template <class T>
class Node {
    private:
        T *data;
        bool isLeaf;
        Node **ptr;
        T *key;
        int size;
    
    public:
        Node() {
            key = new T[M];
            ptr = new Node<T> *[M + 1];
            data = NULL;
        }

        Node(T *pData) {
            key = new T[M];
            this->data = pData;
            ptr = new Node<T> *[M + 1];
        }

        T* getKeys() { //hmmm
            return key;
        }

        int getSize() {
            return size;
        }

        void setSize(int size) {
            this->size = size;
        }

        T* getData() {
            if(this == NULL) {
                return NULL;
            }
            return data;
        }

        void setData(T *pData) {
            this->data = pData;
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