#ifndef MULTIPROCESAMIENTO_H
#define MULTIPROCESAMIENTO_H

#include "FuncionesMultiprocesamiento.h"
#include "Lambda.h"

#define ejecutar(unCodigo) \
    ({ auto _cod = comando(unCodigo); agregarCodigo(_cod); })

#endif
