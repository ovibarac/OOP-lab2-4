#include "service.h"
#include <stdio.h>

void run() {
	//char cmd[20];
	int cmd;
	while (1) {
		print_menu();
		printf("Give command: ");
		//scanf_s("%s", &cmd);
		scanf_s("%d", &cmd);

		if (cmd == 1) {
			add_ui();
		}
		else if (cmd == 0) {
			return;
		}
	}
}

void add_ui() {
	/*
	UI pentru adaugarea unei cheltuieli
	*/
	int zi, suma;
	char tip[20];
	scanf_s("%d", &zi);
	scanf_s("%d", &suma);
	//scanf_s("%s", tip);
	add(zi, suma, tip);

}

void print_menu() {
	printf("1. Adaugare cheltuiala\n");
	printf("0. Exit\n");

}