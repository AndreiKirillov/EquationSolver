#pragma once
#include "Framework.h"
#include "Perceptron.h"
#include "Symbol.h"


using namespace std;

class Network
{
private:
	//map<Symbol, Perceptron> perceptron_storage;
	vector<shared_ptr<Perceptron>> perceptron_storage;

public:
	Network();

	bool IsEmpty();
	int GetSize();

	void CreatePerceptron(const Symbol& symbol, int x, int y);
	void TeachNetwork();


};

