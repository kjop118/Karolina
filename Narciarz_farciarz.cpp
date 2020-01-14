#include <string>
#include <iostream>
using namespace std;


class Narciarz_farciarz
{
	public:
	string imie;
	string nazwisko;
	string data_ur;
	string e_mail;

    Narciarz_farciarz()
    {
        imie = "Jan";
        nazwisko = "Kowalski";
        data_ur = "01.01.2001";
        e_mail = "jankowalski01@email.com";
    }
    
    void wyswietl()
    {
        cout<<imie<<endl<<nazwisko<<endl<<data_ur<<endl<<e_mail<<endl;
    }
    ~Narciarz_farciarz(){}
};

int main()
{
    
    Narciarz_farciarz narciarz;

    return 0;
}
