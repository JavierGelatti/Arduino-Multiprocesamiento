#ifndef COORDINADORHILOS_CPP
#define COORDINADORHILOS_CPP

#include "CoordinadorHilos.h"

CoordinadorHilos::CoordinadorHilos() {
    _hilos = new Lista<Hilo*>();
    _hilos->agregar(new Hilo());
}

void CoordinadorHilos::ejecutar() {
    _hilos->primerElemento()->ejecutar();
}

#endif
