#include "Bus.h"

Bus::Bus()
{
	placa = "";
}

Bus::Bus(string p) :placa(p)
{
}

Bus::~Bus()
{
}

void Bus::setPlaca(string p)
{
	placa = p;
}

string Bus::getPlaca()
{
	return placa;
}

int Bus::cantPasajeros()
{
	return ClaseServicioBus::cantPasajeros(placa);
}

string Bus::tipoBus()
{
	return ClaseServicioBus::tipo(placa);
}

string Bus::toString()
{
	stringstream s;
	s << "Placa: " << placa << endl;
	s << "Modelo del vehiculo: " << ClaseServicioBus::tipo(placa) << endl;
	s << "Cantidad de asientos: " << ClaseServicioBus::cantPasajeros(placa) << endl;

	return s.str();
}
