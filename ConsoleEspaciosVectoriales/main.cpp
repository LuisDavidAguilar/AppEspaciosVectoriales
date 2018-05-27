#include <iostream>

#include "RVector.h"
#include "Matriz.h"
#include "GaussJordan.h"

using namespace std;

int main()
{
	//double v[4] = { 6, 3, 8, 9 }, u[4] = { -5, 5, 8, 4 }, w[4] = { 4, 3, 9, 7 }, x[4] = { 1, 3, 5, 9 };
	//double v[4] = { 6, 3, 8, 9 }, u[4] = { -5, 5, 8, 4 };
	//double v[4] = { 6, 3, 8 ,9 }, u[4] = { -5, 5, 8, 4 } ;
	double v[5] = { 4, -1, -11, 3, -4 }, u[5] = { 4, 3, 1, -1, -5 }, w[5]={ 1, -2, -8, 3, -2 }, x[5]{ 4, -1, -11, 0, 1 };//matriz ampliada
	Matriz A = Matriz(4, 5);
	A.Fill(RVector(sizeof(v)/sizeof(v[0]), v));
	A.Fill(RVector(sizeof(u) / sizeof(u[0]), u));
	A.Fill(RVector(sizeof(w) / sizeof(w[0]), w));
	A.Fill(RVector(sizeof(x) / sizeof(x[0]), x));

	cout << endl << A.DisplayMatriz() << endl;

	//A[0][2] = 3;

	cout << endl << GaussJordan::EscalonarMatriz(A).DisplayMatriz() << endl;

	cout << endl << GaussJordan::ReducidirRenglones(A).DisplayMatriz() << endl;

	cin.get();

	return 0;
}

