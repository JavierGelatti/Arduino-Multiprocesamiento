#ifndef MULTIPROCESAMIENTO_CPP
#define MULTIPROCESAMIENTO_CPP

#include "FuncionesMultiprocesamiento.h"

CoordinadorHilos* _elCoordinador = new CoordinadorHilos();

CoordinadorHilos* getCoordinadorHilos() {
    return _elCoordinador;
}

void ejecutarHilos() {
    _elCoordinador->ejecutar();
}

void esperar(milisegundos unTiempo) {
    _elCoordinador->demorarSiguienteCodigoEn(unTiempo);
}

void nuevoHilo() {
    _elCoordinador->crearHilo();
}

#endif
