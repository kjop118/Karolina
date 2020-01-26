#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;


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
    cout<<"Karnet zostal przedluzony o "<<czas<< "godzin/zjazdow"<<endl;  
    return czas ;
  }

};


class Karnet: public Zjazdowy, public Czasowy, public Przedluz_waznosc  //public Platnosc bo jest w innym pliku
{
  public:
  string data_rozp_karnetu;
  string data_konca_karnetu;
  string e_mail;
string rodzaj_karnetu;
  void kup_karnet()
  {
    cout<<"Wpisz e-mail i wybierz rodzaj karnetu."<<endl;
    cout<<"Dostępna oferta karnetów: "<< endl;
    cout<< "zjazdowy, godzinny, calodniowy, nocny, popoludniowy, dzienny" << endl;

    cout<<"Podaj e-mail: "; cin >> e_mail;
    cout<<"Wpisz rodzaj karnetu: "; cin>> rodzaj_karnetu; 


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


 
        
	
	// potw wyboru
			if( rodzaj_karnetu == "zjazdowy")
			{ 
      Zjazdowy z1;
      z1.ilosc_zjazdow=10;
      cout<<" Karnet zjazdowy zostal zakupiony! Posiadasz: "<<z1.ilosc_zjazdow<<" zjazdów"<<endl;
      int stawka=5;
        int cena;
        cena= stawka* z1.ilosc_zjazdow;
        cout<<"Do zaplacenia  "<<cena<<endl;
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
        int stawka=10;
        int cena;
        cena= stawka* g1.czas;
        cout<<"Do zaplacenia  "<<cena<<endl;
        
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
        int stawka=10;
        int cena;
        cena= stawka* c1.czas;
        cout<<"Do zaplacenia  "<<cena<<endl;
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
        int stawka=10;
        int cena;
        cena= stawka* n1.czas;
        cout<<"Do zaplacenia"<<cena<<endl;
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
        
        int stawka=10;
        int cena;
        cena= stawka* p1.czas;
        cout<<"Do zaplacenia"<<cena<<endl;
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
        int stawka=10;
        int cena;
        cena= stawka* d1.czas;
        cout<<"Do zaplacenia"<<cena<<endl;

			}

  }

void pokaz_dane(); //z innego pliku

};


int main()
{      
// na potrzebne tego programu 
  cout<<"******* Wybierz jaką operacje chcesz wykonać:*********"<<endl;
  cout<<"************** 1. Kup karnet *************************"<<endl;
  cout<<"************** 2. Przedluz karnet ********************"<<endl;
  
  int wybor;
	cout<<"Wprowadz swoj wybor: "; cin>>wybor;
Karnet a;

	switch(wybor)
	{
		case 1:  
            a.kup_karnet();
            break;

		case 2:     
                
               a.przedluz(1); 
               break;

		default: ;
  }
	

return 0 ;
}
