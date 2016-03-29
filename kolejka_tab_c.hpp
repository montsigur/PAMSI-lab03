#ifndef KOLEJKA_TAB_C_HPP
#define KOLEJKA_TAB_C_HPP
#include "kolejka_tab.hpp"

class kolejka_tab_c: public kolejka_tab<int>{

  int stala_powiekszania;
  
  void powieksz() {

    int* nowa_tab = new int[dlugosc + stala_powiekszania];

    for (int i=indeks_poczatkowy; i<=indeks_koncowy; i++)
      nowa_tab[i] = tablica[i];

    dlugosc += stala_powiekszania;
    tablica = nowa_tab;

  }

public:

  kolejka_tab_c() : kolejka_tab<int>() { stala_powiekszania = 5; }
  
};

#endif
