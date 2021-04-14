#include "Prostokat.hh"

using namespace std;

const Wektor2D& Prostokat::operator [] (int indeks) const {
    if (indeks < 0 || indeks >= 4)  {
        cerr << "Nieprawidlowy indeks odwolania do elementu macierzy" << endl;
        exit(0);
    }
    return Wierzch[indeks];
}

void Prostokat::Obroc(long L_obr, double Kat) {
    Macierz2x2 Mac_obr(Kat);

    for (int i = 0; i < L_obr; i++) {
        for (int j = 0; j < 4; j++)
            Wierzch[j] = Mac_obr *  Wierzch[j];
    }
}

void Prostokat::Spr_boki() {
    double Dl_1, Dl_2, Kr_1, Kr_2;
    
    Dl_1 = Wierzch[0].Modul(Wierzch[1]); Dl_2 = Wierzch[2].Modul(Wierzch[3]);
    Kr_1 = Wierzch[0].Modul(Wierzch[3]); Kr_2 = Wierzch[1].Modul(Wierzch[2]);

    if (Dl_1 == Dl_2) cout << "\tDluzsze przeciwlegle boki sa sobie rowne." << endl;
    else cout << "\tDluzsze przeciwlegle boki nie sa rowne!!!" << endl;
    cout << right << setprecision(20)
         << "Dlugosc pierwszego boku: " << Dl_1 << endl
         << "Dlugosc drugiego boku: " << Dl_2 << endl << endl;

    if (Kr_1 == Kr_2) cout << "\tKrotsze przeciwlegle boki sa sobie rowne." << endl;
    else cout << "\tKrotsze przeciwlegle boki nie sa rowne!!!" << endl;
    cout << "Dlugosc pierwszego boku: " << Kr_1 << endl
         << "Dlugosc drugiego boku: " << Kr_2 << endl << endl;
}

ostream& operator << (ostream &Strm, const Prostokat &Pr) {
    Strm << endl << showpoint << setprecision(15) 
         << Pr[0][0] << "\t" << Pr[0][1] << endl
         << Pr[1][0] << "\t" << Pr[1][1] << endl
         << Pr[2][0] << "\t" << Pr[2][1] << endl
         << Pr[3][0] << "\t" << Pr[3][1] << endl << endl;
    return Strm;
}