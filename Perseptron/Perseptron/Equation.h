#pragma once
#include "Framework.h"
#include "Matrix.h"

using namespace std;

class Equation
{
private:
	vector <vector<int>> equation_matrix;

	int size_x;
	int size_y;
	int width_between_symbols;

public:
	Equation();

	void SetSizeX(int x);
	void SetSizeY(int y);

	void SetWidthBetweenSymbols(int width);

	void SetEquationFromFile(string filename);

};

