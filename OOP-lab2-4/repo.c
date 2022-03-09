#include "cheltuiala.h"
#include <string.h>
#include <assert.h>

cheltuiala cheltuieli[20];
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
}