#ifndef KOLEJKA_TAB_C_HPP
#define KOLEJKA_TAB_C_HPP
#include "kolejka_tab.hpp"

class kolejka_tab_c: public kolejka_tab<int>{

  int stala_powiekszania;
  
  void powieksz() {

    dlugosc += stala_powiekszania;
    int* nowa_tab = new int[dlugosc];

    for (int i=indeks_poczatkowy; i<=indeks_koncowy; i++)
      nowa_tab[i] = tablica[i];

    delete tablica;
    tablica = nowa_tab;

  }

public:

  kolejka_tab_c() : kolejka_tab<int>() { stala_powiekszania = 1000; }
  
};

#endif
