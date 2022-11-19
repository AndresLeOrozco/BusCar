#pragma once
#include "Buscar.h"
#include "ExcepcionesInt.h"
#include "ExcepcionPlaca.h"
#include "Vista.h"
class Controladora
{
private:
	BusCar* buscar;
	int opc;
	int opc2;
public:
	Controladora();
	virtual ~Controladora();

	void menu();
	void control0();
	void control1();

	void control1a();
	void control1b();
	void control1c();
	void control1d();

	void control2();
	void control3();

	void control3a();
	void control3b();

	void control4();
};

