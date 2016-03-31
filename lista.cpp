// Wojciech Michałowski
// nr albumu 218705

#include "lista.hpp"
using namespace std;

lista::lista() {

  poczatek = koniec = NULL;
  
}

lista::~lista() {

  wyczysc();
  
}

bool lista::pusta() {

  if (koniec == NULL)
    return true;

  else
    return false;
  
}

void lista::wyczysc() {

  element* elem;
  
  if (!pusta()) {

    elem = koniec;
    
    while (koniec != NULL) {

      elem = koniec;
      koniec = koniec->poprzedni;
      delete elem;
      
    }
  }
}

void lista::dodaj(element* elem) {

  if (pusta())
    poczatek = koniec = elem;

  else {

    elem->poprzedni = koniec;
    koniec = elem;
    
  }
}

void lista::zawartosc() {

  element* iterator = koniec;
  
  if (pusta())
    cout << "Blad. Lista jest pusta." << endl;

  else {

    cout << "Zawartosc listy:" << endl;
    
    while (iterator != NULL) {

      cout << iterator->wartosc << endl;
      iterator = iterator->poprzedni;      
      
    }
  }
}

element* lista::sprawdz() {

  if (pusta())
    cout << "Lista jest pusta.";
  
  return koniec;
}

element* lista::zdejmij() {

  element* ostatni;

  if (pusta()) {
    
    cout << "Blad. Lista jest pusta." << endl;
    return koniec;
    
  }

  else {

    ostatni = koniec;
    koniec = koniec->poprzedni;
    ostatni->poprzedni = NULL;
    return ostatni;
    
  }
}

int lista::rozmiar() {

  element* iterator = koniec;
  int ilosc = 0;

  if (pusta())
    return 0;
  
  while(iterator != NULL) {

    ilosc++;
    iterator = iterator->poprzedni;

  }

  return ilosc;

}
