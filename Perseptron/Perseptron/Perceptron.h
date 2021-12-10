#pragma once
#include "Framework.h"
#include "Filepath.h"

using namespace std;

class Perceptron
{
private:
	vector<vector<int>> inputs;
	vector<vector<int>> weight_matrix;
	vector<vector<int>> signal_matrix;

	static const int LIMIT = 100;
	double sum;

	Filepath filepath;
	string good_path;
	string bad_path;

	int size_x;
	int size_y;
public:
	Perceptron(int x, int y);

	void SetInputsFromFile(const string& filename);
	void CalculateSignals();
	bool GetResult();
	void DisplayInputs();
	void TeachingStep(bool perceptron_deñision);
	void TeachPerceptron(int teaching_value);
	void SavePerceptron();
	//void DownloadPerceptron(const string& filename);
};

