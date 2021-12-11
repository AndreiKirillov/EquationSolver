#pragma once

#include "Framework.h"
#include "Perceptron.h"
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
	Perceptron p(6, 12);
	while (1)
	{
		cin >> what_to_do;
		switch (what_to_do)
		{
		case 1:
		{
			auto begin = chrono::steady_clock::now();  // Замеряем время обучения
			p.TeachPerceptron(5);
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
}

