all: maketest clean

maketest:
	rename -f "s/.test/.cpp/" *
	g++ -g -std=c++11 main.cpp TestLista.cpp TestLambda.cpp TestHilo.cpp -o runtests
	rename "s/.cpp/.test/" *
	./runtests

clean:
	rm runtests
	rename "s/.cpp/.test/" *
	rm -f ru.tests
	rm -f  *~
