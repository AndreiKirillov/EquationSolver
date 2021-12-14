#include "Symbol.h"

Symbol::Symbol() : id(0), value("")
{
}

Symbol::Symbol(int id, string value) : id(id), value(value)
{
}

Symbol::Symbol(const Symbol& symbol) : id(symbol.id), value(symbol.value)
{
}

bool Symbol::operator()(const Symbol& s1, const Symbol& s2)
{
	return s1.id < s2.id;
}

bool operator > (const Symbol& s1, const Symbol& s2)
{
	return s1.id > s2.id;
}

bool operator < (const Symbol& s1, const Symbol& s2)
{
	return s1.id < s2.id;
}

