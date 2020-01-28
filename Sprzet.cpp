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
