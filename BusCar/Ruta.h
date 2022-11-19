#pragma once
#include"Bus.h"
#include "Utiles.h"
#include "ExcepcionPlaca.h"
class Ruta
{
private:
	string codigo;
	Bus** vecBus;
	string Destino;
	int can;
	int tam;
	int asientos;
public:
	Ruta(string, string, int);
	Ruta(string, string, int, int, Bus*[],int);
	Ruta(Ruta&);

	virtual ~Ruta();

	string getCod();
	void setCod(string);

	void cambiarBus(Bus*, int);
	int cantidadAsientos();

	void guardarRuta(ostream&);
	static Ruta* leerRuta(istream&);

	string getDestino();
	void reducirCantAsientos();
	bool ventaPosible();

	Bus* getBus(int);
	string toString();
	void agregarBus(Bus*);
	int cuentaPasajeros();
	bool operator ==(const Ruta&);

	friend ostream& operator << (ostream& out, const Ruta& t) {
		out << "Ruta Destino: " << t.Destino << endl
			<< "Codigo de Ruta: " << t.codigo << endl;
		if (t.vecBus) {
			out << "Placa de los buses: " << endl;
			for (int i = 0; i < t.tam; i++)
			{
				out << t.vecBus[i]->getPlaca() << endl;
			}
		}
		return out;
	}
	double enseniaDisponibilidad();

};
