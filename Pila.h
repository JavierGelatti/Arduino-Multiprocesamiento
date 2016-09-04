#ifndef PILA_H
#define PILA_H

#include "Lista.h"

template <class T>
class Pila : public Lista<T> {
public:
    int alto();
    void push(T unElemento);
    T pop();

private:
};

#include "Pila.cpp"

#endif
