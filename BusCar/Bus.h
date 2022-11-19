#pragma once
#include "ClaseServicioBus.h"
class Bus
{
private:
	string placa;

public:
	Bus();
	Bus(string);
	virtual ~Bus();

	void setPlaca(string);
	string getPlaca();

	int cantPasajeros();
	string tipoBus();

	string toString();
};

