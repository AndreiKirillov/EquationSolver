#pragma once
#include "Framework.h"

using namespace std;

class EquationMaths
{
private:
	string equation_str;

public:
	EquationMaths();
	EquationMaths(string& equation);

	string GetEquation();

};

