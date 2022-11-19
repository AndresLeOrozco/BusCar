#pragma once
#include "Fecha.h"
#include "Ruta.h"
#include "Persona.h"
#include "Utiles.h"
class Venta {
private:
	Fecha* Fe;
	Ruta* ru;
	Persona* pasajero;
	string cod;
public:
	Venta();
	Venta(Fecha*, Ruta*, Persona*, string);

	virtual ~Venta();

	Fecha* getFecha();
	Ruta* getRuta();
	Persona* getPasajero();
	string getcod();

	void setFecha(Fecha*);
	void setRuta(Ruta*);
	void setPasajero(Persona*);

	string toString();

	bool operator ==(const Venta&);

	friend ostream& operator << (ostream& out, const Venta& t) {
		out << "Informacion de la venta codigo " << t.cod << ": " << endl;
		if (t.Fe)
			out << "Fecha: " << *t.Fe << endl;
		if (t.pasajero)
			out << "Informacion del comprador: " << *t.pasajero << endl;
		if (t.ru)
			out << "Informacion de la ruta " << *t.ru << endl;
		return out;
	}

	void guardarVenta(ostream&);
	static Venta* leerVenta(istream&);
};