#include "catch.hpp"
#include "../Pila.h"

SCENARIO("creación de pilas", "[pila]") {
    GIVEN("ninguna precondición") {
        WHEN("se crea una pila") {
            Pila<char> p;
            
            THEN("esta vacía") {
                REQUIRE(p.estaVacia());
            }
        }
    }
}

SCENARIO("manipulación de elementos", "[pila]") {
    GIVEN("una pila vacía") {
        Pila<char> p;
        WHEN("se hace push") {
            p.push('a');
            
            THEN("la pila ya no está vacía") {
                REQUIRE(!p.estaVacia());
            }
            THEN("el alto es uno") {
                REQUIRE(p.alto() == 1);
            }
        }
    }
    GIVEN("una pila con un elemento") {
        Pila<char> p;
        p.push('a');

        WHEN("se hace pop") {
            char resultado = p.pop();
            
            THEN("se devuelve el elemento") {
                REQUIRE(resultado == 'a');
            }
            THEN("se reduce el alto de la pila en uno") {
                REQUIRE(p.alto() == 0);
            }
        }
        WHEN("se hace push") {
            p.push('b');
            
            THEN("se incrementa el alto") {
                REQUIRE(p.alto() == 2);
            }
        }
    }
    GIVEN("una pila con elementos") {
        Pila<char> p;
        p.push('a');
        p.push('b');
        p.push('c');

        WHEN("se hace pop de todos los elementos") {
            char r1 = p.pop();
            char r2 = p.pop();
            char r3 = p.pop();
            
            THEN("se devuelven según el orden LIFO") {
                REQUIRE(r1 == 'c');
                REQUIRE(r2 == 'b');
                REQUIRE(r3 == 'a');
            }
            THEN("la pila esta vacía") {
                REQUIRE(p.alto() == 0);
                REQUIRE(p.estaVacia());
            }
        }
    }
}
