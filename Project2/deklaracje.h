#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<random>

using namespace std;

void podbij(int& money, int& pula, int& user_bet); // funkcja zwiazana z obstawianiem
void sprawdz(int& money, int& pula, int& user_bet, int& comp_bet, bool& fold); // funkcja zwiazana z obstawianiem
void nowagra(int& money); //Czy chcesz rozpoczynac nowa gre?
void zapisgry(int& money); //Czy chcesz zapisac gre?
void tworzenie_talii(string karty[4][13]); //stworzenie tablicy 2-wymiarowej kart
void RozdajKarty(string karty[4][13], string user[5], string computer[5]); //rozdaje losowe karty
void sortowanie(string user[5]); //algorytm sortujacy karty 
int uklady(string user[5]); //sprawdzenie jaki jest uklad kart
int wygrana(string user[5], string computer[5]); // sprawdzenie czyj uklad jest silniejszy
void wymien_karty(string karty[4][13], string user[5]); //algorytm wymiany kart przez uzytkownika

extern random_device device;
