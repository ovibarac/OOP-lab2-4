#ifndef SERVICE_H_
#define SERVICE_H_
#pragma once
#include "Lista.h"

typedef struct {
	Lista allCh;
}Buget;

/*
Creeaza un nou buget
return: Buget
*/
Buget createBuget();

/*
Distruge un buget
b: pointer la buget
*/
void destroyBuget(Buget* b);

/*
Adauga o noua cheltuiala si valideaza
b: pointer la buget
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
*/
void addCheltuiala(Buget* b, int zi, int suma, char tip[]);

/*
Modifica o cheltuiala
ch: pointer la cheltuiala de modificat
new_zi: int > 0, ziua  modificata
new_suma: int > 0, suma modificata
new_tip: sir caractere, tipul modificat
*/
void mod(cheltuiala* ch, int new_zi, int new_suma, char new_tip[]);

/*
Sorteaza lista dupa suma
l: pointer la lista
reverse: 1 daca se sorteaza descrescator, 0 altfel
*/
Lista sortBySuma(Buget* b, int reverse);

/*
Sorteaza lista dupa tip
l: pointer la lista
reverse: 1 daca se sorteaza descrescator, 0 altfel
*/
Lista sortByTip(Buget* b, int reverse);

/*
Testeaza adaugarea unei cheluieli
*/
void testAddCh();

#endif // !SERVICE_H_
