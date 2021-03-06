#include "Macierz2x2.hh"

using namespace std;

/*
  *  Metoda inicjujaca macierz obrotu zgonie z katem podanym jako parametr.
  *
  *  Parametry wywolania:
  *  Kat - kat obrotu macierzy. 
  * 
  *  Warunki wstepne:
  *   Kat podany w stopniach.
  *  Zwracana wartosc:
  *   Brak.
*/
void Macierz2x2::Inicjuj_obr(double Kat) {
    Kat_obr = Kat*M_PI/180; // Zamiana stopni na radiany 
    Elem[0][0] = cos(Kat_obr); Elem[0][1] = -sin(Kat_obr);
    Elem[1][0] = sin(Kat_obr); Elem[1][1] = cos(Kat_obr);
}

/*
  *  Przeciazenie operatora indeksujacego dla macierzy, zwraca wskazane pole macierzy.
  *  Jezeli indeks bedzie nieprawidlowy, metoda zakonczy dzialanie programu.
  *
  *  Parametry wywolania:
  *  wiersz - wiersz zwracanego elementu macierzy
  *  kulmna - kolumna zwracanego elementu macierzy
  * 
  *  Warunki wstepne:
  *   wiersz i kolumna zawierac sie musza w przedziale <0,1>, gdyz rozwazamy macierz 2x2
  *  Warunki koncowe:
  *   Brak.
  *  Zwracana wartosc:
  *   Zwrocona zostaje element macierzy, zgodnie z podanymi parametrami.
*/
double Macierz2x2::operator () (unsigned int wiersz, unsigned int kolumna) const {
    if (wiersz > 1 || kolumna > 1) {
      cerr << "Nieprawidlowy indeks macierzy." << endl;
      exit(0);
    }
    return Elem[wiersz][kolumna];
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
    Wynik[0] = Elem[0][0] * Wek[0] + Elem[0][1] * Wek[1];
    Wynik[1] = Elem[1][0] * Wek[0] + Elem[1][1] * Wek[1];
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
ostream& operator << (ostream &Strm, Macierz2x2 Mac) {
    cout << "| " << Mac(0,0) << "\t" << Mac(0,1) << " |" << endl;
    cout << "| " << Mac(1,0) << "\t" << Mac(1,1) << " |" << endl;
    return Strm;
}