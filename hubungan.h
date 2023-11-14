#ifndef HUBUNGAN_H_INCLUDED
#define HUBUNGAN_H_INCLUDED
#include "Mobil.h"
#include "Montir.h"
#include <iostream>

#define first(L) L.first
#define last(L) L.last
#define next(P) (P)-> next
#define prev(P) (P)-> prev
#define addrsMobil(P) (P)->info.addrsMobil
#define addrsMontir(P) (P)->info.addrsMontir
#define nil NULL

using namespace std;
typedef struct Hubungan infotypeHub;
typedef struct elmListHubungan *adrHubungan;
struct Hubungan{
    adrMontir addrsMontir;
    adrMobil addrsMobil;
};
struct ListHubungan{
    adrHubungan first;
    adrHubungan last;
};
struct elmListHubungan{
    infotypeHub info;
    adrHubungan next;
    adrHubungan prev;
};




adrHubungan allocateHubungan(infotypeHub Hubungan);
adrHubungan searchHubungan(ListHubungan L, infotypeHub P);
void createListHubungan(ListHubungan &L);
void deallocateHubungan(adrHubungan &P);
void insertHubungan(ListHubungan &L, adrHubungan P);
void insertFirstHubungan(ListHubungan &L, adrHubungan P);
void insertAfterHubungan(ListHubungan &L, adrHubungan Prec, adrHubungan P);
void insertLastHubungan(ListHubungan &L, adrHubungan P);
void deleteFirstHubungan(ListHubungan &L);
void deleteLastHubungan(ListHubungan &L);
void deleteHubungan(ListHubungan &L, infotypeHub R);
void deleteAfterHubungan(ListHubungan &L, adrHubungan Prec);
void printHubungan(ListHubungan L);

;


#endif // HUBUNGAN_H_INCLUDED
