#include "BusCar.h"

BusCar::BusCar()
{
	LP = new ListaT<Persona>;
	LV = new ListaT<Venta>;
	LR = new ListaT<Ruta>;
}

BusCar::~BusCar()
{
	if (LP != NULL)delete LP;
	if (LV != NULL)delete LV;
	if (LR != NULL)delete LR;
}

ListaT<Persona>* BusCar::getListaPersona()
{
	return LP;
}

ListaT<Venta>* BusCar::getListaVenta()
{
	return LV;
}

ListaT<Ruta>* BusCar::getListaRuta()
{
	return LR;
}

void BusCar::setListaPersona(ListaT<Persona>* p)
{
	LP = p;
}

void BusCar::setListaVenta(ListaT<Venta>* v)
{
	LV = v;
}

void BusCar::setListaRuta(ListaT<Ruta>* r)
{
	LR = r;
}

void BusCar::hacerVenta(Fecha * f, Ruta * r, Persona * p, string c)
{
	//hacer throw de NULL
	try {
		r->reducirCantAsientos();
		Venta* nuevVenta = new Venta(f, r, p, c);
		LV->ingresaDeUltimo(*nuevVenta);
	}
	catch (...) {//Hacer throw para diferentes errores
		throw;
	}
}

string BusCar::PersonaToString()
{
	stringstream s;
	s << *LP << endl;
	return s.str();
}

string BusCar::VentaToString()
{
	stringstream s;
	s << *LV << endl;
	return s.str();
}

string BusCar::RutaToString()
{
	stringstream s;
	s << *LR << endl;
	return s.str();
}

void BusCar::AgregaPer(Persona* p) { LP->ingresaDeUltimo(*p); }
void BusCar::IngresoDeRutas(Ruta* R) { LR->ingresaDeUltimo(*R); }
void BusCar::RealizaVenta(Venta* V) { LV->ingresaDeUltimo(*V); }

void BusCar::EnseniaTipoBuses() {
	cout << "[----------Tipos de Buses----------]" << endl;
	cout << "------------------------------------" << endl << endl;
	cout << "Tipo Buseta..." << "Cantidad maxima de pasajeros: 40" << endl;
	cout << "Placas: BUS001, BUS002, BUS003" << endl << endl;
	cout << "Tipo Coaster..." << "Cantidad maxima de pasajeros: 27" << endl;
	cout << "Placas: COA001, COA002" << endl << endl;
	cout << "Tipo Hiace..." << "Cantidad maxima de pasajeros: 12" << endl;
	cout << "Placas: HIA001, HIA002, HIA003, HIA004" << endl << endl;
	cout << "Tipo H1..." << "Cantidad maxima de pasajeros: 6" << endl;
	cout << "Placas: HON001, HON002" << endl << endl;

}
void BusCar::EnseniaMedidasSanitarias() { cout << "Maximo de aforo: 80% por Bus" << endl; }
void BusCar::EnseniaRutas() { cout << *LR << endl; }
void BusCar::EnseniaTicketes() { cout << *LV << endl; }
void BusCar::MostrarDisponibPorRutViaj() {}

void BusCar::guardarDatos()
{
	guardarRutas();
	guardarPersonas();
	guardarVentas();
}

void BusCar::guardarRutas()
{
	int RutCant;
	RutCant = LR->cuentaNodos();

	ofstream salida;
	salida.open("../Rutas.txt");
	salida << RutCant << '\t';
	for (int i = 0; i < RutCant; i++)
	{

		LR->getObjPos(i + 1)->guardarRuta(salida);
	}
	salida.close();
}

void BusCar::guardarPersonas()
{
	int PerCant;
	PerCant = LP->cuentaNodos();


	ofstream salida;
	salida.open("../Personas.txt");
	salida << PerCant << '\t';
	for (int i = 0; i < PerCant; i++)
	{

		LP->getObjPos(i + 1)->guardarPersona(salida);
	}
	salida.close();
}

void BusCar::guardarVentas()
{
	int VentCant;
	VentCant = LV->cuentaNodos();

	ofstream salida;
	salida.open("../Ventas.txt");
	salida << VentCant << '\t';
	for (int i = 0; i < VentCant; i++)
	{

		LV->getObjPos(i + 1)->guardarVenta(salida);
	}
	salida.close();
}

void BusCar::leerDatos()
{
	leerRutas();
	leerPersonas();
	leerVentas();
	
}

void BusCar::leerRutas()
{
	ifstream entrada;
	entrada.open("../Rutas.txt");
	if (entrada.good()) {
		string _RutCant;
		int ValRutCant;

		getline(entrada, _RutCant, '\t');
		ValRutCant = convertirInt(_RutCant);
		for (int i = 0; i < 6; i++)
		{
			LR->ingresaDeUltimo(*Ruta::leerRuta(entrada));
		}
	}

	entrada.close();
}

void BusCar::leerPersonas()
{
	ifstream entrada;
	entrada.open("../Personas.txt");
	if (entrada.good()) {
		string _PerCant;
		int ValPerCant;

		
		getline(entrada, _PerCant, '\t');
		ValPerCant = convertirInt(_PerCant);
		for (int i = 0; i < ValPerCant; i++)
		{
			LP->ingresaDeUltimo(*Persona::leerPersona(entrada));
		}
	}

	entrada.close();
}

void BusCar::leerVentas()
{
	ifstream entrada;
	entrada.open("../Ventas.txt");
	if (entrada.good()) {
		string  _VentCant;
		int ValVentCant;

		getline(entrada, _VentCant, '\t');
		ValVentCant = convertirInt(_VentCant);
		for (int i = 0; i < ValVentCant; i++)
		{
			LV->ingresaDeUltimo(*Venta::leerVenta(entrada));
		}


	}

	entrada.close();
}
