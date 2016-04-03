#ifndef KOLEJKA_STL_HPP
#define KOLEJKA_STL_HPP
#include <iostream>
#include <queue>
using namespace std;

class kolejka_stl: private queue<int> {

  queue<int> kolejka;
  
public:

  void dodaj(int element) { kolejka.push(element); }

  int zdejmij() {

    int element = kolejka.front();
    kolejka.pop();
    return element;

  }

  int rozmiar() { return kolejka.size(); }

  void zawartosc() {

    int rozmiar_ = rozmiar();
    int element;
    
    while(rozmiar_-- > 0) {

      element = kolejka.front();
      kolejka.pop();
      cout << element << endl;
      kolejka.push(element);
      
    }
  }

  void wyczysc() {

    while (!kolejka.empty())
      kolejka.pop();
    
  }
};

#endif
