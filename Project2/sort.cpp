#include "deklaracje.h"

void sortowanie(string user[5])
{
	//zamiana kart na wartosci liczbowe
	//wzor karty: [2]Kier  [2]Karo  [2]Trefl  [2]Pik
	//2-14 Pik
	//2-14 Kier
	//2-14 Karo
	//2-14 Trefl

	string Pik = "Pik";
	string Kier = "Kier";
	string Karo = "Karo";
	string Trefl = "Trefl";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 1; j < 5 - i; j++)
		{
			string karta = user[j - 1];
			string karta2 = user[j];

			int karta1_wartosc{};
			int karta2_wartosc{};

			//zamienic J, Q, K, A na 11, 12, 13, 14

			if (karta[1] == 'J') { karta = "[11]"; }
			if (karta[1] == 'Q') { karta = "[12]"; }
			if (karta[1] == 'K') { karta = "[13]"; }
			if (karta[1] == 'A') { karta = "[14]"; }

			if (karta[2] == ']') //karty od 2-9
			{
				char x = karta[1];

				karta1_wartosc = x - '0';
			}
			else
			{
				char y = karta[2];

				int skladnik2 = y - '0';

				karta1_wartosc = 10 + skladnik2;
			}

			if (karta2[1] == 'J') { karta2 = "[11]"; }
			if (karta2[1] == 'Q') { karta2 = "[12]"; }
			if (karta2[1] == 'K') { karta2 = "[13]"; }
			if (karta2[1] == 'A') { karta2 = "[14]"; }


			if (karta2[2] == ']') //karty od 2-9
			{
				char x2 = karta2[1];

				karta2_wartosc = x2 - '0';
			}

			else
			{
				char y2 = karta2[2];

				int skladnik4 = y2 - '0';

				karta2_wartosc = 10 + skladnik4;


			}

			if (karta1_wartosc > karta2_wartosc)
			{
				swap(user[j - 1], user[j]);
			}
		}


	}

}