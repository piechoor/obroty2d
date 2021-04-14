#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor2D {

    double Wsp[2];
  
  public:

    Wektor2D() { Wsp[0] = 0; Wsp[1] = 0; }

    Wektor2D(double Wsp_x, double Wsp_y) { this->Wsp[0] = Wsp_x;  this->Wsp[1] = Wsp_y; }

    const double& operator [] (int indeks) const;

    double& operator [] (int indeks);

    Wektor2D operator + (const Wektor2D Skladnik) const;

    Wektor2D operator - (const Wektor2D Odjemnik) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
