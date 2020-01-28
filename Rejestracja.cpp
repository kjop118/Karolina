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
