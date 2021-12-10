#include "Perceptron.h"
// �����������
Perceptron::Perceptron(int x, int y) : limit(100), sum(0), good_path(""), bad_path(""), size_x(x), size_y(y)
{
	inputs.resize(size_y);                // ����� ������� ���� ��������
	weight_matrix.resize(size_y);
	signal_matrix.resize(size_y);
	for (int i = 0; i < 12; i++)
	{
		inputs[i].resize(size_x);
		weight_matrix[i].resize(size_x);
		signal_matrix[i].resize(size_x);
	}
}

void Perceptron::SetInputsFromFile(const string& filename)  // ���������� ������� ������� ������ �� �����
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
					inputs[i][j] = 1;
					++j;
				}
				else
				{
					inputs[i][j] = 0;
					++j;
				}
			}
		}
	}
}

void Perceptron::CalculateSignals()      // ������� ��������
{                                        // ������ = ������� ������ * ��� �����
	sum = 0;
	for (int i = 0; i < size_y; i++)
		for (int j = 0; j < size_x; j++)
		{
			signal_matrix[i][j] = inputs[i][j] * weight_matrix[i][j];
			sum += signal_matrix[i][j];
		}
}

bool Perceptron::GetResult()        // ���������� ��������� ��������
{
	return sum > limit;
}

void Perceptron::DisplayInputs()    // �������� ����� ����������� � �������
{
	for (auto& elem_i : inputs)        //### - 5
	{                                  //#..
		for (auto& elem_j : elem_i)    //###
			if (elem_j)                //..#
				cout << "#";           //###
			else
				cout << ".";
		cout << endl;
	}
}

void Perceptron::TeachingStep(bool perceptron_de�ision)   // ������������� ����� �����������
{
	if(perceptron_de�ision)    // ���� ������������ ����� True
	{
		for (int i = 0; i < size_y; i++)
			for (int j = 0; j < size_x; j++)
				weight_matrix[i][j] -= inputs[i][j];
	}
	else                       // ���� � ������������ ����� False
	{
		for (int i = 0; i < size_y; i++)
			for (int j = 0; j < size_x; j++)
				weight_matrix[i][j] += inputs[i][j];
	}
}

void Perceptron::TeachPerceptron(int teaching_value)   // �������� �����������
{
	switch (teaching_value)
	{
	case 5:
	{
		good_path = "Good/";
		bad_path = "Bad/";
	}
	break;
	}
	// ��������� ������� �����
	for (int k = 0; k < 100; k++)
	{
		for (int i = 1; i <= 45; i++)
		{
			string good_filename = good_path + to_string(i) + ".txt";
			SetInputsFromFile(good_filename);    //�������� ������� ������
			CalculateSignals();                  //����������� �������
			if (!GetResult())
				TeachingStep(false);             // ������������ ����, ���� �����
		}
		// ��������� ������ �����
		for (int i = 1; i <= 45; i++)
		{
			string filename = bad_path + to_string(i) + ".txt";
			SetInputsFromFile(filename);
			CalculateSignals();
			if (GetResult())
				TeachingStep(true);
		}
	}
	SavePerceptron();      // ��������� ������� ����� � ����
}

void Perceptron::SavePerceptron()        // ��������� ���������� � ���� ��������
{                                    // ������� ����� � ����
	ofstream outf("Results/Save.txt");
	if (outf.good())
	{
		for (auto& elem_i : weight_matrix)
		{
			for (auto& elem_j : elem_i)
				outf << elem_j;
			outf << endl;
		}
	}
}

//void Perceptron::DownloadPerceptron(const string& filename)
//{
//	vector<vector<int>> data;
//	data.resize(size_y);
//	ifstream inf(filename);
//	if (inf.good())
//	{
//		string input_line = "";
//		bool negative_number = false;
//		for (int i = 0; i < size_y; i++)
//		{
//			getline(inf, input_line);
//			for (auto ch : input_line)
//			{
//				if (ch == '-')
//					negative_number = true;
//				else if (negative_number)
//				{
//					data[i].push_back(ch * (-1));
//					negative_number = false;
//				}
//				else
//					data[i].push_back((int)ch);
//			}
//		}
//		weight_matrix = data;
//	}
//}
