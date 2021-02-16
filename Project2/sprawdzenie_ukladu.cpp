#include "deklaracje.h"

int uklady(string user[5])
{
	//para, 2pary, trojka, kareta, full
	bool para{};
	bool pary2{};
	bool trojka{};
	bool kareta{};
	bool full{};

	for (int i = 0; i < 4; i++) //i mniejsze od 4 bo dalej [i + 1]
	{
		string first = user[i];
		string second = user[i + 1];

		char pierwsza = first[1];
		char druga = second[1];

		if (pierwsza == druga)
		{
			if (i < 3) // jezeli jest mozliwosc wystapienia sprawdz czy jest trojka
			{
				string third = user[i + 2];
				char trzecia = third[1];

				if (druga == trzecia)//trojka
				{
					trojka = true;

					if (i < 2)//jezeli jest mozliwosc sprawdz czy jest kareta
					{
						string fourth = user[i + 3];
						char czwarta = fourth[1];

						if (trzecia == czwarta)
						{
							kareta = true;
						}
					}

					if (i == 0)// teraz sprawdz czy moze byc full trojka x para
					{
						string fourth = user[i + 3];
						string fifth = user[i + 4];

						char czwarta = fourth[1];
						char piata = fifth[1];

						if (czwarta == piata)
						{
							full = true;
						}
					}

					if (full == true || kareta == true)
					{
						trojka = false;
					}
				}
			}

			para = true;

			if (para == true && i < 2)
			{
				string third = user[i + 2];
				string fourth = user[i + 3];

				char trzecia = third[1];
				char czwarta = fourth[1];

				if (trzecia == czwarta)// 2 pary-cos lub full
				{
					if (i == 0) // sprawdz fulla para x trojka i para-cos-para
					{
						string fifth = user[i + 4];
						char piata = fifth[1];

						if (czwarta == piata)
						{
							full = true;
						}
					}

					pary2 = true;
				}

				if (i == 0)
				{
					string fifth = user[i + 4]; // sprawdz uklad para - cos - para
					char piata = fifth[1];

					if (czwarta == piata)
					{
						pary2 = true;
					}
				}

				if (full == true)
				{
					pary2 = false;
				}
			}
		}
		if (trojka == true || kareta == true) { pary2 = false; } // wykluczenie 2 ukladow naraz

		if (kareta == true || full == true || trojka == true || pary2 == true)
		{
			para = false;
		}

	}

	if (para == true) { return 1; } // zwracanie odpowiedniej wartosci wg starszenstwa ukladow

	else if (pary2 == true) { return 2; }

	else if (trojka == true) { return 3; }

	else if (kareta == true) { return 7; }

	else if (full == true) { return 6; }

	// zmiana J, Q, K, A na 11, 12, 13, 14, jezeli nie ma ukladow powyzej
	string Pik = "Pik";
	string Kier = "Kier";
	string Karo = "Karo";
	string Trefl = "Trefl";

	for (int i = 0; i < 5; i++)
	{
		string karta = user[i];
		if (user[i].find(Pik) != string::npos)
		{
			if (karta[1] == 'J') { user[i] = "[11]Pik"; }
			if (karta[1] == 'Q') { user[i] = "[12]Pik"; }
			if (karta[1] == 'K') { user[i] = "[13]Pik"; }
			if (karta[1] == 'A') { user[i] = "[14]Pik"; }
		}
		if (user[i].find(Kier) != string::npos)
		{
			if (karta[1] == 'J') { user[i] = "[11]Kier"; }
			if (karta[1] == 'Q') { user[i] = "[12]Kier"; }
			if (karta[1] == 'K') { user[i] = "[13]Kier"; }
			if (karta[1] == 'A') { user[i] = "[14]Kier"; }
		}
		if (user[i].find(Karo) != string::npos)
		{
			if (karta[1] == 'J') { user[i] = "[11]Karo"; }
			if (karta[1] == 'Q') { user[i] = "[12]Karo"; }
			if (karta[1] == 'K') { user[i] = "[13]Karo"; }
			if (karta[1] == 'A') { user[i] = "[14]Karo"; }
		}
		if (user[i].find(Trefl) != string::npos)
		{
			if (karta[1] == 'J') { user[i] = "[11]Trefl"; }
			if (karta[1] == 'Q') { user[i] = "[12]Trefl"; }
			if (karta[1] == 'K') { user[i] = "[13]Trefl"; }
			if (karta[1] == 'A') { user[i] = "[14]Trefl"; }
		}
	}

	//sprawdzenie strita

	int a = {};
	string karta1 = user[0];
	char x = karta1[1];
	if (x == '1') { x = karta1[2]; a = x - '0' + 10; }
	else { a = x - '0'; }

	int b = {};
	karta1 = user[1];
	x = karta1[1];
	if (x == '1') { x = karta1[2]; b = x - '0' + 10; }
	else { b = x - '0'; }

	int c = {};
	karta1 = user[2];
	x = karta1[1];
	if (x == '1') { x = karta1[2]; c = x - '0' + 10; }
	else { c = x - '0'; }

	int d = {};
	karta1 = user[3];
	x = karta1[1];
	if (x == '1') { x = karta1[2]; d = x - '0' + 10; }
	else { d = x - '0'; }

	int e = {};
	karta1 = user[4];
	x = karta1[1];
	if (x == '1') { x = karta1[2]; e = x - '0' + 10; }
	else { e = x - '0'; }

	bool strit{};

	if (a + 1 == b)
	{
		if (b + 1 == c)
		{
			if (c + 1 == d)
			{
				if (d + 1 == e)
				{
					strit = true;
				}
			}
		}
	}

	bool kolor = {}; // sprawdzenie koloru

	if (user[0].find(Pik) != string::npos && user[1].find(Pik) != string::npos && user[2].find(Pik) != string::npos && user[3].find(Pik) != string::npos && user[4].find(Pik) != string::npos)
	{
		kolor = true;
	}
	else if (user[0].find(Kier) != string::npos && user[1].find(Kier) != string::npos && user[2].find(Kier) != string::npos && user[3].find(Kier) != string::npos && user[4].find(Kier) != string::npos)
	{
		kolor = true;
	}
	else if (user[0].find(Karo) != string::npos && user[1].find(Karo) != string::npos && user[2].find(Karo) != string::npos && user[3].find(Karo) != string::npos && user[4].find(Karo) != string::npos)
	{
		kolor = true;
	}
	else if (user[0].find(Trefl) != string::npos && user[1].find(Trefl) != string::npos && user[2].find(Trefl) != string::npos && user[3].find(Trefl) != string::npos && user[4].find(Trefl) != string::npos)
	{
		kolor = true;
	}

	bool poker{};

	if (kolor == true && strit == true)
	{
		poker = true;
		strit = false;
		kolor = false;
	}

	bool pokerkrolewski{};

	if (poker == true)
	{
		string karty = user[0];
		if (karty[1] == '1') // poker ktory zaczyna sie od 10
		{
			pokerkrolewski = true;
			poker = false;
		}

	}


	for (int i = 0; i < 5; i++) // przeksztalcenie z powrotem na symbole
	{
		string karta = user[i];
		if (user[i].find(Pik) != string::npos)
		{
			if (karta[1] == '1' && karta[2] == '1') { user[i] = "[J]Pik"; }
			if (karta[1] == '1' && karta[2] == '2') { user[i] = "[Q]Pik"; }
			if (karta[1] == '1' && karta[2] == '3') { user[i] = "[K]Pik"; }
			if (karta[1] == '1' && karta[2] == '4') { user[i] = "[A]Pik"; }
		}
		if (user[i].find(Kier) != string::npos)
		{
			if (karta[1] == '1' && karta[2] == '1') { user[i] = "[J]Kier"; }
			if (karta[1] == '1' && karta[2] == '2') { user[i] = "[Q]Kier"; }
			if (karta[1] == '1' && karta[2] == '3') { user[i] = "[K]Kier"; }
			if (karta[1] == '1' && karta[2] == '4') { user[i] = "[A]Kier"; }
		}
		if (user[i].find(Karo) != string::npos)
		{
			if (karta[1] == '1' && karta[2] == '1') { user[i] = "[J]Karo"; }
			if (karta[1] == '1' && karta[2] == '2') { user[i] = "[Q]Karo"; }
			if (karta[1] == '1' && karta[2] == '3') { user[i] = "[K]Karo"; }
			if (karta[1] == '1' && karta[2] == '4') { user[i] = "[A]Karo"; }
		}
		if (user[i].find(Trefl) != string::npos)
		{
			if (karta[1] == '1' && karta[2] == '1') { user[i] = "[J]Trefl"; }
			if (karta[1] == '1' && karta[2] == '2') { user[i] = "[Q]Trefl"; }
			if (karta[1] == '1' && karta[2] == '3') { user[i] = "[K]Trefl"; }
			if (karta[1] == '1' && karta[2] == '4') { user[i] = "[A]Trefl"; }
		}
	}

	if (pokerkrolewski == true) // zwracanie odpowiedniej wartosci wg starszenstwa ukladow
	{
		return 9;
	}
	if (poker == true)
	{
		return 8;
	}
	if (kolor == true)
	{
		return 5;
	}
	if (strit == true)
	{
		return 4;
	}
	else return 0;

}

int wygrana(string user[5], string computer[5])
{
	int x = uklady(user);
	int y = uklady(computer);

	if (x == 0) { cout << "Masz najwyzsza karte: " << user[4] << endl; } //done
	if (x == 1) { cout << "Masz Pare" << endl; } //done
	if (x == 2) { cout << "Masz 2 Pary" << endl; } //done
	if (x == 3) { cout << "Masz Trojke" << endl; } //done
	if (x == 7) { cout << "Masz Karete" << endl; } //done
	if (x == 6) { cout << "Masz Fulla" << endl; } //done
	if (x == 9) { cout << "Masz Pokera krolewskiego" << endl; } //done
	if (x == 8) { cout << "Masz Pokera" << endl; } // done
	if (x == 5) { cout << "Masz Kolor" << endl; } //done
	if (x == 4) { cout << "Masz Strit" << endl; } //done

	if (y == 0) { cout << "Przeciwnik ma najwyzsza karte: " << computer[4] << endl; } //done
	if (y == 1) { cout << "Przeciwnik ma Pare" << endl; } //done
	if (y == 2) { cout << "Przeciwnik ma 2 Pary" << endl; } //done
	if (y == 3) { cout << "Przeciwnik ma Trojke" << endl; } //done
	if (y == 7) { cout << "Przeciwnik ma Karete" << endl; } //done
	if (y == 6) { cout << "Przeciwnik ma Fulla" << endl; } //done
	if (y == 9) { cout << "Przeciwnik ma Pokera krolewskiego" << endl; } //done
	if (y == 8) { cout << "Przeciwnik ma Pokera" << endl; } // done
	if (y == 5) { cout << "Przeciwnik ma Kolor" << endl; } //done
	if (y == 4) { cout << "Przeciwnik ma Strit" << endl; } //done


	if (x > y) { return 1; }
	if (x < y) { return 0; }
	if (x == y)
	{
		if (x == 4 || x == 8) //strit vs strit. Wyzszy strit lub poker ma wyzsza pierwsza karte
		{
			//char 0 = int 48
			string karta1 = user[0];
			string karta2 = computer[0];
			char test1 = karta1[1];
			char test2 = karta2[1];

			int j; int k;
			if (test1 == '1') { j = 58; }
			else { j = test1; }

			if (test2 == '1') { k = 58; }
			else { k = test2; }

			if (j > k) { return 1; }
			if (j < k) { return 0; }
			if (j == k) { return 2; }

		}
		if (x == 9) { return 2; } // 2 pokery krolewskie daja remis

		if (x == 6 || x == 7 || x == 3) // trzecia karta w kolejnosci zawsze jest w trojce, wygrywa wyzsza trojka i nie moga wystapic 2 takie same trojki, kareta analogicznie
		{
			string karta1 = user[2];
			string karta2 = computer[2];

			char test1 = karta1[1];
			char test2 = karta2[1];

			int j; int k;
			if (test1 == '1') { j = 58; }
			else if (test1 == 'J') { j = 59; }
			else if (test1 == 'Q') { j = 60; }
			else if (test1 == 'K') { j = 61; }
			else if (test1 == 'A') { j = 62; }
			else { j = test1; }

			if (test2 == '1') { k = 58; }
			else if (test2 == 'J') { k = 59; }
			else if (test2 == 'Q') { k = 60; }
			else if (test2 == 'K') { k = 61; }
			else if (test2 == 'A') { k = 62; }
			else { k = test2; }

			if (j > k) { return 1; }
			if (j < k) { return 0; }
		}

		if (x == 5) //kolor vs kolor wygrywa wyzsza najwyzsza karta
		{
			string karta1 = user[4];
			string karta2 = computer[4];

			char test1 = karta1[1];
			char test2 = karta2[1];

			int j; int k;
			if (test1 == '1') { j = 58; }
			else if (test1 == 'J') { j = 59; }
			else if (test1 == 'Q') { j = 60; }
			else if (test1 == 'K') { j = 61; }
			else if (test1 == 'A') { j = 62; }
			else { j = test1; }

			if (test2 == '1') { k = 58; }
			else if (test2 == 'J') { k = 59; }
			else if (test2 == 'Q') { k = 60; }
			else if (test2 == 'K') { k = 61; }
			else if (test2 == 'A') { k = 62; }
			else { k = test2; }

			if (j > k) { return 1; }
			if (j < k) { return 0; }
		}

		if (x == 2) // 2pary vs 2pary
		{
			int k = 0;
			int j = 0;
			for (int i = 4; i > 0; i--) // czy jest jakas wyzsza para?
			{
				string karta1 = user[i];
				string karta2 = user[i - 1];
				char parauser = 0;
				if (karta1[1] == karta2[1])//para znaleziona spisz jej wartosc
				{
					parauser = karta1[1];
					if (parauser == '1') { k = 58; }
					else if (parauser == 'J') { k = 59; }
					else if (parauser == 'Q') { k = 60; }
					else if (parauser == 'K') { k = 61; }
					else if (parauser == 'A') { k = 62; }
					else { k = parauser; }
				}

				string karta3 = computer[i];
				string karta4 = computer[i - 1];
				char paracomputer = 0;
				if (karta3[1] == karta4[1])//para znaleziona spisz jej wartosc
				{
					paracomputer = karta3[1];
					if (paracomputer == '1') { j = 58; }
					else if (paracomputer == 'J') { j = 59; }
					else if (paracomputer == 'Q') { j = 60; }
					else if (paracomputer == 'K') { j = 61; }
					else if (paracomputer == 'A') { j = 62; }
					else { j = paracomputer; }
				}

				if (k != 0 && j != 0)
				{
					if (k > j) { return 1; }
					if (k < j) { return 0; }
					if (k == j)//1 silniejsza para taka sama szukaj drugiej pary i porownaj je
					{
						k = 0; // wyzerowanie zmiennych
						j = 0;
					}
				}
			}

			for (int i = 0; i < 5; i++)// obie pary byly takie same, sprawdz czy jest wyzsza piata karta
			{

				if (i == 0) // 1 karta uklad 1-2-2
				{
					string karta1 = user[i];
					string karta2 = user[i + 1];
					char kartauser = 0;

					if (karta1[1] != karta2[1])//karta nie tworzy pary
					{
						kartauser = karta1[1];
						if (kartauser == '1') { k = 58; }
						else if (kartauser == 'J') { k = 59; }
						else if (kartauser == 'Q') { k = 60; }
						else if (kartauser == 'K') { k = 61; }
						else if (kartauser == 'A') { k = 62; }
						else { k = kartauser; }
					}

					string karta3 = computer[i];
					string karta4 = computer[i + 1];
					char kartacomp = 0;

					if (karta3[1] != karta4[1])//karta nie tworzy pary
					{
						kartacomp = karta3[1];
						if (kartacomp == '1') { j = 58; }
						else if (kartacomp == 'J') { j = 59; }
						else if (kartacomp == 'Q') { j = 60; }
						else if (kartacomp == 'K') { j = 61; }
						else if (kartacomp == 'A') { j = 62; }
						else { j = kartacomp; }
					}

				}

				if (i == 2) //karta nie tworzy pary do tylu i do przodu (uklad para-1-para)
				{
					string karta1 = user[i];
					string karta2 = user[i + 1];
					string karta3 = user[i - 1];
					char kartauser = 0;

					if (karta1[1] != karta2[1] && karta1[1] != karta3[1])
					{
						kartauser = karta1[1];
						if (kartauser == '1') { k = 58; }
						else if (kartauser == 'J') { k = 59; }
						else if (kartauser == 'Q') { k = 60; }
						else if (kartauser == 'K') { k = 61; }
						else if (kartauser == 'A') { k = 62; }
						else { k = kartauser; }
					}

					string karta4 = computer[i];
					string karta5 = computer[i + 1];
					string karta6 = computer[i - 1];
					char kartacomp = 0;

					if (karta4[1] != karta5[1] && karta4[1] != karta6[1])//karta nie tworzy pary do tylu i do przodu (uklad para-1-para)
					{
						kartacomp = karta4[1];
						if (kartacomp == '1') { j = 58; }
						else if (kartacomp == 'J') { j = 59; }
						else if (kartacomp == 'Q') { j = 60; }
						else if (kartacomp == 'K') { j = 61; }
						else if (kartacomp == 'A') { j = 62; }
						else { j = kartacomp; }
					}
				}

				if (i == 4) // ostatnia karta uklad 2-2-1
				{
					string karta1 = user[i];
					char kartauser = 0;

					kartauser = karta1[1];
					if (kartauser == '1') { k = 58; }
					else if (kartauser == 'J') { k = 59; }
					else if (kartauser == 'Q') { k = 60; }
					else if (kartauser == 'K') { k = 61; }
					else if (kartauser == 'A') { k = 62; }
					else { k = kartauser; }

					string karta3 = computer[i];
					char kartacomp = 0;

					kartacomp = karta3[1];
					if (kartacomp == '1') { j = 58; }
					else if (kartacomp == 'J') { j = 59; }
					else if (kartacomp == 'Q') { j = 60; }
					else if (kartacomp == 'K') { j = 61; }
					else if (kartacomp == 'A') { j = 62; }
					else { j = kartacomp; }
				}

				if (k != 0 && j != 0)
				{
					if (k > j) { return 1; }// karta usera mocniejsza
					if (k < j) { return 0; }
					if (k == j) { return 2; } // remis
				}
			}

		}

		if (x == 0) // najwyzsza karta wygrywa
		{
			for (int i = 4; i >= 0; i--)
			{
				string karta1 = user[i];
				string karta2 = computer[i];
				char a = karta1[1];
				char b = karta2[1];
				int k{};
				int j{};
				if (a == '1') { j = 58; }
				else if (a == 'J') { j = 59; }
				else if (a == 'Q') { j = 60; }
				else if (a == 'K') { j = 61; }
				else if (a == 'A') { j = 62; }
				else { j = a; }
				if (b == '1') { k = 58; }
				else if (b == 'J') { k = 59; }
				else if (b == 'Q') { k = 60; }
				else if (b == 'K') { k = 61; }
				else if (b == 'A') { k = 62; }
				else { k = b; }

				if (j > k) { return 1; }//user wygral
				if (j < k) { return 0; }
				if (j == k)
				{
					if (i == 0)
					{
						return 2; //remis
					}
				}
			}
		}

		if (x == 1) // para vs para
		{
			int k = 0;
			int j = 0;
			for (int i = 4; i > 0; i--) // czy jest jakas wyzsza para?
			{
				string karta1 = user[i];
				string karta2 = user[i - 1];
				char parauser = 0;
				if (karta1[1] == karta2[1])//para
				{
					parauser = karta1[1];
					if (parauser == '1') { k = 58; }
					else if (parauser == 'J') { k = 59; }
					else if (parauser == 'Q') { k = 60; }
					else if (parauser == 'K') { k = 61; }
					else if (parauser == 'A') { k = 62; }
					else { k = parauser; }
				}

				string karta3 = computer[i];
				string karta4 = computer[i - 1];
				char paracomputer = 0;
				if (karta3[1] == karta4[1])//para
				{
					paracomputer = karta3[1];
					if (paracomputer == '1') { j = 58; }
					else if (paracomputer == 'J') { j = 59; }
					else if (paracomputer == 'Q') { j = 60; }
					else if (paracomputer == 'K') { j = 61; }
					else if (paracomputer == 'A') { j = 62; }
					else { j = paracomputer; }
				}

				if (k != 0 && j != 0) // jezeli znajdzie obie pary porownaj je
				{
					if (k > j) { return 1; }
					if (k < j) { return 0; }
					if (k == j) //takie same pary sprawdzaj dalej karty
					{
						k = 0;
						j = 0;
						break;
					}

				}
			}

			int x = 0;
			int z = 0;
			for (int i = 4; i >= 0; i--)
			{
				if (i == 4)
				{
					string karta1 = user[i];
					string karta2 = user[i - 1];
					char kartauser = 0;

					if (karta1[1] != karta2[1])//karta nie tworzy pary
					{
						kartauser = karta1[1];
						if (kartauser == '1') { k = 58; }
						else if (kartauser == 'J') { k = 59; }
						else if (kartauser == 'Q') { k = 60; }
						else if (kartauser == 'K') { k = 61; }
						else if (kartauser == 'A') { k = 62; }
						else { k = kartauser; }
					}

					string karta3 = computer[i];
					string karta4 = computer[i - 1];
					char kartacomp = 0;
					if (karta3[1] != karta4[1])//karta nie tworzy pary
					{
						kartacomp = karta3[1];
						if (kartacomp == '1') { j = 58; }
						else if (kartacomp == 'J') { j = 59; }
						else if (kartacomp == 'Q') { j = 60; }
						else if (kartacomp == 'K') { j = 61; }
						else if (kartacomp == 'A') { j = 62; }
						else { j = kartacomp; }
					}
				}

				if (i != 4 && i != 0) //karta nie tworzy pary z karta do tylu i do przodu 
				{
					string karta1 = user[i];
					string karta2 = user[i + 1];
					string karta3 = user[i - 1];
					char kartauser = 0;

					if (karta1[1] != karta2[1] && karta1[1] != karta3[1])
					{
						kartauser = karta1[1];
						if (kartauser == '1') { x = 58; }
						else if (kartauser == 'J') { x = 59; }
						else if (kartauser == 'Q') { x = 60; }
						else if (kartauser == 'K') { x = 61; }
						else if (kartauser == 'A') { x = 62; }
						else { x = kartauser; }
					}
					string karta4 = computer[i];
					string karta5 = computer[i + 1];
					string karta6 = computer[i - 1];
					char kartacomp = 0;

					if (karta4[1] != karta5[1] && karta4[1] != karta6[1])//brak pary
					{
						kartacomp = karta4[1];
						if (kartacomp == '1') { z = 58; }
						else if (kartacomp == 'J') { z = 59; }
						else if (kartacomp == 'Q') { z = 60; }
						else if (kartacomp == 'K') { z = 61; }
						else if (kartacomp == 'A') { z = 62; }
						else { z = kartacomp; }
					}

					if (k > x) { k = x; } // jezeli k = 0 zastap go nowa karta, k i j zeruje sie w przypadku 2 takich samych figur u komputera i uzytkownika
					if (z > j) { j = z; } // jezeli j = 0 zastap go nowa karta
				}

				if (i == 0)
				{
					string karta1 = user[i];
					string karta2 = user[i - 1];
					char kartauser = 0;

					if (karta1[1] != karta2[1])//brak pary
					{
						kartauser = karta1[1];
						if (kartauser == '1') { k = 58; }
						else if (kartauser == 'J') { k = 59; }
						else if (kartauser == 'Q') { k = 60; }
						else if (kartauser == 'K') { k = 61; }
						else if (kartauser == 'A') { k = 62; }
						else { k = kartauser; }
					}

					string karta3 = computer[i];
					string karta4 = computer[i - 1];
					char kartacomp = 0;
					if (karta3[1] != karta4[1])//brak pary
					{
						kartacomp = karta3[1];
						if (kartacomp == '1') { j = 58; }
						else if (kartacomp == 'J') { j = 59; }
						else if (kartacomp == 'Q') { j = 60; }
						else if (kartacomp == 'K') { j = 61; }
						else if (kartacomp == 'A') { j = 62; }
						else { j = kartacomp; }
					}
				}

				if (k != 0 && j != 0)
				{
					if (k > j) { return 1; }
					if (k < j) { return 0; }
					if (k == j)
					{
						k = 0; // wyzeruj sprawdzane karty zeby przejsc dalej
						j = 0;
						if (i == 0) { return 2; } // remis
					}
				}

			}
		}
	}
	return 0;
}
