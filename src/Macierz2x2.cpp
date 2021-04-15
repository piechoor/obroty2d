#include "Macierz2x2.hh"

using namespace std;

// Konstruktor ustawiajacy pola klasy na podane wartosci pobrane 
// jako parametry oraz kat obrotu na zero.
Macierz2x2::Macierz2x2(double a11, double a12, double a21, double a22) {
    Elem[0] = a11; Elem[1] = a12;
    Elem[2] = a21; Elem[3] = a22;
    Kat_obr = 0;
}

// Konstruktor tworzacy macierz obrotu w okol srodka ukladu wspolrzednych.
// pobiera kat wyrazony w stopniach.
Macierz2x2::Macierz2x2(double Kat) {
    Kat_obr = Kat*M_PI/180; // Zamiana stopni na radiany
    Elem[0] = cos(Kat_obr); Elem[1] = -sin(Kat_obr);
    Elem[2] = sin(Kat_obr); Elem[3] = cos(Kat_obr);
}

/*
  *  Przeciazenie operatora indeksujacego dla macierzy, zwraca wskazane pole macierzy.
  *  Jezeli indeks bedzie nieprawidlowy, metoda zakonczy dzialanie programu.
  *
  *  Parametry wywolania:
  *  indeks - indeks zwracanego elementu macierzy. 
  * 
  *  Warunki wstepne:
  *   indeks musi byc zawierac sie w przedziale <0,3>, gdyz rozwazamy macierz 2x2
  *  Warunki koncowe:
  *   Brak.
  *  Zwracana wartosc:
  *   Zwrocona zostaje element macierzy, zgodnie z podanym indeksem.
*/
const double& Macierz2x2::operator [] (int indeks) const {
    if (indeks < 0 || indeks >= 4)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu macierzy" << endl;
        exit(0);
    }
    return Elem[indeks];
}

/*
  *  Przeciazenie operatora mnozenia macierzy przez wektor, jako wynik zwraca wektor.
  *  Jest to mnozenie, gdzie macierz jest z prawej strony a wektor z lewej.
  *
  *  Parametry wywolania:
  *   Wek - wektor, przez ktory mnozymy macierz
  *
  *  Warunki wstepne:
  *   Poprawnie zdefiniowana macierz i wektor.
  *
  *  Warunki koncowe:
  *   Brak.
  *
  *  Funkcja zwraca wektor bedacy wynikiem mnozenia macierzy oraz podanego wektora.
*/
const Wektor2D Macierz2x2::operator * (const Wektor2D &Wek) const {
    Wektor2D Wynik;
    Wynik[0] = this->Elem[0] * Wek[0] + this->Elem[1] * Wek[1];
    Wynik[1] = this->Elem[2] * Wek[0] + this->Elem[3] * Wek[1];
    return Wynik;
}

/*
  *  Funkcja wypisuje macierz w postaci graficznej.
  *
  *  Parametry wywolania:
  *   Strm - strumien na ktory wypisujemy macierz
  *   Mac - obiekt z ktorego wczytujemy macierz
  *
  *  Warunki wstepne:
  *   Prawidlowy strumien i macierz Mac.
*/
ostream& operator << (ostream &Strm, const Macierz2x2 &Mac) {
    cout << "| " << Mac[0] << "\t" << Mac[1] << " |" << endl;
    cout << "| " << Mac[2] << "\t" << Mac[3] << " |" << endl;
    return Strm;
}