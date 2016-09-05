#ifndef COLA_CPP
#define COLA_CPP

#include "Cola.h"

template <class T>
void Cola<T>::encolar(T unElemento) {
  return this->agregarAlFinal(unElemento);
}

template <class T>
T Cola<T>::desencolar() {
  T elemento = this->primerElemento();
  this->eliminarPrimero();
  return elemento;
}

#endif
