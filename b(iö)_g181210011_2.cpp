/**************************************************************
***
***                  SAKARYA �N�VERS�TES�
***         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
***              B�LG�SAYAR M�HEND�SL��� B�L�M�
***                PROGRAMLAMAYA G�R�� DERS�
***
***			�DEV NUMARASI....:2
***			��RENC� ADI......:Abd�lmuttalib G�LER
***			��RENC� NUMARASI.:G181210011
***			DERS GRUBU.......:B Grubu (��)
***
**************************************************************/
#include <iostream>
#include <time.h>
using namespace std;
    int harf_matris[5][10];//harf matrisi tan�mlanm��t�r.
    int harf;//matris degerlerini tutmak i�in tan�mlanm��t�r.
	int sayac;//ifadelerin matriste kullan�lma durumlar�n� kontrol i�in tan�mlanm��t�r.
	int bellek;//d�ng�de de�erler s�f�rlanaca�� i�in, de�erleri tutmak ve bellekte yer ay�rmak i�in tan�mlanm��t�r.
	
    void  s�ralama_fonk ()//s�ralanm�� diziyi olu�turmak i�in tan�mlanm�� fonksiyondur.
	{
		for (int k = 0; k < 5; k++)
		{
			for (int m = 0; m < 10; m++)
			{
				if (m % 2 == 0)//s�tunlar�n b�y�k ve k���k harfi kontroll� basmas� i�in.
				{
					harf = 65 + rand() % 26;//b�y�k harfleri �retmek i�in random fonsiyonudur.
					for (int a = 0; a < 5; a++)
					{
						for (int b = 0; b < 10; b++)
						{
							if (harf == harf_matris[a][b])
							{
								sayac++;
							}
						}
					}
					if (sayac != 0)//e�er sayac 0 dan farkl� ise benzer ifade birden fazla kez kullan�lm�� olaca��ndan d�ng�ye tekrar girilmelidir.
					{
						m--;//d�ng�ye tekrar girilmesi i�in m 1 azalt�lm��t�r.
						sayac = 0;//tutulan sayac de�eri s�f�rlanm��t�r.
					}
					else if (sayac == 0)//sayac 0 a e�it oldu�unda istenilen kuralda matris olaca��ndan haf�zada matrisi tutmak i�in tek boyutlu dizi atanm��t�r.
					{
						harf_matris[k][m] = harf;
					}
				}
				else if (m % 2 == 1)// s�tunun teklik �iftlik durumunu kontrol eder.
				{
					harf = 97 + rand() % 26;//k���k harflerin ASII kodlar�yla uyumlu random fonksiyonu.
					for (int a = 0; a < 5; a++)//kontroller k���k harf i�in ba�lar.
					{
						for (int b = 0; b < 10; b++)
						{
							if (harf == harf_matris[a][b])
							{
								sayac++;
							}
						}
					}
					if (sayac != 0)//sayac� dikkate al�p istenilen matrisin olu�up olu�mad���n� kontrol eder.
					{
						m--;//d�ng�ye tekrar girilmesi i�in m 1 azalt�lm��t�r.
						sayac = 0;//sayaca atanan de�er s�f�rlan�r.
					}
					else if (sayac == 0)//sayac 0 ise istenilen matris olu�mu�tur.
					{
						harf_matris[k][m] = harf;//matrisi haf�zada tutmak i�in tek boyutlu bir diziye atan�r.
					}
				}
			}

		}
	}
int main()
{
	srand(time(NULL));//rastgele say� �retmek i�in kullan�lm��t�r,k�t�phenesi olan time.h include edilmi�tir.
	s�ralama_fonk();//rastgele matrisin s�ral� bir �ekilde dizilmesini sa�layan fonksiyonu �a��rma.
	cout << "Tekrarsiz ve Rastgele Dizi" << endl;
	//say�lar� ekrana rastgele basan i� i�e for d�ng�s�.
	for (int k = 0; k < 5; k++)
	{
		for (int m = 0; m < 10; m++)
		{
			cout << char(harf_matris[k][m]) << '\t';

		}
		cout << endl;
	}
	//ASCII kodlar� yard�m� ile s�ralanm�� dizi i�in s�ray� olu�turan kod k�mesidir.
	for (int k = 0; k < 5; k++)
	{
		for (int m = 0; m < 10; m++)
		{
			for (int a = 0; a < 5; a++)
			{
				for (int b = 0; b < 10; b++)
				{
					if (harf_matris[k][m] < harf_matris[a][b])
					{
						bellek = harf_matris[a][b];
						harf_matris[a][b] = harf_matris[k][m];
						harf_matris[k][m] = bellek;
					}
				}
			}
		}
	}
	cout << "Siranlamis Dizi" << endl;
	//s�ralanm�� diziyi ekrana basan for d�g�s�.
	for (int k = 0; k < 5; k++)
	{
		for (int m = 0; m < 10; m++)
		{
			cout << char(harf_matris[k][m]) << '\t';
		}
		cout << endl;
	}
	system("PAUSE");
}
