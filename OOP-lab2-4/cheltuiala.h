#ifndef CHELTUIALA_H_

#define CHELTUIALA_H_

#pragma once

typedef struct cheltuiala {
	/*
	zi: ziua  in care s-a efectuat cheltuiala
	suma: suma cheltuielii
	tip: tipul cheltuielii "mancare, transport, telefon&internet, inbracaminte, altele"
	*/
	int zi;
	int suma;
	char tip[20];
}cheltuiala;

#endif // !CHELTUIALA_H_
