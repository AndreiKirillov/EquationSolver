#include "Equation.h"

Equation::Equation() : equation_matrix(0, (vector<int>(0))), width_between_symbols(0), size_x(0), 
size_y(0)
{
}

void Equation::SetSizeX(int x)
{
	size_x = x;
}

void Equation::SetSizeY(int y)
{
	size_y = y;
}

void Equation::SetWidthBetweenSymbols(int width)
{
	width_between_symbols = width;
}

void Equation::SetEquationFromFile(string filename)
{
	ifstream inf(filename);
	int matrix_length = 0;
	if(inf.good())                        // ѕровер€ем длину матрицы из уравнени€ в байтиках
	{
		string first_line = "";
		getline(inf, first_line);
		size_x = first_line.size();
	}
	inf.close();

	Matrix matrix(size_x, size_y);
	matrix.SetMatrixFromFile(filename);
	equation_matrix = matrix.GetMatrix();


}
