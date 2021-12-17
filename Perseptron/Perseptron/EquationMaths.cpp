#include "EquationMaths.h"

EquationMaths::EquationMaths(): equation_str("")
{
}

EquationMaths::EquationMaths(string& equation):equation_str(equation)
{
}

string EquationMaths::GetEquation()
{
	return equation_str;
}
