#include "cheltuiala.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

cheltuiala createCheltuiala(int zi, int suma, char* tip) {
	/*
	Creeaza o noua cheltuiala
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	return: cheltuiala creata
	*/
	cheltuiala ch;
	ch.zi = zi;
	ch.suma = suma;
	size_t nrC = strlen(tip) + 1;
	ch.tip = malloc(sizeof(char) * nrC);
	strcpy_s(ch.tip, nrC, tip);
	return ch;
}

void destroyCheltuiala(cheltuiala* ch) {
	/*
	Dealoca memoria ocupata de o cheltuiala
	ch: pointer la cheltuiala cautata
	*/
	ch->zi = -1;
	ch->suma = -1;
	free(ch->tip);
	ch->tip = NULL;
}

cheltuiala copyCh(cheltuiala* c) {
	return createCheltuiala(c->zi, c->suma, c->tip);
}

void testCreateDestroy() {
	/*
	Testeaza crearea si distrugerea
	*/
	cheltuiala p = createCheltuiala(2, 200, "altele");

	assert(p.zi == 2);
	assert(p.suma == 200);
	assert(strcmp(p.tip, "altele") == 0);

	destroyCheltuiala(&p);
	assert(p.zi == -1);
	assert(p.suma == -1);
	assert(p.tip == NULL);
}