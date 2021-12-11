#include "Perceptron.h"
// Конструктор
Perceptron::Perceptron(int x, int y) : sum(0), is_teached(false),
filepath(), size_x(x), size_y(y)
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
	return sum > LIMIT;
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
	if (is_teached)
		return;

	filepath.SetFilePaths(teaching_value);                // Задаём расположение нужного символа
	vector<string> good_files = filepath.GetGoodFiles();
	vector<string> bad_files = filepath.GetBadFiles();

	if (good_files.size() == 0  || bad_files.size() == 0)
		return;
	for (int k = 0; k < 100; k++)
	{
		for (auto& file : good_files)
		{
			SetInputsFromFile(file);    //Получаем входные данные
			CalculateSignals();                  //Расчитываем сигналы
			if (!GetResult())
				TeachingStep(false);      // Корректируем веса, если нужно
		}
		for (auto& file : bad_files)
		{
			SetInputsFromFile(file);    //Получаем входные данные
			CalculateSignals();                  //Расчитываем сигналы
			if (GetResult())
				TeachingStep(true);      // Корректируем веса, если нужно
		}
	}
	SavePerceptron();      // Сохраняем матрицу весов в файл

	is_teached = true;
}

void Perceptron::SavePerceptron()        // Сохраняем полученную в ходе обучения
{                                    // матрицу весов в файл
	ofstream outf("Symbols/5/Result/Save.txt");
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
