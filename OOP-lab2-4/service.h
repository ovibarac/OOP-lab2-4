#ifndef SERVICE_H_
#define SERVICE_H_
#pragma once
#include "repo.h"

/*
Adauga o noua cheltuiala si valideaza
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
*/
void add(int zi, int suma, char tip[]);

/*
Modifica o cheltuiala
zi: int > 0, ziua  cheltuielii cautate
suma: int > 0, suma cheltuielii cautate
tip: sir caractere, tipul cheltuielii cautate
new_zi: int > 0, ziua  modificata
new_suma: int > 0, suma modificata
new_tip: sir caractere, tipul modificat
*/
void mod(int zi, int suma, char tip[], int new_zi, int new_suma, char new_tip[]);

/*
Returneaza lista de cheltuieli
rtype: pointer la cheltuiala
*/
cheltuiala* get_list();

/*
Returneaza lungimea listei de cheltuieli
rtype: int >= 0
*/
int get_size();

/*
Testeaza obtinerea listei
*/
void test_get_cheltuieli_srv();

/*
Testeaza obtinerea lungimii listei
*/
void test_get_lungime_srv();

/*
Testeaza adaugarea unei cheluieli
*/
void test_add_cheltuiala_srv();

void test_mod();

#endif // !SERVICE_H_
