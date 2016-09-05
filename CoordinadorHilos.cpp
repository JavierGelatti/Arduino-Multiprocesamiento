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
    _hilos->filtrar(lambda(Hilo* h, return !h->terminoDeEjecutarse()));
}

Hilo* CoordinadorHilos::crearHilo() {
    Hilo* elHiloNuevo = new Hilo();
    _hilos->agregar(elHiloNuevo);
    return elHiloNuevo;
}

int CoordinadorHilos::cantidadDeHilos() {
    return _hilos->largo();
}

void CoordinadorHilos::demorarSiguienteCodigoEn(milisegundos tiempoDeDemora) {
    _hilos->ultimoElemento()->demorarSiguienteCodigoEn(tiempoDeDemora);
}

#endif
