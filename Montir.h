#ifndef MONTIR_H_INCLUDED
#define MONTIR_H_INCLUDED
#include <iostream>
#include <stdio.h>
#define first(L) L.first
#define last(L) L.last
#define next(P) (P)-> next
#define info(P) (P)-> info
#define nil NULL
typedef struct montir infotypeMontir;
typedef struct elmListMontir *adrMontir;
using namespace std;
struct montir {
    int agt;
    string namaMontir;

};
struct ListMontir{
    adrMontir first;
    adrMontir last;
};
struct elmListMontir{
    infotypeMontir info;
    adrMontir next;
};




adrMontir allocateMontir(infotypeMontir Montir);
adrMontir searchMontir(ListMontir L, infotypeMontir P);
void createListMontir(ListMontir &L);
void deallocateMontir(adrMontir &P);
void insertMontir(ListMontir &L, adrMontir P);
void deleteFirstMontir(ListMontir &L);
void deleteLastMontir(ListMontir &L);
void deleteAfterMontir(ListMontir &L, adrMontir Prec);
void deleteDataMontir(ListMontir &L, infotypeMontir Q);
void printMontir(ListMontir L);
void insertLastMontir(ListMontir &L,adrMontir A);


#endif // MONTIR_H_INCLUDED
