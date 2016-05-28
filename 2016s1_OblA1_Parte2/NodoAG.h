#ifndef NODOAG_H
#define NODOAG_H

template <class U>
class NodoAG {
	public:
		U dato;
		NodoAG<U> *ph;
		NodoAG<U> *sh;

		NodoAG(const U &e, NodoAG<U> *p, NodoAG<U> *s) : dato(e), ph(p), sh(s) {}
		NodoAG(const NodoAG<U> &n) : dato(n.dato), ph(n.ph), sh(n.sh)  {}

		NodoAG<U> &operator=(const NodoAG<U> &n) { dato = n.dato; ph = n.ph; sh = n.sh; return *this; }

		bool &operator==(const NodoAG<U> &n) { return dato==n.dato; }

		bool &operator<(const NodoAG<U> &n) { return dato<n.dato; }


		virtual ~NodoAG() {}
};

#endif