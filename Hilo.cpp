#ifndef HILO_CPP
#define HILO_CPP

#include "Hilo.h"

Codigo::Codigo() {
    _elMomentoDeEjecutar = 0;
}
bool Codigo::yaEsElMomentoDeEjecutar() {
    return tiempoActual() >= _elMomentoDeEjecutar;
}
void Codigo::ejecutarEn(milisegundos unMomento) {
    _elMomentoDeEjecutar = unMomento;
}


Hilo::Hilo() {
    _cola = new Lista<Codigo*>();
}

void Hilo::ejecutar() {
    if (_cola->estaVacia()) return;

    Codigo* aEjecutar = _cola->primerElemento();
    if (aEjecutar->yaEsElMomentoDeEjecutar()) {
        _cola->eliminarPrimero();
        _colaEnEspera = _cola;

        _cola = new Lista<Codigo*>();
        aEjecutar->ejecutar();
        _cola->transferirAlInicioDe(_colaEnEspera);
        delete _cola;

        _cola = _colaEnEspera;
    }
}

void Hilo::demorarUltimoCodigoEn(milisegundos tiempoDeDemora) {
    _cola->ultimoElemento()->ejecutarEn(tiempoActual() + tiempoDeDemora);
}

#endif
