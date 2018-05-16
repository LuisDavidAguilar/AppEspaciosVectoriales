#pragma once
#include <vector>
#include <string>

class RVector
{
private:
	int size;
	int *components;
public:

#pragma region Constructores
	RVector();
	RVector(int, int*);
	RVector(const std::vector<std::string>&);
	~RVector();
#pragma endregion

#pragma region Propiedades
	int getSize() const;

	void setSize(int size);

	int *getComponents() const;
#pragma endregion

#pragma region Metodos
	friend int operator*(RVector&, RVector&);
	RVector operator*(int);
	std::string Display() const;
	void Clear();
#pragma endregion
};

