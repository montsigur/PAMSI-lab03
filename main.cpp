#include "kolejka_tab_c.hpp"
#include "kolejka_tab_x2.hpp"
#include "kolejka_stl.hpp"
#include "timer/src/Timer.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

  kolejka_tab_c Kc;
  kolejka_tab_x2 Kx2;
  kolejka_stl Kstl;

  int val;

  Timer timer;
  double tik=0, tak;
  
  srand(time(NULL));
  
  for (int i=0; i<5; i++) {

    val = rand();
    
    Kc.dodaj(val);
    Kx2.dodaj((val+1)*(val+1));
    Kstl.dodaj(2*val+1);
    
  }

  timer.start();
  Kc.zawartosc();
  timer.stop();
  tak = timer.getElapsedTimeInMicroSec();
  cout << tak - tik << " us" << endl;

  timer.start();
  Kx2.zawartosc();
  timer.stop();
  tik = timer.getElapsedTimeInMicroSec();
  cout << tik - tak << " us" << endl;

  timer.start();
  Kstl.zawartosc();
  timer.stop();
  tak = timer.getElapsedTimeInMicroSec();
  cout << tak - tik << " us" << endl;
  
  return 0;
}
