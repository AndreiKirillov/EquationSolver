#pragma once
#include "Framework.h"
#include "Matrix.h"

using namespace std;

class EquationMatrix
{
private:
	vector <vector<int>> equation_matrix;
	vector<Matrix> numeric_parts;

	int size_x;
	int size_y;
	int one_part_length;
	int width_between_symbols;

	bool is_empty;
	bool is_divided_parts;


	int CountParts();
	void DivideIntoNumericParts();
public:
	EquationMatrix();

	void SetSizeX(int x);
	void SetSizeY(int y);
	void SetOnePartLength(int length);
	bool IsEmpty();

	void SetWidthBetweenSymbols(int width);

	void SetEquationFromFile(string filename);

	vector<Matrix> GetNumericParts();
};

