#include "Controladora.h"

Controladora::Controladora()
{
	buscar = new BusCar();
	opc = 0;
	opc2 = 0;

	buscar->leerDatos();
}

Controladora::~Controladora()
{
	if (buscar != NULL) {
		delete buscar;
	}
}

void Controladora::menu()
{
	do
	{
		opc = Vista::MenuPrincipal();
		switch (opc)
		{
		case 1: {
			control0();
		}break;
		case 2: {
			control1();
		}break;
		case 3: {
			control2();
		}break;
		case 4: {
			control3();
		}break;
		case 5: {
			control4();
		}break;
		default:
			cout << "Opcion Incorrecta..." << endl;
			break;
		}


	} while (opc != 5);
	system("Pause");
}

void Controladora::control0()
{
	Vista::IngresaPersona(*buscar);
}

void Controladora::control1()
{
	do
	{
		opc2 = Vista::MenuConfiguracion();
		switch (opc2) {
		case 1: {
			control1a();
		}break;

		case 2: {
			control1b();
		} break;

		case 3: {
			control1c();
		}break;

		case 4: {
			control1d();
		}break;

		case 5: {}break;

		default: { cout << "Opcion Incorrecta..." << endl;
			system("Pause");
		}
		}

	} while (opc2 != 5);
}

void Controladora::control1a()
{
	system("cls");
	buscar->EnseniaTipoBuses();
	system("pause");
}

void Controladora::control1b()
{
	system("cls");
	Vista::IngresaRutas(*buscar);
}

void Controladora::control1c()
{
	system("cls");
	buscar->EnseniaMedidasSanitarias();
	system("pause");
}

void Controladora::control1d()
{
	system("cls");
	buscar->EnseniaRutas();
	system("pause");
}

void Controladora::control2()
{
	system("cls");
	Vista::ReservaTiquetes(buscar);
	system("Pause");
}

void Controladora::control3()
{
	system("cls");
	do {
		opc2 = Vista::MenuReportes();
		switch (opc2) {
		case 1: {
			control3a();
		}break;
		case 2: {
			control3b();
		}break;

		case 3: {}break;

		default: cout << "Opcion Incorrecta..." << endl;
			system("Pause");
		}
	} while (opc2 != 3);
}

void Controladora::control3a()
{
	system("cls");
	cout << *buscar->getListaVenta() << endl;
	system("pause");
}

void Controladora::control3b()
{
	system("cls");
	Vista::Disponibilidad(*buscar);
	system("pause");
}

void Controladora::control4()
{
	system("cls");
	cout << "Saliendo del programa, Gracias..." << endl;
	buscar->guardarDatos();
}
