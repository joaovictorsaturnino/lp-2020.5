#ifndef VectorSupermercado_H
#define VectorSupermercado_H
#include <iostream>

using namespace std;

template <class T>

class VectorSupermercado{
    public:
    int size;
    int top;
    T* elements;

    VectorSupermercado();
    
    VectorSupermercado(int s){
        this->size = s;
        this->top = -1;
        this->elements = new T[size];
    }

    void push(T element){
        if(top == (size -1)){
            cout << "Lista cheia" << endl;
        }else{
            this->elements[++top] = element;
        }
    }
    void pop(){
        if(top == -1){
            cout << "Lista vazia" << endl;
        }else{
            this->elements[top--];
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    T back(){
        return this->elements[top];
    }
};

#endif