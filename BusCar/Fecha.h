
#pragma once
#include<iostream>
#include<sstream>
#include "Utiles.h"
using namespace std;
class Fecha {
private:
	int d, m, a;
public:
	Fecha();
	Fecha(int, int, int);

	virtual ~Fecha();

	int getD();
	int getM();
	int getA();

	void setD(int);
	void setM(int);
	void setA(int);

	string toString();


	void guardarFecha(ostream&);

	static Fecha* leerFecha(istream&);

	friend ostream& operator << (ostream& out, const Fecha& t) {
		out << t.d << " / " << t.m << " / " << t.a << endl;
		return out;
	}

};