#ifndef COLA_H
#define COLA_H

#include "Lista.h"

template <class T>
class Cola : public Lista<T> {
public:
    void encolar(T unElemento);
    T desencolar();

private:
};

#include "Cola.cpp"

#endif
