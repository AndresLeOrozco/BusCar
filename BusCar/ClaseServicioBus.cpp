#include "ClaseServicioBus.h"

int ClaseServicioBus::cantPasajeros(string placa)
{
	if (placa == "BUS001" || placa == "BUS002" || placa == "BUS003") {
		return 40;
	}
	if (placa == "COA001" || placa == "COA002") {
		return 27;
	}
	if (placa == "HIA001" || placa == "HIA002" || placa == "HIA003" || placa == "HIA004") {
		return 40;
	}
	if (placa == "HON001" || placa == "HON002") {
		return 27;
	}
	return 0; // Devovler throw ERROR
}

string ClaseServicioBus::tipo(string placa)
{
	if (placa == "BUS001" || placa == "BUS002" || placa == "BUS003") {
		return "Buseta";
	}
	if (placa == "COA001" || placa == "COA002") {
		return "Coaster";
	}
	if (placa == "HIA001" || placa == "HIA002" || placa == "HIA003" || placa == "HIA004") {
		return "Hiace";
	}
	if (placa == "HON001" || placa == "HON002") {
		return "H1";
	}
	return "";  // Devovler throw ERROR
}
