// Para compilar: g++ -c DyV.h (crea un archivo .ghc que se debe borrar antes de copilar con el test_DyV.cpp)

#include<vector>
/*****	UTILIDADES DE LA CLASE VECTOR
std::vector<int> a;            //Vector de ints vacío
std::vector<float> b(10);      //Vector de floats con 10 elementos
std::vector<short> d{1, 2, 3}; //Vector de shorts con 3 elementos: 1, 2 y 3

size_t val = b.size();         //Tamaño del vector b
a.push_back(10);               //Añade el valor 10 al final del vector a
d.pop_back();                  //Elimina el último valor del vector d.
float val2 = b[3];             //Devuelve el valor que haya en la posición 3 de b

*****/
/*****		PSEUDOCODIGO DE BUSQUEDA BINARIA

BusquedaBinaria(val X, val[] V, int ini, int fin):
        Si ini > fin:
                 Devolver “No se encuentra en el array”
        int medio = (ini + fin) / 2
        Si (V[medio] == X):
                 Devolver medio
        SiNo Si(V[medio] > X):
                 Devolver BusquedaBinaria(X, V, ini, medio – 1)
        SiNo:
                 Devolver BusquedaBinaria(X, V, medio + 1, fin)

*****/

#include <iostream>


// Funcion BusquedaBinaria
template <typename T>
int BusquedaBinaria(T x, std::vector<T>& v, int ini, int fin){
	if(ini > fin){
		return -1;
	}
	int medio = (ini + fin) / 2;
	if(v[medio] == x){
		return medio;
	}
	else if(v[medio] > x){
		return BusquedaBinaria(x, v, ini, medio -1);
	}else{
		return BusquedaBinaria(x, v, medio +1, fin);
	}
}

template <typename T>
int BusquedaBinaria_INV(T x, std::vector<T>& v, int ini, int fin){
	if(ini > fin){
		return -1;
	}
	int medio = (ini + fin) / 2;
	if(v[medio] == x){
		return medio;
	}
	else if(v[medio] > x){
		return BusquedaBinaria_INV(x, v, medio +1, fin);
	}else{
		return BusquedaBinaria_INV(x, v, ini, medio -1);
	}
}
