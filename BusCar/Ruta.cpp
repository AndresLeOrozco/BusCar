#include "Ruta.h"

Ruta::Ruta(string cod, string dir, int cB)
{
	Destino = dir;
	codigo = cod;
	tam = cB;
	can = 0;
	vecBus = new Bus *[tam];
	string placa;
	for (int i = 0; i < tam; i++)
	{
		bool bandera = false;
		cout << "Ingrese el bus numero: " << i << "...";
		cin >> placa;

		while (!bandera) {
			try {
				if (placa == "BUS001" || placa == "BUS002" || placa == "BUS003" || placa == "COA001" || placa == "COA002" || placa == "HIA001" || placa == "HIA002" || placa == "HIA003" || placa == "HIA004" || placa == "HON001" || placa == "HON002") {
					vecBus[i] = new Bus(placa);
					can++;
					bandera = true;
				}

				else throw new ExcepcionPlaca(placa);
			}
			catch (ExcepcionPlaca* exc) {
				cout << exc->toString() << endl;
			}
			if (!bandera) {
				cin.clear();
				cin.ignore(255, '\n');
			}
		}
	}
	asientos = cantidadAsientos();
	
}

Ruta::Ruta(string cod, string dir, int cB, int c, Bus* ve[],int as)
{
	Destino = dir;
	codigo = cod;
	tam = cB;
	can = c;
	vecBus = ve;
	asientos = as;
}

Ruta::Ruta(Ruta & r2)
{
	this->codigo = r2.codigo;
	this->Destino = r2.Destino;
	for (int i = 0; i < this->can; i++)
	{
		delete this->vecBus[i];
	}

	for (int i = 0; i < r2.tam; i++)
	{
		this->vecBus[i] = r2.vecBus[i];
	}
}
Ruta::~Ruta()
{
	for (int i = 0; i < can; i++)
	{
		delete vecBus[i];
	}
	delete[] vecBus;
}

string Ruta::getCod()
{
	return codigo;
}

void Ruta::setCod(string cod)
{
	codigo = cod;
}

void Ruta::cambiarBus(Bus* b, int p)
{
	if (p <= tam)
	{
		vecBus[p] = b;
	}
	//agregar error throw
}

Bus* Ruta::getBus(int p)
{
	if (p <= tam) {
		return vecBus[p];
	}
	return NULL; //agregar error throw
}

string Ruta::toString()
{
	stringstream s;
	s << "Codigo de Ruta: " << codigo << endl;
	s << "Direccion: " << Destino << endl;
	for (int i = 0; i < tam; i++)
	{
		s << vecBus[i]->toString() << endl;
	}
	return s.str();
}

void Ruta::agregarBus(Bus* b)
{
	if (can < tam) {
		vecBus[can++] = b;
	}
	//agregar error throw
}

int Ruta::cantidadAsientos()
{
	int asi = 0;
	for (int j = 0; j < tam; j++)
	{
		asi += vecBus[j]->cantPasajeros();
		
	}
	
	return asi;
}

void Ruta::guardarRuta(ostream & salida)
{
	salida << tam << '\t';
	salida << can << '\t';
	salida << codigo << '\t';
	salida << asientos << '\t';
	for (int i = 0; i < tam; i++)
	{
		salida << vecBus[i]->getPlaca() << '\t';
	}
	salida << Destino << '\n';
}

Ruta * Ruta::leerRuta(istream & entrada)
{
	string _tam, _can, _codigo, _asien, _placa, _destino;
	int valTam = 0, valCan = 0, ValAsi = 0;
	getline(entrada, _tam, '\t');
	valTam = convertirInt(_tam);
	getline(entrada, _can, '\t');
	valCan = convertirInt(_can);
	getline(entrada, _codigo, '\t');

	getline(entrada, _asien, '\t');
	ValAsi = convertirInt(_asien);

	Bus* *_vec = new Bus* [valTam];
	for (int i = 0; i < valTam; i++)
	{
		getline(entrada, _placa, '\t');
		_vec[i] = new Bus(_placa);
	}
	getline(entrada, _destino, '\n');
	
	return new Ruta(_codigo, _destino, valTam, valCan, _vec, ValAsi);
}

string Ruta::getDestino()
{
	return Destino;
}

void Ruta::reducirCantAsientos()
{
	asientos--;
}

bool Ruta::ventaPosible()
{
	return asientos == 0;
}

int Ruta::cuentaPasajeros()
{
	return 0;
}
bool Ruta::operator ==(const Ruta& t) {
	if (this->codigo == t.codigo)
		return true;
	else
		return false;

}
double Ruta::enseniaDisponibilidad() {

	cout << asientos << endl;
	return (asientos*100)/cantidadAsientos();
}