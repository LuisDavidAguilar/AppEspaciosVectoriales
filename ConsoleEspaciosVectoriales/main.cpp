#include <iostream>
#include "RVector.h"

using namespace std;

int main()
{
	int lista[3] = { 4,5,6 };
	RVector v = RVector(3, lista);
	cout << v.Display() << endl;
	v.Clear();
	v.~RVector();
	cin.get();
	return 0;
}