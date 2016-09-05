#ifndef HILO_CPP
#define HILO_CPP

#include "Hilo.h"

class Codigo {
public:
    virtual void ejecutar() = 0;
    Codigo() {
        _elMomentoDeEjecutar = 0;
    }
    bool yaEsElMomentoDeEjecutar() {
        return tiempoActual() >= _elMomentoDeEjecutar;
    }
    void ejecutarEn(milisegundos unMomento) {
        _elMomentoDeEjecutar = unMomento;
    }
private:
    milisegundos _elMomentoDeEjecutar;
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
    _cola = new Cola<Codigo*>();
}

template<typename C>
void Hilo::agregarCodigo(C &codigoAEjecutar) {
    CodigoEspecifico<C>* codigo = new CodigoEspecifico<C>(&codigoAEjecutar);
    _cola->agregarAlFinal(codigo);
}

void Hilo::ejecutar() {
    Codigo* aEjecutar = _cola->primerElemento();
    if (aEjecutar->yaEsElMomentoDeEjecutar()) {
        _cola->eliminarPrimero();
        _colaEnEspera = _cola;

        _cola = new Cola<Codigo*>();
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
