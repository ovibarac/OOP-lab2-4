#include "service.h"
#include <stdio.h>

void print_menu(Buget* b) {
	printf("1. Adaugare cheltuiala\n");
	printf("2. Modificare cheltuiala\n");
	printf("3. Filtrare dupa proprietate (zi, suma, tip)\n");
	printf("4. Afiseaza lista\n");
	printf("0. Exit\n");
}

void print_list(Buget* b) {
	/*
	Printeaza lista
	*/
	for (int i = 0; i < &b->allCh.lg; i++) {
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
/*
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
		cheltuiala* ch = get_list();
		int n = get_size();
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				if(ch[i].zi == z)
					printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, ch[i].zi, ch[i].suma, ch[i].tip);
			}
		}
	}
	else if (c == 2) {
		printf("Suma: ");
		int z = 0;
		scanf_s("%d", &z);
		cheltuiala* ch = get_list();
		int n = get_size();
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				if (ch[i].suma == z)
					printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, ch[i].zi, ch[i].suma, ch[i].tip);
			}
		}
	}
	else if (c == 3) {
		printf("Tip: ");
		char tip[20];
		scanf_s("%s", tip, 19);
		cheltuiala* ch = get_list();
		int n = get_size();
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				if (strcmp(ch[i].tip, tip) == 0)
					printf("%d. Zi: %d, Suma: %d, Tip: %s\n", i, ch[i].zi, ch[i].suma, ch[i].tip);
			}
		}
	}
}
*/