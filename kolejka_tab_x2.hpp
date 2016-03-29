#ifndef KOLEJKA_TAB_X2_HPP
#define KOLEJKA_TAB_X2_HPP
#include "kolejka_tab.hpp"

class kolejka_tab_x2: public kolejka_tab<int>{

  void powieksz() {

    int* nowa_tab = new int[2 * dlugosc];

    for (int i=indeks_poczatkowy; i<=indeks_koncowy; i++)
      nowa_tab[i] = tablica[i];

    dlugosc *= 2;
    tablica = nowa_tab;
  
  }
};

#endif
