#ifndef HILO_CPP
#define HILO_CPP

#include "Hilo.h"

Codigo::Codigo() {
    _laDemora = 0;
    _temporizadorIniciado = false;
}
bool Codigo::yaEsElMomentoDeEjecutar() {
    if (!_temporizadorIniciado)
        return _laDemora == 0;

    return tiempoActual() >= _tiempoInicio + _laDemora;
}
void Codigo::ejecutarEn(milisegundos unaDemora) {
    _laDemora = unaDemora;
}
void Codigo::iniciarTemporizador() {
    if (_temporizadorIniciado)
        return;

    _temporizadorIniciado = true;
    _tiempoInicio = tiempoActual();
}


Hilo::Hilo() {
    _cola = new Lista<Codigo*>();
    _demoraSiguiente = 0;
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
    
    if (!_cola->estaVacia())
        _cola->primerElemento()->iniciarTemporizador();
}

void Hilo::demorarUltimoCodigoEn(milisegundos tiempoDeDemora) {
    _cola->ultimoElemento()->ejecutarEn(tiempoDeDemora);
}

void Hilo::demorarSiguienteCodigoEn(milisegundos tiempoDeDemora) {
    _demoraSiguiente = tiempoDeDemora;
}

bool Hilo::terminoDeEjecutarse() {
    return _cola->estaVacia();
}

#endif
