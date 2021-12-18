#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <cstdlib>

using namespace std;

class Karakter
{
public:
	char harf;
	int renk;
	Karakter() {
		srand(time(0));
		harf = 'A' + rand() % 26;//harfler rastgele uretilir
		renk = (rand() % (14 - 9 + 1)) + 9;//renk degerleri istenilen aralikta rastgele uretilir
	}
};

class Katar
{
public:
	void karakterEkle() {
		if (karaktersayisi != 49) //max deger asýlmadýgý surece calisir
		{
			cout << "\nonceki durum - eleman sayisi=" << karaktersayisi + 1<<endl;
			yazdir();//onceki durum yazdirilir
			karaktersayisi = karaktersayisi + 1;//deger artirilir
			Karakter k;
			karakterler[karaktersayisi] = k;
			cout << "\sonraki durum - eleman sayisi=" << karaktersayisi + 1<<endl;
			yazdir();//son durum yazzdirilir
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Ekleme yapilamaz\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	void karakterCikar()
	{
		if (karaktersayisi > 0)
		{
			cout << "\nonceki durum - eleman sayisi=" << karaktersayisi + 1<<endl;
			yazdir();//onceki durum yazdirilir
			karaktersayisi = karaktersayisi - 1;//deger azaltilir
			cout << "\sonraki durum - eleman sayisi=" << karaktersayisi + 1<<endl;
			yazdir();//son durum yazdirilir
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "Cikarma yapilamaz\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	void yazdir() {
		char	DUZCIZGI = 205;
		char	SOLUSTKOSE = 201;
		char	SAGUSTKOSE = 187;
		char	DIKEYCIZGI = 186;
		char	ASAGIAYRAC = 203;
		char	SOLALTKOSE = 200;
		char	SAGALTKOSE = 188;
		char	YUKARIAYRAC = 202;
		if (karaktersayisi >= 0)
		{
			for (int i = 0; i <= karaktersayisi; i++)//harflerin ust cercevesi yazdirilir
			{
				if (i == 0)//eger tek karakter bulunuyorsa tek karakter icin cerceve sonu da yazdirilir
				{
					cout << SOLUSTKOSE << DUZCIZGI;
					if (karaktersayisi == 0) {
						cout << SAGUSTKOSE;
						break;
					}
				}
				else if (i == karaktersayisi)
				{
					cout << ASAGIAYRAC << DUZCIZGI << SAGUSTKOSE;
				}
				else
				{
					cout << ASAGIAYRAC << DUZCIZGI;
				}
			}
			cout << endl;
			for (int i = 0; i <= karaktersayisi; i++)//harflerin cercevesinin orta kismi ve harfler yazdirilir
			{
				cout << DIKEYCIZGI; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), karakterler[i].renk); cout << karakterler[i].harf; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				if (karaktersayisi == i) {
					cout << DIKEYCIZGI;
					break;
				}
			}
			cout << endl;
			for (int i = 0; i <= karaktersayisi; i++)//harflerin cercevesinin alt kismi yazdirilir
			{
				if (i == 0)
				{
					cout << SOLALTKOSE << DUZCIZGI;
					if (karaktersayisi == 0) {
						cout << SAGALTKOSE;
						break;
					}
				}
				else if (i == karaktersayisi)
				{
					cout << YUKARIAYRAC << DUZCIZGI << SAGALTKOSE;
				}
				else
				{
					cout << YUKARIAYRAC << DUZCIZGI;
				}
			}
			cout << endl;
		}
		else//karakter katarinin bos olmasi durumu
		{
			cout << SOLUSTKOSE << SAGUSTKOSE << endl; cout << DIKEYCIZGI << DIKEYCIZGI << endl;
			cout << SOLALTKOSE << SAGALTKOSE << endl;

		}
		
	}
	Katar() {
		karaktersayisi = -1;//katar icin ilk deger atanir
	}
private:
	int karaktersayisi;
	Karakter karakterler[50];
};


enum RENKLER
{
	LIGHTBLUE = 9,	
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
};

int main()
{
	string secim="";
	Katar k;
	while (secim!="3")
	{
		cout << "Islem Seciniz\n1- Karakter Ekle\n2- Karakter Cikar\n3- Programdan Cikis\n";
		cin >> secim;
		
		if (secim == "1")
		{
			k.karakterEkle();
		}
		else if (secim == "2")
		{
			k.karakterCikar();
		}
		else if (secim == "3")
		{
			exit(0);
		}
	}

	return 0;
}
