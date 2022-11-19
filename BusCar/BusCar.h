#pragma once
#include "ListaT.h"
#include "Persona.h"
#include "Venta.h"
#include "Ruta.h"
#include "Utiles.h"
#include <fstream>
class BusCar
{
private:
	ListaT<Persona>* LP;
	ListaT<Venta>* LV;
	ListaT<Ruta>* LR;
public:
	BusCar();
	virtual ~BusCar();

	ListaT<Persona>* getListaPersona();
	ListaT<Venta>* getListaVenta();
	ListaT<Ruta>* getListaRuta();

	void setListaPersona(ListaT<Persona>*);
	void setListaVenta(ListaT<Venta>*);
	void setListaRuta(ListaT<Ruta>*);

	void hacerVenta(Fecha*, Ruta*, Persona*, string);

	string PersonaToString();
	string VentaToString();
	string RutaToString();


	void AgregaPer(Persona* p);
	void IngresoDeRutas(Ruta* R);
	void RealizaVenta(Venta* V);

	void EnseniaTipoBuses();
	void EnseniaRutas();
	void EnseniaMedidasSanitarias();
	void EnseniaTicketes();
	void MostrarDisponibPorRutViaj();

	void guardarDatos();

	void guardarRutas();
	void guardarPersonas();
	void guardarVentas();


	void leerDatos();

	void leerRutas();
	void leerPersonas();
	void leerVentas();
};

