#include "deklaracje.h"


void nowagra(int& money)
{
	string newgame{};
	cout << "Czy chcesz rozpoczac nowa gre?" << endl << "Wpisz 1 jesli tak, wpisz 0 jesli chcesz wczytac stan gry" << endl << "Wpisz 2 by wyswietlic zasady gry." << endl;
	string wczytaj;
	fstream zapis;
	zapis.open("savestate.txt", ios::in);
	while (!zapis.eof())
	{zapis >> wczytaj;}
	zapis.close();
	cout << "W zapisie masz " << wczytaj << "Zetonow. Nowa gre zaczynasz ze 100 zetonow" << endl;
	cin >> newgame;
	while (newgame != "0" && newgame != "1" && newgame != "2")
	{
		cout << "Wpisales nieprawidlowa wartosc. Wpisz 1 by rozpoczac nowa gre lub 0 zeby wczytac stan gry" << endl;
		cin >> newgame;
	}
	if (newgame == "2") //zasady
	{
		cout << "ZASADY GRY W POKERA" << endl;
		cout << endl;
		cout << "W talii znajduja sie 52 karty, od dwojek do asa." << endl;
		cout << "Starszenstwo kart od karty najnizszej:" << endl;
		cout << "2-3-4-5-6-7-8-9-10-J-Q-K-A As najwyzszy. Kolory nie maja znaczenia." << endl;
		cout << "Uklady od najsilniejszego:" << endl;
		cout << "1.Poker krolewski. 5 kart w jednym kolorze po kolei i zaczyna sie od 10" << endl << "[10]Pik-[J]Pik-[Q]Pik-[K]Pik-[A]Pik" << endl;
		cout << "2.Strit w kolorze. 5 kart w jednym kolorze po kolei. W przypadku remisu wygrywa poker z wyzsza karta. np." << endl << "[5]Pik-[6]Pik-[7]Pik-[8]Pik-[9]Pik" << endl;
		cout << "3.Kareta. 4 takie same karty. W przypadku remisu wygrywa reka z czterema kartami, ktore sa wyzsze. np." << endl << "[9]Pik-[A]Pik-[A]Kier-[A]Karo-[A]Trefl" << endl;
		cout << "4.Full. 3 karty o takiej samej wartosci i dwie inne o takiej samej wartosci(trojka i para). Jesli wystapi wiecej niz jeden full, wygrywa uklad z wyzsza trojka. np." << endl << "[K]Pik-[K]Kier-[K]Karo-[A]Pik-[A]Trefl" << endl;
		cout << "5.Kolor. 5 kart w takim samym kolorze nie po kolei. Przy kolor vs kolor wygrywa kolor z wyzsza karta. np." << endl << "[2]Pik-[6]Pik-[7]Pik-[9]Pik-[A]Pik" << endl;
		cout << "6.Strit. Piec kart po kolei. W przypadku strit vs strit wygrywa strit z wyzsza karta. np." << endl << "[10]Karo-[J]Trefl-[Q]Pik-[K]Kier-[A]Pik" << endl;
		cout << "7.Trojka. 3 karty takie same. W przypadku remisu wygrywa wyzsza trojka. np." << endl << "[10]Pik - [K]Kier - [K]Karo - [K]Pik - [A]Trefl" << endl;
		cout << "8.Dwie Pary. W przypadku remisu wygrywa wyzsza para. Jezeli pary sa identyczne wygrywa wyzsza piata karta. np." << endl << "[10]Pik-[10]Kier-[K]Pik-[K]Kier-[A]Pik" << endl;
		cout << "9.Para. W przypadku remisu wygrywa wyzsza para. Jezeli pary sa identyczne wygrywa najwyzsza karta. np." << endl << "[10]Pik-[10]Kier-[Q]Pik-[K]Kier-[A]Pik" << endl;
		cout << "10.Najwyzsza karta. Uklad nie pasujacy do powyzszych. W przypadku remisu wygrywa wyzsza karta. np." << endl << "[2]Pik - [4]Kier - [J]Pik - [K]Kier - [A]Pik" << endl;
		cout << endl;
		cout << "ZASADY LICYTACJI" << endl;
		cout << "Na samym poczatku jest pobierany zaklad w ciemno." << endl;
		cout << "Gracze przebijaja lub wyrownuja swoj zaklad na zmiane. Jezeli ilosc postawiona przez jednego gracza jest zbyt duza dla drugiego, moze on spasowac. Przegrywa on wtedy i traci swoj wczesniej wlozony zaklad" << endl;
		cout << "Po zakonczonej pierwszej rundzie licytacji gracze moga wymienic swoje karty lub ich czesc. Pozniej nastepuje druga tura licytacji." << endl;
		cout << "Po zakonczeniu drugiej tury licytacji tj. wyrownaniu zakladu, nastepuje sprawdzenie ktory z graczy wygrywa" << endl;
		cout << endl;
		cout << "Czy chcesz rozpoczac nowa gre?" << endl << "Wpisz 1 jesli tak, wpisz 0 jesli chcesz wczytac stan gry" << endl;
		cout << "W zapisie masz " << wczytaj << "Zetonow. Nowa gre zaczynasz ze 100 zetonow" << endl;
		cin >> newgame;
		while (newgame != "0" && newgame != "1")
		{
			cout << "Wpisales nieprawidlowa wartosc. Wpisz 1 by rozpoczac nowa gre lub 0 zeby wczytac stan gry" << endl;
			cin >> newgame;
		}

	}

	if (newgame == "1") { money = 100; }
	if (newgame == "0") // wczytaj
	{
		money = stoi(wczytaj);
	}


}

void zapisgry(int& money)
{
	cout << "Czy chcesz zapisac stan gry? obecnie masz :" << money << "zetonow na koncie" << endl;
	cout << "Wpisz 1 jesli chcesz zapisac stan gry, 0 jesli nie chcesz zapisywac" << endl;
	string zapis{};
	cin >> zapis;
	while (zapis != "0" && zapis != "1")
	{
		cout << "Wpisales nieprawidlowa wartosc. Wpisz 1 by zapisac gre lub 0 by nie zapisywac" << endl;
		cin >> zapis;
	}
	if (zapis == "1") // zapisz gre
	{
		ofstream zapisgry("savestate.txt");
		zapisgry << money;
		zapisgry.close();
	}

}