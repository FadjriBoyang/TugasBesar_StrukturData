#include "Montir.h"
#include <iostream>

using namespace std;

void createListMontir(ListMontir &L){
    first(L)=NULL;
    last(L)=NULL;
}
adrMontir allocateMontir(infotypeMontir Montir){
    adrMontir P=new elmListMontir;
    info(P).namaMontir=Montir.namaMontir;
    next(P)=NULL;
}
void deallocateMontir(adrMontir &P){
    delete P;
}


void insertMontir(ListMontir &L, adrMontir P){
    if(first(L) != NULL && last(L)!=NULL){
        next(P) = first(L);
        first(L) = P;
    }else{
        first(L) = P;
        last(L) = P;

    }

}


adrMontir searchMontir(ListMontir L, infotypeMontir P){
    adrMontir Q = first(L);
    string goal = P.namaMontir;

    if(first(L) != NULL && goal != ""){

        while(info(Q).namaMontir != goal && next(Q) != NULL){
            Q = next(Q);
        }
        if(goal == info(Q).namaMontir){

            return Q;
        }else{

            return NULL;
        }
    }else{

        return NULL;
    }

}


void deleteFirstMontir(ListMontir &L){
    if(first(L)!=NULL && last(L)!=NULL){
        adrMontir P=first(L);
        first(L)=next(P);
        next(P)=NULL;
        deallocateMontir(P);
    }else{
        cout<<"List Kosong!"<<endl;
    }
}

void deleteLastMontir(ListMontir &L){
    adrMontir Q=last(L);
    adrMontir P=next(Q);
    if(first(L)!=NULL && last(L)!=NULL){
        while(next(P)!=Q){
            P=next(P);
        }
        next(P)=NULL;
        last(L)=P;
        deallocateMontir(P);
    }else{
        cout<<"List Kosong!"<<endl;
    }
}
void insertLastMontir(ListMontir &L,adrMontir &A){
    if (first(L) == NULL ) {
        first(L) = A;
        last(L) = A;
    }else {
        adrMontir prec = first(L);

        while (next(prec) != NULL) {
            prec = next(prec);
        }
        next(prec) = A;
        last(L) = A;
    }
}

void deleteAfterMontir(ListMontir &L, adrMontir Prec){
    adrMontir Q=first(L);
    if(first(L)!=NULL){
        while(next(Q)!=NULL && info(Q).namaMontir!=info(Prec).namaMontir){
            Q=next(Q);
        }
        if(info(Q).namaMontir==info(Prec).namaMontir){
            if(next(Q)==NULL){
                cout<<"Montir tidak dapat dihapus"<<endl;
            }else if(next(next(Q))==NULL){
                deleteLastMontir(L);
            }else{
                adrMontir P = next(Q);
                next(Q)=next(P);
                next(P)=NULL;
                deallocateMontir(P);
            }
        }else{
            cout<<"Data Montir tidak ditemukan"<<endl;
        }
    }else{
        cout<<"List kosong!"<<endl;

    }
}

void deleteDataMontir(ListMontir &L, infotypeMontir Q){
    adrMontir P = searchMontir(L, Q);
    if(first(L) != NULL){
        if(P != NULL){
            if(first(L)==P){
                deleteFirstMontir(L);
            }else if(next(P) == NULL){
                deleteLastMontir(L);
            }else{
                deleteAfterMontir(L,P);
            }
        }else{
            cout << "Montir tidak ada dalam List" << endl;
        }
    }else{
        cout << "List Kosong!" << endl;
    }
}

void printMontir(ListMontir L){
    int i=1;

    if(first(L)!=NULL){
        adrMontir P = first(L);
        while(P!=NULL){

            cout<<"Montir : "<<i<<endl;
            cout<<"Nama Montir : "<<info(P).namaMontir<<endl;

            P=next(P);
            i++;
            cout<<endl;
        }
    }else{
        cout<<"Data Montir Kosong"<<endl;
    }
}

