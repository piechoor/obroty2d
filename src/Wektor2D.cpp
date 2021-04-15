#include "Wektor2D.hh"

using namespace std;


double Wektor2D::Modul(const Wektor2D &Wek) const {
    Wektor2D Roznica;
    Roznica = *this - Wek;
    return sqrt(pow(Roznica[0], 2) + pow(Roznica[1], 2));
}

const double& Wektor2D::operator [] (int indeks) const {
    if (indeks < 0 || indeks >= 2)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu wektora" << endl;
        exit(0);
    }
    return this->Wsp[indeks];
}

double& Wektor2D::operator [] (int indeks) {
    if (indeks < 0 || indeks >= 2)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu wektora" << endl;
        exit(0);
    }
    return Wsp[indeks];
}

Wektor2D Wektor2D::operator + (const Wektor2D Skladnik) const {
    Wektor2D Wynik;
    Wynik.Wsp[0] = this->Wsp[0] + Skladnik.Wsp[0];
    Wynik.Wsp[1] = this->Wsp[1] + Skladnik.Wsp[1];
    return Wynik;
}

Wektor2D Wektor2D::operator - (const Wektor2D Skladnik) const {
    Wektor2D Wynik;
    Wynik.Wsp[0] = this->Wsp[0] - Skladnik.Wsp[0];
    Wynik.Wsp[1] = this->Wsp[1] - Skladnik.Wsp[1];
    return Wynik;
}

istream& operator >> (istream &Strm, Wektor2D &Wek)
{
    char nawias_L = 'x', nawias_P = 'x', przecinek = 'x';

    Strm >> nawias_L >> Wek[0] >> przecinek >> Wek[1] >> nawias_P; // Pobranie wektora w zadanym formacie

    if (nawias_L != '(' || nawias_P != ')' || przecinek != ',')
      Strm.setstate(ios::failbit); // Jezeli pobrano nieprawidlowy znak ustaw flage bledu

    return Strm;
}

ostream& operator << (ostream &Strm, const Wektor2D &Wek)
{
  Strm << "(" << Wek[0]  << "," << Wek[1] << ")"; // Wyswietlenie l zespolonej w prawidlowym formacie
  return Strm;
} 