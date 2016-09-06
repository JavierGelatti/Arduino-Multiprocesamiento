#ifndef MULTIPROCESAMIENTO_H
#define MULTIPROCESAMIENTO_H

#include "FuncionesMultiprocesamiento.h"

#define ejecutar(unCodigo) \
    ({ auto _cod = comando(unCodigo); agregarCodigo(_cod); })

#endif
