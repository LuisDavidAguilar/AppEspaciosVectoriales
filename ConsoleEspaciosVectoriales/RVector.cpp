#include "RVector.h"
#include <sstream>

using namespace std;


#pragma region Constructores

RVector::RVector()
{
	size = 0;
	components = new int[size];
}

RVector::RVector(int s, int *vector_source)
{
	size = s;
	size = s;
	components = new int[size];
	for (int i = 0; i < size; ++i) {
		*(components + i) = *(vector_source + i);
	}
}

RVector::RVector(const std::vector<std::string> &vector_source)
{
	size = vector_source.size();
	components = new int[size];
	for (int i = 0; i < size; ++i) {
		*(components + i) = stoi(vector_source[i]);
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

int * RVector::getComponents() const
{
	return components;
}

#pragma endregion


#pragma region Metodos

int operator*(RVector &v, RVector &w)
{
	int producto_punto, i;
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
	int *vector = new int[size];
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
		ss << *(components + i) << " ";
	}
	ss << " >";
	return ss.str();
}

void RVector::Clear()
{
	delete[](components);
}

#pragma endregion