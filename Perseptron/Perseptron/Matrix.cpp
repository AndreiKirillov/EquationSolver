#include "Matrix.h"

Matrix::Matrix(int x, int y) : matrix(y, vector<int>(x,0)), size_x(x), size_y(y)
{
}

void Matrix::SetMatrixFromFile(const string& filename)
{
	string input_line;
	ifstream inf(filename);
	if (inf.good())
	{
		for (int i = 0; i < size_y; i++)
		{
			int j = 0;
			getline(inf, input_line);
			for (auto ch : input_line)
			{
				if (ch == '#')
				{
					matrix[i][j] = 1;
					++j;
				}
				else
				{
					matrix[i][j] = 0;
					++j;
				}
			}
		}
	}
	else
		throw exception("Error reading from file!");
}
