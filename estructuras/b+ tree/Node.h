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
        T *key;
        int size;
        Node *left;
        Node *right;  
    
    public:
        Node() {
            key = new T[M];
            data = NULL;
            left = NULL;
            right = NULL;   
        }

        Node(T *pData) {
            key = new T[M];
            this->data = pData;
            left = NULL;
            right = NULL; 
        }

        T* getKeys() {
            return key;
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

        Node* getLeft() {
            if(this == NULL || left == NULL) {
                return NULL;
            }
            return left;
        }

        Node* getRight() {    
            if(this == NULL || right == NULL) {
                return NULL;
            }
            return right;     
        }

        void setLeft(Node<T> *pValue) {
            this->left = pValue;
        }

        void setRight(Node<T> *pValue) {  
            this->right = pValue;      
        }   
};

#endif