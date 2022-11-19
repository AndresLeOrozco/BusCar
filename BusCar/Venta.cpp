#include "Venta.h"
Venta::Venta() :Fe(NULL), ru(NULL), pasajero(NULL), cod(" ") {}
Venta::Venta(Fecha* F, Ruta* r, Persona* P, string C) : Fe(F), ru(r), pasajero(P), cod(C) {}

Venta:: ~Venta() {
	if (Fe)
		delete Fe;
	if (ru)
		delete ru;
	

}

Fecha* Venta::getFecha() { return Fe; }
Ruta* Venta::getRuta() { return ru; }
Persona* Venta::getPasajero() { return pasajero; }
string Venta::getcod() { return cod; }

void Venta::setFecha(Fecha* F) { Fe = F; }
void Venta::setRuta(Ruta* r) { ru = r; }
void Venta::setPasajero(Persona* P) { pasajero = P; }

bool Venta::operator ==(const Venta& t) {
	if (this->cod == t.cod)
		return true;
	else
		return false;

}

void Venta::guardarVenta(ostream & salida)
{
	Fe->guardarFecha(salida);
	ru->guardarRuta(salida);
	pasajero->guardarPersona(salida);
	salida << cod << '\n';
}

Venta * Venta::leerVenta(istream & entrada)
{
	string _cod;
	Fecha* _f = Fecha::leerFecha(entrada);
	Ruta* _r = Ruta::leerRuta(entrada);
	Persona* _p = Persona::leerPersona(entrada);
	getline(entrada, _cod, '\n');

	return new Venta(_f, _r, _p, _cod);
}

string Venta::toString() {
	stringstream s;
	s << "Informacion de la venta codigo " << cod << ": " << endl;
	if (Fe)
		s << "Fecha: " << Fe->toString() << endl;
	if (pasajero)
		s << "Informacion del comprador: " << pasajero->toString() << endl;
	if (ru)
		s << "Informacion del Viaje " << ru->toString() << endl;
	return s.str();
}