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
};

class Sprzet{

    public:
    //string data_rozp_wyp;
    //string data_konca_wyp;

	void pokaz_stan(Narty &obiekt1, Snowboard &obiekt2, Buty_Narciarskie &obiekt3, Buty_Snowboardowe &obiekt4, Kijki &obiekt5, Kask &obiekt6)
	{
		cout<<"********** STAN SPRZETU W WYPORZCZLNI *********"<<endl;
		cout<<"Narty: "<<obiekt1.ilosc<<" sztuk"<<endl;
		cout<<"Snowboard: "<<obiekt2.ilosc<<" sztuk"<<endl;
		cout<<"Buty Narciarskie: "<<obiekt3.ilosc<<" sztuk"<<endl;
		cout<<"Buty Snowboardowe: "<<obiekt4.ilosc<<" sztuk"<<endl;
		cout<<"Kijki: "<<obiekt5.ilosc<<" sztuk"<<endl;
		cout<<"Kaski: "<<obiekt6.ilosc<<" sztuk"<<endl;
	}

		void wypozyczenie()
		{
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
				//mozna zrobic go to do menue wyboru
			}

		}

		void oddawanie()
		{
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
				//mozna zrobic go to do menue wyboru
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
		//case 3: s1.pokaz_stan(); break;
		default: break;
	}
	


	return 0;
}