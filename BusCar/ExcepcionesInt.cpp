#include "ExcepcionesInt.h"
ExcepcionesInt::ExcepcionesInt() {  }
ExcepcionesInt:: ~ExcepcionesInt() {}

string ExcepcionesInt::toString() {
	stringstream s;
	s << "Valor ingresado no es un numero" << endl;
	return s.str();
}