all: maketest clean

maketest:
	rename -f "s/.test/.cpp/" *
	g++ -g -std=c++11 main.cpp TestLista.cpp TestPila.cpp TestLambda.cpp TestMultiprocesamiento.cpp -o runtests
	rename "s/.cpp/.test/" *
	./runtests

clean:
	rm runtests
