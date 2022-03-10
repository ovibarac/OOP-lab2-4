#pragma once
#ifndef VALIDATOR_H_
#define VALIDATOR_H_


/*
Valideaza o cheltuiala
zi: int > 0, ziua  in care s-a efectuat cheltuiala
suma: int > 0, suma cheltuielii
tip: sir caractere, tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
errors: output, array de siruri de caractere reprezentand erorile
nr_err: int>=0, numarul erorilor rezultate
*/
void validate(int zi, int suma, char tip[], char errors[5][100], int* nr_err);

/*
Testeaza validarea
*/
void test_validate();

#endif // !VALIDATOR_H_

