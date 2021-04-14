#include "Macierz2x2.hh"

using namespace std;

Macierz2x2::Macierz2x2(double a11, double a12, double a21, double a22, double Kat) {
    Elem[0] = a11; Elem[1] = a12;
    Elem[2] = a21; Elem[3] = a22;
    Kat = 0;
}

Macierz2x2::Macierz2x2(double a11, double a12, double a21, double a22) {
    Elem[0] = a11; Elem[1] = a12;
    Elem[2] = a21; Elem[3] = a22;
}

ostream& operator << (ostream &Strm, const Macierz2x2 &Mac) {
    cout << "| " << Mac[0] << "\t" << Mac[1] << " |" << endl;
    cout << "| " << Mac[2] << "\t" << Mac[3] << " |" << endl;
    return Strm;
}

const double& Macierz2x2::operator [] (int indeks) const {
    if (indeks < 0 || indeks >= 4)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu macierzy" << endl;
        exit(0);
    }
    return Elem[indeks];
}

const Wektor2D Macierz2x2::operator * (const Wektor2D &Wek) const {
    Wektor2D Wynik;
    Wynik[0] = this->Elem[0] * Wek[0] + this->Elem[1] * Wek[1];
    Wynik[1] = this->Elem[2] * Wek[0] + this->Elem[3] * Wek[1];
    return Wynik;
}