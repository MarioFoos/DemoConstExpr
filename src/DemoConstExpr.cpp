//============================================================================
// Name        : DemoConstExpr.cpp
// Author      : Mario Foos
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <type_traits>
#include <array>
#include <cstddef>

using namespace std;

// Expresiones constantes
constexpr int cuadrado(int x)
{
	return x*x;
}
// Se evalúa en tiempo de compilación
constexpr int resultado = cuadrado (5);

constexpr int sumatoria(int n)
{
	int result = 1;
	for(int i = 1; i <= n; ++i)
	{
		result += i;
	}
	return result;
}

constexpr int suma7 = sumatoria(7);

template<typename T> constexpr auto obtenerValor(T t)
{
	if constexpr(std::is_integral_v<T>)
	{
		// Para tipos enteros se retorn t + 1
		return t + 1;
	}
	else
	{
		// Para otros tipos, simplemente devuelve t
		return t;
	}
}

constexpr std::array<int, 5> generarArray()
{
	array<int, 5> arr = {};

	for(size_t i = 0; i < arr.size (); ++i)
	{
		arr[i] = static_cast<int>(2*i);
	}
	return arr;
}

constexpr auto miArray = generarArray(); // Evaluado en tiempo de compilación.


int main()
{
	//------------------------------------------------
	//cout << resultado << endl;

	//------------------------------------------------
	//cout << suma7 << endl;

	//------------------------------------------------
	//constexpr int valor = 5;

	/*constexpr int a = obtenerValor(5);
	constexpr float b = obtenerValor(5.5);

    cout << a << endl;
    cout << b << endl;*/

	//------------------------------------------------

	for(auto value : miArray)
	{
		cout << value << " ";
	}

	return 0;
}
