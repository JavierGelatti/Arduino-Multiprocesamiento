#ifndef HILO_CPP
#define HILO_CPP

#include "Hilo.h"

typedef void (*funcion)();

class Codigo {
public:
    virtual void ejecutar() = 0;
};

template<typename C>
class CodigoEspecifico : public Codigo {
public:
    CodigoEspecifico(C* unBloque) {
        _elBloqueOriginal = unBloque;
    }
    virtual void ejecutar() {
        (*_elBloqueOriginal)();    
    }
private:
    C* _elBloqueOriginal;
};

Hilo::Hilo() {
    _pila = new Pila<Codigo*>();
}

template<typename C>
void Hilo::agregarCodigo(C &codigoAEjecutar) {
    CodigoEspecifico<C>* codigo = new CodigoEspecifico<C>(&codigoAEjecutar);
    _pila->push(codigo);
}

void Hilo::ejecutar() {
    _pila->pop()->ejecutar();
}

#endif
