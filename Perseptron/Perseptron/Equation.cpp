#include "Equation.h"

Equation::Equation() : equation_matrix(0, (vector<int>(0))), numeric_parts(0, Matrix(0,0)), width_between_symbols(0),
size_x(0), size_y(0), is_empty(true), one_part_length(0)
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

void Equation::SetOnePartLength(int length)
{
	one_part_length = length;
}

bool Equation::IsEmpty()
{
	return is_empty;
}

void Equation::SetWidthBetweenSymbols(int width)
{
	width_between_symbols = width;
}

void Equation::SetEquationFromFile(string filename)
{
	ifstream inf(filename);
	int matrix_length = 0;
	if(inf.good())                        // ��������� ����� ������� �� ��������� � ��������
	{
		string first_line = "";
		getline(inf, first_line);
		size_x = first_line.size();
	}
	inf.close();

	Matrix matrix(size_x, size_y);
	matrix.SetMatrixFromFile(filename);
	equation_matrix = matrix.GetMatrix();

	is_empty = false;
}

int Equation::CountParts()
{
	if (is_empty)
	{
		cout << "��������� �� �������� ������!" << endl;
		return 0;
	}

	int count_parts = 0;
	if (one_part_length > 0)
	{
		int total_length = equation_matrix[0].size();
		count_parts = total_length / (one_part_length + width_between_symbols);
	}

	return count_parts;
}

void Equation::DivideIntoNumericParts()
{
	if (is_empty)
	{
		cout << "��������� �� �������� ������!" << endl;
		return;
	}

	int count_parts = CountParts();
	vector<Matrix> equation_parts(count_parts, Matrix(one_part_length, 12));

	vector<int> current_line(0);
	for (int i = 0; i < size_y; i++)
	{
		current_line = equation_matrix[i];

		int current_x = 0;
		int current_part = 0;
		while (current_part < count_parts)
		{
			int k = 0;
			vector<int> part_vector(0);
			while (k < one_part_length)
			{
				part_vector.push_back(current_line[current_x + k]);
				++k;
			}
			equation_parts[current_part].SetLine(part_vector, i);
			current_x += (k + width_between_symbols);
			++current_part;
		}
	}

	numeric_parts = equation_parts;
}

vector<Matrix> Equation::GetNumericParts()
{
	return numeric_parts;
}
