#include "DyV.h"
#include <iostream>
#include <vector>

using namespace std;

// Función para verificar si un vector está ordenado en orden ascendente
template <typename T>
bool estaOrdenado(const std::vector<T>& vec) {
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
    }
    return true;
}

// Función para probar QuickSort con diferentes tipos de datos
void testQuickSort() {
    bool todas_las_pruebas_correctas = true;

    // Prueba con enteros
    std::vector<int> vec_int = {34, 7, 23, 32, 5, 62};
    QuickSort(vec_int, 0, vec_int.size() - 1);
    if (estaOrdenado(vec_int)) {
        std::cout << "Prueba con int pasó correctamente.\n";
    } else {
        std::cout << "Prueba con int falló.\n";
        todas_las_pruebas_correctas = false;
    }

    // Prueba con flotantes
    std::vector<float> vec_float = {3.4, 7.1, 2.3, 3.2, 5.0, 6.2};
    QuickSort(vec_float, 0, vec_float.size() - 1);
    if (estaOrdenado(vec_float)) {
        std::cout << "Prueba con float pasó correctamente.\n";
    } else {
        std::cout << "Prueba con float falló.\n";
        todas_las_pruebas_correctas = false;
    }

    // Prueba con caracteres
    std::vector<char> vec_char = {'d', 'a', 'c', 'f', 'b', 'e'};
    QuickSort(vec_char, 0, vec_char.size() - 1);
    if (estaOrdenado(vec_char)) {
        std::cout << "Prueba con char pasó correctamente.\n";
    } else {
        std::cout << "Prueba con char falló.\n";
        todas_las_pruebas_correctas = false;
    }

    // Resultado final
    if (todas_las_pruebas_correctas) {
        std::cout << "Todas las pruebas de QuickSort pasaron correctamente." << std::endl;
    } else {
        std::cout << "Algunas pruebas de QuickSort fallaron." << std::endl;
    }
}

int main(){

	vector<int> vI = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<double> vF = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
	vector<char> vC = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	
	vector<int> invVi = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	vector<double> invVf = {2.0, 1.9, 1.8, 1.7, 1.6, 1.5, 1.4, 1.3, 1.2, 1.1};
	vector<char> invVc = {'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

	int valor1 = BusquedaBinaria(3, vI, 0, vI.size() - 1);
	int valor2 = BusquedaBinaria(1.7, vF, 0, vF.size() - 1);
	int valor3 = BusquedaBinaria('e', vC, 0, vC.size() - 1);

	int valor4 = BusquedaBinaria_INV(7, invVi, 0, invVi.size() -1);
	int valor5 = BusquedaBinaria_INV(1.3, invVf, 0, invVf.size() -1);
	int valor6 = BusquedaBinaria_INV('E', invVc, 0, invVc.size() -1);
	
	if(valor1 == -1 || valor4 == -1){
	cout << "No se ha podido encontrar el valor del vector de enteros";
	}else{
	cout << "Se ha encontrado el valor en el vector de enteros en la posicion: " << valor1 << " Posición inv:" << valor4 << endl;
	}
	if(valor2 == -1 || valor5 == -1){
	cout << "No se ha podido encontrar el valor del vector de double";
	}else{
	cout << "Se ha encontrado el valor en el vector de double en la posicion: " << valor2 << " Posición inv:" << valor5 << endl;
	}
	if(valor3 == -1 || valor6 == -1){
	cout << "No se ha podido encontrar el valor del vector de char"; 
	}else{
	cout << "Se ha encontrado el valor en el vector de char en la posicion: " << valor3	<< " Posición inv:" << valor6 << endl;
	}

	testQuickSort();

}
