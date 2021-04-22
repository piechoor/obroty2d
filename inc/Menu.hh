#ifndef MENU_HH
#define MENU_HH

#include <iostream>
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

// Funckja wyswietla mozliwe operacje na prostokacie.
void Wysw_menu();

// Funkcja wykonujaca operacje obrotu na prostokacie.
bool Przetw_obrot(Prostokat &Pr);

// Funckja wywolujaca menu programu
bool Przetw_menu(Prostokat Pr, PzG::LaczeDoGNUPlota Lacze);

#endif