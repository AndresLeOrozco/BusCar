#include "Fecha.h"
Fecha::Fecha() :d(0), m(0), a(0) {}
Fecha::Fecha(int D, int M, int A) : d(D), m(M), a(A) {}

Fecha:: ~Fecha() {}

int Fecha::getD() { return d; }
int Fecha::getM() { return m; }
int Fecha::getA() { return a; }

void Fecha::setD(int D) { d = D; }
void Fecha::setM(int M) { m = M; }
void Fecha::setA(int A) { a = A; }

string Fecha::toString() {
	stringstream s;
	s << d << " / " << m << " / " << a << "/" << endl;
	return s.str();

}

void Fecha::guardarFecha(ostream & salida)
{
	salida << d << '\t';
	salida << m << '\t';
	salida << a << '\n';
}

Fecha * Fecha::leerFecha(istream & entrada)
{
	string _dia, _mes, _anio;
	getline(entrada, _dia, '\t');
	getline(entrada, _mes, '\t');
	getline(entrada, _anio, '\n');

	int valDia = convertirInt(_dia);
	int valMes = convertirInt(_mes);
	int valAnio = convertirInt(_anio);
	return new Fecha(valDia, valMes, valAnio);
}

