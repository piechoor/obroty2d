#include <iostream>
#include <iomanip>
#include <fstream>
 
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;


void Wysw_menu() {
   cout << "o - obrot prostokata o zadany kat" << endl
        << "p - przesuniecie prostokata o zadany wektor" << endl
        << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
        << "m - wyswietl menu" << endl
        << "k - koniec dzialania programu" << endl << endl;
}


#define DL_KROTKI_BOK  100
#define DL_DLUGI_BOK   150


int main() {
   Wektor2D P1(20,30), P2(120,30), P3(120,80), P4(20,80), Transl;
   Prostokat Pr(P1, P2, P3, P4);
   PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji rysunku prostokata
   
   if (!Pr.Zapisz("prostokat.dat")) return 1;
   Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2);
   Lacze.ZmienTrybRys(PzG::TR_2D);

   char wybor; double kat; unsigned long liczba;

   Pr.Spr_boki();
   Wysw_menu();
   do {
      cout << "Twoj wybor? (m - menu) > "; cin >> wybor;
      switch (wybor) {
      case 'o':
         cout << "Podaj wartosc kata obrotu w stopniach: "; cin >> kat;
         cout << "Ile razy operacja obrotu ma byc powtorzona?: "; cin >> liczba;
         Pr.Obroc(liczba, kat);
         if (!Pr.Zapisz("prostokat.dat")) return 1;
         Pr.Spr_boki();
         Lacze.Rysuj();
         cout << "Naciśnij ENTER, aby kontynuowac" << endl;
         cin.ignore(100000,'\n'); break;
      case 'p':
         cout << "Wprowadz wspolrzedne wektora translacji w postaci (x,y) dla wspolrzednej x oraz wspolrzednej y: ";
         cin >> Transl;
         while (cin.fail()) {
            cin.clear();
            cout << "Blad odczytu, sprobuj jeszcze raz: ";
            cin.ignore(1000, '\n');  cin >> wybor;
         }
         Pr.Przesun(Transl);
         Lacze.Rysuj();
         if (!Pr.Zapisz("prostokat.dat")) return 1;
         break;
      case 'w':
         cout << Pr; break;
      case 'm':
         Wysw_menu(); break;
      case 'k':
         cout << "Koniec dzialania programu" << endl; break;
      default:
         cin.ignore(1000, '\n');
         cout << "Wprowadzono nieprawidlowa opcje menu. Sprobuj jeszcze raz." << endl;
      }
   } while (wybor != 'k');
   return 0;
}
