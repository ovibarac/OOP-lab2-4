#include "cheltuiala.h"
#include <string.h>
#include <assert.h>

cheltuiala cheltuieli[400];
int n = 0;

void add_cheltuiala(int zi, int suma, char tip[]) {
	/*
	Adauga o noua cheltuiala
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	cheltuieli[n].zi = zi;
	cheltuieli[n].suma = suma;
	strcpy_s(cheltuieli[n].tip, 20, tip);
	n++;
}

cheltuiala * get_cheltuieli() {
	/*
	Returneaza lista de cheltuieli
	rtype: pointer la cheltuiala
	*/
	return cheltuieli;
}

cheltuiala* find_cheltuiala(int zi, int suma, char tip[]) {
	/*
	Gaseste o cheltuiala dupa atribute
	rtype: pointer la cheltuiala
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	return: pointer la cheltuiala
	*/
	for (int i = 0; i < n; i++) {
		if (zi == cheltuieli[i].zi && suma == cheltuieli[i].suma && strcmp(tip, cheltuieli[i].tip) == 0)  {
			return &cheltuieli[i];
		}
	}
}


int get_lungime() {
	/*
	Returneaza lungimea listei de cheltuieli
	rtype: int >= 0
	*/
	return n;
}

void test_get_cheltuieli() {
	/*
	Testeaza obtinerea listei
	*/
	assert(get_cheltuieli() == cheltuieli);
}

void test_get_lungime() {
	/*
	Testeaza obtinerea lungimii listei
	*/
	assert(n == get_lungime());
}

void test_add_cheltuiala() {
	/*
	Testeaza adaugarea unei cheluieli
	*/
	int cn = n;
	cheltuiala ch[20];
	for (int i = 0; i <= n; i++) {
		ch[i] = cheltuieli[i];
	}

	add_cheltuiala(3, 300, "mancare");

	assert(n == cn + 1);
	assert(cheltuieli[n - 1].zi == 3);
	assert(cheltuieli[n - 1].suma == 300);
	assert(strcmp(cheltuieli[n - 1].tip, "mancare") == 0);

	n = cn;
}

void test_find_cheltuieli() {
	/*
	Testeaza gasirea unei cheltuieli
	*/

	cheltuiala ch;
	ch.zi = 1;
	ch.suma = 2;

	strcpy_s(ch.tip, 19, "mancare");
	add_cheltuiala(1, 2, "mancare");
	cheltuiala* c = find_cheltuiala(1, 2, "mancare");
	assert(c->zi == 1);
	assert(c->suma == 2);
	assert(strcmp(c->tip, "mancare") == 0);
}