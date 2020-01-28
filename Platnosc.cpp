class platnosc
{
    public:
    int Realizuj(int kwota)
    {
        plac:
        string rodzaj;
        cout<<endl<<"Wybierz sposob platnosci (karta/gotowka)"<<endl;
        cout<<"Wprowadz swoj wybor: "; cin>>rodzaj;

        if(rodzaj == "karta")
        {
            Karta karta;
            karta.wykonaj(kwota);
        }
        else if(rodzaj == "gotowka")
        {
            Gotowka gotowka;
            gotowka.wykonaj(kwota);
        }
        else
        {
            cout<<"Nie ma takiego wyboru"<<endl;
            goto plac;
        }
         
        return 0;
    }

};
