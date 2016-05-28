#ifndef NODOABB_H
#define NODOABB_H

template <class U>
class NodoABB {
	public:
		U dato;
		NodoABB<U> *hDer;
		NodoABB<U> *hIzq;

		NodoABB(const U &e, NodoABB<U> *i, NodoABB<U> *d) : dato(e), hIzq(i), hDer(d) {}
		NodoABB(const NodoABB<U> &n) : dato(n.dato), hIzq(n.hIzq), hDer(n.hDer) {}

		NodoABB<U> &operator=(const NodoABB<U> &n) { dato = n.dato; hIzq = n.hIzq; hDer = n.hDer; }

		virtual ~NodoABB() {}
};

#endif