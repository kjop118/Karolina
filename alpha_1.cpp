#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ROZMIAR 10000

class Narciarz_farciarz
{   
    protected:
	string imie;
	string nazwisko;
	string data_ur;
	string e_mail;

    public:
	Narciarz_farciarz()
	{
		imie = "Krzysztof";
		nazwisko = "Krawczyk";
		data_ur = "08.09.1946";
		e_mail = "krzysztofkrawczyk@marynarz.pl";
	}
};

class Kasjer
{
	public:
	void potwierdzenie(int kwota)
	{
		cout<<endl<<"Potwierdzam otrzymanie platnosci na kwote "<<kwota<<" zl"<<endl;
		cout<<"Wystawianie paragonu ..."<<endl;
		cout<<"Prosze czekać ... ... ..."<<endl;
		cout<<"Paragon wydrukowany. Dziekujemy za cierpliwosc"<<endl;
	}
};

class Logowanie
{
    public:
    string e_mail;
    string imie;
    string nazwisko;


	void wprowadz_dane()
	{
        cout<<endl<<"************** OSRODEK NARCIARSKI *************"<<endl;
		cout<<"Podaj e-mail: "; cin>>e_mail;
		
	}
	
	int sprawdzanie_BD()
	{
		fstream plik;
		plik.open("BD_narciarzy.txt",ios::in);

		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}
		
		string linia;
		int nr_linii=4;
		while (getline(plik, linia))
		{   
            
           
			if(nr_linii)
			{
				if(linia==e_mail)
                {
                    cout<<endl<<"WITAJ "<<e_mail<<endl<<endl;
                    return 1;
                }
			}
			nr_linii +=5;
		}
        plik.close();
        cout<<endl<<"Nie ma takigo uzytkownika w systemie"<<endl;
        cout<<"       Wprowadź poprawne dane       "<<endl;
		Logowanie l1;
		l1.wprowadz_dane();
		l1.sprawdzanie_BD();
        return 0;
	
	}
};    

class dane
{

    string e_mail;
    string imie;
    string nazwisko;
    public:

	void wprowadz_dane()
	{
		cout<<"Podaj e-mail uzytkownika: "; cin>>e_mail;
	}

	int sprawdzanie_karnet()
	{
		fstream plik;
		plik.open("BD_karnet.txt",ios::in);

		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}
        string karnet;
		string linia;
		int nr_linii=1;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				if(linia==e_mail)
                {
                    getline(plik, linia);
                    karnet=linia;
                    goto koniec_karnet;
                }
			}
			nr_linii +=5;
		}
		cout<<endl<<"Nie ma takigo uzytkownika w systemie"<<endl;
		return 0;
		koniec_karnet:
        cout<<karnet;
        plik.close();

        return 0;

	}

	int sprawdzanie_sprzet()
	{
		fstream plik;
		plik.open("BD_sprzet_uzytkownika.txt",ios::in);

		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}
        string sprzet;
		string linia;
		int nr_linii=1;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				if(linia==e_mail)
                {
                    getline(plik, linia);
                    sprzet=linia;
                    goto koniec_sprzet;
                }
			}
			nr_linii +=5;
		}
		cout<<endl<<"Nie ma takigo uzytkownika w systemie"<<endl;
		return 0;
		koniec_sprzet:
        cout<<sprzet;
        plik.close();

        return 0;

	}

	int sprawdzenie_danych()
	{
	    cout<<endl<<"Ktore dane chcesz sprawdzic ? (sprzetowe/karnetowe)"<<endl;
			string decyzja;

			cin >> decyzja;

			if(decyzja=="sprzetowe")
			{
					wprowadz_dane();
					sprawdzanie_sprzet();
			}
			else if(decyzja=="karnetowe")
			{
				dane a;
				a.wprowadz_dane();
				a.sprawdzanie_karnet();
			}
			else
			{
                return 1;

			}
			return 0;
	}
};

class Kierownik
{
	public:
	void sprawdzam()
	{
		dane a;
		a.sprawdzenie_danych();
	}
};

class Rejestracja
{
    public:
    void wprowadz_dane(string imie, string nazwisko, string data_ur, string e_mail)
    {
        fstream plik;

        plik.open("BD_narciarzy.txt",ios::out | ios::app);

        plik<<imie<<endl;//1
        plik<<nazwisko<<endl;//2
        plik<<data_ur<<endl;//3
        plik<<e_mail<<endl;//4
        plik<<endl;//5
        plik.close();
    }
    void pokaz_dane(string mail)
    {
        fstream plik;
        plik.open("BD_narciarzy.txt",ios::in);
        if(plik.good()==false)
        {
            cout<<"blad"<<endl;
        }
        else
        {
            string imie,nazwisko,data_ur,email;
            string linia;
            int nr_linii=1;
            int id=0;
            string szukany_email;
            string szukany_imie;
            string szukany_nazwisko;
            string szukany_data_ur;

            while(getline(plik,linia))
            {

                switch(nr_linii)
                {
                    case 1: imie=linia; break;
                    case 2: nazwisko = linia;break;
                    case 3: data_ur = linia;break;
                    case 4: email= linia;break;
                    case 5: break;


                }
                if (nr_linii==5)
                {
                    nr_linii=0;
                    if(email==mail)
                    {
                        szukany_imie=imie;
                        szukany_nazwisko=nazwisko;
                        szukany_data_ur=data_ur;
                        szukany_email=email;
                    }
                }

                    nr_linii++;
            }

            plik.close();
            cout<<szukany_imie<<" "<<szukany_nazwisko<<" "<<szukany_data_ur<<" "<<szukany_email<<endl;
        }
    }
};

class platnosc
{
	public:
    int Realizuj(int kwota)
    {
		plac:
		string rodzaj;
		cout<<endl<<"Wybierz sposob platnosci (karta/gotowka)"<<endl;
		cout<<"Wprowadz swoj wybor: "; cin>>rodzaj;

        if(rodzaj == "karta")
        {
			cout<<"Do zapłaty: "<<kwota<<"zl"<<endl;
            int numer,PIN;
            cout<<"Podaj numer karty."<<endl;
            cin>>numer;
            cout<<"Podaj PIN."<<endl;
            cin>>PIN;
            cout<<"Laczenie z bankiem..."<<endl;
            //sleep(1000);
            cout<<"Akceptacja."<<endl;
        }
        else if(rodzaj == "gotowka")
        {
			cout<<"Do zapłaty: "<<kwota<<"zl"<<endl;
            cout<<"Obsluga kasy..."<<endl;
            //sleep(1000);          
        } 
		else
		{
			cout<<"Nie ma takiego wyboru"<<endl;
			goto plac;
		}
		 
		return 0;
    }   

};


/////////////////////// KLASY DLA SEKCJI KARNET ///////////

class Popoludniowy
{
    public:
    int dane_od;
    int dane_do;
    int czas;
};

class Nocny
{
    public:
     int dane_od;
     int dane_do;
     int czas;
};

class Calodniowy
{
    public:
     int dane_od;
     int dane_do;
     int czas;
};

class Godzinny
{
    public:
     int dane_od;
     int dane_do;
     int czas;
};

class Dzienny
{
    public:
     int dane_od;
     int dane_do;
     int czas;
};

class Zjazdowy
{
    public:
    int ilosc_zjazdow;
};

class Czasowy: public Dzienny, public Popoludniowy, public Nocny, public Calodniowy, public Godzinny
{
    public:
	int dane_od;
	int dane_do;

};



class Przedluz_waznosc
{
  public:
  int przedluz(int data_od)
  {
    //na stale przedluza o 6h
    int czas = 6;
    cout<<endl<<"Karnet zostal przedluzony o "<<czas<< "godzin"<<endl;  
	cout<<"            ZYCZYMY UDANJ ZABAWY !!!         "<<endl;
    return czas ;  
  }

};

class Karnet: public Zjazdowy, public Czasowy, public Przedluz_waznosc, public platnosc  
{
    public:
    string data_rozp_karnetu;
    string data_konca_karnetu;
    string e_mail;
    string rodzaj_karnetu;
	platnosc p;
	Kasjer kasjer;

    void kup_karnet()
    {
        cout<<"Podaj e-mail: "; cin >> e_mail;
        cout<<endl<<"************ Wybierz rodzaj karnetu: **********"<<endl;
		cout<<"******************* zjazdowy ******************"<<endl;
		cout<<"******************* godzinny ******************"<<endl;
		cout<<"****************** calodniowy *****************"<<endl;
		cout<<"******************** nocny ********************"<<endl;
		cout<<"****************** popolodniowy ***************"<<endl;
		cout<<"******************** dzienny ******************"<<endl;
        cout<<"Wprowadz swoj wybor: "; cin>>rodzaj_karnetu; 

        fstream plik;
		plik.open("BD_karnet.txt",ios::out | ios::app); 

		if(plik.good()==false)
		{
			cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		plik<<e_mail<<endl;
		plik<<rodzaj_karnetu<<endl;
		plik<<endl;
    
        plik.close();

		if( rodzaj_karnetu == "zjazdowy")
		{ 
            Zjazdowy z1;
            z1.ilosc_zjazdow=10;
      
            cout<<endl<<"Karnet zjazdowy zostal zakupiony! Posiadasz: "<<z1.ilosc_zjazdow<<" zjazdów"<<endl;
			int stawka=5;
     		int cena;
     		cena= stawka* z1.ilosc_zjazdow;
			p.Realizuj(cena);
			kasjer.potwierdzenie(cena);	
		}
        else if( rodzaj_karnetu == "godzinny")
		{
            cout<<endl<<"Od której godziny wykupic karnet?"<<endl;
            Godzinny g1;
            cout<<"Wprowadz swoj wybor: "; cin>>g1.dane_od;

			cout<<endl<<" Na ile godzin wykupić karnet?"<< endl;
            cout<<"Wprowadz swoj wybor: "; cin>>g1.czas;

            g1.dane_do= g1.czas + g1.dane_od;
        
            cout<<endl<<"Karnet godzinny zostal zakupiony!"<<endl;
            cout<<"Czas trwania karnetu: "<< g1.czas<<" godziny"<<endl;
            cout<<"Karnet ważny od godziny: "<<g1.dane_od<<" do godziny: "<< g1.dane_do<<endl;
		
			int stawka=10;
       		int cena;
    		cena= stawka* g1.czas;
    	    p.Realizuj(cena);
			kasjer.potwierdzenie(cena);
        }
		else if( rodzaj_karnetu == "calodniowy")
		{
            Calodniowy c1;	
            c1.czas=12;
            c1.dane_od=9;
            c1.dane_do=21;

            cout<<endl<<"Karnet całodniowy zostal zakupiony!"<<endl;
            cout<<"Karnet ważny od godziny: "<<c1.dane_od<<" do godziny: "<<c1.dane_do<<endl; 
            cout<<"Czyli ważny przez: "<<c1.czas<<" godzin."<<endl;
			
			int stawka=10;
      	 	int cena;
       		cena= stawka* c1.czas;
			p.Realizuj(cena);
			kasjer.potwierdzenie(cena);
		}
		else if( rodzaj_karnetu == "nocny")
		{
            cout<<endl<<"Karnet nocny zostal zakupiony!"<<endl;
            Nocny n1;
            n1.czas=2;
            n1.dane_od=21;
            n1.dane_do=23;

            cout<<"Karnet ważny od godziny : "<<n1.dane_od<<" do godziny: "<<n1.dane_do<<endl; 
            cout<<"Czyli ważny przez: "<<n1.czas<<" godziny."<<endl;
			
			int stawka=10;
        	int cena;
        	cena= stawka* n1.czas;
        	p.Realizuj(cena);
			kasjer.potwierdzenie(cena);
		}
		else if( rodzaj_karnetu == "popoludniowy")
		{
			cout<<endl<<"Karnet popołudniowy zostal zakupiony!"<<endl;

            Popoludniowy p1;
        	p1.czas=6;
            p1.dane_od=12;
            p1.dane_do=18;

            cout<<"Karnet ważny od godziny : "<<p1.dane_od<<" do godziny: "<<p1.dane_do<<endl; 
            cout<<"Czyli ważny przez: "<<p1.czas<<" godzin."<<endl;
			
			int stawka=10;
       		int cena;
      		cena= stawka* p1.czas;
			p.Realizuj(cena);
			kasjer.potwierdzenie(cena);
		}
		else if( rodzaj_karnetu == "dzienny")
		{
			cout<<endl<<"Karnet dzienny zostal zakupiony!"<<endl;
            
            Dzienny d1;	
            d1.czas=9;
            d1.dane_od=9;
            d1.dane_do=18;

            cout<<endl<<"Karnet ważny od godziny : "<<d1.dane_od<<" do godziny: "<<d1.dane_do<<endl; 
            cout<<"Czyli ważny przez: "<<d1.czas<<" godzin."<<endl;
			
			int stawka=10;
        	int cena;
        	cena= stawka* d1.czas;
			p.Realizuj(cena);
			kasjer.potwierdzenie(cena);
		}
		cout<<endl<<"            ZYCZYMY UDANJ ZABAWY !!!         "<<endl;
    }

	
    void sprawdz_karnet()
	{
		/*
		string tab_mail[ROZMIAR];
		string tab_sprzet[ROZMIAR], tab[ROZMIAR];
		int i = 0;
		string email, sprzet, pusto;
		

		fstream plik;
		plik.open("BD_karnet.txt", ios::in );
		if (!plik.good())
		{
			cout << "Blad pliku!" << endl;
			return 0;
		}
		else 
		{
			while (!plik.eof()) 
			{
			plik >> email >> sprzet >> pusto;
			email = tab_mail[i];
			sprzet = tab_sprzet[i];
			pusto = tab[i];
			//tab_mail[i] = email;	cout<<tab_mail<<endl;
			//tab_sprzet[i] = sprzet;		cout<<tab_sprzet<<endl;	
			i++;	
			cout<<email<<endl;
			cout<<sprzet<<endl;	
			//cout<<pusto<<endl;
			}
			return 0;
		}
		plik.close();
		*/
		
  		fstream plik;
  		plik.open("BD_karnet.txt", ios::in );

		if(plik.good()==false)
		{
			cout<<"plik nie istnieje";
		}
		string linia;
		int nr_linii=1;
		while(getline(plik,linia))
		{
			switch(nr_linii)
			{
				case 1: e_mail= linia; cout<<e_mail<<endl;  break;
				case 2: rodzaj_karnetu=linia; cout<<rodzaj_karnetu<<endl; break;
				case 3: cout<<endl; break;
				
			}
			if(nr_linii == 3)
			{
				nr_linii = 0;
			}
			nr_linii++; 
		}
		plik.close(); 
		cout<<endl<<"            OPERACJA ZAKONCZONA !!!         "<<endl;
	} 
};



////////// WYPOZYCZANIE SPRZETU ///////////

class Buty_Narciarskie
{	
	public:
	int cena;
	int ilosc;
	int tab[6];

    Buty_Narciarskie()
    {
        cena = 20;
    }

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
	public:
	int cena;
	int ilosc;
	int tab[6];

    Narty()
    {
        cena = 30;
    }

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
	public:
	int cena;
	int ilosc;
	int tab[6];

    Snowboard()
    {
        cena = 30;
    }

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
	public:
	int cena;
	int ilosc;
	int tab[6];

    Kijki()
    {
        cena = 10;
    }

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
	public:
	int cena;
	int ilosc;
	int tab[6];
	
    Buty_Snowboardowe()
    {
        cena = 30;
    }

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
	public:
	int cena;
	int ilosc;
	int tab[6];

    Kask()
    {
        cena = 10;
    }

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
			cout<<"Brak kaskow w magazynie"<<endl;
			
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

class Sprzet
{
    public:
	Narty n1;
	Snowboard s1;
	Buty_Narciarskie bn1;
	Buty_Snowboardowe bs1;
	Kijki ki1;
	Kask ka1;
	platnosc p;
	Kasjer kasjer;

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

		cout<<endl<<"********** STAN SPRZETU W WYPOZYCZALNI *********"<<endl;
		cout<<"Narty: "<<tab[0]<<" egzemplarzy"<<endl;
		cout<<"Snowboard: "<<tab[1]<<" egzemplarzy"<<endl;
		cout<<"Buty Narciarskie: "<<tab[2]<<" egzemplarzy"<<endl;
		cout<<"Buty Snowboardowe: "<<tab[3]<<" egzemplarzy"<<endl;
		cout<<"Kijki: "<<tab[4]<<" egzemplarzy"<<endl;
		cout<<"Kaski: "<<tab[5]<<" egzemplarzy"<<endl;

	
	}

		void wypozyczenie()
		{   
            string mail;
            fstream plik;

            cout<<endl<<"Podaj email: "; cin>>mail;
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

                string narty = "Narty";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<narty<<endl;
                plik.close();
			
				//realizacja platnosci
				p.Realizuj(n1.cena);
				kasjer.potwierdzenie(n1.cena);

			}
			else if( wybor1 == 2)
			{
				s1.aktualny_stan(i);	

                string snowboard = "Snowboard";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<snowboard<<endl;
                plik.close();

				p.Realizuj(s1.cena);
				kasjer.potwierdzenie(s1.cena);	
			}
			else if( wybor1 == 3)
			{
				bn1.aktualny_stan(i);

                string buty1 = "Buty Narciarskie";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<buty1<<endl;
                plik.close();	

				p.Realizuj(bn1.cena);
				kasjer.potwierdzenie(bn1.cena);		
			}
			else if( wybor1 == 4)
			{
				bs1.aktualny_stan(i);	

                string buty2 = "Buty Snowboardowe";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<buty2<<endl;
                plik.close();	

				p.Realizuj(bs1.cena);
				kasjer.potwierdzenie(bs1.cena);
			}
			else if( wybor1 == 5)
			{
				ki1.aktualny_stan(i);	

                string kijki = "Kijki";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<kijki<<endl;
                plik.close();	

				p.Realizuj(ki1.cena);
				kasjer.potwierdzenie(ki1.cena);
			}
			else if( wybor1 == 6)
			{
				ka1.aktualny_stan(i);

                string kask = "Kask";
                plik.open("BD_sprzet_uzytkownika.txt",ios::out | ios::app);
			    plik<<mail<<endl;
			    plik<<kask<<endl;
                plik.close();	

				p.Realizuj(ka1.cena);
				kasjer.potwierdzenie(ka1.cena);	
			}
			else
			{
				cout<<"Nie ma takiej opcji !!!"<<endl;
				goto wypozycz;
			}
			cout<<endl<<"            ZYCZYMY UDANJ ZABAWY !!!         "<<endl;

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
			cout<<endl<<"            DZIEKUJEMY. DO ZOBACZENIA !!!         "<<endl;
		}		
};


class Obsluga_wypozyczalni
{
	public:
	void wypozycz()
	{
		cout<<endl<<"Komu chcesz wypozyczyc sprzet"<<endl;
		Sprzet sprzet;
		sprzet.wypozyczenie();
	}
    
};

//////////////// GLOWNY PROGRAM ////////////////

int main()
{
    poczatek:
	cout <<endl<<"Witamy w systemie obslugi osrodka narciarskiego!!!"<< endl;
	cout <<"*************** Wybierz kim jesteś ***************"<< endl;
	cout <<"****************** 1. Kierownik ******************"<< endl;
	cout <<"******************** 2. Kasjer *******************"<< endl;
	cout <<"************ 3. Obsluga wypozyczalni *************"<< endl;
	cout <<"****************** 4. Narciarz *******************"<< endl;

    Karnet a;
	Sprzet s1;

	int opcja;
	cout<<"Wprowadz swoj wybor: "; cin >> opcja;
	switch (opcja)
	{
		case 1:
		{
            Kierownik kierownik;
			kierownik.sprawdzam();
			cout<<endl<<"            DANE SPRAWDZONE. CZAS NA PRZERWE !!!         "<<endl;
		}
		    break;
		case 2:
		{
            Kasjer k1;
            wybierz:
			int opcja3;
			cout<<endl<<"*************** Wybierz opcje ***************"<< endl;
			cout<<"************** 1. Sprawdz dane **************"<< endl;
			cout<<"************ 2. Obsluga karnetu ************"<< endl;

			cout<<"Wprowadz swoj wybor: "; cin>>opcja3;
			switch(opcja3)
			{
				case 1:
				{
					dane a;
					if(a.sprawdzenie_danych()) goto poczatek;
		    	}
					break;
				case 2: cout<<endl; a.sprawdz_karnet(); break;
				default: goto wybierz; break;
			}
		    }
			break;

		case 3:
		{   
			Obsluga_wypozyczalni ow;
            wybierz1:
			cout<<endl<<"***************** Wybierz opcje ******************"<<endl;
			cout<<"************ 1. Wypozyczenie sprzetu *************"<<endl;
			cout<<"******** 2. Stan sprzetu w wypozyczalnii *********"<<endl;

			int opcja4;
			cout<<"Wprowadz swoj wybor: "; cin>>opcja4;
				
				switch(opcja4)
				{	
					case 1:
						ow.wypozycz();
						break;
					case 2:
						s1.pokaz_stan();
						break;
					default: goto wybierz1; break;
				}
		}
			break;
		case 4:
		{
    		Narciarz_farciarz n;
            wybierz2:
			cout<<endl<<"*************** OSRODEK NARCIARSKI ***************"<<endl;
			cout<<"***************** Wybierz opcje ******************"<<endl;
			cout<<"***************** 1. Logowanie *******************"<<endl;
			cout<<"***************** 2. Rejestracja *****************"<<endl;

			int opcja5;
			cout<<"Wprowadz swoj wybor: "; cin>>opcja5;

			switch(opcja5)
			{
				case 1:
				{
					Logowanie logowanie;
					logowanie.wprowadz_dane();
					logowanie.sprawdzanie_BD();
				}
					break;
				case 2:
				{
					Rejestracja rejestracja;
					string imie,nazwisko,email,data;
					cout<<"Wprowadz imie: "; cin>>imie;
					cout<<"Wprowadz nazwisko: ";cin>>nazwisko;
					cout<<"Wprowadz email: ";cin>>email;
					cout<<"Wprowadz swoja date urodzenia: ";cin>>data;
					rejestracja.wprowadz_dane(imie,nazwisko,data,email);
				}
					break;
				default: goto wybierz2; break;
			}

	  		cout<<endl<<"**************** OSRODEK NARCIARSKI ***************"<<endl;
			cout<<"****************** 1. Kup Karnet ******************"<<endl;
			cout<<"**************** 2. Przedluz karnet ***************"<<endl;
			cout<<"**************** 3. Wypozycz sprzet ***************"<<endl;
			cout<<"***************** 4. Sprawdz dane *****************"<<endl;
			
			int opcja6;
			cout<<"Wprowadz swoj wybor: "; cin>>opcja6;

			switch(opcja6)
			{  
				case 1: a.kup_karnet(); break;
				case 2: a.przedluz(1); break;
				case 3:
				{
                    wybierz3:
					cout<<endl<<"***************** WYBIERZ OPCJE *****************"<<endl;
					cout<<"************** 1. Wypozycz sprzet ***************"<<endl;
					cout<<"*************** 2. Zwrot sprzetu ****************"<<endl;
					cout<<"***************** 3. Pokaz stan *****************"<<endl;

					int wybor;
					cout<<"Wprowadz swoj wybor: "; cin>>wybor;

                    if(wybor == 1)
                    {
                        s1.wypozyczenie();
                    }
					else if(wybor==2)
                    {
                        s1.oddawanie();
                    }
                    else if(wybor==3)
                    {
                        s1.pokaz_stan();
                    }
                    else
                    {
                        return 0;
                    }
				}
					break;	
				case 4:
				{
					Rejestracja rejestracja;
					string mail;
					cout<<"Podaj swoj email: "; cin>>mail;
					rejestracja.pokaz_dane(mail);
				}
					break;
				
				default: goto wybierz3; break;
            }
		}
            break;

		default: goto poczatek; break;
	}

	return 0;
}