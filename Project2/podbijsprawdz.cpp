#include"deklaracje.h"

void podbij(int& money, int& pula, int& user_bet)
{
	cout << "O ile chcesz podbic stawke? Masz " << money << "Zetonow" << endl;
	int podbicie{};
	cin >> podbicie;
	while (cin.fail() || podbicie > money || podbicie < 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Nieprawidlowa liczba. Masz " << money << "Zetonow" << endl;
		cin >> podbicie;
	}
	pula += podbicie;
	money -= podbicie;
	user_bet += podbicie;
}

void sprawdz(int& money, int& pula, int& user_bet, int& comp_bet, bool& fold)
{
	cout << "Czy chcesz sprawdzic? Wpisz 0 by spasowac, 1 by sprawdzic" << endl;
	int test;
	cin >> test;
	while (cin.fail() || (test != 1 && test != 0))
	{
		cin.clear();
		cin.ignore();
		cout << "Nieprawidlowa liczba. Wpisz 0 by spasowac, 1 by sprawdzic" << endl;
		cin >> test;
	}
	if (test == 0)
	{
		fold = true;
	}
	if (test == 1) // dorownaj zakladem do komputera
	{
		int y = comp_bet - user_bet; // tyle pieniedzy trzeba dolozyc
		if (money < y) // wejscie za wszystko
		{
			user_bet = money;
			money = 0;
			pula += user_bet;
		}
		else
		{
			user_bet = y;
			money -= user_bet;
			pula += user_bet;
		}
	}


}

