#include <string.h>
#include <assert.h>

void validate(int zi, int suma, char tip[], char errors[5][100], int* nr_err) {
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
		strcpy_s(errors[*nr_err], 99, "Ziua trebuie sa fie intreg intre 1 si 31");
		(*nr_err)++;
	}
	if (suma <= 0) {
		strcpy_s(errors[*nr_err], 99, "Suma trebuie sa fie intreg strict pozitiv");
		(*nr_err)++;
	}
	if (strcmp(tip, "mancare") != 0 && strcmp(tip, "transport") != 0 && strcmp(tip, "telefon&internet") != 0 &&
		strcmp(tip, "imbracaminte") != 0 && strcmp(tip, "altele") != 0) {
		strcpy_s(errors[*nr_err], 99, "Tipul trebuie sa fie: mancare, transport, telefon&internet, inbracaminte sau altele");
		(*nr_err)++;
	}
}

void test_validate() {
	/*
	Testeaza validarea
	*/
	char errors[5][100];
	int nr_err = 0;
	int zi = 0;
	int suma = 0;
	char tip[20];
	strcpy_s(tip, 19, "a");
	validate(zi, suma, tip, errors, &nr_err);

	assert(strcmp(errors[0], "Ziua trebuie sa fie intreg intre 1 si 31") == 0);
	assert(strcmp(errors[1], "Suma trebuie sa fie intreg strict pozitiv") == 0);
	assert(strcmp(errors[2], "Tipul trebuie sa fie: mancare, transport, telefon&internet, inbracaminte sau altele") == 0);
	assert(nr_err == 3);

	char errors2[5][100];
	nr_err = 0;
	zi = 30;
	suma = -1;
	strcpy_s(tip, 19, "mancare");
	validate(zi, suma, tip, errors2, &nr_err);

	assert(strcmp(errors2[0], "Suma trebuie sa fie intreg strict pozitiv") == 0);
	assert(nr_err == 1);

	char errors3[5][100];
	nr_err = 0;
	zi = 30;
	suma = 200;
	strcpy_s(tip, 19, "asd");
	validate(zi, suma, tip, errors3, &nr_err);

	assert(strcmp(errors3[0], "Tipul trebuie sa fie: mancare, transport, telefon&internet, inbracaminte sau altele") == 0);
	assert(nr_err == 1);

	char errors4[5][100];
	nr_err = 0;
	zi = 0;
	suma = 200;
	strcpy_s(tip, 19, "altele");
	validate(zi, suma, tip, errors4, &nr_err);

	assert(strcmp(errors4[0], "Ziua trebuie sa fie intreg intre 1 si 31") == 0);
	assert(nr_err == 1);
}