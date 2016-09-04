#ifndef HILO_H
#define HILO_H

#include "Pila.h"

class Codigo;

class Hilo {
public:
    Hilo();
    void ejecutar();

    template <typename C>
    void agregarCodigo(C &codigoAEjecutar);
private:
    Pila<Codigo*>* _pila;
};

#include "Hilo.cpp"

#endif
