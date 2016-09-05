#ifndef HILO_H
#define HILO_H

#include "Lista.h"
#include "TiempoActual.h"

typedef void (*funcion)();

class Codigo {
public:
    Codigo();
    bool yaEsElMomentoDeEjecutar();
    void ejecutarEn(milisegundos unMomento);
    virtual void ejecutar() = 0;
private:
    milisegundos _elMomentoDeEjecutar;
};

template<typename C>
class CodigoEspecifico : public Codigo {
public:
    CodigoEspecifico(C* unBloque) { _elBloqueOriginal = unBloque; }
    virtual void ejecutar() { (*_elBloqueOriginal)(); };
private:
    C* _elBloqueOriginal;
};

class Hilo {
public:
    Hilo();
    void ejecutar();

    template <typename C>
    void agregarCodigo(C &codigoAEjecutar);

    void demorarUltimoCodigoEn(milisegundos tiempoDeDemora);
private:
    Lista<Codigo*>* _cola;
    Lista<Codigo*>* _colaEnEspera;
};

template<typename C>
void Hilo::agregarCodigo(C &codigoAEjecutar) {
    CodigoEspecifico<C>* codigo = new CodigoEspecifico<C>(&codigoAEjecutar);
    _cola->agregarAlFinal(codigo);
}

#endif
