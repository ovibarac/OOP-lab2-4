#pragma once
#ifndef LISTA_H
#define LISTA_H
#include "cheltuiala.h"

typedef cheltuiala ElemType;

typedef struct {
	ElemType* elems;
	int lg;
	int cp;
}Lista;

/*
Creeaza o lista goala
*/
Lista createEmpty();

/*
Destroy list
*/
void destroy(Lista* l);

/*
Returneaza lungimea listei
*/
int size(Lista* l);

/*
Add element into the list
post: element is added to the end of the list
*/
void add(Lista* l, ElemType el);

/*
Get an element from the list
poz - position of the element, need to be valid
return element on the given position
*/
ElemType get(Lista* l, int poz);

/*
Modify the element on the given pozition
return the overwritten element
*/
ElemType set(Lista* l, int poz, cheltuiala p);

/*
Testeaza crearea listei
*/
void testCreateList();

#endif // !LISTA_H

