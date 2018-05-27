#pragma once

#include "Matriz.h"
#include "RVector.h"

class GaussJordan
{
private:
	static bool ColumnaCero(Matriz&);
	static int pivote;
public:
	GaussJordan();
	~GaussJordan();

	static Matriz EscalonarMatriz(Matriz&);
	static Matriz ReducidirRenglones(Matriz&);
};

