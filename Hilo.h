#ifndef HILO_H
#define HILO_H

#include "Lista.h"
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
    Lista<Codigo*>* _cola;
    Lista<Codigo*>* _colaEnEspera;
};

#include "Hilo.cpp"

#endif
