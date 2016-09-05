#ifndef HILO_H
#define HILO_H

#include "Cola.h"

typedef void (*funcion)();

class Codigo;

class Hilo {
public:
    Hilo();
    void ejecutar();

    template <typename C>
    void agregarCodigo(C &codigoAEjecutar);
private:
    Cola<Codigo*>* _cola;
    Cola<Codigo*>* _colaEnEspera;
};

#include "Hilo.cpp"

#endif
