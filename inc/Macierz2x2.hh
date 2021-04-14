#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH


#include <iostream>
#include <cmath>
#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz2x2 {

    double Elem[4];
    float Kat_obr;
    
  public:
  
    Macierz2x2() { Elem[0] = Elem[1] = Elem[2] = Elem[3] = Kat_obr = 0; }

    Macierz2x2(double a11, double a12, double a21, double a22);

    Macierz2x2(float Kat);

    const double& operator [] (int indeks) const;

    const Wektor2D operator * (const Wektor2D &Wek) const;  

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
