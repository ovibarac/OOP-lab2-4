#include "validator.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "cheltuiala.h"
#include "service.h"
#include "Lista.h"

Buget createBuget(){
	/*
	Creeaza un nou buget
	return: Buget
	*/
	Buget rez;
	rez.allCh = createEmpty();
	return rez;
}

void destroyBuget(Buget* b) {
	/*
	Distruge un buget
	b: pointer la buget
	*/
	destroy(&b->allCh);
}

void addCheltuiala(Buget* b, int zi, int suma, char tip[]) {
	/*
	Adauga o noua cheltuiala si valideaza
	b: pointer la buget
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	
	//validare
	int nr_err = 0;
	char errors[5][100];
	validate(zi, suma, tip, errors, &nr_err);
	if (nr_err == 0) {
		cheltuiala ch = createCheltuiala(zi, suma, tip);
		add(&b->allCh, ch);
	}
	else {for (int i = 0; i < nr_err; i++) {printf("%s\n", errors[i]);}}
}

void mod(cheltuiala* ch, int new_zi, int new_suma, char new_tip[]) {
	/*
	Modifica o cheltuiala
	ch: pointer la cheltuiala de modificat
	new_zi: int > 0, ziua  modificata
	new_suma: int > 0, suma modificata
	new_tip: sir caractere, tipul modificat
	*/
	int nr_err = 0;
	char errors[5][100];
	validate(new_zi, new_suma, new_tip, errors, &nr_err);
	if (nr_err == 0) {
		if (ch != NULL) {
			ch->zi = new_zi;
			ch->suma = new_suma;
			size_t nrC = strlen(new_tip) + 1;
			
			strcpy_s(ch->tip, nrC, new_tip);
		}
	}
	else { for (int i = 0; i < nr_err; i++) { printf("%s\n", errors[i]); } }
}

Lista sortBySuma(Buget* b, int reverse) {
	/*
	Sorteaza lista dupa suma
	l: pointer la lista
	reverse: 1 daca se sorteaza descrescator, 0 altfel
	*/
	Lista l = sort(b, cmpSuma, reverse);
	return l;
}

Lista sortByTip(Buget* b, int reverse) {
	/*
	Sorteaza lista dupa tip
	l: pointer la lista
	reverse: 1 daca se sorteaza descrescator, 0 altfel
	return: lista sortata
	*/
	Lista l = sort(b, cmpTip, reverse);
	return l;
}

Lista sort(Buget* b, FunctieComparare cmpF, int reverse) {
	Lista l = copyList(&b->allCh);
	int i, j;
	if (reverse == 0) {
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala c1 = get(&l, i);
				cheltuiala c2 = get(&l, j);
				if (cmpF(&c1, &c2) > 0) {
					set(&l, i, c2);
					set(&l, j, c1);
				}
			}
		}
	}
	else {
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala c1 = get(&l, i);
				cheltuiala c2 = get(&l, j);
				if (cmpF(&c1, &c2) < 0) {
					set(&l, i, c2);
					set(&l, j, c1);
				}
			}
		}
	}
	return l;
}

int cmpSuma(cheltuiala* c1, cheltuiala* c2) {
	if (c1->suma > c2->suma) {
		return 1;
	}
	else if (c1->suma == c2->suma) {
		return 0;
	}
	else {
		return -1;
	}
}

int cmpTip(cheltuiala* c1, cheltuiala* c2) {
	return strcmp(c1->tip, c2->tip);
}

void test_sort() {
	Buget b = createBuget();
	addCheltuiala(&b, 1, 2, "altele");
	addCheltuiala(&b, 2, 20, "mancare");
	addCheltuiala(&b, 4, 45, "transport");
	addCheltuiala(&b, 3, 20, "mancare");


	Lista l = sortByTip(&b, 0);
	assert(l.elems[0].zi == 1);
	assert(l.elems[0].suma == 2);
	assert(strcmp(l.elems[0].tip, "altele") == 0);

	l = sortByTip(&b, 1);
	assert(l.elems[0].zi == 4);
	assert(l.elems[0].suma == 45);
	assert(strcmp(l.elems[0].tip, "transport") == 0);

	l = sortBySuma(&b, 0);
	assert(l.elems[0].zi == 1);
	assert(l.elems[0].suma == 2);
	assert(strcmp(l.elems[0].tip, "altele") == 0);

	l = sortByTip(&b, 1);
	assert(l.elems[0].zi == 4);
	assert(l.elems[0].suma == 45);
	assert(strcmp(l.elems[0].tip, "transport") == 0);
	destroy(&l);
	destroyBuget(&b);
}

void testAddCh() {
	Buget b = createBuget();
	addCheltuiala(&b, 1, 2, "altele");
	addCheltuiala(&b, 2, 20, "mancare");
	
	assert(size(&b.allCh) == 2);
	
	destroyBuget(&b);
}

void test_mod() {
	Buget b = createBuget();

	addCheltuiala(&b, 1, 2, "mancare");
	cheltuiala* ch = findCheltuiala(&b.allCh, 1, 2, "mancare");
	mod(ch, 5, 6, "altele");
	assert(ch->zi == 5);
	assert(ch->suma == 6);
	assert(strcmp(ch->tip, "altele") == 0);

	ch = findCheltuiala(&b.allCh, 7, 8, "mancare");
	assert(ch == NULL);

	destroyBuget(&b);
	

}
