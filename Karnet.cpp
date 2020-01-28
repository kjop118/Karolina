class Karnet: public Zjazdowy, public Czasowy, public Przedluz_waznosc, public platnosc
{
    public:
    string data_rozp_karnetu;
    string data_konca_karnetu;
    string e_mail;
    string rodzaj_karnetu;
    platnosc p;
    Kasjer kasjer;

    void kup_karnet()
    {
        cout<<"Podaj e-mail: "; cin >> e_mail;
        cout<<endl<<"************ Wybierz rodzaj karnetu: **********"<<endl;
        cout<<"******************* zjazdowy ******************"<<endl;
        cout<<"******************* godzinny ******************"<<endl;
        cout<<"****************** calodniowy *****************"<<endl;
        cout<<"******************** nocny ********************"<<endl;
        cout<<"****************** popolodniowy ***************"<<endl;
        cout<<"******************** dzienny ******************"<<endl;
        cout<<"Wprowadz swoj wybor: "; cin>>rodzaj_karnetu;

        fstream plik;
        plik.open("BD_karnet.txt",ios::out | ios::app);

        if(plik.good()==false)
        {
            cout<< "Brak bazy danych"<<endl;
            exit (0);
        }

        plik<<e_mail<<endl;
        plik<<rodzaj_karnetu<<endl;
        plik<<endl;
    
        plik.close();

        if( rodzaj_karnetu == "zjazdowy")
        {
            Zjazdowy z1;
            z1.ilosc_zjazdow=10;
      
            cout<<endl<<"Karnet zjazdowy zostal zakupiony! Posiadasz: "<<z1.ilosc_zjazdow<<" zjazdów"<<endl;
            int stawka=5;
             int cena;
             cena= stawka* z1.ilosc_zjazdow;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        else if( rodzaj_karnetu == "godzinny")
        {
            cout<<endl<<"Od której godziny wykupic karnet?"<<endl;
            Godzinny g1;
            cout<<"Wprowadz swoj wybor: "; cin>>g1.dane_od;

            cout<<endl<<" Na ile godzin wykupić karnet?"<< endl;
            cout<<"Wprowadz swoj wybor: "; cin>>g1.czas;

            g1.dane_do= g1.czas + g1.dane_od;
        
            cout<<endl<<"Karnet godzinny zostal zakupiony!"<<endl;
            cout<<"Czas trwania karnetu: "<< g1.czas<<" godziny"<<endl;
            cout<<"Karnet ważny od godziny: "<<g1.dane_od<<" do godziny: "<< g1.dane_do<<endl;
        
            int stawka=10;
               int cena;
            cena= stawka* g1.czas;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        else if( rodzaj_karnetu == "calodniowy")
        {
            Calodniowy c1;
            c1.czas=12;
            c1.dane_od=9;
            c1.dane_do=21;

            cout<<endl<<"Karnet całodniowy zostal zakupiony!"<<endl;
            cout<<"Karnet ważny od godziny: "<<c1.dane_od<<" do godziny: "<<c1.dane_do<<endl;
            cout<<"Czyli ważny przez: "<<c1.czas<<" godzin."<<endl;
            
            int stawka=10;
               int cena;
               cena= stawka* c1.czas;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        else if( rodzaj_karnetu == "nocny")
        {
            cout<<endl<<"Karnet nocny zostal zakupiony!"<<endl;
            Nocny n1;
            n1.czas=2;
            n1.dane_od=21;
            n1.dane_do=23;

            cout<<"Karnet ważny od godziny : "<<n1.dane_od<<" do godziny: "<<n1.dane_do<<endl;
            cout<<"Czyli ważny przez: "<<n1.czas<<" godziny."<<endl;
            
            int stawka=10;
            int cena;
            cena= stawka* n1.czas;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        else if( rodzaj_karnetu == "popoludniowy")
        {
            cout<<endl<<"Karnet popołudniowy zostal zakupiony!"<<endl;

            Popoludniowy p1;
            p1.czas=6;
            p1.dane_od=12;
            p1.dane_do=18;

            cout<<"Karnet ważny od godziny : "<<p1.dane_od<<" do godziny: "<<p1.dane_do<<endl;
            cout<<"Czyli ważny przez: "<<p1.czas<<" godzin."<<endl;
            
            int stawka=10;
               int cena;
              cena= stawka* p1.czas;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        else if( rodzaj_karnetu == "dzienny")
        {
            cout<<endl<<"Karnet dzienny zostal zakupiony!"<<endl;
            
            Dzienny d1;
            d1.czas=9;
            d1.dane_od=9;
            d1.dane_do=18;

            cout<<endl<<"Karnet ważny od godziny : "<<d1.dane_od<<" do godziny: "<<d1.dane_do<<endl;
            cout<<"Czyli ważny przez: "<<d1.czas<<" godzin."<<endl;
            
            int stawka=10;
            int cena;
            cena= stawka* d1.czas;
            p.Realizuj(cena);
            kasjer.potwierdzenie(cena);
        }
        cout<<endl<<"            ZYCZYMY UDANJ ZABAWY !!!         "<<endl;
    }

    
    void sprawdz_karnet()
    {
          fstream plik;
          plik.open("BD_karnet.txt", ios::in );

        if(plik.good()==false)
        {
            cout<<"plik nie istnieje";
        }
        string linia;
        int nr_linii=1;
        while(getline(plik,linia))
        {
            switch(nr_linii)
            {
                case 1: e_mail= linia; cout<<e_mail<<endl;  break;
                case 2: rodzaj_karnetu=linia; cout<<rodzaj_karnetu<<endl; break;
                case 3: cout<<endl; break;
                
            }
            if(nr_linii == 3)
            {
                nr_linii = 0;
            }
            nr_linii++;
        }
        plik.close();
        cout<<endl<<"            OPERACJA ZAKONCZONA !!!         "<<endl;
    }
};
