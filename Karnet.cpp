include <iostream>


class Karnet
{
    public:
    string data_rozp_karnetu;
    string data_konca_karnetu;
    int cena;
    int ilosc;
    
    void kup_karnet()
    {
        cout<<"Wybierz rodzaj karnetu"<<endl;
        cout<<"1. Karnet czasowy"<<endl;
        cout<<"2. Karnet zjazdowy"<<endl;
        
        int rodzaj;
        cin>>rodzaj;
        
        switch(rodzaj)
            case 1:
                cout<<"Wybierz rodzaj karnetu"<<endl;
                cout<<"1. Poranny w cenie 60zl"<<endl;
                cout<<"2. Popoludniowy w cenie 50zl"<<endl;
                cout<<"3. Nocny w cenie 40zl"<<endl;
                cout<<"4. Calodniowy w cenie 130zl"<<endl;
                cout<<"5. Godzinny"<<endl;
        
                int wybor;
                int cena = 0;
        
                if (wybor==1)
                {   
                    cena += 60; 
                    cout<<"Do zaplaty: "<<cena<<"zl"<<endl;
                }
                else if (wybor==2)
                {   
                    cena += 50; 
                    cout<<"Do zaplaty: "<<cena<<"zl"<<endl;
                }
                else if (wybor==3)
                {   
                    cena += 40; 
                    cout<<"Do zaplaty: "<<cena<<"zl"<<endl;
                }
                else if (wybor==4)
                {   
                    cena += 140; 
                    cout<<"Do zaplaty: "<<cena<<"zl"<<endl;
                }
                else if (wybor==5)
                {
                    cout<<"Wybierz czas"<<endl;
                    cout<<"1. 2 godzinny w cenie 30zl"<<endl;
                    cout<<"2. 4 godzinny w cenie 65zl"<<endl;
                    
                    int wybor1;
                }
                else
                {
                    cout<<"BRAK TAKIEGO KARNETU"<<endl;
                    //mozna zrobic goto do wyboru karnetu
                }
        
    
    }
    void pokaz_dane():
 };
 
 int main()
 {
    
  
    return 0;
 }
