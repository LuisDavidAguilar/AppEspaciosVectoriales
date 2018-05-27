#include "RVector.h"
#include <sstream>
#include <iomanip>

using namespace std;


#pragma region Constructores

RVector::RVector()
{
	size = 0;
	components = new double[size];
}

RVector::RVector(int s, double *vector_source)
{
	size = s;
	components = new double[size];
	for (int i = 0; i < size; ++i) {
		*(components + i) = *(vector_source + i);
	}
}

RVector::RVector(const std::vector<std::string> &vector_source)
{
	size = vector_source.size();
	components = new double[size];
	for (int i = 0; i < size; ++i) {
		*(components + i) = stod(vector_source[i]);
	}
}


RVector::~RVector()
{
}

#pragma endregion


#pragma region Propiedades

int RVector::getSize() const
{
	return size;
}

void RVector::setSize(int size)
{
	RVector::size = size;
}

double * RVector::getComponents() const
{
	return components;
}

#pragma endregion


#pragma region Metodos

double& RVector::operator[](int nSubindex)
{
	static double iErr = -1;

	if (nSubindex >= 0 && nSubindex < size)
		return *(components + nSubindex);
	else {
		return iErr;
	}
}

double operator*(RVector &v, RVector &w)
{
	double producto_punto;
	int i;
	producto_punto = 0; i = 0;
	if (v.size > w.size) {
		while (i != w.size) {
			producto_punto += v.components[i] * w.components[i];
			i++;
		}
		while (i != v.size) {
			producto_punto += v.components[i];
			i++;
		}
	}
	else if (v.size < w.size) {
		while (i != v.size) {
			producto_punto += v.components[i] * w.components[i];
			i++;
		}
		while (i != w.size) {
			producto_punto += w.components[i];
			i++;
		}
	}
	else {
		while (i != v.size) {
			producto_punto += v.components[i] * w.components[i];
			i++;
		}
	}
	return producto_punto;
}

RVector RVector::operator*(int alfa)
{
	double *vector = new double[size];
	for (int i = 0; i < size; ++i) {
		*(vector + i) = *(components + i) * alfa;
	}
	return RVector(size, vector);
}

string RVector::Display() const
{
	stringstream ss;
	ss << "< ";
	for (int i = 0; i < size; i++)
	{
		ss << std::left << std::setw(6) << std::setfill(' ');
		ss << setprecision(2) << fixed << *(components + i) << " ";
	}
	ss << ">";
	return ss.str();
}



void RVector::Clear()
{
	delete[](components);
}

#pragma endregion