#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;


class Logowanie
{
    public:
    string e_mail;
    string imie;
    string nazwisko;

	void wprowadz_dane()
	{
        cout<<endl<<"****** OSRODEK NARCIARSKI ******"<<endl;
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
        //cout<<"       Wprowadź poprawne dane       "<<endl;
        return 0;
	
	}
};    
	

int main()
{


    Logowanie narciarz1;
    narciarz1.wprowadz_dane();
    narciarz1.sprawdzanie_BD();

    return 0;
}
