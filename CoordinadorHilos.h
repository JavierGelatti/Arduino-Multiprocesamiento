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
private:
    Lista<Hilo*>* _hilos;
};

template<typename C>
void CoordinadorHilos::agregarCodigo(C &codigoAEjecutar) {
    if (_hilos->estaVacia())
        _hilos->agregar(new Hilo());

    _hilos->primerElemento()->agregarCodigo(codigoAEjecutar);
}

#endif
