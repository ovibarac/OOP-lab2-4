#include "service.h"
#include <stdio.h>

void generate(Buget* b) {
	/*
	Genereaza o lista de cheltuieli
	*/
	addCheltuiala(b, 3, 20, "mancare");
	addCheltuiala(b, 5, 20, "altele");
	addCheltuiala(b, 15, 200, "transport");
	addCheltuiala(b, 20, 19, "mancare");
	addCheltuiala(b, 1, 200, "transport");
	addCheltuiala(b, 4, 50, "altele");
}

void print_menu(Buget* b) {
	printf("1. Adaugare cheltuiala\n");
	printf("2. Modificare cheltuiala\n");
	printf("3. Stergere cheltuiala\n");
	printf("4. Afiseaza lista\n");
	printf("5. Filtrare dupa proprietate (zi, suma, tip)\n");
	printf("6. Sortare\n");
	printf("0. Exit\n");
}

void print_list(Buget* b) {
	/*
	Printeaza lista
	*/
	for (int i = 0; i < b->allCh.lg; i++) {
		if (&(b->allCh.elems[i]) != NULL)
			printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, b->allCh.elems[i].zi, b->allCh.elems[i].suma, b->allCh.elems[i].tip);
	}
}

void add_ui(Buget* b) {
	/*
	UI pentru adaugarea unei cheltuieli
	*/
	int zi, suma;
	char tip[20];
	printf("Zi: ");
	scanf_s("%d", &zi);
	printf("Suma: ");
	scanf_s("%d", &suma);
	printf("Tip: ");
	scanf_s("%s", tip, 19);
	addCheltuiala(b, zi, suma, tip);
}

void mod_ui(Buget* b) {
	int zi, suma;
	char tip[20];
	printf("Zi: ");
	scanf_s("%d", &zi);
	printf("Suma: ");
	scanf_s("%d", &suma);
	printf("Tip: ");
	scanf_s("%s", tip, 19);

	int new_zi, new_suma;
	char new_tip[20];
	printf("Noua zi: ");
	scanf_s("%d", &new_zi);
	printf("Noua suma: ");
	scanf_s("%d", &new_suma);
	printf("Noul tip: ");
	scanf_s("%s", new_tip, 19);

	cheltuiala* ch = findCheltuiala(&b->allCh, zi, suma, tip);
	if (ch == NULL) {
		printf("Cheltuiala not found");
	}
	else {
		mod(ch, new_zi, new_suma, new_tip);
	}
}

void delete_ui(Buget* b) {
	int zi, suma;
	char tip[20];
	printf("Zi: ");
	scanf_s("%d", &zi);
	printf("Suma: ");
	scanf_s("%d", &suma);
	printf("Tip: ");
	scanf_s("%s", tip, 19);

	cheltuiala* ch = findCheltuiala(&b->allCh, zi, suma, tip);
	if (ch == NULL) {
		printf("Cheltuiala not found");
	}
	else {
		b->allCh.elems = deleteCheltuiala(&b->allCh, ch);
	}
}

void filtrare_prop(Buget* b) {
	printf("Proprietatea:\n");
	printf("1. Zi\n");
	printf("2. Suma\n");
	printf("3. Tip\n");
	int c = 0;
	scanf_s("%d", &c);
	if (c == 1) {
		printf("Zi: ");
		int z = 0;
		scanf_s("%d", &z);
		for (int i = 0; i < b->allCh.lg; i++) {
			if (&(b->allCh.elems[i]) != NULL && b->allCh.elems[i].zi == z)
				printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, b->allCh.elems[i].zi, b->allCh.elems[i].suma, b->allCh.elems[i].tip);
		}
	}
	else if (c == 2) {
		printf("Suma: ");
		int z = 0;
		scanf_s("%d", &z);
		for (int i = 0; i < b->allCh.lg; i++) {
			if (&(b->allCh.elems[i]) != NULL && b->allCh.elems[i].suma == z)
				printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, b->allCh.elems[i].zi, b->allCh.elems[i].suma, b->allCh.elems[i].tip);
		}
	}
	else if (c == 3) {
		printf("Tip: ");
		char tip[20];
		scanf_s("%s", tip, 19);
		for (int i = 0; i < b->allCh.lg; i++) {
			if (&(b->allCh.elems[i]) != NULL && strcmp(b->allCh.elems[i].tip, tip) == 0)
				printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, b->allCh.elems[i].zi, b->allCh.elems[i].suma, b->allCh.elems[i].tip);
		}
	}
}

void sortare_ui(Buget* b) {
	printf("Ordonare dupa:\n");
	printf("1. Suma\n");
	printf("2. Tip\n");
	int c = 0;
	scanf_s("%d", &c);
	Lista l;
	if (c == 1) {
		printf("Ordine:\n");
		printf("1. Crescatoare\n");
		printf("2. Descrescatoare\n");
		int r = 0;
		scanf_s("%d", &r);
		if (r == 1) {
			l = sortBySuma(b, 0);

		}
		else if (r == 2) {
			l = sortBySuma(b, 1);
		}
	}
	else if(c == 2) {
		printf("Ordine:\n");
		printf("1. Crescatoare\n");
		printf("2. Descrescatoare\n");
		int r = 0;
		scanf_s("%d", &r);
		if (r == 1) {
			l = sortByTip(b, 0);
		}
		else if (r == 2) {
			l = sortByTip(b, 1);
		}
	}
	Buget srtbgt;
	srtbgt.allCh = copyList(&l);
	print_list(&srtbgt);

	destroy(&l);
	destroyBuget(&srtbgt);
}
