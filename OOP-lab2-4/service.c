#include "repo.h"
#include "validator.h"
#include <stdio.h>
#include <assert.h>

void add(int zi, int suma, char tip[]) {
	/*
	Adauga o noua cheltuiala si valideaza
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	
	//validare
	int nr_err = 0;
	char errors[5][100];
	validate(zi, suma, tip, errors, &nr_err);
	if (nr_err == 0) {
		add_cheltuiala(zi, suma, tip);
	}
	else {
		for (int i = 0; i < nr_err; i++) {
			printf("%s\n", errors[i]);
		}
	}
}

void mod(int zi, int suma, char tip[], int new_zi, int new_suma, char new_tip[]) {
	/*
	Modifica o cheltuiala
	zi: int > 0, ziua  cheltuielii cautate
	suma: int > 0, suma cheltuielii cautate
	tip: sir caractere, tipul cheltuielii cautate
	new_zi: int > 0, ziua  modificata
	new_suma: int > 0, suma modificata
	new_tip: sir caractere, tipul modificat
	*/
	cheltuiala* ch = find(zi, suma, tip);
	ch->zi = new_zi;
	ch->suma = new_suma;
	strcpy_s(ch->tip, 19, new_tip);
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

void test_get_cheltuieli_srv() {
	/*
	Testeaza obtinerea listei
	*/
	assert(get_cheltuieli() == get_list());
}

void test_get_lungime_srv() {
	/*
	Testeaza obtinerea lungimii listei
	*/
	int n1 = get_size();
	int n2 = get_lungime();
	assert(n1 == n2);
}

void test_add_cheltuiala_srv() {
	/*
	Testeaza adaugarea unei cheluieli
	*/
	char errors[5][100];
	int nr_err = 0;
	int zi = 2;
	int suma = 20;
	char tip[20];

	strcpy_s(tip, 19, "mancare");
	validate(zi, suma, tip, errors, &nr_err);
	assert(nr_err == 0);

	add(zi, suma, tip);
	cheltuiala* ch = get_list();
	int n = get_size();

	assert(ch[n - 1].zi == 2);
	assert(ch[n - 1].suma == 20);
	assert(strcmp(ch[n - 1].tip, "mancare") == 0);

	

}
