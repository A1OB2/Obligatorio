#ifndef ABB_H
#define ABB_H

#include "assert.h"

template <class T>
class ABB abstract {
	public:

		// PRE: -
		// POS: Destructor
		virtual ~ABB() {}

		// PRE: -
		// POS: Vacia el arbol
		virtual void Vaciar() abstract;

		// PRE: -
		// POS: Agrega el elemento e en el arbol. Si existe lo sobrescribe
		virtual void Insertar(T &e) abstract;

		/**** Predicado ****/
		// PRE: -
		// POS: Retorna true si el arbol esta vacio
		virtual bool EsVacio() const abstract; 

		/**** Selectoras y otras ****/
		// PRE: El arbol no es vacio
		// POS: Retorna el maximo elemento del arbol
		virtual const T& Maximo() const abstract;

		// PRE: El arbol no es vacio
		// POS: Retorna el minimo elemento del arbol
		virtual const T& Minimo() const abstract;

		// PRE: -
		// POS: Busca si existe un elemento que sea igual a e
		// Usa el operador == del elemento e para encontrar uno igual
		virtual bool Existe(const T &e) const abstract;

		// PRE: Existe el elemento a recuperar
		// POS: Retorna el primer elemento que sea igual a e
		// Usa el operador == del elemento e para encontrar uno igual
		virtual const T& Recuperar(const T &e) const abstract;

		// PRE: -
		// POS: Borra el elemento que sea igual a e
		// Usa el operador == del elemento e para encontrar uno igual.
		// Si no lo encuentra no tiene efecto
		virtual void Borrar(const T &e) abstract;

		// PRE: -
		// POS: Aplica el procedimiento f a los elementos del arbol en Pre-Order
		// Recibe un puntero que permite pasarle parametros adicionales a la funcion. Si no se usa pasar NULL.
		virtual void PreOrder(void (*f)(const T&, void *), void *ptr) const abstract;

		// PRE: -
		// POS: Aplica el procedimiento f a los elementos del arbol en In-Order
		// Recibe un puntero que permite pasarle parametros adicionales a la funcion. Si no se usa pasar NULL.
		virtual void InOrder(void (*f)(const T&, void *), void *ptr) const abstract;
	
		// PRE: -
		// POS: Aplica el procedimiento f a los elementos del arbol en Post-Order
		// Recibe un puntero que permite pasarle parametros adicionales a la funcion. Si no se usa pasar NULL.
		virtual void PosOrder(void (*f) (const T&, void *), void *ptr) const abstract;


	protected:

		ABB() { }
		ABB(const ABB &a) { assert(false); }

	private:
		ABB<T> &operator=(const ABB<T> &a) { assert(false); }

};
#endif