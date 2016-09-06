#ifndef LISTA_H
#define LISTA_H

template <class T>
class Nodo;

template <class T>
class Lista {
public:
    Lista();
    void agregar(T unElemento);
    void agregarAlInicio(T unElemento);
    void agregarAlFinal(T unElemento);
    bool estaVacia();
    int largo();
    T primerElemento();
    T ultimoElemento();
    void eliminarPrimero();
    void eliminarUltimo();
    
    void transferirAlInicioDe(Lista<T>* otraLista);

    template<typename C>
    void forEach(C &consumidor);
    template<typename C>
    void filtrar(C &condicion);

private:
    int _largo;
    Nodo<T>* _primerNodo;
    Nodo<T>* _ultimoNodo;
    void eliminarNodo(Nodo<T>* unNodo);
};

#include "Lista.cpp"

#endif
