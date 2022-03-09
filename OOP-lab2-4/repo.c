#include "cheltuiala.h"
#include <string.h>

cheltuiala cheltuieli[20];
int n = 0;

void add_cheltuiala(int zi, int suma, char tip[]) {
	/*
	Adauga o noua cheltuiala
	zi: ziua  in care s-a efectuat cheltuiala
	suma: suma cheltuielii
	tip: tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	cheltuieli[n].zi = zi;
	cheltuieli[n].suma = suma;
	strcpy_s(cheltuieli[n].tip, 20, tip);
	n++;
	//validare
}

cheltuiala * get_cheltuieli() {
	/*
	Returneaza lista de cheltuieli
	rtype: pointer la cheltuiala
	*/
	return cheltuieli;
}

int get_lungime() {
	/*
	Returneaza lungimea listei de cheltuieli
	rtype: int >= 0
	*/
	return n;
}