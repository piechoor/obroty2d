#include "Prostokat.hh"

using namespace std;


/*
  *  Przeciazenie operatora indeksujacego dla prostokata, zwraca wskazany wierzcholek jako wektor.
  *  Jezeli indeks bedzie nieprawidlowy, metoda zakonczy dzialanie programu.
  *
  *  Parametry wywolania:
  *   indeks - indeks zwracanego wierzcholka prostokata. 
  * 
  *  Warunki wstepne:
  *   indeks musi byc zawierac sie w przedziale <0,3>, prostokat ma 4 wierzcholki
  *  Warunki koncowe:
  *   Brak.
  *  Zwracana wartosc:
  *   Zwrocony zostaje wektor reprezentujacy punkt bedacy wierzcholkiem prostokata.
*/
const Wektor2D& Prostokat::operator [] (unsigned int indeks) const {
    if (indeks > 4)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu prostokata." << endl;
        exit(0);
    }
    return Wierzch[indeks];
}

/*
  *  Metoda tworzy macierz obrotu zggodnie z podanym jako parametr katem.
  *  Nastepnie sprawdza czy zostala podana prawidlowa liczba obrotow, jezeli nie - wyswitla komunikat.
  *  Na koncu mnozy macierz obrotu przez wektor zadana liczbe razy.
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, np.
  *   L_obr - liczba razy, jaka mnozymy macierz przez wektor
  *   Kat - kat podany w stopniach, o ktory obracamy prostokat
  *
  *  Warunki wstepne:
  *   Kat podany w stopniach - inaczej program zadziala nie poprawnie
  *   Dodatnia L_obr - liczba obrotow.
  *
  *  Warunki koncowe:
  *   Brak.
*/
void Prostokat::Obroc(unsigned long L_obr, double Kat) {
    Macierz2x2 Mac_obr;
    Mac_obr.Inicjuj_obr(Kat);

    for (unsigned int i = 0; i < L_obr; i++) {
        for (int j = 0; j < 4; j++)
            Wierzch[j] = Mac_obr * Wierzch[j];
    }
}

/*
  *  Metoda oblicza dlugosci bokow prostokata, nastepnie porownuje przeciwlegle
  *  wyswietla ich dlugosci oraz w zaleznosci czy sa rowne wsywietla stosowny komunikat.
*/
void Prostokat::Spr_boki() const {
    double Dl_1, Dl_2, Kr_1, Kr_2;
    
    Dl_1 = Wierzch[0].Modul(Wierzch[1]); Dl_2 = Wierzch[2].Modul(Wierzch[3]);
    Kr_1 = Wierzch[0].Modul(Wierzch[3]); Kr_2 = Wierzch[1].Modul(Wierzch[2]);

    if (Dl_1 == Dl_2) cout << endl << "\tDluzsze przeciwlegle boki sa sobie rowne." << endl;
    else cout << "\tDluzsze przeciwlegle boki nie sa rowne!!!" << endl;
    cout << right << setprecision(20) << fixed
         << "Dlugosc pierwszego boku: " << Dl_1 << endl
         << "  Dlugosc drugiego boku: " << Dl_2 << endl << endl;

    if (Kr_1 == Kr_2) cout << endl << "\tKrotsze przeciwlegle boki sa sobie rowne." << endl;
    else cout << "\tKrotsze przeciwlegle boki nie sa rowne!!!" << endl;
    cout << "Dlugosc pierwszego boku: " << Kr_1 << endl
         << "  Dlugosc drugiego boku: " << Kr_2 << endl << endl;
}

/*
  *  Metoda dodaje wspolrzedne podanego wektora do kazdego wierzcholka prostokata.
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, np.
  *   Wek - wektor o ktory przesuwamy caly prostokat
  *
  *  Warunki wstepne:
  *   Zdefiniowana klasa prostokat i prawidlowy wektor Wek.
*/
void Prostokat::Przesun(const Wektor2D &Wek) {
    for (int i = 0; i < 4; i++)
        Wierzch[i] = Wierzch[i] + Wek;
}

/*
  *  Metoda zapisujaca wspolrzedne prostokata do pliku o nazwie podanej jako parametr.
  *  Gdy operacja zapisu sie nie powiodla metoda wyswietla stosowny komunikat.
  *
  *  Opis poszczegolnych parametrow wywolania funkcji, np.
  *   sNazwaPliku - nazwa pliku, do ktorego zapisujemy wspolrzedne
  *
  *  Warunki wstepne:
  *   Prawidlowa nazwa pliku.
  *
  *  Funkcja zwraca true, gdy operacja zapisu sie powiodla i false, gdy nie.
*/

bool Prostokat::Zapisz(const char *sNazwaPliku) const {
  ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  StrmPlikowy << *this;

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

// Funkcja wyswietlajaca wspolrzedne wierzcholkow prostokata w konkretnym formacie.
ostream& operator << (ostream &Strm, const Prostokat &Pr) {
    Strm << endl << fixed << setprecision(15) 
         << setw(16) << Pr[0][0] << " " << setw(16) << Pr[0][1] << endl
         << setw(16) << Pr[1][0] << " " << setw(16) << Pr[1][1] << endl
         << setw(16) << Pr[2][0] << " " << setw(16) << Pr[2][1] << endl
         << setw(16) << Pr[3][0] << " " << setw(16) << Pr[3][1] << endl 
         << setw(16) << Pr[0][0] << " " << setw(16) << Pr[0][1] << endl << endl;
    return Strm;
}