#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>

#include "Wektor2D.hh"
#include "Macierz2x2.hh"

/*
 *  Klasa Prostokat modeluje prostokat skladjacy sie z 4 punktow wyrazonych 
 *  jako wektory 2D. Pozwala wykonywac operacje umozliwiajace obrot, translacje
 *  oraz sprawdzenie stani prostokata.
 */
class Prostokat {

    Wektor2D Wierzch[4]; // Tablica wierzcholkow prostokata
  
  public:

    Prostokat() {}; // Konstruktor domyslny klasy

    // Konstruktor pobierajacy cztery wektory i ustwaiajacy je jako kolejne wierzcholki prostokata.
    Prostokat(Wektor2D W1, Wektor2D W2, Wektor2D W3, Wektor2D W4) {
      Wierzch[0] = W1; Wierzch[1] = W2; Wierzch[2] = W3; Wierzch[3] = W4; };

    // Przeciazenie operatora indeksujacego, zwraca wektor reprezentujacy dany wierzcholek
    // w zaleznosci od podanego indeksu.
    const Wektor2D& operator [] (unsigned int indeks) const;

    // Metoda obraca kazdy wierzcholek prostokata L_obr liczbe obrotow o dany kat Kat.
    void Obroc(unsigned long L_obr, double Kat);

    // Metoda sprawdzajaca dlugosci naprzeciwleglych bokow prostokata i wyswietlajaca o nich komunikat.
    void Spr_boki() const;

    // Metoda przesuwajaca kazdy wierzcholek prostokata o zadany wektor
    void Przesun(const Wektor2D &Wek);

    // Metoda zapisujaca wspolrzedne prostokata do pliku o nazwie podanej jako parametr.
    bool Zapisz(const char *sNazwaPliku) const;
};


// Funkcja wyswietlajaca wspolrzedne wierzcholkow prostokata.
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
