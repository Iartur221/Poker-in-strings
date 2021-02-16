#include "deklaracje.h"

void tworzenie_talii(string karty[4][13])
{
	//Asy [A]  krole [K] damy[Q] walety [J], 10, 9, 8, 7, 6, 5, 4, 3, 2
	//tablica dwuwymiarowa kolor x wartosc karty

	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 15; j++)
		{
			if (i == 0)
			{
				string s = to_string(j);
				if (j == 11) { s = "J"; }
				if (j == 12) { s = "Q"; }
				if (j == 13) { s = "K"; }
				if (j == 14) { s = "A"; }
				karty[i][j - 2] = "[" + s + "]Pik";
			}
			if (i == 1)
			{
				string s = to_string(j);
				if (j == 11) { s = "J"; }
				if (j == 12) { s = "Q"; }
				if (j == 13) { s = "K"; }
				if (j == 14) { s = "A"; }
				karty[i][j - 2] = "[" + s + "]Kier";
			}
			if (i == 2)
			{
				string s = to_string(j);
				if (j == 11) { s = "J"; }
				if (j == 12) { s = "Q"; }
				if (j == 13) { s = "K"; }
				if (j == 14) { s = "A"; }
				karty[i][j - 2] = "[" + s + "]Karo";
			}
			if (i == 3)
			{
				string s = to_string(j);
				if (j == 11) { s = "J"; }
				if (j == 12) { s = "Q"; }
				if (j == 13) { s = "K"; }
				if (j == 14) { s = "A"; }
				karty[i][j - 2] = "[" + s + "]Trefl";
			}
		}
	}
}

void RozdajKarty(string karty[4][13], string user[5], string computer[5]) //rozdaje losowe karty
{
	// zastap symbol w talii zerem, jesli wylosuje 0 powtorz losowanie
	mt19937 generator(device());
	uniform_int_distribution<int> distribution_kolor(0, 3);
	uniform_int_distribution<int> distribution_karta(0, 12);

	int x = distribution_kolor(generator); // x = kolor karty
	int y = distribution_karta(generator); // y = wartosc karty

	user[0] = "0";
	user[1] = "0";
	user[2] = "0";
	user[3] = "0";
	user[4] = "0";
	computer[0] = "0";
	computer[1] = "0";
	computer[2] = "0";
	computer[3] = "0";
	computer[4] = "0";

	//rozdanie dla gracza
	for (int i = 0; user[0] == "0" || user[1] == "0" || user[2] == "0" || user[3] == "0" || user[4] == "0";)
	{

		x = distribution_kolor(generator);
		y = distribution_karta(generator);

		if (karty[x][y] != "0")
		{
			user[i] = karty[x][y];
			karty[x][y] = "0";
			i++;
		}
	}

	//rozdanie dla komputera
	for (int i = 0; computer[0] == "0" || computer[1] == "0" || computer[2] == "0" || computer[3] == "0" || computer[4] == "0";)
	{
		x = distribution_kolor(generator);
		y = distribution_karta(generator);

		if (karty[x][y] != "0")
		{
			computer[i] = karty[x][y];
			karty[x][y] = "0";
			i++;
		}
	}

}