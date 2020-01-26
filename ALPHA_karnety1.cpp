#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;


class Narciarz_farciarz
{
	protected:

	string imie;
	string nazwisko;
	string data_ur;
	string e_mail;
};

class Logowanie{
    string e_mail;
    string imie;
    string nazwisko;
    public:
	void wprowadz_dane()
	{
		cout<<"Podaj e-mail: "; cin>>e_mail;
		cout<<"Podaj imie: "; cin>>imie ;
		cout<<"Podaj nazwisko: "; cin>>nazwisko ;
	}

	void sprawdzanie_BD()
	{
	//otwarcie pliku, sprawdzanie maila
		fstream plik;
		plik.open("BD_narciarzy.txt",ios::in);
		if(plik.good()==false)
		{
		cout<< "Brak bazy danych"<<endl;
			exit (0);
		}

		string linia;
		int nr_linii=1;
		while (getline(plik, linia))
		{
			if(nr_linii)
			{
				//if()
					//sprawdzanie lini 1, potem przeskakuje o 5 lini,
					//znow sprawdza az ta linia nie jest pusta

				 //ID=atoi(linia.c_str()); break;
				//case 2: imie= linia; break;
				//case 3: nazwisko= linia; break;

			}

			nr_linii +=5;

		}
	plik.close();
	}


};

class dane
{

    string e_mail;
    string imie;
    string nazwisko;
    public:
    void dane_karnet()
    {


    }
	void wprowadz_dane()
	{

		cout<<"Podaj e-mail: "; cin>>e_mail;

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

        //cout<<"       Wprowadź poprawne dane       "<<endl;
        return 0;

	}

	int sprawdzanie_sprzet()
	{
		fstream plik;
		plik.open("BD_sprzet.txt",ios::in);

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

        //cout<<"       Wprowadź poprawne dane       "<<endl;
        return 0;

	}

	int sprawdzenie_danych()
	{
	    cout<<"**************  Ktore dane chcesz sprawdzic ? (sprzetowe/karnetowe) **************"<<endl;
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
        
    
        int czas_trwania_godziny(int dane_od, int dane_do)
         {
            int czas;
             czas= dane_do - dane_od;
             cout<<czas;
            return czas;
        }
  
    };

class Rodzaj_karnetu: public Zjazdowy, public Czasowy 
{
    public:
    string rodzaj_karnetu;
};


class Przedluz_waznosc
{
  public:
  int przedluz(int data_od)
  {
    //na stale przedluza o 6h
    int czas = 6;
    cout<<"Karnet zostal przedluzony o "<<czas<< "godzin"<<endl;  //tu wypierdala blad a nie powinno
    return czas ;
    
  }
};


class Karnet: public Rodzaj_karnetu, public Przedluz_waznosc  //public Platnosc bo jest w innym pliku
{
  public:
  string data_rozp_karnetu;
  string data_konca_karnetu;
  string e_mail;

  void kup_karnet()
  {
        cout<<"Wpisz e-mail i wybierz rodzaj karnetu czasowego:"<<endl;
        cout<<"Dostępna oferta karnetów: "<< endl;
        cout << "Godzinny,Całodniowy, Nocny, Popołudniowy, Dzienny" << endl;

        cout<<"Podaj e-mail: "; cin >> e_mail;
        cout<<"Wpisz rodzaj karnetu"; cin>> rodzaj_karnetu; 

//zapis do pliku
        fstream plik;
		plik.open("BD_karnet.txt",ios::out); 

		  if(plik.good()==false)
		  {
		  cout<< "Brak bazy danych"<<endl;
			exit (0);
		  }
         plik<<e_mail<<endl;
        plik<<rodzaj_karnetu<<endl;
    
        plik.close();

        //WYSWIETLA POWIERDZENIE O ZAKUPIE/UTWORZENIU OBIEKTU

// potw wyboru
			if( rodzaj_karnetu == "zjazdowy")
			{ 
      Zjazdowy z1;
      z1.ilosc_zjazdow=10;
      cout<<" Karnet zjazdowy zostal zakupiony! Posiadasz: "<<z1.ilosc_zjazdow<<" zjazdów"<<endl;
			}

			else if( rodzaj_karnetu == "godzinny")
			{ cout<<"Od której godziny wykupic karnet?"<<endl;
        Godzinny g1;
        cin>>g1.dane_od;
				cout<<" Na ile godzin wykupić karnet?"<< endl;
        cin>>g1.czas;
        g1.dane_do= g1.czas + g1.dane_od;
        
        cout<<" Karnet godzinny zostal zakupiony!"<<endl;
        cout<<"Czas trwania karnetu: "<< g1.czas<<" godziny"<<endl;
        cout<<"Karnet ważny od godziny: "<<g1.dane_od<<" do godziny: "<< g1.dane_do<<endl;
        
			}
			else if( rodzaj_karnetu == "calodniowy")
			{
        Calodniowy c1;	
        c1.czas=12;
        c1.dane_od=9;
        c1.dane_do=21;
        cout<<" Karnet całodniowy zostal zakupiony!"<<endl;
        cout<<"Karnet ważny od godziny : "<<c1.dane_od<<" do godziny: "<<c1.dane_do<<endl; 
        cout<<"Czyli ważny przez: "<<c1.czas<<" godzin."<<endl;
			}
			else if( rodzaj_karnetu == "nocny")
			{
        cout<<" Karnet nocny zostal zakupiony!"<<endl;
        Nocny n1;
        n1.czas=2;
        n1.dane_od=21;
        n1.dane_do=23;
        cout<<"Karnet ważny od godziny : "<<n1.dane_od<<" do godziny: "<<n1.dane_do<<endl; 
        cout<<"Czyli ważny przez: "<<n1.czas<<" godziny."<<endl;
			}
			else if( rodzaj_karnetu == "popoludniowy")
			{
				cout<<" Karnet popołudniowy zostal zakupiony!"<<endl;
        Popoludniowy p1;
        		p1.czas=6;
        p1.dane_od=12;
        p1.dane_do=18;
        cout<<"Karnet ważny od godziny : "<<p1.dane_od<<" do godziny: "<<p1.dane_do<<endl; 
        cout<<"Czyli ważny przez: "<<p1.czas<<" godzin."<<endl;
			}
			else if( rodzaj_karnetu == "dzienny")
			{
				cout<<" Karnet dzienny zostal zakupiony!"<<endl;
        Dzienny d1;	
        d1.czas=9;
        d1.dane_od=9;
        d1.dane_do=18;
        cout<<"Karnet ważny od godziny : "<<d1.dane_od<<" do godziny: "<<d1.dane_do<<endl; 
        cout<<"Czyli ważny przez: "<<d1.czas<<" godzin."<<endl;
			}

  }

  void pokaz_dane(){}; //z innego pliku

};



/*
class Karnet{
    public:
    string data_rozp_karnetu;
    string data_konca_karnetu;
    void kup_karnet();
    void pokaz_dane():
 };
class Sprzet{
    public:
    string jaki_sprzet;
    string data_rozp_wyp;
    string data_konca_wyp;
    void wypozyczenie();
};
class Dane{
    string sprawdzenie_danych():
 };
class Rejestracja{
    public:
    void wprowadz_dane(string imie, string nazwisko, string data_ur, string e_mail){
            string imie, nazwisko, data_ur, e_mail;
            cout<<"rejestracja uzytkownika : "<<imie<<endl;
             }
    };
*/








int main()
{
    poczatek:
	int opcja;
	int opcja6;

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//goto:
	cout <<"Witamy w systemie obslugi osrodka narciarskiego!!!"<< endl;
	cout <<"*************** Wybierz kim jesteś ***************"<< endl;
	cout <<"****************** 1. Kierownik ******************"<< endl;
	cout <<"****************** 2. Kasjer *********************"<< endl;
	cout <<"************ 3. Obsluga wypozyczalni *************"<< endl;
	cout <<"****************** 4. Narciarz *******************"<< endl;

    // musi byc tu bo wywali program
    Karnet a;

	cin >> opcja;
	switch (opcja)
	{
		case 1:
		    {


                        dane a;
					    if(a.sprawdzenie_danych())goto poczatek;
		    }
		    break;

			//break;
		case 2:
		    {


			//tworzymy obiekt kasjerka

			int opcja3;
			cout<<"*************** Wybierz opcje ***************"<< endl;
			cout<<"************** 1. Sprawdz dane **************"<< endl;
			cout<<"************ 2. Obsluga karnetu ************"<< endl;

			cin>>opcja3;
			switch(opcja3)
			{
				case 1:
					{
					    dane a;
					    if(a.sprawdzenie_danych())goto poczatek;
		    }

					break;
				case 2:
					//funkcja zwiazana z obslugą karnetu
					break;
				default:
					break;
			}
		    }
			break;

		case 3:
		    {


			//tworzymy obiekt obsluga wypozyczalni
			cout<<"***************** Wybierz opcje ******************"<<endl;
			cout<<"************ 1. Wypozyczenie sprzetu *************"<<endl;
			cout<<"******** 2. Stan sprzetu w wypozyczalnii *********"<<endl;

			int opcja4;
			cin>>opcja4;
			switch(opcja4)
			{
				case 1:
					//funkcja zwiazana z wypozyczeniem sprzetu
					break;
				case 2:
					//funkcja zwiazana z wyswietleniem stanu sprzetu
					break;
				default:
					break;
			}
		    }
			break;
		case 4:
			//tworzymy obiekt narciarz
		    {



    		int opcja5;
			cout<<"*************** OSRODEK NARCIARSKI ***************"<<endl;
			cout<<"***************** Wybierz opcje ******************"<<endl;
			cout<<"***************** 1. Logowanie *******************"<<endl;
			cout<<"***************** 2. Rejestracja *****************"<<endl;
			cin>>opcja5;
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
				        cin>>imie;
				        cin>>nazwisko;
				        cin>>email;
				        cin>>data;
				        rejestracja.wprowadz_dane(imie,nazwisko,data,email);
				    }

					break;
				default:
                    break;


			}
			}

			cout<<"****************1. Kup Karnet ********************"<<endl;
			cout<<"****************2. Przedluz karnet ***************"<<endl;
			cout<<"****************3. Wypozycz sprzet ***************"<<endl;
			cout<<"****************4. Sprawdz dane ******************"<<endl;

			//zapis do osobnego pliku narciarzy, sprawdzanie potem czy narciarz istnieje w pliku
			//odczyt z pliku
            
            
			cin>>opcja6;
			switch(opcja6)
			{  
				case 1:   {
                //funkcja z kupnem karnetu
                         
                              a.kup_karnet();
                        }  

					break;

				case 2:{
					    //funkcja z przedluzeniem karnetu
                    
                     a.przedluz(1); 

                }
					break;
				case 3:
					//funkcja z wypozyczeniem sprzetu
					break;
				case 4:
					{
					    Rejestracja rejestracja;
					    string mail;
					    cout<<"podaj swoj mail"<<endl;
					    cin>>mail;
					    rejestracja.pokaz_dane(mail);
					}

					break;

				default:
					break;
			}

			break;
	}





	return 0;
}
