all: maketest clean

maketest:
	rename "s/.test/.cpp/" *
	g++ main.cpp TestLista.cpp TestPila.cpp -o runtests
	rename "s/.cpp/.test/" *
	./runtests

clean:
	rm runtests
