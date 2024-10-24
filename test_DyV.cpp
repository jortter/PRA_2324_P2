#include "DyV.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> vI = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<double> vF = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
	vector<char> vC = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	int valor1 = BusquedaBinaria(3, vI, 0, vI.size() - 1);
	int valor2 = BusquedaBinaria(1.7, vF, 0, vF.size() - 1);
	int valor3 = BusquedaBinaria('e', vC, 0, vC.size() - 1);
	
	if(valor1 == -1){
	cout << "No se ha podido encontrar el valor del vector de enteros";
	}else{
	cout << "Se ha encontrado el valor en el vector de enteros en la posicion: " << valor1 << endl;
	}
	if(valor2 == -1){
	cout << "No se ha podido encontrar el valor del vector de double";
	}else{
	cout << "Se ha encontrado el valor en el vector de double en la posicion: " << valor2 << endl;
	}
	if(valor3 == -1){
	cout << "No se ha podido encontrar el valor del vector de char"; 
	}else{
	cout << "Se ha encontrado el valor en el vector de char en la posicion: " << valor3 << endl;
	}

}