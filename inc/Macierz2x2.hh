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

    double Elem[4]; // Elementy macierzy oznaczone od lewej do prawej, od gory do dolu.
    double Kat_obr; // Kat obrotu dla macierzy obrotu
    
  public:

    // Konstruktor domyslny zerujacy wszystkie pola klasy.
    Macierz2x2() { Elem[0] = Elem[1] = Elem[2] = Elem[3] = Kat_obr = 0; }

    // Konstruktor ustawiajacy pola klasy na podane wartosci oraz kat obrotu na zero.
    Macierz2x2(double a11, double a12, double a21, double a22);

    // Konstruktor tworzacy macierz obrotu.
    Macierz2x2(double Kat);

    // Przeciazenie operatora indeksujacego dla macierzy.
    const double& operator [] (int indeks) const;

    // Przeciazenie operatora mnozenia macierzy przez wektor, jako wynik zwraca Wektor2D.
    const Wektor2D operator * (const Wektor2D &Wek) const;  

};


// Przeciazenie operatora << pozwalajace na wyswietlenie macierzy.
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
