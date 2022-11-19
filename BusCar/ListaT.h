#pragma once
#include "Nodo.h"

template<class T>
class ListaT
{
private:
	Nodo<T>* ppio;
public:
	ListaT();
	ListaT(const ListaT&);
	virtual ~ListaT();

	void eliminaTodos();
	void ingresaDeUltimo(T&);

	T* RetornaIgual(T&);
	T* getObjPos(int);

	ListaT& operator = (const ListaT&);
	friend ostream& operator <<(ostream& sal, const ListaT& LT1) {
		Nodo<T>* p = LT1.ppio;
		int contador = 1;
		while (p != NULL) {
			sal << contador << ": " << endl;
			sal << *p->getPtrInfo() << endl;
			p = p->getSiguiente();
			contador++;
		}
		return sal;


	}

	int cuentaNodos();
};

template<class T>
ListaT<T>::ListaT()
{
	ppio = NULL;
}

template<class T>
ListaT<T>::ListaT(const ListaT & l2)
{
}

template<class T>
ListaT<T>::~ListaT()
{
	eliminaTodos();
}

template<class T>
void ListaT<T>::eliminaTodos()
{
	Nodo<T>*primero = NULL;
	while (ppio->getSiguiente() != NULL) {
		primero = ppio;
		ppio = ppio->getSiguiente();
		if (primero != NULL) {
			delete primero;
		}
		
	}
}

template<class T>
void ListaT<T>::ingresaDeUltimo(T& t2)
{
	if (ppio == NULL) {
		ppio = new Nodo<T>(&t2, NULL);
	}
	else
	{
		Nodo<T>*p = ppio;
		while (p->getSiguiente() != NULL)
		{
			p = p->getSiguiente();
		}
		p->setSiguiente(new Nodo<T>(&t2, NULL));
	}
}

template<class T>
T* ListaT<T>::RetornaIgual(T& a) {
	Nodo<T>* P = ppio;
	while (P) {
		if (*P->getPtrInfo() == a)
			return P->getPtrInfo();
		P = P->getSiguiente();
	}
	return NULL;
}

template<class T>
inline T * ListaT<T>::getObjPos(int n)
{
	int contador = 1;
	Nodo<T>* p = ppio;
	while (p != NULL) {
		if (contador == n)
		{
			return p->getPtrInfo();
		}

		p = p->getSiguiente();
		contador++;
	}

	return NULL;
}

template<class T>
ListaT<T>& ListaT<T>::operator=(const ListaT<T>& LT2)
{
	Nodo<T>* p2 = LT2.ppio;
	if (this != &LT2) {
		this->eliminaTodos();
		while (p2 != NULL)
		{
			T* obj = new T(*p2->getPtrInfo());
			this->ingresaDeUltimo(*obj);
			p2 = p2->getSiguiente();
		}
	}
	return *this;

}

template<class T>
inline int ListaT<T>::cuentaNodos()
{
	int cont = 0;
	Nodo<T>* p = ppio;
	while (p!=NULL)
	{
		cont++;
		p = p->getSiguiente();
	}
	return cont;
}
