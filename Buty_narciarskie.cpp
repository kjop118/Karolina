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
