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
	Lista l = copyList(&b->allCh);

	if (reverse == 0) {
		int i, j;
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala p1 = get(&l, i);
				cheltuiala p2 = get(&l, j);
				if (p1.suma > p2.suma) {
					//interschimbam
					set(&l, i, p2);
					set(&l, j, p1);
				}
			}
		}
	}
	else {
		int i, j;
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala p1 = get(&l, i);
				cheltuiala p2 = get(&l, j);
				if (p1.suma < p2.suma) {
					//interschimbam
					set(&l, i, p2);
					set(&l, j, p1);
				}
			}
		}
	}

	return l;
}

Lista sortByTip(Buget* b, int reverse) {
	/*
	Sorteaza lista dupa tip
	l: pointer la lista
	reverse: 1 daca se sorteaza descrescator, 0 altfel
	*/
	Lista l = copyList(&b->allCh);

	if (reverse == 0) {
		int i, j;
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala p1 = get(&l, i);
				cheltuiala p2 = get(&l, j);
				if (strcmp(p1.tip, p2.tip) > 0) {
					//interschimbam
					set(&l, i, p2);
					set(&l, j, p1);
				}
			}
		}
	}
	else {
		int i, j;
		for (i = 0; i < size(&l); i++) {
			for (j = i + 1; j < size(&l); j++) {
				cheltuiala p1 = get(&l, i);
				cheltuiala p2 = get(&l, j);
				if (strcmp(p1.tip, p2.tip) < 0) {
					//interschimbam
					set(&l, i, p2);
					set(&l, j, p1);
				}
			}
		}
	}

	return l;
}

/*
void testAddCh() {
	Buget b = createBuget();
	addCheltuiala(&b, 1, 2, "altele");
	addCheltuiala(&b, "a2", "b2", 20);
	MyList filtered = getAllPet(&store, NULL);
	assert(size(&filtered) == 2);
	destroy(&filtered);

	filtered = getAllPet(&store, "a2");
	assert(size(&filtered) == 1);
	destroy(&filtered);

	filtered = getAllPet(&store, "2");
	assert(size(&filtered) == 1);
	destroy(&filtered);

	filtered = getAllPet(&store, "a");
	assert(size(&filtered) == 2);
	destroy(&filtered);

	destroyStore(&store);
}*/
/*
void test_mod() {
	
	char errors[5][100];
	int nr_err = 0;
	int zi = 2;
	int suma = 20;
	char tip[20];
	strcpy_s(tip, 19, "mancare");
	validate(zi, suma, tip, errors, &nr_err);

	add(zi, suma, tip);
	cheltuiala* ch = get_list();
	int n = get_size();

	cheltuiala* fc = find_cheltuiala(zi, suma, tip);
	mod(zi, suma, tip, 3, 3, "altele");
	assert(fc->zi == 3);
	assert(fc->suma == 3);
	assert(strcmp(fc->tip, "altele") == 0);

}*/
