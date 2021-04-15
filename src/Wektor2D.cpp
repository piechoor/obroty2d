#include "Wektor2D.hh"

using namespace std;

/*
  *  Metoda zwracajaca odleglosc miedzy dwoma punktami reprezentowanymi jako wektory.
  *
  *  Parametry wywolania:
  *  Wek - zawiera drugi wektor - punkt wzgledem ktorego liczymy modul.
  * 
  *  Warunki wstepne:
  *   Obiekt i Wek musza byc prawidlowo zdefiniowanymi wektorami.
  *  Warunki koncowe:
  *   Brak.
  *  Zwracana wartosc:
  *   Zwrocona zostaje odleglosc miedzy punktami wyrazonymi jako wektory zaczepionymi
  *   w srodku ukladu wspolrzednych.
*/
double Wektor2D::Modul(const Wektor2D &Wek) const {
    Wektor2D Roznica; // Pomocniczy wektor
    Roznica = *this - Wek;
    return sqrt(pow(Roznica[0], 2) + pow(Roznica[1], 2));
}

/*
  *  Przeciazenia operatora indeksujacego dla wektora, zwraca wskazane pole wektora.
  *  Jezeli indeks bedzie nieprawidlowy, metoda zakonczy dzialanie programu.
  *
  *  Parametry wywolania:
  *  indeks - indeks zwracanej wspolrzednej wektora. 
  * 
  *  Warunki wstepne:
  *   indeks musi byc rowny 0 lub 1, gdyz rozwazamy wektor o dwoch wspolrzednych
  *  Warunki koncowe:
  *   Brak.
  *  Zwracana wartosc:
  *   Zwrocona zostaje wspolrzedna wektora, zgodnie z podanym indeksem.
*/
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

/*
  *  Przeciazenie operatora dodawania dla dwoch wektorow, danego obiektu
  *  oraz wektora podanego jako parametr.
  *
  *  Parametr wywolania:
  *   Skladnik - wektor, drugi obok obiektu skladnik dodwania
  *
  *  Warunki wstepne:
  *   Obiekt i Skladnik musza byc prawidlowo zdefiniowanymi wektorami.
  *
  *  Warunki koncowe:
  *   Brak.
  *
  *  Zwraca wektor bedacy suma obiektu i parametru.
*/
Wektor2D Wektor2D::operator + (const Wektor2D Skladnik) const {
    Wektor2D Wynik;
    Wynik.Wsp[0] = this->Wsp[0] + Skladnik.Wsp[0];
    Wynik.Wsp[1] = this->Wsp[1] + Skladnik.Wsp[1];
    return Wynik;
}

/*
  *  Przeciazenie operatora odejmowania dla dwoch wektorow, danego obiektu
  *  oraz wektora podanego jako parametr.
  *
  *  Parametr wywolania:
  *   Skladnik - wektor, drugi obok obiektu skladnik odejmowania
  *
  *  Warunki wstepne:
  *   Obiekt i Skladnik musza byc prawidlowo zdefiniowanymi wektorami.
  *
  *  Warunki koncowe:
  *   Brak.
  *
  *  Zwraca wektor bedacy roznica obiektu i parametru.
*/
Wektor2D Wektor2D::operator - (const Wektor2D Skladnik) const {
    Wektor2D Wynik;
    Wynik.Wsp[0] = this->Wsp[0] - Skladnik.Wsp[0];
    Wynik.Wsp[1] = this->Wsp[1] - Skladnik.Wsp[1];
    return Wynik;
}

/*
  *  Funkcja wczytuje wektor postaci (x,y) ze strumienia Strm i wpisuje go 
  *  do obiektu typu Wektor2D Wek. 
  *  Jezeli wprowadzono wektor nieprawidlowo, ustawi flage failbit.
  *
  *  Parametry wywolania:
  *   Strm - strumien z ktorego wczytujemy wektor
  *   Wek - obiekt do ktorego wczytujemy wektor
  *
  *  Warunki wstepne:
  *   Prawidlowo zapisany wektor - musi byc postaci (x,y), gdzie x,y sa liczbami
  *   rzeczywistymi. Jezeli nie bedzie to spelnione zostanie ustawiona flaga bledu.
*/
istream& operator >> (istream &Strm, Wektor2D &Wek)
{
    char nawias_L = 'x', nawias_P = 'x', przecinek = 'x';

    Strm >> nawias_L >> Wek[0] >> przecinek >> Wek[1] >> nawias_P; // Pobranie wektora w zadanym formacie

    if (nawias_L != '(' || nawias_P != ')' || przecinek != ',')
      Strm.setstate(ios::failbit); // Jezeli pobrano nieprawidlowy znak ustaw flage bledu

    return Strm;
}

/*
  *  Funkcja wypisuje wspolrzedne wektora Wek na strumien Strm w postaci (x,y)
  *
  *  Parametry wywolania:
  *   Strm - strumien na ktory wypisujemy wektor
  *   Wek - obiekt z ktorego wczytujemy wektor
  *
  *  Warunki wstepne:
  *   Prawidlowy strumien i wektor Wek.
*/
ostream& operator << (ostream &Strm, const Wektor2D &Wek)
{
  Strm << "(" << Wek[0]  << "," << Wek[1] << ")"; // Wyswietlenie l zespolonej w prawidlowym formacie
  return Strm;
} 