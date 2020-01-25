#include <iostream>
using namespace std;


class Buty_Narciarskie
{	
	int cena = 20;
	public:
	int ilosc=10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		//cout<<"Stan w wypozyczalni "<<ilosc<<endl;
		return ilosc;
	}
	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
	}
};


class Narty
{
	int cena = 30;
	public:
	int ilosc= 10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		//cout<<"Stan w wypozyczalni "<<ilosc<<endl;
		return ilosc;
	}

	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
	}

};

class Snowboard
{
	int cena = 30;
	public:
	int ilosc= 10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		return ilosc;
	}

	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
	}

};


class Kijki
{	
	int cena = 10;
	public:
	int ilosc = 10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		return ilosc;
	}

	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
	}
};

class Buty_Snowboardowe
{
	
	int cena = 30;
	//int rozmiar;
	public:
	int ilosc = 10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		return ilosc;
	}

	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
	}
};

class Kask
{
	int cena = 10;
	//int rozmiar;
	public:
	int ilosc = 10;

	int aktualny_stan(int i)
	{
		ilosc = ilosc + i;
		//cout<<endl<<"Do zapłaty "<<cena<<" zl"<<endl;
		return ilosc;
	}

	void stan()
	{
		cout<<ilosc<<" egzeplarzy"<<endl;
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
		cout<<endl<<"********** STAN SPRZETU W WYPORZCZLNI *********"<<endl;
		cout<<"Narty: "; n1.stan();
		cout<<"Snowboard: "; s1.stan();
		cout<<"Buty Narciarskie: "; bn1.stan();
		cout<<"Buty Snowboardowe: "; bs1.stan();
		cout<<"Kijki: "; ki1.stan();
		cout<<"Kaski: "; ka1.stan();
	}

		void wypozyczenie()
		{
			wypozycz;
			cout<<endl<<"******* JAKI SPRZĘT CHCESZ WYPOŻYCZYĆ ? *******"<<endl;
			cout<<"****************** 1. Narty *******************"<<endl;
			cout<<"**************** 2. Snowboard *****************"<<endl;
			cout<<"************ 3. Buty Narciarskie **************"<<endl;
			cout<<"************ 4. Buty Snowboardowe *************"<<endl;
			cout<<"****************** 5. Kijki *******************"<<endl;
			cout<<"******************* 6. Kask *******************"<<endl;
				
			int wybor1;
			cout<<"Wprowadz swoj wybor: "; cin>>wybor1;
			int ilosc= -1;

			if( wybor1 == 1)
			{ 
				n1.aktualny_stan(ilosc);
			}
			else if( wybor1 == 2)
			{
				s1.aktualny_stan(ilosc);		
			}
			else if( wybor1 == 3)
			{
				bn1.aktualny_stan(ilosc);		
			}
			else if( wybor1 == 4)
			{
				bs1.aktualny_stan(ilosc);	
			}
			else if( wybor1 == 5)
			{
				ki1.aktualny_stan(ilosc);		
			}
			else if( wybor1 == 6)
			{
				ka1.aktualny_stan(ilosc);		
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
			int ilosc= 1;

			if( wybor1 == 1)
			{
				Narty n1; 
				n1.aktualny_stan(ilosc);
					
			}
			else if( wybor1 == 2)
			{
				Snowboard s1;
				s1.aktualny_stan(ilosc);			
			}
			else if( wybor1 == 3)
			{
				Buty_Narciarskie bn1;
				bn1.aktualny_stan(ilosc);		
			}
			else if( wybor1 == 4)
			{
				Buty_Snowboardowe bs1;
				bs1.aktualny_stan(ilosc);				
			}
			else if( wybor1 == 5)
			{
				Kijki ki1;
				ki1.aktualny_stan(ilosc);			
			}
			else if( wybor1 == 6)
			{
				Kask ka1;
				ka1.aktualny_stan(ilosc);		
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
