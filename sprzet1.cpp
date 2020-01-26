#include <iostream>
#include <fstream>
using namespace std;


class Buty_Narciarskie
{	
	int cena = 20;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();

		ilosc = tab[2];
		ilosc = ilosc + i;

		if (ilosc < 0)
		{
			cout<<"Brak butow narciarskich w magazynie"<<endl;

		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn butow narciarskich"<<endl;
		}
		else
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<tab[0]<<endl;
			plik<<tab[1]<<endl;
			plik<<ilosc<<endl;
			plik<<tab[3]<<endl;
			plik<<tab[4]<<endl;
			plik<<tab[5]<<endl;

			plik.close();	
		}

		return ilosc;		
	}
};


class Narty
{
	int cena = 30;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();
		ilosc = tab[0];
		ilosc = ilosc + i;
		
		if(ilosc < 0)
		{
			cout<<"Brak nart w magazynie"<<endl;
		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn nart"<<endl;
		}
		else
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<ilosc<<endl;
			plik<<tab[1]<<endl;
			plik<<tab[2]<<endl;
			plik<<tab[3]<<endl;
			plik<<tab[4]<<endl;
			plik<<tab[5]<<endl;

			plik.close();	
		}

		return ilosc;
	}
};

class Snowboard
{
	int cena = 30;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();
		ilosc = tab[1];
		ilosc = ilosc + i;

		if(ilosc < 0)
		{
			cout<<"Brak snowboardu w magazynie"<<endl;
		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn snowboardow"<<endl;
		}
		else 
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<tab[0]<<endl;
			plik<<ilosc<<endl;
			plik<<tab[2]<<endl;
			plik<<tab[3]<<endl;
			plik<<tab[4]<<endl;
			plik<<tab[5]<<endl;

			plik.close();
		}
		
		
		return ilosc;
	}

};


class Kijki
{	
	int cena = 10;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();
		ilosc = tab[4];
		ilosc = ilosc + i;
		
		if(ilosc < 0)
		{
			cout<<"Brak kijkow w magazynie"<<endl;
		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn kijkow"<<endl;
		}
		else
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<tab[0]<<endl;
			plik<<tab[1]<<endl;
			plik<<tab[2]<<endl;
			plik<<tab[3]<<endl;
			plik<<ilosc<<endl;
			plik<<tab[5]<<endl;

			plik.close();
		}
		
		return ilosc;
		
	}
};

class Buty_Snowboardowe
{
	
	int cena = 30;
	//int rozmiar;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();
		ilosc = tab[3];
		ilosc = ilosc + i;
		
		if(ilosc < 0)
		{
			cout<<"Brak butow snowboardowych w magazynie"<<endl;
		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn butow snowboardowych"<<endl;
		}
		else
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<tab[0]<<endl;
			plik<<tab[1]<<endl;
			plik<<tab[2]<<endl;
			plik<<ilosc<<endl;
			plik<<tab[4]<<endl;
			plik<<tab[5]<<endl;

			plik.close();
		}
		
		return ilosc;
	}

};

class Kask
{
	int cena = 10;
	//int rozmiar;
	public:
	int ilosc;
	int tab[6];

	int aktualny_stan(int i)
	{
				fstream plik;
		plik.open("BD_sprzet.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int licznik = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[licznik] = atoi(linia.c_str());
				licznik++;
			}
			nr_linii++;
		}
		plik.close();
		ilosc = tab[5];
		ilosc = ilosc + i;
		
		if(ilosc < 0)
		{
			cout<<"Brak Kaskow w magazynie"<<endl;
			
		}
		else if (ilosc > 10)
		{
			cout<<"Pelny magazyn kaskow"<<endl;
		}
		else 
		{
			plik.open("BD_sprzet.txt",ios::out);
			plik<<tab[0]<<endl;
			plik<<tab[1]<<endl;
			plik<<tab[2]<<endl;
			plik<<tab[3]<<endl;
			plik<<tab[4]<<endl;
			plik<<ilosc<<endl;

			plik.close();
		}
		
		return ilosc;
	}

};

class Sprzet{

    public:
    //string data_rozp_wyp;
    //string data_konca_wyp;
	Narty n1;
	Snowboard s1;
	Buty_Narciarskie bn1;
	Buty_Snowboardowe bs1;
	Kijki ki1;
	Kask ka1;


	void pokaz_stan()
	{
		int tab[6];

		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);

		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		int i = 0;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				tab[i] = atoi(linia.c_str());
				i++;
			}
			nr_linii++;
		}
		plik.close();

		cout<<endl<<"********** STAN SPRZETU W WYPORZCZLNI *********"<<endl;
		cout<<"Narty: "<<tab[0]<<" egzemplarzy"<<endl;
		cout<<"Snowboard: "<<tab[1]<<" egzemplarzy"<<endl;
		cout<<"Buty Narciarskie: "<<tab[2]<<" egzemplarzy"<<endl;
		cout<<"Buty Snowboardowe: "<<tab[3]<<" egzemplarzy"<<endl;
		cout<<"Kijki: "<<tab[4]<<" egzemplarzy"<<endl;
		cout<<"Kaski: "<<tab[5]<<" egzemplarzy"<<endl;

	
	}

		void wypozyczenie()
		{
			wypozycz:
			cout<<endl<<"******* JAKI SPRZĘT CHCESZ WYPOŻYCZYĆ ? *******"<<endl;
			cout<<"****************** 1. Narty *******************"<<endl;
			cout<<"**************** 2. Snowboard *****************"<<endl;
			cout<<"************ 3. Buty Narciarskie **************"<<endl;
			cout<<"************ 4. Buty Snowboardowe *************"<<endl;
			cout<<"****************** 5. Kijki *******************"<<endl;
			cout<<"******************* 6. Kask *******************"<<endl;
				
			int wybor1;
			cout<<"Wprowadz swoj wybor: "; cin>>wybor1;
			const int i= -1;

			if( wybor1 == 1)
			{ 
				n1.aktualny_stan(i);
			}
			else if( wybor1 == 2)
			{
				s1.aktualny_stan(i);		
			}
			else if( wybor1 == 3)
			{
				bn1.aktualny_stan(i);		
			}
			else if( wybor1 == 4)
			{
				bs1.aktualny_stan(i);	
			}
			else if( wybor1 == 5)
			{
				ki1.aktualny_stan(i);		
			}
			else if( wybor1 == 6)
			{
				ka1.aktualny_stan(i);		
			}
			else
			{
				cout<<"Nie ma takiej opcji !!!"<<endl;
				goto wypozycz;
			}

		}

		void oddawanie()
		{
			oddaj:
			cout<<endl<<"********* JAKI SPRZĘT CHCESZ ODDAĆ ? **********"<<endl;
			cout<<"****************** 1. Narty *******************"<<endl;
			cout<<"**************** 2. Snowboard *****************"<<endl;
			cout<<"************ 3. Buty Narciarskie **************"<<endl;
			cout<<"************ 4. Buty Snowboardowe *************"<<endl;
			cout<<"****************** 5. Kijki *******************"<<endl;
			cout<<"******************* 6. Kask *******************"<<endl;

			int wybor1;
			cout<<"Wprowadz swoj wybor: "; cin>>wybor1;
			const int i = 1;

			if( wybor1 == 1)
			{
				Narty n1; 
				n1.aktualny_stan(i);
					
			}
			else if( wybor1 == 2)
			{
				Snowboard s1;
				s1.aktualny_stan(i);			
			}
			else if( wybor1 == 3)
			{
				Buty_Narciarskie bn1;
				bn1.aktualny_stan(i);		
			}
			else if( wybor1 == 4)
			{
				Buty_Snowboardowe bs1;
				bs1.aktualny_stan(i);				
			}
			else if( wybor1 == 5)
			{
				Kijki ki1;
				ki1.aktualny_stan(i);			
			}
			else if( wybor1 == 6)
			{
				Kask ka1;
				ka1.aktualny_stan(i);		
			}
			else
			{
				cout<<"Nie ma takiej opcji !!!"<<endl;
				goto oddaj;
			}
		}		
};
int main()
{

	Sprzet s1;

	cout<<endl<<"***************** WYBIERZ OPCJE *****************"<<endl;
	cout<<"************** 1. Wypozycz sprzet ***************"<<endl;
	cout<<"*************** 2. Zwrot sprzetu ****************"<<endl;
	cout<<"***************** 3. Pokaz stan *****************"<<endl;

	int wybor;
	cout<<"Wprowadz swoj wybor: "; cin>>wybor;

	switch(wybor)
	{
		case 1: s1.wypozyczenie(); break;
		case 2: s1.oddawanie(); break;
		case 3: s1.pokaz_stan(); break;
		default: break;
	}
	
	return 0;
}