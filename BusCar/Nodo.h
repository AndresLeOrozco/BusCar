#pragma once

#include <sstream>
#include <iostream>

using namespace std;
template<class T>
class Nodo
{
private:
	T* ptrInfo;
	Nodo<T>* sig;
public:
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();

	T* getPtrInfo();
	Nodo<T>* getSiguiente();

	void setPtrInfo(T*);
	void setSiguiente(Nodo*);

	friend ostream& operator << (ostream& out, const Nodo<T>& t) {
		out << *(t.ptrInfo) << endl;
		return out;
	}

};

template<class T>
Nodo<T>::Nodo(T* obj, Nodo<T>* s) :ptrInfo(obj), sig(s)
{
}

template<class T>
Nodo<T>::~Nodo()
{
	if (ptrInfo) {
		delete ptrInfo;
	}
	
}

template<class T>
T * Nodo<T>::getPtrInfo()
{
	return ptrInfo;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return sig;
}


template<class T>
void Nodo<T>::setPtrInfo(T* obj)
{
	ptrInfo = obj;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo* s)
{
	sig = s;
}
