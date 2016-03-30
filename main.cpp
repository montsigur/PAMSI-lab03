#include "kolejka_tab_c.hpp"
#include "kolejka_tab_x2.hpp"
#include "kolejka_stl.hpp"
#include "kolejka_lab02.hpp"
#include "timer/src/Timer.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void pomiar(int ilosc) {

  kolejka_lab02 pomiary;

  Timer timer;
  
  srand(time(NULL)); 

  timer.start();
  kolejka_tab_c K_c;
  for (int i=0; i<ilosc; i++)
    K_c.dodaj(rand());
  timer.stop();
  pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));

  timer.start();
  kolejka_tab_x2 K_x2;
  for (int i=0; i<ilosc; i++)
    K_x2.dodaj(rand());
  timer.stop();
  pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));

  timer.start();
  kolejka_stl K_stl;
  for (int i=0; i<ilosc; i++)
    K_stl.dodaj(rand());
  timer.stop();
  pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));

  timer.start();
  kolejka_lab02 K_lab02;
  for (int i=0; i<ilosc; i++)
    K_lab02.dodaj(new element(rand()));
  timer.stop();
  pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));

  cout << "Pomiary czasu dodawania dla "
       << ilosc << " losowych danych" << endl;
  cout << "\ttab c: " << pomiary.zdejmij()->wartosc << " us" << endl;
  cout << "\ttab x2: " << pomiary.zdejmij()->wartosc << " us" << endl;
  cout << "\ttab stl: " << pomiary.zdejmij()->wartosc << " us" << endl;
  cout << "\ttab lab02: " << pomiary.zdejmij()->wartosc << " us" << endl;
  cout << endl;
}

int main() {

  for (int i=16; i <= 2 * 32768; i *= 2)
    pomiar(i);
  
  return 0;
}
