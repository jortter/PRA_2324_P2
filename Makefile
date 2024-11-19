bin/testCambio: monedas.cpp
	mkdir -p bin
	g++ -o bin/testCambio monedas.cpp
clean:
	rm -rf *.o *.gch bin 2>/dev/null || true
