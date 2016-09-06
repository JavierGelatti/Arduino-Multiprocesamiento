#ifndef COORDINADORHILOS_H
#define COORDINADORHILOS_H

#include "Hilo.h"

class CoordinadorHilos {
public:
    CoordinadorHilos();
    void ejecutar();
    template<typename C>
    void agregarCodigo(C &codigoAEjecutar);
    Hilo* crearHilo();
    int cantidadDeHilos();
    void demorarSiguienteCodigoEn(milisegundos tiempoDeDemora);
private:
    Lista<Hilo*>* _hilos;
    Hilo* _hiloActual;
    
    void _crearHilo();
};

template<typename C>
void CoordinadorHilos::agregarCodigo(C &codigoAEjecutar) {
    if (_hilos->estaVacia())
        _crearHilo();

    _hiloActual->agregarCodigo(codigoAEjecutar);
}

#endif
