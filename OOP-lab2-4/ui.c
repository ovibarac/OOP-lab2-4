#include "service.h"
#include <stdio.h>

void print_menu() {
	printf("1. Adaugare cheltuiala\n");
	printf("2. Modificare cheltuiala\n");
	printf("4. Afiseaza lista\n");
	printf("0. Exit\n");
}

void add_ui() {
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
	add(zi, suma, tip);
}

void mod_ui() {
	/*
	UI pentru modificarea unei cheltuieli
	*/
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
	mod(zi, suma, tip, new_zi, new_suma, new_tip);
}


void run() {
	int cmd=0;
	while (1) {
		print_menu();
		printf("\nGive command: ");
		scanf_s("%d", &cmd);

		if (cmd == 1) {
			add_ui();
		}
		else if (cmd == 2) {
			mod_ui();
		}
		else if (cmd == 0) {
			return;
		}
		printf('\n');
	}
}
