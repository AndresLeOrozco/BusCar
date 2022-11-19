#pragma once
#include<iostream>
#include<sstream>
#include "Utiles.h"
using namespace std;

class Persona {
private:
	string ced;
	string nom;
public:
	Persona();
	Persona(string, string);

	virtual ~Persona();

	string getCed();
	string getNom();

	void setNom(string);

	string toString();

	friend ostream& operator << (ostream& out, const Persona& t) {
		out << "Cedula: " << t.ced << " Nombre: " << t.nom << endl;
		return out;
	}

	bool operator ==(const Persona&);

	void guardarPersona(ostream&);
	static Persona* leerPersona(istream&);
};

