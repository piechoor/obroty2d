#include "Menu.hh"

using namespace std;

// Funckja wyswietla mozliwe operacje na prostokacie.
void Wysw_menu() {
   cout << "o - obrot prostokata o zadany kat" << endl
        << "p - przesuniecie prostokata o zadany wektor" << endl
        << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
        << "m - wyswietl menu" << endl
        << "k - koniec dzialania programu" << endl << endl;
}

/*
  *  Funkcja wykonujaca operacje obrotu na prostokacie.
  *
  *  Parametry wywolania:
  *  Pr - prostokat, na ktorym wykonujemy operacje obrotu.
  * 
  *  Warunki wstepne:
  *   Prawidlowo zdefiniowany prostokat Pr.
  *
  *  Zwracana wartosc:
  *   true w przypadku prawidlowej pracyy funkcji i false, gdy nie udal sie wykonac operacji
*/
bool Przetw_obrot(Prostokat &Pr) {
    double kat; unsigned long liczba; // Zmienne na kat obrotu i liczbe obrotow

    cout << "Podaj wartosc kata obrotu w stopniach: "; cin >> kat;
    cout << "Ile razy operacja obrotu ma byc powtorzona?: "; cin >> liczba;

    Pr.Obroc(liczba, kat);
    if (!Pr.Zapisz("prostokat.dat")) return 1; // Zapisz prostokat do pliku, jezeli blad zakoncz funkcje
    Pr.Spr_boki();

    return 0;
}

/*
  *  Funckja wywolujaca menu programu.
  *
  *  Parametry wywolania:
  *   Pr - prostokat, na ktorym wykonujemy operacje obrotu.
  *   Lacze - lacze do GNU plota pozwalajace na wyswietlanie prostokata
  * 
  *  Warunki wstepne:
  *   Prawidlowo zdefiniowany prostokat Pr, skonfigurowane lacze do gnu plota.
  *
  *  Zwracana wartosc:
  *   true w przypadku prawidlowej pracy menu i false, gdy nie udal sie wykonac operacji
*/
bool Przetw_menu(Prostokat Pr, PzG::LaczeDoGNUPlota Lacze) {
    char wybor; Wektor2D Transl; // Zmienne na wybor opcji i wektor translacji
    Wysw_menu();
    do {
        cout << "Twoj wybor? (m - menu) > "; cin >> wybor; // Pobranie opcji z klawiatury
        switch (wybor) {
            case 'o': // Opcja obrotu
                if(Przetw_obrot(Pr)) return 1;
                Lacze.Rysuj(); // Wyswietl prostokat
                break;
            case 'p': // Opcja translacji
                cout << "Wprowadz wspolrzedne wektora translacji w postaci "
                     << "(x,y) dla wspolrzednej x oraz wspolrzednej y: ";
                cin >> Transl;
                while (cin.fail()) { // Jezeli nie udalo sie wczytac wektora, sprobuj ponownie
                    cin.clear();
                    cout << "Blad odczytu, sprobuj jeszcze raz: ";
                    cin.ignore(1000, '\n');
                    cin >> Transl;
                }
                Pr.Przesun(Transl);
                Lacze.Rysuj(); // Wyswietl prostokat
                if (!Pr.Zapisz("prostokat.dat")) return 1; // Zapisz prostokat do pliku, jezeli blad zakoncz funkcje
                break;
            case 'w': // Opcja wyswietlenia
                cout << Pr; break;
            case 'm': // Wyswietlenie menu
                Wysw_menu(); break;
            case 'k': // Zakonczenie menu
                cout << "Koniec dzialania programu" << endl; break;
            default:
                cin.ignore(1000, '\n');
                cout << "Wprowadzono nieprawidlowa opcje menu. Sprobuj jeszcze raz." << endl;
        }
    } while (wybor != 'k');
    return 0;
}