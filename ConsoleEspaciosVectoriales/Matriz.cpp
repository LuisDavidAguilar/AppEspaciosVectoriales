#include "Matriz.h"


using namespace std;

int Matriz::row_index;

//<editor-fold desc="ConstructoresMatriz">
Matriz::Matriz() {
	rows = 0;
	cols = 0;
	vectores = new RVector[0];
}

//Matriz::Matriz(int rows, int cols, Vector *vectores) : rows(rows), cols(cols), vectores(vectores) {}

Matriz::Matriz(int rows, int cols) : rows(rows), cols(cols), vectores(new RVector[rows]) {}

Matriz::~Matriz() {

}
//</editor-fold>



//<editor-fold desc="PropiedadesMatriz">
int Matriz::getRows() const {
	return rows;
}

int Matriz::getCols() const {
	return cols;
}

RVector *Matriz::getVectores() const {
	return vectores;
}
//</editor-fold>



//<editor-fold desc="MetodosMatriz">
void Matriz::Fill(const RVector &vector_source) {
	*(vectores + row_index) = vector_source;
	if ((row_index + 1) == rows)
		row_index = 0;
	else
		row_index++;
}

Matriz operator*(const Matriz &A, const Matriz &B) {
	Matriz C;
	RVector c_Vector;
	if (A.cols == B.rows) {
		C = Matriz(A.rows, B.cols);
		int *v = nullptr;
		for (int i = 0; i < C.rows; ++i) {
			v = new int[B.cols];
			for (int j = 0; j < C.cols; ++j) {
				*(v + j) = 0;
				for (int k = 0; k < A.cols; ++k) {
					*(v + j) += (A.vectores[i].getComponents()[k]) * (B.vectores[k].getComponents()[j]);
				}
			}
			c_Vector = RVector(B.cols, v);
			C.Fill(c_Vector);
			c_Vector.Clear();
			c_Vector.~RVector();
		}
	}
	return C;
}

void Matriz::Clear() {
	for (int i = 0; i < rows; ++i) {
		vectores[i].Clear();
	}
	delete[](vectores);
}

bool Matriz::Empty() {
	bool emp;
	if (rows == 0 && cols == 0)
		emp = true;
	else
		emp = false;
	return emp;
}
//</editor-fold>


//<editor-fold desc="MetodosAuxiliaresMatriz">
//</editor-fold>
