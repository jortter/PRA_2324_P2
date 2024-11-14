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

// Función BusquedaBinaria_INV para vectores ordenados de manera descendente
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

/**** PSEUDOCODIGO FUNCION SORT
QuickSort(val[] V, int ini, int fin):
        Si ini < fin:
                 int pivot = Partition(V, ini, fin)
                 QuickSort(V, ini, pivot - 1)
                 QuickSort(V, pivot + 1, fin)

Partition(val[] V, int ini, int fin):
         val x = V[fin]
         int i = ini
         Para j = ini hasta fin - 1:
               Si V[j] <= x:
                     Intercambiar V[i] V[j]
                     i = i + 1
         Intercambiar V[i] V[fin]
         Devolver i 
****/


// función para intercambiar dos elementos
template <typename t>
void swap(t& a, t& b) {
    t temp = a;
    a = b;
    b = temp;
}

// Funcion Partition
template <typename T>
int Partition(std::vector<T>& v, int ini, int fin){
	T x = v[fin];
	int i = ini;
	for( int j = ini; j < fin; j++){
		if(v[j] <= x){
			swap(v[i], v[j]);
			i++;
		}
	}
	swap(v[i], v[fin]);
	return i;
}

// Partition usando el primer elemento como pivote
int PartitionPrimero(std::vector<int>& V, int ini, int fin) {
    swap(V[ini], V[fin]); // Cambiamos el primer elemento con el último para reutilizar la misma lógica
    return Partition(V, ini, fin);
}

// Partition usando un elemento aleatorio como pivote
template <typename T>
int PartitionAleatorio(std::vector<T>& V, int ini, int fin) {
   	int random_index = ini + std::rand() % (fin - ini + 1);
    swap(V[random_index], V[fin]);
    return Partition(V, ini, fin);
}

// Partition usando el elemento central como pivote
template <typename T>
int PartitionCentral(std::vector<T>& V, int ini, int fin) {
    int mid = (ini + fin) / 2;
    swap(V[mid], V[fin]);
    return Partition(V, ini, fin);
}

// Funcion QuickSort último
template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(v, ini, fin);
		QuickSort(v, ini, pivot -1);
		QuickSort(v, pivot + 1, fin);
	}
}


// Funcion QuickSort primero
template <typename T>
void QuickSortPrimero(std::vector<T>& v, int ini, int fin){
	if(ini < fin){
		int pivot = PartitionPrimero(v, ini, fin);
		QuickSortPrimero(v, ini, pivot -1);
		QuickSortPrimero(v, pivot + 1, fin);
	}
}

// Funcion QuickSort aleatorio
template <typename T>
void QuickSortAleatorio(std::vector<T>& v, int ini, int fin){
	if(ini < fin){
		int pivot = PartitionAleatorio(v, ini, fin);
		QuickSortAleatorio(v, ini, pivot -1);
		QuickSortAleatorio(v, pivot + 1, fin);
	}
}

// Funcion QuickSort central
template <typename T>
void QuickSortCentral(std::vector<T>& v, int ini, int fin){
	if(ini < fin){
		int pivot = PartitionCentral(v, ini, fin);
		QuickSortCentral(v, ini, pivot -1);
		QuickSortCentral(v, pivot + 1, fin);
	}
}
