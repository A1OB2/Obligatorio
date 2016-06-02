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
		NodoABB(const U &dato) : dato(dato), hIzq(NULL), hDer(NULL) {}
		NodoABB<U> &operator=(const NodoABB<U> &n) { dato = n.dato; hIzq = n.hIzq; hDer = n.hDer; }

		virtual ~NodoABB() {}

};

template<class U>
NodoABB<U> copyOf(NodoABB<U> * a) {
	NodoABB<U> ret = NULL;
	if (a != NULL) {
		ret = new NodoABB(a->dato);
		ret->hIzq = copyOf(a->hIzq);
		ret->hDer = copyOf(a->hDer);
	}
	return ret;
}


#endif