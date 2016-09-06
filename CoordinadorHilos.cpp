#ifndef COORDINADORHILOS_CPP
#define COORDINADORHILOS_CPP

#include "CoordinadorHilos.h"
#include "Lambda.h"

CoordinadorHilos::CoordinadorHilos() {
    _hilos = new Lista<Hilo*>();
    _crearHilo();
}

void CoordinadorHilos::_crearHilo() {
    Hilo* elHiloNuevo = new Hilo();
    _hiloActual = elHiloNuevo;
    _hilos->agregar(elHiloNuevo);
}

void CoordinadorHilos::ejecutar() {
    auto ejecutarHilo = closure(Hilo* h, _hiloActual = h; h->ejecutar());
    _hilos->forEach(ejecutarHilo);
    _hilos->filtrar(lambda(Hilo* h, return !h->terminoDeEjecutarse()));
}

Hilo* CoordinadorHilos::crearHilo() {
    _crearHilo();
    return _hiloActual;
}

int CoordinadorHilos::cantidadDeHilos() {
    return _hilos->largo();
}

void CoordinadorHilos::demorarSiguienteCodigoEn(milisegundos tiempoDeDemora) {
    if (_hilos->estaVacia())
        _crearHilo();
 
    _hiloActual->demorarSiguienteCodigoEn(tiempoDeDemora);
}

#endif
