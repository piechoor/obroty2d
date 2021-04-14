#include "Prostokat.hh"

using namespace std;

const Wektor2D& Prostokat::operator [] (int indeks) const {
    if (indeks < 0 || indeks >= 4)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu macierzy" << endl;
        exit(0);
    }
    return Wierzch[indeks];
}

void Prostokat::Obroc(long L_obr, float Kat) {
    Macierz2x2 Mac_obr(Kat);

    for (int i = 0; i < L_obr; i++) {
        for (int j = 0; j < 4; j++)
            Wierzch[j] = Mac_obr *  Wierzch[j];
    }
}

ostream& operator << (ostream &Strm, const Prostokat &Pr) {
    Strm << Pr[0] << endl << Pr[1] << endl << Pr[2] << endl << Pr[3] << endl;
    return Strm;
}