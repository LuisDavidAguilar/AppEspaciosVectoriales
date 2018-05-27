#pragma once
#include <vector>
#include <string>

class RVector
{
private:
	int size;
	double *components;
public:

#pragma region Constructores
	RVector();
	RVector(int, double*);
	RVector(const std::vector<std::string>&);
	~RVector();
#pragma endregion

#pragma region Propiedades
	int getSize() const;

	void setSize(int size);

	double *getComponents() const;
#pragma endregion

#pragma region Metodos
	double& operator[](int);
	friend double operator*(RVector&, RVector&);
	RVector operator*(int);
	std::string Display() const;
	void Clear();
#pragma endregion
};

