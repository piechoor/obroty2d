#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <fstream>

#include "Wektor2D.hh"
#include "Macierz2x2.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {

    Wektor2D Wierzch[4];
  
  public:

    Prostokat() { };

    Prostokat(Wektor2D W1, Wektor2D W2, Wektor2D W3, Wektor2D W4) {
      Wierzch[0] = W1; Wierzch[1] = W2; Wierzch[2] = W3; Wierzch[3] = W4; };

    const Wektor2D& operator [] (int indeks) const;

    void Obroc(long L_obr, double Kat);

    void Spr_boki(); 

    bool Zapisz(const char  *sNazwaPliku);
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
