#include "kolejka_tab_c.hpp"
#include "kolejka_tab_x2.hpp"
#include "kolejka_lab02.hpp"
#include "timer/src/Timer.h"
#include <queue>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void pomiar(vector<int> rozmiary) {

  kolejka_lab02 pomiary;

  ofstream plik("pomiary.dat");

  Timer timer;
  int ilosc_pomiarow;
  
  srand(time(NULL)); 

  // for (int ilosc_danych: rozmiary) {
  //   timer.start();
  //   kolejka_tab_c K_c;
  //   for (int i=0; i< ilosc_danych; i++)
  //     K_c.dodaj(rand());
  //   timer.stop();
  //   pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));
  //   K_c.wyczysc();
  // }

  for (int ilosc_danych: rozmiary) {
    timer.start();
    kolejka_tab_x2 K_x2;
    for (int i=0; i< ilosc_danych; i++)
      K_x2.dodaj(rand());
    timer.stop();
    pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));
    K_x2.wyczysc();
  }

  for (int ilosc_danych: rozmiary) {
    timer.start();
    queue<int> K_stl;
    for (int i=0; i< ilosc_danych; i++)
      K_stl.push(rand());
    timer.stop();
    pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));
    int rozmiar = K_stl.size();
    while (rozmiar --> 0)
      K_stl.pop();
  }

  for (int ilosc_danych: rozmiary) {
    timer.start();
    kolejka_lab02 K_lab02;
    for (int i=0; i< ilosc_danych; i++)
      K_lab02.dodaj(new element(rand()));
    timer.stop();
    pomiary.dodaj(new element(timer.getElapsedTimeInMicroSec()));
    K_lab02.wyczysc();
  }

  ilosc_pomiarow = pomiary.rozmiar();

  plik << rozmiary.size() << " " << 3 << endl;
  
  while (ilosc_pomiarow --> 0)
    plik << rozmiary[rozmiary.size()-1 - ilosc_pomiarow % rozmiary.size()]
	 << " " << pomiary.zdejmij()->wartosc << endl;
  
  plik.close();
}

int main() {

  vector<int> rozmiary; // = {1000, 10000, 100000, 500000};

  for (int i=1000; i<100000; i+=1000)
    rozmiary.push_back(i);

  pomiar(rozmiary);
  
  return 0;
}
