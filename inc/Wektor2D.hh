#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <iomanip>
#include <cmath>

/*
 *  Klasa Wektor2D modeluje wektor na plaszczyznie R2.
 *  Jej metody definiuja glowne operacje na wektorach.
 */
class Wektor2D {

    double Wsp[2]; // Tablica wspolrzednych wektora
  
  public:

    Wektor2D() { Wsp[0] = 0; Wsp[1] = 0; } // Konstruktor domyslny zerujacy pola wektora

    // Konstruktor przypisujacy polom struktury dwie pobrane liczby rzeczywiste
    Wektor2D(double Wsp_x, double Wsp_y) { Wsp[0] = Wsp_x; Wsp[1] = Wsp_y; }

    // Metoda zwracajaca odleglosc miedzy dwoma punktami reprezentowanymi jako wektory
    double Modul(const Wektor2D &Wek) const;

    // Przeciazenia operatora indeksujacego dla wektora, zwraca wskazane pole wektora
    const double& operator [] (unsigned int indeks) const;
    double& operator [] (unsigned int indeks);

    // Przeciazenie operatora dodawania dla dwoch wektorow
    Wektor2D operator + (const Wektor2D Skladnik) const;

    // Przeciazenie operatora odejmowania dla dwoch wektorow
    Wektor2D operator - (const Wektor2D Odjemnik) const;

};


/*
 * Funkcja wczytuje wektor postaci (x,y) ze strumienia Strm i wpisuje go 
 * do obiektu typu Wektor2D Wek.
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * Funkcja wypisuje wspolrzedne wektora Wek na strumien Strm w postaci (x,y)
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
