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
Testeaza adaugarea unei cheluieli
*/
void test_add_cheltuiala_srv();

void test_mod();

#endif // !SERVICE_H_
