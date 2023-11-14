#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdlib.h>
#include <conio.h>
#include "Montir.h"
#include "Mobil.h"
#include "Hubungan.h"

void blank();
void inputMontir(ListMontir &LMT);
void inputMobil(ListMobil &LMB);
void inputHubungan(ListHubungan &LH,ListMontir &LMT, ListMobil &LMB);
void deleteMontir(ListMontir &Mt);
void deleteMobil(ListMobil &MB);
void printMobilMontirtertentu(ListHubungan &LH);
int HitungMaxPerbaikan(ListHubungan L, infotypeMontir MT);
void printSeluruhPerbaikan(ListHubungan LH);
void montirPalingRajin(ListHubungan LH, ListMontir LMT);
int hitungKerusakan(ListHubungan LH, infotypeMobil MB);
void mobilLebihDariSatuMontir(ListHubungan LH, ListMobil LMB);
int menuUtama();
void menuInti(int menuUtama, int i, ListMontir &LMT, ListMobil &LMB, ListHubungan &LH);
void menuAwal();





#endif // MENU_H_INCLUDED
