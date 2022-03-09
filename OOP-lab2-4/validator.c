#include <string.h>

void validate(int zi, int suma, char tip[], char errors[][], int *nr_err) {
	/*
	Valideaza o cheltuiala
	zi: int > 0, ziua  in care s-a efectuat cheltuiala
	suma: int > 0, suma cheltuielii
	tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	errors: output, array de siruri de caractere reprezentand erorile
	nr_err: int>=0, numarul erorilor rezultate
	*/
	*nr_err = 0;
	if (zi <= 0 || zi > 31) {
		strcpy(errors[*nr_err], "Ziua trebuie sa fie intreg intre 1 si 31");
		(*nr_err)++;
	}
	if (suma <= 0) {
		strcpy(errors[*nr_err], "Suma trebuie sa fie intreg strict pozitiv");
		(*nr_err)++;
	}
	if (strcmp(tip, "mancare") != 0 && strcmp(tip, "transport") != 0 && strcmp(tip, "telefon&internet") != 0 &&
		strcmp(tip, "imbracaminte") != 0 && strcmp(tip, "altele") != 0) {
		strcpy(errors[*nr_err], "Tipul trebuie sa fie: mancare, transport, telefon&internet, inbracaminte sau altele ");
		(*nr_err)++;
	}
}