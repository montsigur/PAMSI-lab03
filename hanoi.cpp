#include "lista.hpp"
using namespace std;

int indeksRez(int indeks_do, int indeks_od) {

  if (indeks_do * indeks_od != 0)
    return 0;
  else if (indeks_do + indeks_od == 2)
    return 1;
  else
    return 2;

}

void przeniesDysk(lista* drazek_od, lista* drazek_do) {

  if (drazek_do->rozmiar() > 0 and
      drazek_od->sprawdz()->wartosc > drazek_do->sprawdz()->wartosc)
    cout << "Blad. Niedozwolony ruch." << endl;

  else
    drazek_do->dodaj(drazek_od->zdejmij());
}

void hanoi(int ilosc_dyskow,
	   int indeks_od,
	   int indeks_do,
	   lista* drazki) {

  int indeks_rezerwowy = indeksRez(indeks_do, indeks_od);
  
  lista* drazek_do = drazki+indeks_do,
    *drazek_od = drazki+indeks_od;

  if (ilosc_dyskow != 0) {

    hanoi(ilosc_dyskow-1, indeks_od, indeks_rezerwowy, drazki);
    przeniesDysk(drazek_od, drazek_do);
    hanoi(ilosc_dyskow-1, indeks_rezerwowy, indeks_do, drazki);

  }
}

int main() {

  lista* drazki = new lista[3];
  drazki[0] = lista(); drazki[1] = lista(); drazki[2] = lista();

  for (int i = 5; i > 0; i--)
    drazki[0].dodaj(new element(i));

  hanoi(5, 0, 1, drazki);

  drazki[0].zawartosc();
  drazki[1].zawartosc();

  return 0;

}
