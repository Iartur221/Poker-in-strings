#include "deklaracje.h"

random_device device; //ziarno dla generatorow

int main()
{
	bool granie = true;
	while (granie == true)
	{
		int money{};
		string talia[4][13]{};
		string user_hand[5];
		string computer_hand[5];
		cout << "  _____       ________       _    _    _________     _____" << endl;
		cout << " $ ___  $    $ ______ $     $ $  $ $  $ $_______$   $ ___  $ " << endl;
		cout << "$ $   $ $   $ $      $ $    $ $ $ $   $ $          $ $   $ |" << endl;
		cout << "$ $___$ $  $ $        $ $   $ $$ $    $ $_______   $ $___$ $" << endl;
		cout << "$ ______$ $ $          $ $  $ $ $     $ $_______$  $    ___$" << endl;
		cout << "$ $       $ $          $ $  $ $ $     $ $          $ $$ $ " << endl;
		cout << "$ $        $ $        $ $   $ $$ $    $ $          $ $ $ $ " << endl;
		cout << "$ $         $ $______$ $    $ $ $ $   $ $_______   $ $  $ $ " << endl;
		cout << "$_$          $________$     $_$  $_$  $_$_______$  $_$   $_$ " << endl;
		cout << "Rekomendowana szerokosc konsoli: minimum 160" << endl;

		nowagra(money);
		int gra = 1;
		while (gra == 1)
		{
			int rozdanie = 1;
			int user_bet = 0;
			int comp_bet = 0;
			bool fold = 0;
			int pula = 0;

			while (rozdanie == 1)
			{
				cout << "Zaklad w ciemno: 5 Zetonow" << endl; // staly zaklad w ciemno
				money -= 5;
				user_bet += 5;
				comp_bet += 5;
				pula += 10;
				tworzenie_talii(talia);
				RozdajKarty(talia, user_hand, computer_hand);
				sortowanie(user_hand);
				sortowanie(computer_hand);
				cout << "Twoje karty:" << user_hand[0] << "  " << user_hand[1] << "  " << user_hand[2] << "  " << user_hand[3] << "  " << user_hand[4] << endl;

				podbij(money, pula, user_bet);

				int comp_todo = uklady(computer_hand);
				if (comp_todo >= 2) // komputer ma 2 pary lub lepiej
				{
					int x = comp_bet;
					comp_bet = user_bet;
					comp_bet += pula / 2; // podbicie o polowe puli
					cout << "Komputer podbija o " << pula / 2 << "Zetonow" << endl;
					pula += comp_bet - x;
				}
				else if (comp_todo < 2 && comp_todo > 0)//komputer ma pare
				{
					int x = comp_bet;
					comp_bet = user_bet;
					cout << "Komputer sprawdza" << endl;
					pula += (comp_bet - x);
				}
				else
				{
					mt19937 generator(device());
					uniform_int_distribution<int> Czyzagra(1, 100);
					int kompgra = Czyzagra(generator);
					if (kompgra < 65 && user_bet > comp_bet) // % Zagranych rozdan bez ukladu
					{
						cout << "Komputer pasuje rozdanie" << endl;
						money += pula;
						break;
					}
					else
					{
						int x = comp_bet;
						comp_bet = user_bet;
						cout << "Komputer sprawdza" << endl;
						pula += (comp_bet - x);
					}

				}
				cout << "W puli znajduje sie " << pula << "Zetonow" << endl;

				if (comp_bet > user_bet)
				{
					sprawdz(money, pula, user_bet, comp_bet, fold);
				}
				if (fold == true)
				{
					cout << "Spasowales rozdanie" << endl;
					break;
				}

				wymien_karty(talia, user_hand); // wymiana kart
				sortowanie(user_hand);
				sortowanie(computer_hand);
				cout << endl;
				cout << "Twoje karty:" << user_hand[0] << "  " << user_hand[1] << "  " << user_hand[2] << "  " << user_hand[3] << "  " << user_hand[4] << endl;
				comp_bet = 0;
				user_bet = 0;
				podbij(money, pula, user_bet);

				if (comp_todo >= 2)
				{
					int x = comp_bet;
					comp_bet = user_bet;
					comp_bet += pula / 2;
					cout << "Komputer podbija o " << pula / 2 << "Zetonow" << endl;
					pula += (comp_bet - x);
				}
				else if (comp_todo < 2 && comp_todo > 0)
				{
					int x = comp_bet;
					comp_bet = user_bet;
					cout << "Komputer sprawdza" << endl;
					pula += (comp_bet - x);
				}
				else
				{
					mt19937 generator(device());
					uniform_int_distribution<int> Czyzagra(1, 100);
					int kompgra = Czyzagra(generator);
					if (kompgra < 55 && user_bet > comp_bet) // % Zagranych rozdan z wysoka karta po wymianie kart
					{

						cout << "Komputer pasuje rozdanie" << endl;
						money += pula;
						break;
					}
					else
					{
						int x = comp_bet;
						comp_bet = user_bet;
						cout << "Komputer sprawdza" << endl;
						pula += comp_bet - x;
					}

				}
				cout << "W puli znajduje sie " << pula << "Zetonow" << endl;

				if (comp_bet > user_bet)
				{
					sprawdz(money, pula, user_bet, comp_bet, fold);
				}


				if (fold == true)
				{
					cout << "Spasowales rozdanie" << endl;
					break;
				}

				int x = wygrana(user_hand, computer_hand); // sprawdzenie kto wygrywa

				cout << "Twoje karty:" << user_hand[0] << "  " << user_hand[1] << "  " << user_hand[2] << "  " << user_hand[3] << "  " << user_hand[4] << endl;
				cout << endl;
				cout << "Karty Komputera:" << computer_hand[0] << "  " << computer_hand[1] << "  " << computer_hand[2] << "  " << computer_hand[3] << "  " << computer_hand[4] << endl;

				if (x == 1)
				{
					cout << "WYGRANA" << endl;
					money += pula;
					break;
				}
				if (x == 0)
				{
					cout << "PRZEGRANA" << endl;
					break;
				}
				if (x == 2)
				{
					cout << "REMIS" << endl;
					money += user_bet;
					break;
				}
			}
			cout << endl;
			cout << endl;
			if (money == 0) //przypadek przegrania wszystkich zetonow
			{
				cout << "Przegrales. Masz 0 zetonow. Czy chcesz rozpoczac nowa gre?" << endl;
				nowagra(money);
			}

			zapisgry(money);
			cout << "Czy chcesz zagrac jeszcze raz? Wpisz 1 jesli tak, wpisz 0 by wyjsc do menu glownego lub wyjsc z gry" << endl;
			cin >> gra;
			while (cin.fail() || (gra != 1 && gra != 0))
			{
				cin.clear();
				cin.ignore();
				cout << "Nieprawidlowa liczba. Wpisz 0 by wyjsc do menu glownego lub wyjsc z gry, 1 by zagrac jeszcze raz";
				cin >> gra;
			}

		}
		cout << "Czy chcesz wyjsc z gry? Wpisz 1 by wyswietlic menu glowne, 0 by wylaczyc program" << endl;
		cin >> granie;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Nieprawidlowa liczba. Wpisz 0 by wylaczyc program, 1 by przejsc do menu glownego" << endl;
			cin >> granie;
		}
	}
}