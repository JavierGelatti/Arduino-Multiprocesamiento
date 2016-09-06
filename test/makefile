all: maketest clean

maketest:
	rename -f "s/.test/.cpp/" *
	g++ -g -std=c++11 main.cpp TestLista.cpp TestLambda.cpp TestHilo.cpp TestCoordinadorHilos.cpp StubTiempoActual.cpp ../src/Hilo.cpp ../src/CoordinadorHilos.cpp TestMultiprocesamiento.cpp ../src/Multiprocesamiento.cpp -o runtests
	rename "s/.cpp/.test/" *
	./runtests

clean:
	rm runtests
	rename "s/.cpp/.test/" *
	rm -f ru.tests
	rm -f  *~
