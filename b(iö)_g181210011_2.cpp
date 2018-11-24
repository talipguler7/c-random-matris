/**************************************************************
***
***                  SAKARYA ÜNÝVERSÝTESÝ
***         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
***              BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
***                PROGRAMLAMAYA GÝRÝÞ DERSÝ
***
***			ÖDEV NUMARASI....:2
***			ÖÐRENCÝ ADI......:Abdülmuttalib GÜLER
***			ÖÐRENCÝ NUMARASI.:G181210011
***			DERS GRUBU.......:B Grubu (ÝÖ)
***
**************************************************************/
#include <iostream>
#include <time.h>
using namespace std;
    int harf_matris[5][10];//harf matrisi tanýmlanmýþtýr.
    int harf;//matris degerlerini tutmak için tanýmlanmýþtýr.
	int sayac;//ifadelerin matriste kullanýlma durumlarýný kontrol için tanýmlanmýþtýr.
	int bellek;//döngüde deðerler sýfýrlanacaðý için, deðerleri tutmak ve bellekte yer ayýrmak için tanýmlanmýþtýr.
	
    void  sýralama_fonk ()//sýralanmýþ diziyi oluþturmak için tanýmlanmýþ fonksiyondur.
	{
		for (int k = 0; k < 5; k++)
		{
			for (int m = 0; m < 10; m++)
			{
				if (m % 2 == 0)//sütunlarýn büyük ve küçük harfi kontrollü basmasý için.
				{
					harf = 65 + rand() % 26;//büyük harfleri üretmek için random fonsiyonudur.
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
					if (sayac != 0)//eðer sayac 0 dan farklý ise benzer ifade birden fazla kez kullanýlmýþ olacaðýndan döngüye tekrar girilmelidir.
					{
						m--;//döngüye tekrar girilmesi için m 1 azaltýlmýþtýr.
						sayac = 0;//tutulan sayac deðeri sýfýrlanmýþtýr.
					}
					else if (sayac == 0)//sayac 0 a eþit olduðunda istenilen kuralda matris olacaðýndan hafýzada matrisi tutmak için tek boyutlu dizi atanmýþtýr.
					{
						harf_matris[k][m] = harf;
					}
				}
				else if (m % 2 == 1)// sütunun teklik çiftlik durumunu kontrol eder.
				{
					harf = 97 + rand() % 26;//küçük harflerin ASII kodlarýyla uyumlu random fonksiyonu.
					for (int a = 0; a < 5; a++)//kontroller küçük harf için baþlar.
					{
						for (int b = 0; b < 10; b++)
						{
							if (harf == harf_matris[a][b])
							{
								sayac++;
							}
						}
					}
					if (sayac != 0)//sayacý dikkate alýp istenilen matrisin oluþup oluþmadýðýný kontrol eder.
					{
						m--;//döngüye tekrar girilmesi için m 1 azaltýlmýþtýr.
						sayac = 0;//sayaca atanan deðer sýfýrlanýr.
					}
					else if (sayac == 0)//sayac 0 ise istenilen matris oluþmuþtur.
					{
						harf_matris[k][m] = harf;//matrisi hafýzada tutmak için tek boyutlu bir diziye atanýr.
					}
				}
			}

		}
	}
int main()
{
	srand(time(NULL));//rastgele sayý üretmek için kullanýlmýþtýr,kütüphenesi olan time.h include edilmiþtir.
	sýralama_fonk();//rastgele matrisin sýralý bir þekilde dizilmesini saðlayan fonksiyonu çaðýrma.
	cout << "Tekrarsiz ve Rastgele Dizi" << endl;
	//sayýlarý ekrana rastgele basan iç içe for döngüsü.
	for (int k = 0; k < 5; k++)
	{
		for (int m = 0; m < 10; m++)
		{
			cout << char(harf_matris[k][m]) << '\t';

		}
		cout << endl;
	}
	//ASCII kodlarý yardýmý ile sýralanmýþ dizi için sýrayý oluþturan kod kümesidir.
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
	//sýralanmýþ diziyi ekrana basan for dögüsü.
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
