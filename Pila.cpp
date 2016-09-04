#ifndef PILA_CPP
#define PILA_CPP

#include "Pila.h"

template <class T>
void Pila<T>::push(T unElemento) {
  return this->agregarAlFinal(unElemento);
}

template <class T>
int Pila<T>::alto() {
  return this->largo();
}

template <class T>
T Pila<T>::pop() {
  T elemento = this->ultimoElemento();
  this->eliminarUltimo();
  return elemento;
}

#endif
