#ifndef HILO_H
#define HILO_H

#include "Cola.h"
#include "TiempoActual.h"

typedef void (*funcion)();

class Codigo;

class Hilo {
public:
    Hilo();
    void ejecutar();

    template <typename C>
    void agregarCodigo(C &codigoAEjecutar);

    void demorarUltimoCodigoEn(milisegundos tiempoDeDemora);
private:
    Cola<Codigo*>* _cola;
    Cola<Codigo*>* _colaEnEspera;
};

#include "Hilo.cpp"

#endif
