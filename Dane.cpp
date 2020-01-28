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
