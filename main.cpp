#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <conio.h>

using namespace std;

struct Adresat {

    int id;
    string imie, nazwisko, nrTelefonu, email, adres;
};

void wczytajZPliku(vector <Adresat> &kontakty) {

    Adresat osoba;
    string linia, pole;

    fstream plik;
    plik.open("Kontakty.txt", ios::in);

    if (plik.good() == false) {
        plik.open("Kontakty.txt", ios::out);
        cout << "Utworzono plik kontaktow." << endl;
        system("pause");
    }

    while (getline(plik, linia)) {

        istringstream iss(linia);

        getline(iss, pole, '|');
        osoba.id = stoi(pole);

        getline(iss, osoba.imie, '|');
        getline(iss, osoba.nazwisko, '|');
        getline(iss, osoba.nrTelefonu, '|');
        getline(iss, osoba.email, '|');
        getline(iss, osoba.adres, '|');

        kontakty.push_back(osoba);
    }

    plik.close();
}

void dodajDoPliku(const Adresat &osoba) {

    fstream plik;
    plik.open("Kontakty.txt", ios::out | ios::app);

    plik << osoba.id << "|";
    plik << osoba.imie << "|";
    plik << osoba.nazwisko << "|";
    plik << osoba.nrTelefonu << "|";
    plik << osoba.email << "|";
    plik << osoba.adres << "|" << endl;

    plik.close();
}

string wczytajLinie() {

    string wejscie = "";
    cin.sync();
    getline(cin, wejscie);
    return wejscie;
}

void dodanieKontaktu(vector <Adresat> &kontakty) {

    Adresat osoba;

    if (kontakty.empty()) osoba.id = 1;
    else osoba.id = kontakty.back().id + 1;
    
    system("cls");

    cout << "Podaj imie: " ;
    osoba.imie = wczytajLinie();

    cout << "Podaj nazwisko: ";
    osoba.nazwisko = wczytajLinie();

    cout << "Podaj nr telefonu: ";
    osoba.nrTelefonu = wczytajLinie();

    cout << "Podaj email: ";
    osoba.email = wczytajLinie();

    cout << "Podaj adres: ";
    osoba.adres = wczytajLinie();

    kontakty.push_back(osoba);
    dodajDoPliku(osoba);

    cout << "Utworzono nowy kontakt." << endl;
    system("pause");
}

void wyswietlWybrane(const Adresat &osoba) {

    cout << "ID: \t\t\t" << osoba.id << endl;
    cout << "Imie: \t\t\t" << osoba.imie << endl;
    cout << "Nazwisko: \t\t" << osoba.nazwisko << endl;
    cout << "Numer telefonu: \t" << osoba.nrTelefonu << endl;
    cout << "Email: \t\t\t" << osoba.email << endl;
    cout << "Adres: \t\t\t" << osoba.adres << endl << endl;
}

void wyswietlPoImieniu(vector <Adresat> kontakty) {

    Adresat osoba;
    system("cls");

    if (kontakty.empty()) {
        cout << "Brak danych w ksiazce adresowej" << endl;
        system("pause");
        return;
    }

    cout << "Podaj imie: ";
    string imie = wczytajLinie();
    cout << endl;

    bool flaga = true;

    for (Adresat osoba : kontakty) {
        if (osoba.imie == imie) {
            wyswietlWybrane(osoba);
            flaga = false;
        }
    }

    if (flaga)
        cout << "Brak kontaktu o podanym imieniu." << endl << endl;

    system("pause");
}

void wyswietlPoNazwisku(vector <Adresat> kontakty) {

    Adresat osoba;
    system("cls");

    if (kontakty.empty()) {
        cout << "Brak danych w ksiazce adresowej" << endl;
        system("pause");
        return;
    }
    cout << "Podaj nazwisko: ";
    string nazwisko = wczytajLinie();
    cout << endl;

    bool flaga = true;

    for (Adresat osoba : kontakty) {
        if (osoba.nazwisko == nazwisko) {
            wyswietlWybrane(osoba);
            flaga = false;
        }
    }

    if (flaga)
        cout << "Brak kontaktu o podanym nazwisku." << endl << endl;

    system("pause");
}

void wyswietlKontakty(vector <Adresat> kontakty) {

    system("cls");

    if (kontakty.empty()) {
        cout << "Brak danych w ksiazce adresowej" << endl;
        system("pause");
        return;
    }

    cout << "\t---ZAPISANE KONTAKTY---" << endl << endl;

    for (Adresat osoba : kontakty) {

        cout << "ID: \t\t\t" << osoba.id << endl;
        cout << "Imie: \t\t\t" << osoba.imie << endl;
        cout << "Nazwisko: \t\t" << osoba.nazwisko << endl;
        cout << "Numer telefonu: \t" << osoba.nrTelefonu << endl;
        cout << "Email: \t\t\t" << osoba.email << endl;
        cout << "Adres: \t\t\t" << osoba.adres << endl << endl;
    }

    system("pause");
}

void nadpiszPlik (vector <Adresat> kontakty) {

    ofstream plik;
    plik.open("Kontakty.txt");

    for ( size_t i = 0; i < kontakty.size(); i++) {

        plik << kontakty[i].id << "|";
        plik << kontakty[i].imie << "|";
        plik << kontakty[i].nazwisko << "|";
        plik << kontakty[i].nrTelefonu << "|";
        plik << kontakty[i].email << "|";
        plik << kontakty[i].adres << "|" << endl;
    }

    plik.close();
}

void usunKontakt(vector <Adresat> &kontakty) {

    Adresat osoba;
    int idDoUsuniecia;
    bool flaga = true;
    char wybor;

    system("cls");

    if (kontakty.empty()) {
        cout << "Brak danych w ksiazce adresowej" << endl;
        system("pause");
        return;
    }

    cout << "Podaj id adresata do usuniecia: ";
    cin >> idDoUsuniecia;

    for (vector <Adresat> :: iterator itr = kontakty.begin(); itr != kontakty.end(); itr++) {

        osoba = *itr;
        if (osoba.id == idDoUsuniecia) {

            flaga = false;
            cout << "Nacisnij t, w celu potwierdzenia usuniecia lub dowolny inny klawisz by anulowac." << endl;
            wybor = getch();

            switch (wybor) {

            case 't':
                kontakty.erase(itr);
                nadpiszPlik(kontakty);
                cout << "Usunieto kontakt" << endl;
                system("pause");
                break;

            default:
                cout << "Anulowano usuniecie" << endl;
                system("pause");
            }
        }
    }

    if (flaga) {

        cout << "Brak kontaktu o podanym id." << endl;
        system("pause");
    }
}

void menuKsiazki () {

    cout << "1. Dodaj adresata." << endl;
    cout << "2. Wyszukaj po imieniu." << endl;
    cout << "3. Wyszukaj po nazwisku." << endl;
    cout << "4. Wyswietl zapisane kontakty." << endl;
    cout << "5. Usun adresata." << endl;
    cout << "6. Edytuj adresata." << endl;
    cout << "9. Zakoncz program." << endl;
}

void menuEdycji () {

    cout << "Wybierz dana do edycji." << endl;
    cout << "1. Imie." << endl;
    cout << "2. Nazwisko." << endl;
    cout << "3. Numer telefonu." << endl;
    cout << "4. Email." << endl;
    cout << "5. Adres." << endl;
    cout << "6. Powrot do menu." << endl;
}

void edycjaKontaktu (vector <Adresat> &kontakty) {

    system("cls");
    bool flaga = false;
    int id, indeks;
    char wybor;

    if (kontakty.empty()) {
        cout << "Brak danych w ksiazce adresowej" << endl;
        system("pause");
        return;
    }

    cout << "Podaj id adresata: ";
    cin >> id;

    system("cls");

    for (size_t i = 0; i < kontakty.size(); i++) {

        if (kontakty[i].id == id) {

            indeks = i;
            flaga = true;
            break;
        }
    }

    if (flaga) {

        while(1) {

            system("cls");
            menuEdycji();

            wybor = getch();

            switch(wybor) {

            case '1':
                cout << "Podaj nowe imie: ";
                kontakty[indeks].imie = wczytajLinie();
                nadpiszPlik(kontakty);
                cout << "Nadpisano nowe imie." << endl;
                system("pause");
                break;

            case '2':
                cout << "Podaj nowe nazwisko: ";
                kontakty[indeks].nazwisko = wczytajLinie();
                nadpiszPlik(kontakty);
                cout << "Nadpisano nowe nazwisko." << endl;
                break;

            case '3':
                cout << "Podaj nowy numer telefonu: ";
                kontakty[indeks].nrTelefonu = wczytajLinie();
                nadpiszPlik(kontakty);
                cout << "Nadpisano nowy numer telefonu." << endl;
                system("pause");
                break;

            case '4':
                cout << "Podaj nowy email: ";
                kontakty[indeks].email = wczytajLinie();
                nadpiszPlik(kontakty);
                cout << "Nadpisano nowy email." << endl;
                system("pause");
                break;

            case '5':
                cout << "Podaj nowy adres: ";
                kontakty[indeks].adres = wczytajLinie();
                nadpiszPlik(kontakty);
                cout << "Nadpisano nowy adres." << endl;
                system("pause");
                break;

            case '6':
                return;
            }
        }
    }

    else {

        cout << "Brak kontaktu o podanym id." << endl;
        system("pause");
    }
}

int main() {

    vector <Adresat> kontakty;
    char wybor;
    wczytajZPliku(kontakty);

    while(1) {

        system("cls");
        menuKsiazki();

        wybor = getch();

        switch(wybor) {

        case '1':
            dodanieKontaktu(kontakty);
            break;

        case '2':
            wyswietlPoImieniu(kontakty);
            break;

        case '3':
            wyswietlPoNazwisku(kontakty);
            break;

        case '4':
            wyswietlKontakty(kontakty);
            break;

        case '5':
            usunKontakt(kontakty);
            break;

        case '6':
            edycjaKontaktu(kontakty);
            break;

        case '9':
            exit(0);
        }
    }

    return 0;
}
