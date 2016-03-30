// Wojciech Michałowski
// nr albumu 218705

#include "kolejka_lab02.hpp"
using namespace std;

kolejka_lab02::kolejka_lab02() {

  poczatek = koniec = NULL;
  
}

kolejka_lab02::~kolejka_lab02() {

  wyczysc();
  
}

bool kolejka_lab02::pusta() {

  if (poczatek == NULL)
    return true;

  else
    return false;
  
}

void kolejka_lab02::wyczysc() {

  element* elem;
  
  if (!pusta()) {

    elem = poczatek;
    
    while (poczatek != NULL) {

      elem = poczatek;
      poczatek = poczatek->nastepny;
      delete elem;
      
    }
  }
}

void kolejka_lab02::dodaj(element* elem) {

  if (pusta()) {

    poczatek = elem;
    koniec = elem;
    
  }
  
  else {

    koniec->nastepny = elem;
    koniec = elem;
    
  }
}

void kolejka_lab02::zawartosc() {

  element* iterator = poczatek;
  
  if (pusta())
    cout << "Blad. Kolejka jest pusta." << endl;

  else {

    cout << "Zawartosc kolejki:" << endl;
    
    while (iterator != NULL) {

      cout << iterator->wartosc << endl;
      iterator = iterator->nastepny;      
      
    }
  }
}

element* kolejka_lab02::sprawdz() {

  if (pusta())
    cout << "Kolejka jest pusta." << endl;

  return poczatek;
    
}

element* kolejka_lab02::zdejmij() {

  element* pierwszy;
  
  if (pusta()) {

    cout << "Blad. Kolejka jest pusta." << endl;
    return poczatek;

  }

  else {

    pierwszy = poczatek;
    poczatek = poczatek->nastepny;
    pierwszy->nastepny = NULL;
    return pierwszy;
    
  }
}

int kolejka_lab02::rozmiar() {

  element* iterator = poczatek;
  int ilosc = 0;

  if (pusta())
    return 0;
  
  while(iterator != NULL) {

    ilosc++;
    iterator = iterator->nastepny;

  }

  return ilosc;

}

// bool kolejka_lab02::zawiera_wartosc(string wartosc) {

//   element* iter = poczatek;

//   while (iter != NULL) {

//     if (iter->wartosc == wartosc)
//       return true;

//     iter = iter->nastepny;
    
//   }

//   return false;
  
// }
