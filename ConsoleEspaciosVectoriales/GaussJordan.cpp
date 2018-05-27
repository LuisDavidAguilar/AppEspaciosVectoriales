#include "GaussJordan.h"

using namespace std;

int GaussJordan::pivote;

#pragma region Metodos

GaussJordan::GaussJordan()
{
}


GaussJordan::~GaussJordan()
{
}

Matriz GaussJordan::EscalonarMatriz(Matriz &matriz)
{
	Matriz A = Matriz(matriz);
	pivote = 0;
	while (pivote < A.getRows())
	{
		if (A[pivote][pivote] != 0)
		{
			int renglonActual = pivote + 1;
			while (renglonActual < A.getRows())
			{
				if (A[renglonActual][pivote] == 0)
					renglonActual++;
				
				else
				{
					double x = -A[renglonActual][pivote] / A[pivote][pivote];
					for (int i = 0; i < A.getCols(); i++)
					{
						A[renglonActual][i] = A[pivote][i] * x + A[renglonActual][i];
					}
					renglonActual++;
				}
			}
		}
		else 
		{
			//BUSCAR PIVOTE Y CAMBIAR FILA
		}
		pivote++;
	}
	return A;
}

Matriz GaussJordan::ReducidirRenglones(Matriz &matriz_Source)
{
	Matriz A = Matriz(matriz_Source);
	pivote--;
	while (pivote >= 0)
	{
		if (A[pivote][pivote] != 0)
		{

			double y = 1 / A[pivote][pivote];
			for (int i = 0; i < A.getCols(); i++)
				A[pivote][i] *= y;

			int renglonActual = pivote - 1;
			while (renglonActual >= 0)
			{
				if (A[renglonActual][pivote] == 0)
					renglonActual--;
				else
				{
					double x = -A[renglonActual][pivote] / A[pivote][pivote];
					for (int i = 0; i < A.getCols(); i++)
					{
						A[renglonActual][i] = A[pivote][i] * x + A[renglonActual][i];
					}
					renglonActual--;
				}
			}
		}
		else
		{
			//BUSCAR PIVOTE Y CAMBIAR FILA
		}
		pivote--;
	}
	return A;
}

#pragma endregion

#pragma region MetodosPrivados

bool GaussJordan::ColumnaCero(Matriz &)
{
	return false;
}

#pragma endregion