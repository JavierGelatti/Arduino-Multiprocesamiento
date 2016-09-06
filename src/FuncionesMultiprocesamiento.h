#ifndef MULTIPROCESAMIENTO_F_H
#define MULTIPROCESAMIENTO_F_H

#include "TiempoActual.h"
#include "CoordinadorHilos.h"

CoordinadorHilos* getCoordinadorHilos();

template<typename C>
void agregarCodigo(C &codigoAEjecutar) {
    getCoordinadorHilos()->agregarCodigo(codigoAEjecutar);
}

void ejecutarHilos();

void esperar(milisegundos unTiempo);

void nuevoHilo();

void agregarCodigo();

#endif
