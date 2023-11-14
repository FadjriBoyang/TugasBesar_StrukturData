#include "mobil.h"
#include <iostream>

using namespace std;
void createListMobil(ListMobil &L) {
    first(L) = nul;
}
adrMobil allocateMobil(infotypeMobil mobil){

    adrMobil P = new elmListMobil;
    info(P).nama = mobil.nama;
    next(P)=nul;
}
void deallocateMobil(adrMobil &P){
    delete P;
}
void insertMobil(ListMobil &L, adrMobil P){
    if(first(L) != nul){
        next(P) = first(L);
        first(L) = P;

    } else{
        first(L) = P;
    }

}
void deleteFirstMobil(ListMobil &L){
    if(first(L)!=nul){
        adrMobil P=first(L);
        first(L)=next(P);
        next(P)=nul;
        deallocateMobil(P);

    }else{
        cout<<"Mobil tidak ada dalam data"<<endl;
    }
}
void deleteLastMobil(ListMobil &L){
    if(first(L)!=nul){
        adrMobil q = first(L);
        while(next(next(q))!= nul){
            q = next(q);
        }
        adrMobil P = next(q);
        next(P)= nul;
        next(q)= nul;
        deallocateMobil(P);

    }else{
        cout<<"Mobil kosong"<<endl;
    }
}
void deleteAfterMobil(ListMobil &L, adrMobil Prec){
    if(first(L)!=nul && Prec != nul){
        adrMobil q=first(L);

        while(next(q)!=nul && info(q).nama!=info(Prec).nama){
            q=next(q);
        }
        if(info(q).nama==info(Prec).nama){

            if(next(q)==nul){
                cout<<"Tidak berhasil menghapus data montir"<<endl;

            }else if(next(next(q))==nul){
                deleteLastMobil(L);

            }else{
                adrMobil P=next(q);
                next(q)=next(P);
                next(P)=nul;
                deallocateMobil(P);
            }
        }else{
            cout<<"Mobil tidak ditemukan"<<endl;
        }
    }else{
        cout<<"List mobil kosong"<<endl;
    }
}

void deleteMobil(ListMobil &L, infotypeMobil MB){
    if(first(L) != nul && MB.nama!= ""){
        adrMobil P = searchMobil(L, MB);
        if(P != nul){
            if(P == first(L)){
                deleteFirstMobil(L);
            }else if(next(P) == nul){
                deleteLastMobil(L);
            }else{
                adrMobil Q = first(L);
                while(next(Q) != P){
                    Q = next(Q);
                }
                deleteAfterMobil(L,Q);
            }
        }else{
            cout << "Tidak dapat menghapus data mobil,data tidak ada dalam List" << endl;
        }
    }else{
        cout << "Tidak dapat menghapus list,karena list sudah kosong" << endl;
    }
}
void printMobil(ListMobil L){
    int k;
    if(first(L)!=nul){
        adrMobil P=first(L);
        k=1;
        while(P!=nul){
            cout<<"Mobil"<<k<<endl;
            cout<<"Nama Mobil:"<<info(P).nama<<" "<<endl;
            P=next(P);
            k++;
            cout<<endl;
        }
    }else{
        cout<<"data tidak dapat dilihat"<<endl;
    }
}
adrMobil searchMobil(ListMobil L, infotypeMobil P){
    if(first(L) != nul && P.nama != ""){
        adrMobil q = first(L);
        while(next(q) != nul &&  info(q).nama != P.nama){
            q = next(q);
        }
        if(info(q).nama == P.nama){
            return q;
        }else{
            return nul;
        }
    }else{
        return nul;
    }
}
