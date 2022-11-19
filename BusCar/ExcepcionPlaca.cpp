#include "ExcepcionPlaca.h"
ExcepcionPlaca::ExcepcionPlaca(string exc) { Valor = exc; }
ExcepcionPlaca::~ExcepcionPlaca() {}

string ExcepcionPlaca::toString() {
	stringstream s;
	s << "La placa ingresada no concuerda con las placas del sistema..." << endl;
	return s.str();
}