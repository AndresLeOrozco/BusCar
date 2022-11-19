#include "Persona.h"
Persona::Persona() :ced(" "), nom(" ") {}
Persona::Persona(string C, string N) : ced(C), nom(N) {}

Persona:: ~Persona() {}

string Persona::getCed() { return ced; }
string Persona::getNom() { return nom; }

void Persona::setNom(string N) { nom = N; }

string Persona::toString() {
	stringstream s;
	s << "Cedula: " << ced << " Nombre: " << nom << endl;
	return s.str();

}

bool Persona::operator ==(const Persona& t) {
	if (this->ced == t.ced)
		return true;
	else
		return false;

}

void Persona::guardarPersona(ostream& salida)
{
	salida << ced << '\t';
	salida << nom << '\n';
}

Persona * Persona::leerPersona(istream& entrada)
{
	string _ce, _no;
	getline(entrada, _ce, '\t');
	getline(entrada, _no, '\n');
	return new Persona(_ce, _no);
}
