#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

/*
 *  Klasa modeluje Macierz2x2 o 4 elementach, mozliwe jest rowniez zastosowanie
 *  klasy jako macierz obrotu, poniewaz zdefiniowany jest kat obrotu oraz
 *  konstruktor tworzacy taka macierz.
 */
class Macierz2x2 {

    double Elem[2][2]; // 
    double Kat_obr; // Kat obrotu dla macierzy obrotu
    
  public:

    // Konstruktor domyslny zerujacy wszystkie pola klasy.
    Macierz2x2() { Elem[0][0] = Elem[0][1] = Elem[1][0] = Elem[1][1] = Kat_obr = 0; }

    void Inicjuj_obr(double Kat);

    double operator () (unsigned int wiersz, unsigned int kolumna) const;

    // Przeciazenie operatora mnozenia macierzy przez wektor, jako wynik zwraca Wektor2D.
    const Wektor2D operator * (const Wektor2D &Wek) const;  

};


// Przeciazenie operatora << pozwalajace na wyswietlenie macierzy.
std::ostream& operator << (std::ostream &Strm, Macierz2x2 Mac);

#endif
