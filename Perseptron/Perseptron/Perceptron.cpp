#include "Perceptron.h"
// Конструктор
Perceptron::Perceptron(int x, int y) : limit(100), sum(0), good_path(""), bad_path(""), size_x(x), size_y(y)
{
	inputs.resize(size_y);                // Задаём размеры всем матрицам
	weight_matrix.resize(size_y);
	signal_matrix.resize(size_y);
	for (int i = 0; i < 12; i++)
	{
		inputs[i].resize(size_x);
		weight_matrix[i].resize(size_x);
		signal_matrix[i].resize(size_x);
	}
}

void Perceptron::SetInputsFromFile(const string& filename)  // Заполнение матрицы входных данных из файла
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

void Perceptron::CalculateSignals()      // Подсчёт сигналов
{                                        // сигнал = входной сигнал * вес связи
	sum = 0;
	for (int i = 0; i < size_y; i++)
		for (int j = 0; j < size_x; j++)
		{
			signal_matrix[i][j] = inputs[i][j] * weight_matrix[i][j];
			sum += signal_matrix[i][j];
		}
}

bool Perceptron::GetResult()        // Возвращает результат обучения
{
	return sum > limit;
}

void Perceptron::DisplayInputs()    // Красивый вывод изображения в консоль
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

void Perceptron::TeachingStep(bool perceptron_deсision)   // Корректировка весов персептрона
{
	if(perceptron_deсision)    // Если неправильный ответ True
	{
		for (int i = 0; i < size_y; i++)
			for (int j = 0; j < size_x; j++)
				weight_matrix[i][j] -= inputs[i][j];
	}
	else                       // Если её неправильный ответ False
	{
		for (int i = 0; i < size_y; i++)
			for (int j = 0; j < size_x; j++)
				weight_matrix[i][j] += inputs[i][j];
	}
}

void Perceptron::TeachPerceptron(int teaching_value)   // Обучение персептрона
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
	// Прогоняем хорошие файлы
	for (int k = 0; k < 100; k++)
	{
		for (int i = 1; i <= 45; i++)
		{
			string good_filename = good_path + to_string(i) + ".txt";
			SetInputsFromFile(good_filename);    //Получаем входные данные
			CalculateSignals();                  //Расчитываем сигналы
			if (!GetResult())
				TeachingStep(false);             // Корректируем веса, если нужно
		}
		// Прогоняем плохие файлы
		for (int i = 1; i <= 45; i++)
		{
			string filename = bad_path + to_string(i) + ".txt";
			SetInputsFromFile(filename);
			CalculateSignals();
			if (GetResult())
				TeachingStep(true);
		}
	}
	SavePerceptron();      // Сохраняем матрицу весов в файл
}

void Perceptron::SavePerceptron()        // Сохраняем полученную в ходе обучения
{                                    // матрицу весов в файл
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
