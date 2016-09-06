#ifndef LISTA_CPP
#define LISTA_CPP

#include "Lista.h"

template <class T>
class Nodo {
public:
    Nodo(T unElemento) {
        this->_elemento = unElemento;
        this->_anterior = this;
        this->_siguiente = this;
    }
    void acoplarseDespuesDe(Nodo<T>* otroNodo) {
        this->_anterior = otroNodo;
        otroNodo->_siguiente = this;
    }
    void acoplarseAntesDe(Nodo<T>* otroNodo) {
        otroNodo->acoplarseDespuesDe(this);
    }
    void eliminarAnterior() {
        if (this->_anterior != this)
            delete this->_anterior;
        this->_anterior = this;    
    }
    void eliminarSiguiente() {
        if (this->_siguiente != this)
            delete this->_siguiente;
        this->_siguiente = this;    
    }
    void desvincularse() {
        this->_anterior->_siguiente = this->_siguiente;
        this->_siguiente->_anterior = this->_anterior;
        this->_anterior = this;
        this->_siguiente = this;
    }
    T elemento() {
        return _elemento;
    }
    Nodo<T>* anterior() {
        return _anterior;
    };
    Nodo<T>* siguiente() {
        return _siguiente;
    };
private:
    T _elemento;
    Nodo<T>* _anterior;
    Nodo<T>* _siguiente;
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
    Nodo<T>* nuevoNodo = new Nodo<T>(unElemento);

    if (estaVacia())
        _primerNodo = nuevoNodo;
    else
        nuevoNodo->acoplarseDespuesDe(_ultimoNodo);
    
    _ultimoNodo = nuevoNodo;    
    _largo++;    
}

template <class T>
void Lista<T>::agregarAlInicio(T unElemento) {
    if (estaVacia())
        return agregar(unElemento);

    Nodo<T>* nuevoNodo = new Nodo<T>(unElemento);
    nuevoNodo->acoplarseAntesDe(_primerNodo);

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
    return _primerNodo->elemento();
}

template <class T>
T Lista<T>::ultimoElemento() {
    return _ultimoNodo->elemento();
}

template <class T>
void Lista<T>::eliminarPrimero() {
    _primerNodo = _primerNodo->siguiente();
    _primerNodo->eliminarAnterior();
    _largo--;
}

template <class T>
void Lista<T>::eliminarUltimo() {
    _ultimoNodo = _ultimoNodo->anterior();
    _ultimoNodo->eliminarSiguiente();
    _largo--;
}

template <class T>
void Lista<T>::transferirAlInicioDe(Lista<T>* otraLista) {
    while (!estaVacia()) {
        otraLista->agregarAlInicio(ultimoElemento());
        eliminarUltimo();
    }
}

template <class T>
template <typename C>
void Lista<T>::forEach(C &consumidor) {
    Nodo<T>* nodoActual = _primerNodo;
    for (int i = 0; i < _largo; i++) {
        consumidor(nodoActual->elemento());
        nodoActual = nodoActual->siguiente();
    }
}

template <class T>
template <typename C>
void Lista<T>::filtrar(C &condicion) {
    Nodo<T>* nodoActual = _primerNodo;
    int nodosEliminados = 0;

    for (int i = 0; i < _largo; i++) {
        Nodo<T>* nodoSiguiente = nodoActual->siguiente();
        if (!condicion(nodoActual->elemento())) {
            eliminarNodo(nodoActual);
            nodosEliminados++;              
        }
        nodoActual = nodoSiguiente;
    }

    _largo -= nodosEliminados;
}

template <class T>
void Lista<T>::eliminarNodo(Nodo<T>* unNodo) {
    if (unNodo == _primerNodo)
        _primerNodo = unNodo->siguiente();
    if (unNodo == _ultimoNodo)
        _ultimoNodo = unNodo->anterior();

    unNodo->desvincularse();
    delete unNodo;
}

#endif

