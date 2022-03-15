#ifndef CHELTUIALA_H_

#define CHELTUIALA_H_

#pragma once

typedef struct cheltuiala {
	/*
	zi: ziua  in care s-a efectuat cheltuiala
	suma: suma cheltuielii
	tip: tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	int zi;
	int suma;
	char * tip;
}cheltuiala;

/*
Creeaza o noua cheltuiala
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
return: cheltuiala creata
*/
cheltuiala createCheltuiala(int zi, int suma, char* tip);

/*
Dealoca memoria ocupata de o cheltuiala
ch: pointer la cheltuiala cautata
*/
void destroyCheltuiala(cheltuiala* ch);

/*
Testeaza crearea si distrugerea
*/
void testCreateDestroy();
#endif // !CHELTUIALA_H_
