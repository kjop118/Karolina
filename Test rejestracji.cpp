#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\user\Desktop\Studia\semestr III\Algorytmy i struktury danych\lab\testy1\rejestracja.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(wprowadz_dane)
		{
            Rejestracja rej1;
            string imie = "Stefan";
            string nazwisko = "Batory";
            string data = "17.06.1999";
            string email = "stefan.batory@gmail.com";
            rej1.wprowadz_dane(imie, nazwisko, data, email);
            fstream plik;
            plik.open("BD_narciarzy.txt", ios::in);

            string linia;
            int nr_linii = 1;
            int id = 0;
            string plik_email;
            string plik_imie;
            string plik_nazwisko;
            string plik_data;
            while (getline(plik, linia))
            {

                switch (nr_linii)
                {
                case 1: plik_imie = linia; break;
                case 2: plik_nazwisko = linia; break;
                case 3: plik_data = linia; break;
                case 4: plik_email = linia; break;
                case 5: break;
                }
                if (nr_linii == 5)
                {
                    nr_linii = 0;
                }
                nr_linii++;
            }
            
            
            Assert::AreEqual(imie, plik_imie);
            Assert::AreEqual(nazwisko, plik_nazwisko);
            Assert::AreEqual(data, plik_data);
            Assert::AreEqual(email, plik_email);
            plik.close();
		}
	};
}
