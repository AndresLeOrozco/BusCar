#include "Vista.h"
#include "ExcepcionesInt.h"
int Vista::MenuPrincipal() {
	int opc;
	bool b1 = false;
	system("cls");
	cout << "[------------------BusCar Costa Rica SA--------------------]" << endl;
	cout << "------------------------------------------------------------" << endl << endl;
	cout << "<------------Menu principal-----------" << endl;
	cout << endl;
	cout << "1. Ingreso de personas" << endl;
	cout << "2. Configuracion flota de Transporte" << endl;
	cout << "3. Reserva Ticketes" << endl;
	cout << "4. Reportes" << endl;
	cout << "5. Salir" << endl;
	cout << "Digite una opcion...";
	while (b1 == false) {
		try {
			if (cin >> opc)
				b1 = true;
			else
				throw new ExcepcionesInt();
		}
		catch (ExcepcionesInt* Exc) {
			cout << Exc->toString() << endl;

		}
		catch (...) {
			cout << "Error desconocido" << endl;
		}
		if (!b1) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return opc;

}
void Vista::IngresaPersona(BusCar& buscar) {
	Persona* P = NULL;
	string n, c;
	system("cls");
	cout << "[---------------------Ingresando Personas al sistema----------------------]" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Ingrese el nombre de la persona...";
	cin >> n;
	cout << "Ingrese la cedula de la persona...";
	cin >> c;
	P = new Persona(c, n);
	buscar.AgregaPer(P);
}
int Vista::MenuConfiguracion() {
	int opc2;

	bool b2 = false;
	system("cls");
	cout << "<---------Menu Configuracion--------->" << endl << endl;
	cout << "1. Tipo de Buses" << endl;
	cout << "2. Ingresar Buses a Rutas" << endl;
	cout << "3. Restricciones sanitarias" << endl;
	cout << "4. Rutas de viaje" << endl;
	cout << "5. Regresar" << endl;
	cout << "Digite una opcion...";
	while (!b2) {
		try {
			if (cin >> opc2) {
				b2 = true;
			}
			else
				throw new ExcepcionesInt();
		}
		catch (ExcepcionesInt* Exc) {
			cout << Exc->toString() << endl;
		}
		if (!b2) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return opc2;
}
void Vista::IngresaRutas(BusCar& buscar) {

	system("cls");
	Ruta* R1 = NULL;
	Ruta* R2 = NULL;
	Ruta* R3 = NULL;
	Ruta* R4 = NULL;
	Ruta* R5 = NULL;
	Ruta* R6 = NULL;
	int r1, r2, r3, r4, r5, r6;
	int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0, cont6 = 0;
	string cod1 = " ", cod2, cod3, cod4, cod5, cod6;
	bool d1 = false, d2 = false, d3 = false, d4 = false, d5 = false, d6 = false;


	cout << "----------Ingresando los buses a las rutas----------" << endl << endl;
	cout << "-----Ruta destino Volcan Arenal, San Carlos-----";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d1) {
		try {
			if (cin >> r1) {
				d1 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
		if (!d1) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	d1 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod1;
	buscar.EnseniaTipoBuses();
	R1 = new Ruta(cod1, "Volcan Arenal, San Carlos", r1);
	buscar.getListaRuta()->ingresaDeUltimo(*R1);

	system("cls");
	cout << "-----Ruta destino Rio celeste, San Carlos-----";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d2) {
		try {
			if (cin >> r2) {
				d2 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
	}
	d2 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod2;
	buscar.EnseniaTipoBuses();
	R2 = new Ruta(cod2, "Rio celeste, San Carlos", r2);
	buscar.getListaRuta()->ingresaDeUltimo(*R2);

	system("cls");
	cout << "-----Ruta destino Tamarindo, Guanacaste-----";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d3) {
		try {
			if (cin >> r3) {
				d3 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
	}
	d3 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod3;
	buscar.EnseniaTipoBuses();
	R3 = new Ruta(cod3, "Tamarindo, Guanacaste", r3);
	buscar.getListaRuta()->ingresaDeUltimo(*R3);


	system("cls");
	cout << "-----Ruta destino Puerto Viejo, Limon-----";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d4) {
		try {
			if (cin >> r4) {
				d4 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
	}
	d4 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod4;
	buscar.EnseniaTipoBuses();
	R4 = new Ruta(cod4, "Puerto Viejo, Limon", r4);
	buscar.getListaRuta()->ingresaDeUltimo(*R4);



	system("cls");
	cout << "-----Ruta destino Cobano, Puntarenas-----";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d5) {
		try {
			if (cin >> r5) {
				d5 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
	}
	d5 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod5;
	buscar.EnseniaTipoBuses();
	R5 = new Ruta(cod5, "Cobano, Puntarenas", r5);
	buscar.getListaRuta()->ingresaDeUltimo(*R5);


	system("cls");
	cout << "Ruta destino Volcan Irazu, Cartago...";
	cout << "Ingrese la cantidad de buses de la ruta...";
	while (!d6) {
		try {
			if (cin >> r6) {
				d6 = true;
			}
			else
				throw new ExcepcionesInt();

		}
		catch (ExcepcionesInt* exc) {
			cout << exc->toString() << endl;
		}
	}
	d6 = false;
	cout << "Ingrese el codigo que desea ponerle a la ruta...";
	cin >> cod6;
	buscar.EnseniaTipoBuses();
	R6 = new Ruta(cod6, "Volcan Irazu, Cartago", r6);
	buscar.getListaRuta()->ingresaDeUltimo(*R6);

}
void Vista::ReservaTiquetes(BusCar* buscar) {
	Persona* p1 = NULL;
	Ruta* r1 = NULL;
	Fecha* f1 = NULL;
	bool bandera = false;

	if (buscar->getListaRuta()->cuentaNodos() > 0) {

		cout << "--------------Reserva de tiquetes--------------" << endl << endl;
		string nom;
		string ced;
		int pos, d, m, a;
		int cont = 0;
		bool t = false;
		cout << "Lista de clientes ingresados al sistema: " << endl << endl;
		cout << buscar->PersonaToString() << endl;
		while (!t) {
			cout << "Ingrese la cedula del cliente que realiza la reservacion...";
			cin >> ced;
			Persona* aux = new Persona(ced, "");
			if (buscar->getListaPersona()->RetornaIgual(*aux)) {
				p1 = buscar->getListaPersona()->RetornaIgual(*aux);
				t = true;
			}
			else {
				cout << "Persona no encontrada, Favor volver a ingresar..." << endl;
			}
		}
		t = false;
		system("cls");
		cout << *buscar->getListaRuta() << endl << endl << endl;
		cout << "Ingrese el numero de la ruta que desea...";
		while (!bandera) {
			try {
				if (cin >> pos) {
					if (pos <= 6)
						bandera = true;
					else
						cout << "Posicion no encontrada, favor ingresar nuevamente" << endl;
				}
				else
					throw new ExcepcionesInt();

			}
			catch (ExcepcionesInt* exc) {
				exc->toString();
			}
			if (!bandera) {
				cin.clear();
				cin.ignore(255, '\n');
			}
		}
		bandera = false;

		system("CLS");
		cout << "Ingrese el anio de reservacion...";
		while (!bandera) {
			try {
				if (cin >> a) {
					if (a <= 2022)
						bandera = true;
					else
						cout << "anio superior al actual, vuelva a ingresar" << endl;
				}
				else
					throw new ExcepcionesInt();

			}
			catch (ExcepcionesInt* exc) {
				exc->toString();
			}
			if (!bandera) {
				cin.clear();
				cin.ignore(255, '\n');
			}
		}
		bandera = false;
		cout << endl;
		cout << "Ingrese el mes de reservacion...";
		while (!bandera) {
			try {
				if (cin >> m) {
					if (m <= 12)
						bandera = true;
					else
						cout << "No existe ese numero de mes, vuelva a ingresar" << endl;
				}
				else
					throw new ExcepcionesInt();

			}
			catch (ExcepcionesInt* exc) {
				exc->toString();
			}
			if (!bandera) {
				cin.clear();
				cin.ignore(255, '\n');
			}
		}
		bandera = false;
		cout << endl;
		cout << "Ingrese el dia de reservacion...";
		while (!bandera) {
			try {
				if (cin >> d) {
					if (d <= 31)
						bandera = true;
					else
						cout << "No existe ese numero de dia, vuelva a ingresar" << endl;
				}
				else
					throw new ExcepcionesInt();

			}
			catch (ExcepcionesInt* exc) {
				exc->toString();
			}
			if (!bandera) {
				cin.clear();
				cin.ignore(255, '\n');
			}
		}
		cout << endl;
		f1 = new Fecha(d, m, a);

		if (buscar->getListaRuta()->getObjPos(pos)->ventaPosible()) {
			cout << "Es imposible realizar la venta ya que no hay cupos disponibles para esta ruta" << endl;
		}
		else
			buscar->hacerVenta(f1, buscar->getListaRuta()->getObjPos(pos), p1, "12345B");

	}
	else
		cout << "No se puede realizar la reservacion ya que no hay rutas disponibles " << endl;

}
int Vista::MenuReportes() {
	int opc2;
	bool band = false;
	system("cls");
	cout << "<---------Menu Reportes--------->" << endl << endl;
	cout << "1. Mostrar Todos los tiquetes emitidos" << endl;
	cout << "2. Mostrar Disponibilidad de pasajeros por ruta de viaje" << endl;
	cout << "3. Regresar" << endl;
	cout << "Digite una opcion...";
	while (!band) {
		try {
			if (cin >> opc2) {
				band = true;
			}
			else
				throw new ExcepcionesInt();
		}
		catch (ExcepcionesInt* Exc) {
			Exc->toString();
		}
		if (!band) {
			cin.clear();
			cin.ignore(255, '\n');
		}
	}
	return opc2;

}
void Vista::Disponibilidad(BusCar& buscar) {
	int pos = 1;
	if (buscar.getListaRuta()->cuentaNodos() > 0) {
		while (pos < buscar.getListaRuta()->cuentaNodos()) {

			if (buscar.getListaRuta()->getObjPos(pos)) {
				cout << buscar.getListaRuta()->getObjPos(pos)->getDestino() << ", Disponibilidad: " << buscar.getListaRuta()->getObjPos(pos)->enseniaDisponibilidad() << "%" << endl;
			}
			pos++;
		}
	}
	else
		cout << "No hay rutas disponibles..." << endl;
}