#include "repo.h"

void add(int zi, int suma, char tip[]) {
	/*
	Adauga o noua cheltuiala si valideaza
	zi: ziua  in care s-a efectuat cheltuiala
	suma: suma cheltuielii
	tip: tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	
	//validare
	add_cheltuiala(zi, suma, tip);
}

cheltuiala * get_list() {
	/*
	Returneaza lista de cheltuieli
	rtype: pointer la cheltuiala
	*/
	return get_cheltuieli();
}

int get_size() {
	/*
	Returneaza lungimea listei de cheltuieli
	rtype: int >= 0
	*/
	return get_lungime();
}
