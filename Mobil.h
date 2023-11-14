#ifndef MOBIL_H_INCLUDED
#define MOBIL_H_INCLUDED
#include <stdio.h>
#include <iostream>
#define first(L) L.first
#define next(P) (P)-> next
#define info(P) (P)-> info
#define nul NULL
using namespace std;
typedef struct mobil infotypeMobil;
typedef struct elmListMobil *adrMobil;
struct mobil {
    int agt;
    string nama;
};
struct elmListMobil{
    infotypeMobil info;
    adrMobil next;
};
struct ListMobil{
    adrMobil first;
};

void createListMobil(ListMobil &L);
adrMobil allocateMobil(infotypeMobil mobil);
void dealokasiMobil(adrMobil &P);
void insertMobil(ListMobil &L, adrMobil P);
void deleteMobil(ListMobil &L, infotypeMobil B);
void printMobil(ListMobil L);
adrMobil searchMobil(ListMobil L, infotypeMobil P);
void deallocateMobil(adrMobil &P);
void deleteFirstMobil(ListMobil &L);
void deleteLastMobil(ListMobil &L);
void deleteAfterMobil(ListMobil &L, adrMobil Prec);
void deallocateMobil(adrMobil &P);
#endif // MOBIL_H_INCLUDED
