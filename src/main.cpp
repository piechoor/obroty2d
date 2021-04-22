#include <iostream>
//#include <iomanip>
//#include <fstream>
 
#include "Wektor2D.hh"
#include "Macierz2x2.hh"
#include "Prostokat.hh"
#include "lacze_do_gnuplota.hh"
#include "Menu.hh"

using namespace std;

int main() {
   Wektor2D P1(20,30), P2(120,30), P3(120,80), P4(20,80); // Definiowanie wierzcholkow
   Prostokat Pr(P1, P2, P3, P4); // Stworzenie prostokata z powyzszych wierzcholkow
   PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji rysunku prostokata
   
   if (!Pr.Zapisz("prostokat.dat")) return 1; // Zapisz prostokat do pliku, jezeli blad zakoncz program

   // Konfiguracja lacza
   Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2); // Rysowanie linii bokow
   Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Punktowy,2); // Rysowanie punktow wierzcholkow
   Lacze.ZmienTrybRys(PzG::TR_2D); // Rysowanie w 2 wymiarach

   if(Przetw_menu(Pr,Lacze)) return 1; // Otworz menu operacji na prostokacie
                                       // Zakoncz program, jezeli wystapil blad.
   return 0;
}
