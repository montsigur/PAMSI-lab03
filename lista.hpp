// Wojciech Michałowski
// nr albumu 218705

#ifndef LISTA_HPP
#define LISTA_HPP
#include "element.hpp"

class lista {

public:

  lista();

  ~lista();

  void dodaj(element* elem);

  element* sprawdz();

  element* zdejmij();

  bool pusta();

  void wyczysc();

  int rozmiar();

  void zawartosc();

private:

  element* poczatek;
  element* koniec;
};

#endif
