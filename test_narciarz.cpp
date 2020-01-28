#include <gtest/gtest.h>
#include "pch.h"
#include <iostream>
using namespace std;

class Narciarz_farciarz
{
public:
	string imie;
	string nazwisko;
	string data_ur;
	string e_mail;

public:
	Narciarz_farciarz()
	{
		imie = "Krzysztof";
		nazwisko = "Krawczyk";
		data_ur = "08.09.1946";
		e_mail = "krzysztofkrawczyk@marynarz.pl";
	}
};


TEST(TestNarciarza, Narciarz_farciarz) 
{
	Narciarz_farciarz narciarz;
	ASSERT_STREQ("Krzysztof", narciarz.imie);
    ASSERT_STREQ("Krawczyk", narciarz.nazwisko);
    ASSERT_STREQ("08.09.1946", narciarz.data_ur);
    ASSERT_STREQ("krzysztofkrawczyk@marynarz.pl", narciarz.e_mail);
	
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
