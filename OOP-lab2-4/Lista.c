#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "Lista.h"
#include "cheltuiala.h"

Lista createEmpty() {
	/*
	Creeaza o lista goala
	*/
	Lista nou;
	nou.lg = 0;
	nou.cp = 2;
	nou.elems = malloc(sizeof(ElemType) * nou.cp);
	return nou;
}

int size(Lista* l) {
	/*
	Returneaza lungimea listei
	*/
	return l->lg;
}


void destroy(Lista* l) {
	/*	
	Destroy list
	*/
	//dealocare cheltuieli
	for (int i = 0; i < l->lg; i++) {
		destroyCheltuiala(&l->elems[i]);
	}
	free(l->elems);

	l->elems = NULL;
	l->lg = 0;
}


void ensureCapacity(Lista* l) {
	/*
	Allocate more memory if needed
	*/
	if (l->lg < l->cp) {
		return; 
	}
	//alocate more memory
	int newCapacity = l->cp + 2;
	ElemType* nElems = malloc(sizeof(ElemType) * newCapacity);
	//copy elems
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	//dealocate old vector
	free(l->elems);
	l->elems = nElems;
	l->cp = newCapacity;
}

void add(Lista* l, ElemType el) {
	/*
	Add element into the list
	post: element is added to the end of the list
	*/
	ensureCapacity(l);
	l->elems[l->lg] = el;
	l->lg++;
}

ElemType get(Lista* l, int poz) {
	/*
	Get an element from the list
	poz - position of the element, need to be valid
	return element on the given position
	*/
	return l->elems[poz];
}

ElemType set(Lista* l, int poz, cheltuiala p) {
	/*
	Modify the element on the given pozition
	return the overwrited element
	*/
	ElemType rez = l->elems[poz];
	l->elems[poz] = p;
	return rez;
}

void testCreateList() {
	/*
	Testeaza crearea listei
	*/
	Lista l = createEmpty();
	assert(size(&l) == 0);
	destroy(&l);
}