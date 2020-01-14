
#include <iostream>
using namespace std;

class Czasowy: public Dzienny, public Popoludniowy, public Nocny, public Calodniowy, public Godzinny
{
    public:
  int dane_od;
  int dane_do;
};

class Dzienny{};
class Popoludniowy{};
class Nocny{};
class Calodniowy{};
class Godzinny{};
