#pragma once
#include<iostream>
#include<sstream>
using namespace std;
class ExcepcionPlaca {
private:
	string Valor;
public:
	ExcepcionPlaca(string);
	virtual ~ExcepcionPlaca();
	virtual string toString();
};