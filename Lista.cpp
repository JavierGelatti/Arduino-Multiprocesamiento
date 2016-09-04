#ifndef LISTA_CPP
#define LISTA_CPP

#include "Lista.h"

template <class T>
struct Nodo {
    T elemento;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;
};

template <class T>
Lista<T>::Lista() : _largo(0) {
}

template <class T>
bool Lista<T>::estaVacia() {
  return _largo == 0;
}

template <class T>
void Lista<T>::agregar(T unElemento) {
    Nodo<T>* nuevoNodo = new Nodo<T>;
    nuevoNodo->elemento = unElemento;
    nuevoNodo->anterior = _ultimoNodo;

    if (estaVacia())
        _primerNodo = nuevoNodo;
    else
        _ultimoNodo->siguiente = nuevoNodo;  
    
    _ultimoNodo = nuevoNodo;    
    _largo++;    
}

template <class T>
void Lista<T>::agregarAlInicio(T unElemento) {
    if (estaVacia())
        return agregar(unElemento);

    Nodo<T>* nuevoNodo = new Nodo<T>;
    nuevoNodo->elemento = unElemento;
    nuevoNodo->siguiente = _primerNodo;

    _primerNodo->anterior = nuevoNodo;
    _primerNodo = nuevoNodo;   
 
    _largo++;    
}

template <class T>
void Lista<T>::agregarAlFinal(T unElemento) {
    agregar(unElemento);   
}

template <class T>
int Lista<T>::largo() {
    return _largo;
}

template <class T>
T Lista<T>::primerElemento() {
    return _primerNodo->elemento;
}

template <class T>
T Lista<T>::ultimoElemento() {
    return _ultimoNodo->elemento;
}

template <class T>
void Lista<T>::eliminarPrimero() {
    Nodo<T>* nuevoPrimerNodo = _primerNodo->siguiente;
    delete _primerNodo;
    _primerNodo = nuevoPrimerNodo;
    _largo--;
}

template <class T>
void Lista<T>::eliminarUltimo() {
    Nodo<T>* nuevoUltimoNodo = _ultimoNodo->anterior;
    delete _ultimoNodo;
    _ultimoNodo = nuevoUltimoNodo;
    _largo--;
}

template <class T>
void Lista<T>::transferirAlInicioDe(Lista<T>* otraLista) {
    while (!estaVacia()) {
        otraLista->agregarAlInicio(ultimoElemento());
        eliminarUltimo();
    }
}

#endif

