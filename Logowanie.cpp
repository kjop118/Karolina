class Logowanie
{
    public:
    string e_mail;
    string imie;
    string nazwisko;


    string wprowadz_dane()
    {
        cout<<endl<<"************** OSRODEK NARCIARSKI *************"<<endl;
        cout<<"Podaj e-mail: "; cin>>e_mail;
        return e_mail;
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
        cout<<"       Wprowadź poprawne dane       "<<endl;
        Logowanie l1;
        l1.wprowadz_dane();
        l1.sprawdzanie_BD();
        return 0;
    
    }
};
