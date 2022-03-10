#ifndef REPO_H_
#define REPO_H_

#pragma once
#include "cheltuiala.h"

/*
Adauga o noua cheltuiala
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
*/
void add_cheltuiala(int zi, int suma, char tip[]);

/*
Returneaza lista de cheltuieli
rtype: pointer la cheltuiala
*/
cheltuiala * get_cheltuieli();

/*
Gaseste o cheltuiala dupa atribute
rtype: pointer la cheltuiala
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
return: pointer la cheltuiala
*/
cheltuiala* find_cheltuiala(int zi, int suma, char tip[]);

/*
Returneaza lungimea listei de cheltuieli
rtype: int >= 0
*/
int get_lungime();

/*
Testeaza obtinerea listei
*/
void test_get_cheltuieli();

/*
Testeaza obtinerea lungimii listei
*/
void test_get_lungime();

/*
Testeaza adaugarea unei cheluieli
*/
void test_add_cheltuiala();

/*
Testeaza gasirea unei cheltuieli
*/
void test_find_cheltuieli();

#endif // !REPO_H_