#include "deklaracje.h"

void wymien_karty(string karty[4][13], string user[5])
{
	// wybieramy jakie karty wymieniamy
	// algorytm wymiany kart
	mt19937 generator(device());
	uniform_int_distribution<int> distribution_kolor(0, 3);
	uniform_int_distribution<int> distribution_karta(0, 12);

	cout << "Ile kart chcesz wymienic?" << endl;
	string liczba{};
	cin >> liczba;
	while (liczba != "0" && liczba != "1" && liczba != "2" && liczba != "3" && liczba != "4" && liczba != "5")
	{
		cout << "Blad. Wpisz poprawny numer" << endl;
		cin >> liczba;
	}

	int ile = stoi(liczba);

	if (ile >= 5)
	{
		cout << "Wymieniasz wszystkie karty" << endl;
		ile = 5;
	}

	if (ile == 1)
	{
		cout << "Ktora karte chcesz wymienic? Wpisz ktora to karta, w kolejnosci od lewej do prawej" << endl;

		string card1{};
		cin >> card1;

		while (card1 != "1" && card1 != "2" && card1 != "3" && card1 != "4" && card1 != "5")
		{
			cout << "Taka karta nie istnieje. Wpisz poprawny numer karty" << endl;
			cin >> card1;
		}

		int z = stoi(card1);

		user[z - 1] = "0";

		while (user[z - 1] == "0")
		{
			int x = distribution_kolor(generator);
			int y = distribution_karta(generator);
			while (karty[x][y] == "0")
			{
				x = distribution_kolor(generator);
				y = distribution_karta(generator);
			}
			user[z - 1] = karty[x][y];
		}

	}

	if (ile > 1 && ile < 5)
	{
		cout << "Ktore karty chcesz wymienic? Wybierz karte w kolejnosci od lewej do prawej. Po wybraniu pierwszego numeru karty bedziesz mogl wybrac kolejna karte" << endl;

		string card1{};
		cin >> card1;
		while (card1 != "1" && card1 != "2" && card1 != "3" && card1 != "4" && card1 != "5")
		{
			cout << "Taka karta nie istnieje. Wpisz poprawny numer karty" << endl;
			cin >> card1;
		}
		int karta1 = stoi(card1);
		user[karta1 - 1] = "0";

		string card2{};
		cout << "Wybierz druga karte" << endl;
		cin >> card2;
		while (card2 != "1" && card2 != "2" && card2 != "3" && card2 != "4" && card2 != "5" || card2 == card1)
		{
			cout << "Taka karta nie istnieje lub juz zostala wybrana wczesniej. Wpisz poprawny numer karty" << endl;
			cin >> card2;
		}
		int karta2 = stoi(card2);
		user[karta2 - 1] = "0";

		if (ile > 2)
		{
			string card3{};
			cout << "Wybierz trzecia karte" << endl;
			cin >> card3;
			while (card3 != "1" && card3 != "2" && card3 != "3" && card3 != "4" && card3 != "5" || card3 == card1 || card3 == card2)
			{
				cout << "Taka karta nie istnieje lub juz zostala wybrana wczesniej. Wpisz poprawny numer karty" << endl;
				cin >> card3;
			}
			int karta3 = stoi(card3);
			user[karta3 - 1] = "0";

			if (ile > 3) {
				string card4{};
				cout << "Wybierz czwarta karte" << endl;
				cin >> card4;
				while (card4 != "1" && card4 != "2" && card4 != "3" && card4 != "4" && card4 != "5" || card4 == card1 || card4 == card2 || card4 == card3)
				{
					cout << "Taka karta nie istnieje lub juz zostala wybrana wczesniej. Wpisz poprawny numer karty" << endl;
					cin >> card4;
				}
				int karta4 = stoi(card4);
				user[karta4 - 1] = "0";
			}
		}

		for (int i = 0; i < 5; i++)
		{
			if (user[i] == "0")
			{
				int x = distribution_kolor(generator);
				int y = distribution_karta(generator);

				while (karty[x][y] == "0")
				{
					x = distribution_kolor(generator);
					y = distribution_karta(generator);
				}
				user[i] = karty[x][y];
			}
		}
	}

	if (ile == 5)
	{
		user[0] = "0";
		user[1] = "0";
		user[2] = "0";
		user[3] = "0";
		user[4] = "0";
		for (int i = 0; i < 5; i++)
		{
			if (user[i] == "0")
			{
				int x = distribution_kolor(generator);
				int y = distribution_karta(generator);

				while (karty[x][y] == "0")
				{
					x = distribution_kolor(generator);
					y = distribution_karta(generator);
				}
				user[i] = karty[x][y];
			}
		}
	}
}