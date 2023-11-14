#include "Montir.h"
#include "Mobil.h"
#include "hubungan.h"
#include <iostream>

using namespace std;


void createListHubungan(ListHubungan &L){
    first(L) = NULL;
    last(L) = NULL;
}
adrHubungan allocateHubungan(infotypeHub hubungan){
    adrHubungan P=new elmListHubungan;
    info(P)=hubungan;
    next(P)=NULL;
    prev(P)=NULL;
}
void deallocateHubungan(adrHubungan &P){
    delete P;
}
void insertHubungan(ListHubungan &L, adrHubungan P){
    if(first(L) != NULL && last(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}
void insertFirstHubungan(ListHubungan &L, adrHubungan P){
    if(first(L) != NULL && last(L) != NULL){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;
    }
}

void insertAfterHubungan(ListHubungan &L, adrHubungan Prec, adrHubungan P){
    if(first(L)!=NULL && last(L)!=NULL && Prec!=NULL){
        adrHubungan Q=first(L);
        while(next(Q)!=NULL && addrsMontir(Q)!= addrsMontir(Prec) && addrsMobil(Q)!=addrsMobil(Prec)){
            Q=next(Q);
        }
        if(addrsMontir(Q)== addrsMontir(Prec) && addrsMobil(Q)==addrsMobil(Prec)){
            if(next(Q)==NULL){
                insertLastHubungan(L,P);
            }else{
                next(P)=next(Q);
                prev(next(Q))=P;
                next(Q)=P;
                prev(P)=Q;
            }
        }
    }else{
        cout<<"Tidak ada Hubungan"<<endl;
    }
}

void insertLastHubungan(ListHubungan &L, adrHubungan P){
    if(first(L)!=NULL && last(L)!=NULL){
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }else{
        insertFirstHubungan(L,P);
    }
}

void deleteFirstHubungan(ListHubungan &L){
    if(first(L)!=NULL && last(L)!=NULL){
        adrHubungan P=first(L);
        first(L)=next(P);
        next(P)=NULL;
    }else{
        cout<<"Tidak ada Hubungan"<<endl;
    }
}

void deleteLastHubungan(ListHubungan &L){
    if(first(L)!=NULL && last(L)!=NULL){
        adrHubungan Q=last(L);
        last(L)=prev(Q);
        next(last(L))=NULL;
        delete Q;
    }else{
        cout<<"Tidak ada Hubungan"<<endl;
    }
}

void deleteAfterHubungan(ListHubungan &L, adrHubungan Prec){
if(first(L)!=NULL && last(L)!=NULL && Prec!=NULL){
        adrHubungan Q=first(L);
        while(next(Q)!=NULL && addrsMontir(Q)!= addrsMontir(Prec) && addrsMobil(Q)!=addrsMobil(Prec)){
            Q=next(Q);
        }
        if(addrsMontir(Q)== addrsMontir(Prec) && addrsMobil(Q)==addrsMobil(Prec)){
            if(next(Q)==NULL){
                deleteLastHubungan(L);
            }else{
                adrHubungan P=next(Q);
                next(Q)=next(P);
                prev(next(P))=Q;
                delete P;
            }
        }
    }else{
        cout<<"Tidak ada Hubungan"<<endl;
    }
}
adrHubungan searchHubungan(ListHubungan L, infotypeHub P){
    if(first(L) != NULL && last(L)!=NULL && P.addrsMontir != NULL && P.addrsMobil != NULL){
        adrHubungan Hubungan=NULL;
        adrHubungan Q = first(L);
        while(Q!=NULL){
            if(addrsMontir(Q) == P.addrsMontir && addrsMobil(Q) == P.addrsMobil){
                Hubungan=Q;
            }
            Q=next(Q);
        }
        if(Hubungan!=NULL){
            return Hubungan;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }

}
void deleteHubungan(ListHubungan &L, infotypeHub hub){
    if(first(L) != NULL && last(L)!= NULL && hub.addrsMobil != NULL && hub.addrsMontir != NULL){
        adrHubungan P = searchHubungan(L,hub);
        if(P != NULL){
            if(P == first(L)){
            deleteFirstHubungan(L);
            }else if(P == last(L)){
                deleteLastHubungan(L);
            }else{
            adrHubungan prec = prev(P);
            deleteAfterHubungan(L,prec);
            }
        }else{
            cout << "Tidak ada data dalam List" << endl;
        }
    }else{
        cout << "Data Kosong" << endl;
    }
}

void printHubungan(ListHubungan L){
    if(first(L)!=NULL){
        adrHubungan P=first(L);
        int i=1;
        while(P!=NULL){
            cout<<"Hubungan ke "<<i<<endl;
            cout<<"Montir: "<<info(addrsMontir(P)).namaMontir<<" "<<endl;
            cout<<"Mobil: "<<info(addrsMobil(P)).nama<<" "<<endl;
            cout<<endl;
             i++;
            P=next(P);

        }
    }else{
        cout<<"Tidak ada Hubungan "<<endl;
    }
}


