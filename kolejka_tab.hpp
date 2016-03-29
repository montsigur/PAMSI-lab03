#ifndef KOLEJKA_TAB_HPP
#define KOLEJKA_TAB_HPP
#include <iostream>
#include "EmptyQueueException.hpp"
using namespace std;


template <typename klasa>
class kolejka_tab {

protected:
  
  int dlugosc,
    indeks_poczatkowy,
    indeks_koncowy;

  klasa* tablica;
  
  virtual void powieksz() = 0;

  bool przepelniona() {

    if (indeks_koncowy == dlugosc - 1)
      return true;
    else
      return false;
  
  }
 
  
public:

  kolejka_tab() {

    dlugosc = 10;
    indeks_poczatkowy = indeks_koncowy = 0;
    tablica = new klasa[dlugosc];
  
  }

  ~kolejka_tab() {

    delete tablica;
  
  }

  void wyczysc() {

    indeks_poczatkowy = indeks_koncowy = 0;
  
  }


  void dodaj(klasa element) {
  
    if (przepelniona())
      powieksz();

    tablica[indeks_koncowy++] = element;
  
  }

  klasa usun() {

    try {

      if (pusta())
	throw EmptyQueueException();

      else
	return tablica[indeks_poczatkowy++];
    }

    catch (exception& blad) {

      cout << blad.what() << endl;

    }  
  }

  bool pusta() {

    if (indeks_poczatkowy == indeks_koncowy)
      return true;
    else
      return false;
  
  }

  int rozmiar() { return dlugosc; }

  void zawartosc() {

    try {
    
      if (pusta())
	throw EmptyQueueException();

      else
	for (int i=indeks_poczatkowy; i<indeks_koncowy; i++)
	  cout << tablica[i] << endl;
    }

    catch (exception& blad) {

      cout << blad.what() << endl;
      
    }
  }
};

#endif
