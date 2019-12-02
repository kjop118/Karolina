#include <iostream>
#include <string>
using namespace std;

/*
class Narciarz_farciarz{
public:
string imie;
string nazwisko;
string data_ur;
string e_mail;

};

class Karnet{
    public:
    string data_rozp_karnetu;
    string data_konca_karnetu;
    void kup_karnet();
    void pokaz_dane():
 } ;

class Sprzet{
    public:
    string jaki_sprzet;
    string data_rozp_wyp;
    string data_konca_wyp;
    void wypozyczenie();
};

class Dane{
    string sprawdzenie_danych():
 } ;

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
	int opcja;

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//goto:
	cout <<"Witamy w systemie obslugi osrodka narciarskiego!!!"<< endl;
	cout <<"*************** Wybierz kim jesteś ***************"<< endl;
	cout <<"****************** 1. Kierownik ******************"<< endl;
	cout <<"******************** 2. Kasjer *******************"<< endl;
	cout <<"************ 3. Obsluga wypozyczalni *************"<< endl;
	cout <<"****************** 4. Narciarz *******************"<< endl;
	


	cin >> opcja;
	switch (opcja) 
	{
		case 1:
			//tworzymy obiekt kierowniczka
			cout<<"************** Czy chcesz sprawdzić dane? (tak/nie) **************"<<endl;
			string decyzja;

			cin >> decyzja;

			switch(decyzja)
			{
				case 'tak':
					//funkcja ze sprawdzaniem danych
					break;
				case 'nie':
					//mozna sie cofnąc do wyboru osoby
					//np. goto:
					break;
				default:
					break;
			}

			break;		
		case 2:
			//tworzymy obiekt kasjerka

			int opcja3;
			cout<<"*************** Wybierz opcje ***************"<< endl;
			cout<<"************** 1. Sprawdz dane **************"<< endl;
			cout<<"************ 2. Obsluga karnetu ************"<< endl;

			cin>>opcja3;
			switch(opcja3)
			{
				case 1:
					//funkcja sprawdzajaca dane
					break;
				case 2:
					//funkcja zwiazana z obslugą karnetu
					break;
				default:
					break;
			}

			break;

		case 3:
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
				deafult:
					break;
			}
			
			break;
		case 4:
			//tworzymy obiekt narciarz
		
    		int opcja5;
			cout<<"*************** OSRODEK NARCIARSKI ***************"<<endl;
			cout<<"***************** Wybierz opcje ******************"<<endl;
			cout<<"**************** 1. Rejestracja ******************"<<endl;
			cout<<"***************** 2. Kup Karnet ******************"<<endl;
			cout<<"*************** 3. Przedluz karnet ***************"<<endl;
			cout<<"*************** 4. Wypozycz sprzet ***************"<<endl;
			cout<<"**************** 5. Sprawdz dane *****************"<<endl;

			cin>>opcja5;
			switch(opcja5)
			{
				case 1:
					//funkcja z rejestracją
					break;
				case 2:
					//funkcja z kupnem karnetu
					break;
				case 3:
					//funkcja z przedluzeniem karnetu
					break;
				case 4:
					//funkcja z wypozyczeniem sprzetu
					break;
				case 5:
					//funkcja zwiazana ze sprawdzaniem danych
					break;
				default:
					break;
			}
	
			break;
	
		default:
			break;
	}

	return 0:
}
