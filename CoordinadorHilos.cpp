#ifndef COORDINADORHILOS_CPP
#define COORDINADORHILOS_CPP

#include "CoordinadorHilos.h"
#include "Lambda.h"

CoordinadorHilos::CoordinadorHilos() {
    _hilos = new Lista<Hilo*>();
    _hilos->agregar(new Hilo());
}

void CoordinadorHilos::ejecutar() {
    _hilos->forEach(lambda(Hilo* h, h->ejecutar()));
}

Hilo* CoordinadorHilos::crearHilo() {
    Hilo* elHiloNuevo = new Hilo();
    _hilos->agregar(elHiloNuevo);
    return elHiloNuevo;
}

#endif
