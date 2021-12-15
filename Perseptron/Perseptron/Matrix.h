#pragma once
#include "Framework.h"

using namespace std;

class Matrix
{
private:
	vector<vector<int>> matrix;

	int size_x;
	int size_y;

public:
	Matrix(int x, int y);

	void SetMatrixFromFile(const string& filename);

	void Display();

	vector<vector<int>> GetMatrix();
	int GetSizeX();
	int GetSizeY();
};

