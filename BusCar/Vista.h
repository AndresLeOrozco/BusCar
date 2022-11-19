#pragma once
#include <iostream>
#include <sstream>
#include "BusCar.h"
class Vista {
public:

	static int MenuPrincipal();
	static void IngresaPersona(BusCar&);
	static int MenuConfiguracion();
	static void IngresaRutas(BusCar&);
	static void ReservaTiquetes(BusCar*);
	static int MenuReportes();
	static void Disponibilidad(BusCar&);
};