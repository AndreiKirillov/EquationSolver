#include "Symbol.h"

Symbol::Symbol() : id(0), value(""), name("")
{
}

Symbol::Symbol(int id, string newname, string newvalue) : id(id),name(newname), value(newvalue)
{
}

Symbol::Symbol(const Symbol& symbol) : id(symbol.id), value(symbol.value), name(symbol.name)
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

