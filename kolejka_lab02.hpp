// Wojciech Michałowski
// nr albumu 218705

#ifndef KOLEJKA_LAB02_HPP
#define KOLEJKA_LAB02_HPP
#include "element.hpp"

class kolejka_lab02 {

public:

  kolejka_lab02();

  ~kolejka_lab02();

  void dodaj(element* elem);

  element* sprawdz();

  element* zdejmij();

  bool pusta();

  void wyczysc();

  int rozmiar();

  // bool zawiera_wartosc(string wartosc);

  void zawartosc();
  
private:

  element* poczatek;
  element* koniec;
};

#endif
