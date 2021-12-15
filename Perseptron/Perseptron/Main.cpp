#pragma once

#include "Framework.h"
#include "Perceptron.h"
#include "Network.h"
#include "Symbol.h"

using namespace std;

vector<Symbol> SetAllSymbols()
{
	vector<Symbol> v;
	
	v.push_back(Symbol(0, "0"));
	v.push_back(Symbol(1, "1"));
	v.push_back(Symbol(2, "2"));
	v.push_back(Symbol(3, "3"));
	v.push_back(Symbol(4, "4"));
	v.push_back(Symbol(5, "5"));
	v.push_back(Symbol(6, "6"));
	v.push_back(Symbol(7, "7"));
	v.push_back(Symbol(8, "8"));
	v.push_back(Symbol(9, "9"));
	v.push_back(Symbol(10, "x"));
	v.push_back(Symbol(11, "plus"));
	v.push_back(Symbol(12, "minus"));
	v.push_back(Symbol(13, "multiply"));
	v.push_back(Symbol(14, "divide"));
	v.push_back(Symbol(15, "equal"));

	return v;
}

vector<string> GetTestFiles()
{
	vector<string> test_files;
	for (int i = 0; i <= 9; i++)
	{
		test_files.push_back("Examples/" + to_string(i) + ".txt");
	}

	test_files.push_back("Examples/-.txt");
	test_files.push_back("Examples/+.txt");
	test_files.push_back("Examples/divide.txt");
	test_files.push_back("Examples/=.txt");
	test_files.push_back("Examples/multiply.txt");
	test_files.push_back("Examples/x.txt");

	return test_files;
}

Network CreateNetwork(const vector<Symbol>& symbols_storage, int x, int y)
{
	Network network;
	if (symbols_storage.size() > 0)
	{
		for (auto& symbol : symbols_storage)
		{
			network.CreatePerceptron(symbol, x, y);
		}
	}
	else
		cout << "Переданный массив символов пуст!" << endl;
	return network;
}

void TestNetwork(Network& network, const vector<string>& test_files)
{
	if (network.IsEmpty())
	{
		cout << "Невозможно протестировать нейросеть, она не содержит персептронов!" << endl;
		return;
	}

	vector<Matrix> test_matrices;
	
	for_each(test_files.cbegin(), test_files.cend(), [&](const string filename)
		{
			Matrix matrix(6,12);
			matrix.SetMatrixFromFile(filename);
			test_matrices.push_back(matrix);
		});

	network.Test(test_matrices);
}


void TestPerceptron(Perceptron& p)     // Функция тестирования персептрона
{
	for (int i = 0; i <= 10; i++)
	{
		string filename = "Examples/" + to_string(i) + ".txt";
		p.SetInputsFromFile(filename);
		p.CalculateSignals();
		p.DisplayInputs();
		if (p.GetResult())
			cout << "Значение: TRUE" << endl << endl;
		else
			cout << "Значение: FALSE" << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\tМеню программы" << endl << endl;
	cout << "1 - Обучить нейронную сеть" << endl
		<< "2 - Проверить" << endl
		//<< "3 - Загрузить обученный персептрон" << endl
		<< "0 - Выход" << endl;
	int what_to_do;
	Symbol s(5, "5");
	Perceptron p(s, 6, 12);
	while (1)
	{
		cin >> what_to_do;
		switch (what_to_do)
		{
		case 1:
		{
			auto begin = chrono::steady_clock::now();  // Замеряем время обучения
			//p.TeachPerceptron();
			Network network;
			vector<Symbol> symbol_storage = SetAllSymbols();
			for (auto& symbol : symbol_storage)
			{
				network.CreatePerceptron(symbol, 6, 12);
			}
			cout << "Размер сети - " << network.GetSize() << endl;
			network.TeachNetwork();

			vector<string> test_files = GetTestFiles();

			TestNetwork(network, test_files);

			auto end = chrono::steady_clock::now();



			auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin);
			cout << endl << "\tОбучение прошло успешно!" << endl;
			cout << "Длительность обучения - " << duration.count() << " миллисекунд" << endl;
		}
			break;
		case 2:
		{
			cout << "\tПроверка работы нейросети" << endl << endl;
			TestPerceptron(p);
		}
			break;
		/*case 3:
			p.DownloadPerceptron("Results/Save.txt");
			break;*/
		default:
			return 0;
		}
	}


	////vector<Symbol> symbols = SetAllSymbols();
	////
	////for (auto& sym : symbols)
	////{

	////}

	
}

