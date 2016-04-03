#ifndef KOLEJKA_TAB_X2_HPP
#define KOLEJKA_TAB_X2_HPP
#include "kolejka_tab.hpp"

class kolejka_tab_x2: public kolejka_tab<int>{

  void powieksz() {

    dlugosc *= 2;
    int* nowa_tab = new int[dlugosc];

    for (int i=indeks_poczatkowy; i<=indeks_koncowy; i++)
      nowa_tab[i] = tablica[i];

    delete tablica;
    tablica = nowa_tab;
  
  }
};

#endif
