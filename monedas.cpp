#include <iostream>
#include <algorithm>
#include <vector>

const int infinito = 1e9;	// Mejor un valor muy alto que poner infinito para evitar problemas de desbordamiento

int cambio(const std::vector<int>& v, int n, int fin, int** M){
	// Casos base -> El orden de los casos base en el código respecto al caso base de la función de memoria IMPORTA!!

	// Si la cantidad a devolver es 0 (no queda cantidad) pues no devuelvo ningún mínimo de monedas
	if(n == 0)
		return 0;
	// Si al hacer n - v[fin] en la llamada recursiva acabo llegando a < 0, devuelvo infinito porque estoy minimizando (sino devolvería un -1 o algo así)
	// Al ir haciendo fin-1 en la llamada recursiva puedo llegar al punto en el que fin sea < 0 (no quedan monedas), en tal caso devuelvo infinito
	if(n < 0 || fin < 0)		
		return infinito;
	// Ponemos el caso base de la función de memoria en el último en orden para evitar segmentation faults (evitar que n < 0 o fin < 0 después de checkear, para no acceder
	// a posiciones inválidas)
	// Si no hemos visitado esa solución nunca, la visitamos y nos guardamos su valor en la tabla
	if(M[n][fin] != -1)
		return M[n][fin];

	// Caso recursivo
	M[n][fin] = std::min(0 + cambio(v, n, fin-1, M), 1 + cambio(v, n-v[fin], fin, M));
	// Devolvemos el valor óptimo situado en la matriz de memoria
	return M[n][fin];
}

int main(){
	// Vector de sistema de monedas v
	std::vector<int> v = {1, 4, 6};
	int cantidad = 8;
	// M es el valor óptimo (función de memoria). Recordar que una matriz en C/C++ es un array de arrays
	// Como un array es un puntero a la primera posición del array, una matriz es un puntero a una secuencia de punteros
	// Aquí reservamos memoria para las filas de la matriz (v.size()), las cuales serán punteros a otros arrays (a las columnas, luego las filas apuntan a las columanas)
	// La matriz será de (cantidad+1) x (v.size()+1)
	int** M = new int*[cantidad+1];
	// Reservamos memoria para las columnas e inicializamos la matriz a -1 usando std::fill(inicio, fin, valor)
	for(int i = 0; i <= cantidad; i++){
		M[i] = new int[v.size()+1];		// Los +1 en v.size() y en cantidad es porque la matriz va de 0 a n (8) y de 0 a v.size() (3)
		std::fill(M[i], M[i] + v.size()+1, -1);
	}

	// La función me debería devolver la tabla de memoria que contendría el número mínimo de monedas de cada valor para devolver cada cantidad hasta 8
	int resultado = cambio(v, cantidad, v.size()-1, M);

	if(resultado == infinito)
		std::cout << "No se puede devolver la cantidad con las monedas dadas" << std::endl;
	else
		std::cout << "El número de monedas mínimo para la cantidad de monedas es: " << resultado << std::endl;

	// Debemos liberar la memoria -> HACER ESTO SIEMPRE A NO SER QUE USEMOS PUNTEROS INTELIGENTES
	for(int i = 0; i <= cantidad; i++){
		// Liberamos las filas
		delete[] M[i];
	}
	// Liberamos las columnas (lo que sobra)
	delete[] M;

	return 0;
}
