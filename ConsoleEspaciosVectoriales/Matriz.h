#pragma once
#include "RVector.h"
#include <string>

class Matriz
{
private:
	//<editor-fold desc="AtributosMatriz">
	int rows;
	int cols;
	RVector *vectores;
	int static row_index;
	//</editor-fold>
public:
	//<editor-fold desc="ConstructoresMatriz">
	Matriz();

	//Matriz(int rows, int cols, Vector *vectores);

	Matriz(Matriz&);

	Matriz(int rows, int cols);

	~Matriz();
	//</editor-fold>

	//<editor-fold desc="PropiedadesMatriz">
	int getRows() const;

	int getCols() const;

	RVector *getVectores() const;
	//</editor-fold>


	//<editor-fold desc="MetodosMatriz">
	void Fill(const RVector&);
	RVector& operator[](int);
	friend Matriz operator*(const Matriz&, const Matriz&);
	std::string DisplayMatriz();
	void Clear();
	bool Empty();
	//</editor-fold>
};

