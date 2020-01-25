#include <iostream>
#include <string>
using namespace std;


class Popoludniowy{};
class Nocny{};
class Calodniowy{};
class Godzinny{
  public:
  int ilosc_godzin;
};
class Dzienny{};


class Czasowy: public Dzienny, public Popoludniowy, public Nocny, public Calodniowy, public Godzinny
{
    public:
  static int dane_od;
  static int dane_do;
    
  int czas_trwania_dni(){
    //cout<<"Podaj "
  }



    int czas_trwania_godziny(int dane_od, int dane_do)
  {
      int czas;
      czas= dane_do - dane_od;
      cout<<czas;
      return czas;
  }
  
};



class Zjazdowy
{
public:
int ilosc_zjazdow;

};



class Rodzaj_karnetu: public Czasowy, public Zjazdowy
{
  public:
  void Wybierz_rodzaj_karnetu(string) //nwm na chuj na metoda, pewnie sie wyjebie
  {
    
  }
};


class Przedluz_waznosc
{
  public:
  int przedluz(int data_od)
  {
    //data od jest tez data konca karnetu
    //na stale przedluza o 6h

    //int data_ot;
    int czas = 6;
    //data_ot += czas ;
    //czas = czas + data_ot;
    cout<<"Karnet zostal przedluzony o "<<czas<< "godzin"<<endl;  //tu wypierdala blad a nie powinno
    return czas ;
    
  }
};


//Platnosc w innym pliku
class Karnet: public Rodzaj_karnetu, public Przedluz_waznosc //public Platnosc
{

public:
string data_rozp_karnetu;
string data_konca_karnetu;
void kup_karnet()
  {
  
    }

void pokaz_dane();

};



int main()
{      Karnet a;
// na potrzebne tego programu 
  cout<<"******* Wybierz jaką operacje chcesz wykonać:*********"<<endl;
  cout<<"************** 1. Kup karnet *************************"<<endl;
  cout<<"************** 2. Przedluz karnet ********************"<<endl;
  
  int wybor;
	cout<<"Wprowadz swoj wybor: "; cin>>wybor;

	switch(wybor)
	{
		case 1:  int wybor1;
            cout<< "***** Wybierz rodzaj karnetu: **********"<<endl;
            cout<<"********* 1. Czasowy ********************" <<endl;
            cout<<"********** 2. Zjazdowy ******************"<<endl;
            cout<<"Wprowadz swoj wybor: "; cin>>wybor1;
            switch(wybor1)
            {

              case 1: cout<<"******** Wybierz rodzaj karnetu czasowego:******"<<endl;
                      cout<<"******** 1. Godzinny ***************************"<<endl;
                      cout<< "************ 2.Całodniowy *********************"<<endl;
                      cout<< "************ 3. Nocny *************************"<<endl;
                      cout<< "************ 4. Popołudniowy ******************"<<endl;
                      cout<< "************ 5. Dzienny ***********************"<<endl;
                      cout<<"Wprowadz swoj wybor: "; int wybor2; cin>>wybor2;
                      
                      switch(wybor2)
                      {   // walnac wywolania funkcji
                        case 1:  Godzinny g1; break;
                        case 2:  Calodniowy c1; break;
                        case 3:  Nocny n1; break;
                        case 4:  Popoludniowy p1; break;
                        case 5:  Dzienny d1; break;
                        default: break;
                      }
                    
                    
                    break;

              case 2:  Zjazdowy z1; break;

              default: cout<<"Error 404"<<endl; break;
            }
  
          break;
		case 2: //cout<<" Od ktorej godziny chcesz przedluzyc karnet?"<<endl; int godzina;
            //cin>>godzina;
           a.przedluz(1); break;

		//case 3: a.czas_trwania_godziny(14,18); cout<<endl; break;
		default: cout<< "Error 404"<<endl; break;
	}
	

return 0 ;
}