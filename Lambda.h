#ifndef LAMBDA_H
#define LAMBDA_H

#define lambda(argumentos, unCachoDeCodigo) \
    *([] (argumentos) { unCachoDeCodigo; })

#define closure(argumentos, unCachoDeCodigo) \
    ([&] (argumentos) { unCachoDeCodigo; })

#define comando(unCachoDeCodigo) \
    closure(, unCachoDeCodigo)

#define lambda_alternativo(argumentos, unCachoDeCodigo) \
    *(funcion_anonima(void, (argumentos) {unCachoDeCodigo;}))

#define funcion_anonima(return_type, function_body) \
  ({ struct _lambda { static return_type _f function_body }; *_lambda::_f; })

#endif
