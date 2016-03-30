// Wojciech Michałowski
// nr albumu 218705

#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <iostream>
using namespace std;

struct element {

  element* nastepny;
  element* poprzedni;
  int wartosc;

  element(int wart_pocz) {

    nastepny = NULL;
    poprzedni = NULL;
    wartosc = wart_pocz;

  }

  element() {
    nastepny = NULL;
    poprzedni = NULL;

  }
};

#endif
