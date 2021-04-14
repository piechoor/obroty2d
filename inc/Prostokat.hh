#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include "Wektor2D.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat {

    Wektor2D Wierzch[4];
  
  public:
  
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostokat    &Pr
                          );


#endif
