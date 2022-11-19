#include "Utiles.h"
#include <sstream>

int convertirInt(string s)
{
	stringstream r(s);
	int v;
	r >> v;
	return v;
}

double convertirDouble(string s)
{
	stringstream r(s);
	double v;
	r >> v;
	return v;
}