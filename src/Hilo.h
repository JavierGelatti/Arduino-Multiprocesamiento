#ifndef HILO_H
#define HILO_H

#include "Lista.h"
#include "TiempoActual.h"

typedef void (*funcion)();

class Codigo {
public:
    Codigo();
    bool yaEsElMomentoDeEjecutar();
    void ejecutarEn(milisegundos unaDemora);
    void iniciarTemporizador();
    virtual void ejecutar() = 0;
private:
    milisegundos _laDemora;
    milisegundos _tiempoInicio;
    bool _temporizadorIniciado;
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
    void demorarSiguienteCodigoEn(milisegundos tiempoDeDemora);
    bool terminoDeEjecutarse();
private:
    Lista<Codigo*>* _cola;
    Lista<Codigo*>* _colaEnEspera;
    milisegundos _demoraSiguiente;
};

template<typename C>
void Hilo::agregarCodigo(C &codigoAEjecutar) {
    CodigoEspecifico<C>* codigo = new CodigoEspecifico<C>(&codigoAEjecutar);
    codigo->ejecutarEn(_demoraSiguiente);
    _demoraSiguiente = 0;
    _cola->agregarAlFinal(codigo);
}

#endif
