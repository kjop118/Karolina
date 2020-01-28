class Karta
{
    public:
    int kwota;

    int wykonaj(int kwota)
    {
        cout<<"Do zapłaty: "<<kwota<<"zl"<<endl;
        int numer,PIN;
        cout<<"Podaj numer karty."<<endl;
        cin>>numer;
        cout<<"Podaj PIN."<<endl;
        cin>>PIN;
        cout<<"Laczenie z bankiem..."<<endl;
        //sleep(1000);
        cout<<"Akceptacja."<<endl;
        return 0;
    }
};
