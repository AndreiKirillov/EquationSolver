#pragma once
#include"Framework.h"

using namespace std;

class Symbol
{
private:
	
public:
	int id;
	string name;
	string value;

	Symbol();
	Symbol(int id, string newname, string newvalue);
	Symbol(const Symbol& symbol);

	friend bool operator> (const Symbol& s1, const Symbol& s2);
	friend bool operator< (const Symbol& s1, const Symbol& s2);
	bool operator()(const Symbol& s1, const Symbol& s2);
};

