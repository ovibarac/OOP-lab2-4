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
Gaseste o cheltuiala
l: lista
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
return: pointer la cheltuiala, cheltuiala gasita
*/
cheltuiala* findCheltuiala(Lista* l, int zi, int suma, char* tip);

/*
Sterge o cheltuiala
l: lista
ch: pointer la cheltuiala care se va sterge
*/
cheltuiala* deleteCheltuiala(Lista* l, cheltuiala* ch);

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

Lista copyList(Lista* l);

/*
Testeaza crearea listei
*/
void testCreateList();

/*
Testeaza crearea listei
*/
void test_delete_cheltuiala();

#endif // !LISTA_H

