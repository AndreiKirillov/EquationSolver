#pragma once
#include "Framework.h"
#include "Filepath.h"
#include "Symbol.h"
#include "Matrix.h"


using namespace std;

class Perceptron
{
private:
	Symbol identifying_symbol;

	vector<vector<int>> inputs;
	vector<vector<int>> weight_matrix;
	vector<vector<int>> signal_matrix;

	static const int LIMIT = 100;
	double sum;
	bool is_teached;

	Filepath filepath;
	//string good_path;
	//string bad_path;

	int size_x;
	int size_y;

public:
	Perceptron();
	Perceptron(int x, int y);
	Perceptron(const Symbol& s, int x, int y);

	void SetParams(const Symbol& s, int x, int y);
	void SetInputsFromFile(const string& filename);
	void SetInputsFromMatrix(Matrix& matrix);

	void CalculateSignals();
	bool GetResult();
	void DisplayInputs();

	void TeachingStep(bool perceptron_deñision);
	void TeachPerceptron();
	bool Test(Matrix& matrix);

	void SavePerceptron();
	
	
	//void DownloadPerceptron(const string& filename);
};
