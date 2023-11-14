#include "Montir.h"
#include "Mobil.h"
#include "Hubungan.h"
#include "Menu.h"

void inputMontir(ListMontir &LMT){
    infotypeMontir P;
    blank();

    cout<<"Input Data"<<endl;
    cout<<"Nama Montir : ";
    cin>>P.namaMontir;

    adrMontir Mt = searchMontir(LMT,P);
    if(Mt != NULL){
          cout<<"Montir sudah ada dalam List"<<endl;
    }else{
        insertMontir(LMT,allocateMontir(P));
        cout<<"Montir telah dimasukan kedalam data"<<endl;
    }

}


void inputMobil(ListMobil &LMB){
    infotypeMobil P;
    blank();

    cout<<"Input Data"<<endl;
    cout<<"Nama Mobil : ";
    cin>>P.nama;

    adrMobil Mb = searchMobil(LMB,P);
    if(Mb != NULL){
          cout<<"Mobil sudah ada dalam List"<<endl;
    }else{
        insertMobil(LMB,allocateMobil(P));
        cout<<"Mobil telah dimasukan kedalam data"<<endl;
    }

}
void inputHubungan(ListHubungan &LH,ListMontir &LMT, ListMobil &LMB){
    infotypeMontir Mt;
    infotypeMobil Mb;
    infotypeHub H;

    cout << "Input Hubungan Bengkel" << endl;
    cout << "Nama Montir : ";
    cin >> Mt.namaMontir;

    adrMontir MN= searchMontir(LMT,Mt);

    cout << "Nama Mobil: ";
    cin >> Mb.nama;

    adrMobil ML = searchMobil(LMB, Mb);
    H.addrsMontir = MN;
    H.addrsMobil = ML;

    cout<<MN<<endl;
    if(MN != NULL && ML != NULL){
        insertHubungan(LH, allocateHubungan(H));
        cout << endl << "Hubungan berhasil ditambahkan" << endl;
    }else{
        cout << endl << "Hubungan kandas, tidak dapat ditambahkan" << endl;
        }
    }


void deleteMontir(ListMontir &MT){
    blank();
    infotypeMontir P;

    cout<<"Input Montir yang akan di hapus"<<endl;
    cout<<"Nama Montir : ";
    cin>>P.namaMontir;

    deleteMontir(MT);
    getch();
}
void blank(){
    system ("CLS");
}
void deleteMobil(ListMobil &MB){
    blank();
    infotypeMobil P;

    cout<<"Input nama mobil yang akan dihapus"<<endl;
    cout<<"Nama Mobil : ";
    cin>>P.nama;

    deleteMobil(MB,P);
    getch();
}
void printMobilMontirtertentu(ListHubungan &LH){
    infotypeMontir MT;
    int i = 1;

    cout << "Tampilkan Mobil yang pernah memperbaiki Montir tertentu" << endl;
    cout << "Masukkan nama Montir: ";
    cin >> MT.namaMontir;

    if(first(LH) != NULL && last(LH) != NULL){
        adrHubungan Q=first(LH);
        while(Q != NULL){
            if(MT.namaMontir==info(addrsMontir(Q)).namaMontir){

                cout << "Mobil ke " << i << endl;
                cout << "Nama Mobil : " << info(addrsMobil(Q)).nama << endl;

                i++;
            }
            Q = next(Q);
        }
        if(i == 1){
            cout<<"Montir " << MT.namaMontir<< " tidak pernah memperbaiki mobil " << endl;
        }
    }else{
        cout << "List Kosong!" << endl;
    }
}
int HitungMaxPerbaikan(ListHubungan L, infotypeMontir MT){
    if(first(L) != NULL && last(L) != NULL){
        adrHubungan Q = first(L);
        int i = 0;
        while(Q != Q){
            if(info(addrsMontir(Q)).namaMontir == MT.namaMontir){
                i++;
            }
            Q = next(Q);
        }
        return i;
    }else{
        return 0;
    }
}

void printSeluruhPerbaikan(ListHubungan LH){
    if(first(LH)!=NULL){
        adrHubungan P=first(LH);
        int i=1;
        while(P!=NULL){

            cout<<"Perbaikan"<<i<<endl;
            cout<<"Mobil:"<<info(addrsMobil(P)).nama<<" "<<endl;
            cout<<"Montir:"<<info(addrsMontir(P)).namaMontir<<" "<<endl;

            P=next(P);
            i++;

            cout<<endl;
        }
    }else{
        cout<<"Tidak ada Perbaikan"<<endl;
    }
}
void montirPalingRajin(ListHubungan LH, ListMontir LMT){
    if(first(LH) != NULL && first(LMT)!=NULL){
        int maks;
        int i;
        adrMontir Q = first(LMT);
        adrMontir Pmax = first(LMT);
        while(Q != NULL){
            infotypeMontir MT;
            MT.namaMontir = info(Q).namaMontir;
            i = HitungMaxPerbaikan(LH, MT);
            if(Q == first(LMT)){
                maks = i;
            }else if(i > maks){
                maks = i;
                Pmax = Q;
            }
            Q = next(Q);
        }

        cout << "Montir yang paling banyak memperbaiki mobil " << endl;
        cout << "Nama : " << info(Pmax).namaMontir << endl;
        cout << "Jumlah Mobil yang diperbaiki : " << maks << endl;

    }else{
        cout << "List Kosong" << endl;
    }
}
int hitungKerusakan(ListHubungan LH, infotypeMobil MB){
    if(first(LH) != NULL && last(LH) != NULL){
        adrHubungan Q = first(LH);
        int i = 0;
        while(Q != NULL){
            if(info(addrsMobil(Q)).nama == MB.nama){
                i++;
            }
            Q = next(Q);
        }
        return i;
    }else{
        return 0;
    }
}
void mobilLebihDariSatuMontir(ListHubungan LH, ListMobil LMB) {
    if(first(LH) != NULL && first(LMB)){
        int i;
        int j = 0;
        adrMobil Q = first(LMB);
        while (Q!= NULL) {
            infotypeMobil MB;
            MB.nama = info(Q).nama;
            i = hitungKerusakan(LH, MB);
            while(j<1){
                cout<< "Mobil yang diperbaiki dengan lebih dari 1 Montir : "<<endl;
            }
            if (i > 1) {
                cout <<"Nama Mobil : "<<info(Q).nama<<endl;
            }
            Q = next(Q);
        }
    }else{
        cout << "List kosong" << endl;
    }
}
int menuUtama(){
    int i = 0;
    bool run = false;
    blank();

    cout << " ______________________________________________________________" << endl;
    cout << "|                         Menu Bengkel                         |"<< endl;
    cout << "|                                                              |" << endl;
    cout << "|                        1. Insert Data                        |" << endl;
    cout << "|                        2. Delete Data                        |" << endl;
    cout << "|                        3. Print Data                         |" << endl;
    cout << "|                        0. Exit                               |" << endl;
    cout << "|______________________________________________________________|" << endl;
    cout << "Select Option : " ;

    do{
        cin>>i;
        if(i>=0 && i<=3){
            run=true;
        }else{
            cout<<"Ulangi Input"<<endl;
        }
    }while(run!=true);

    return i;
}

void menuInti(int menuUtama, int i, ListMontir &LMT, ListMobil &LMB, ListHubungan &LH){
    bool run = false;
    i=0;
    if(menuUtama == 1){


        cout << " ______________________________________________________________" << endl;
        cout << "|                         Menu Insert                          |"<< endl;
        cout << "|                                                              |" << endl;
        cout << "|                        1. Insert Montir                      |" << endl;
        cout << "|                        2. Insert Mobil                       |" << endl;
        cout << "|                        3. Insert Hubungan                    |" << endl;
        cout << "|                        0. Exit                               |" << endl;
        cout << "|______________________________________________________________|" << endl;
        cout << "Select Option : " ;

        while(run != true){
            cout << "Pilih menu : ";
            cin >> i;

            if(i >= 0 && i <= 3){
            run = true;
            }else{
            cout << "Input yang bener" << endl;
                }
        }
        if(i == 1){
            inputMontir(LMT);
            getch();
        }else if(i == 2){
            inputMobil(LMB);
            getch();
        }else{
            inputHubungan(LH,LMT,LMB);
            getch();
        }
    }else if(menuUtama == 2){

        cout << " ______________________________________________________________" << endl;
        cout << "|                         Menu Insert                          |"<< endl;
        cout << "|                                                              |" << endl;
        cout << "|                        1. Delete Montir                      |" << endl;
        cout << "|                        2. Delete Mobil                       |" << endl;
        cout << "|                        0. Exit                               |" << endl;
        cout << "|______________________________________________________________|" << endl;
        cout << "Select Option : " ;

        while(run != true){
            cout << "Pilih menu : ";
            cin >> i;
            if(i >= 0 && i <= 2){
            run = true;
            }else{
            cout << "Input yang bener" << endl;
            }
        }
        if(i == 1){
            deleteMontir(LMT);
            getch();
        }else {
            deleteMobil(LMB);
            getch();
        }
    }else{

        cout << " ______________________________________________________________" << endl;
        cout << "|                         Menu Insert                          |"<< endl;
        cout << "|                                                              |" << endl;
        cout << "|          1. Print Seluruh Perbaikan Mobil                    |" << endl;
        cout << "|          2. Print Montir yang paling banyak memperbaiki      |" << endl;
        cout << "|          3. Print Daftar Mobil yang pernah diperbaiki        |" << endl;
        cout << "|             montir tertentu                                  |" << endl;
        cout << "|          4. Print Daftar Mobil yang pernah diperbaiki        |" << endl;
        cout << "|             oleh lebih dari satu Montir                      |" << endl;
        cout << "|          0. Exit                                             |" << endl;
        cout << "|______________________________________________________________|" << endl;
        cout << "Select Option : " ;

        while(run != true){
            cout << "Pilih menu : ";
            cin >> i;
            if(i >= 0 && i <= 4){
            run = true;
            }else{
            cout << "Input yang bener" << endl;
            }
        }
        if(i == 1){
            printSeluruhPerbaikan(LH);
            getch();
        }else if(i == 2){
            montirPalingRajin(LH,LMT);
            getch();
        }else if(i == 3){
            printMobilMontirtertentu(LH);
            getch();
        }else{
            mobilLebihDariSatuMontir(LH,LMB);
            getch();
        }


    }
}

void menuAwal(){
    int A;
    int B;
    bool run = false;

    ListMontir MT;
    createListMontir(MT);
    ListMobil MB;
    createListMobil(MB);
    ListHubungan H;
    createListHubungan(H);

    while(run!=true){
        A = menuUtama();
        if(A != 0){
            blank();
            menuInti(A,B,MT,MB,H);
            getch();
        }else{
            run = true;
        }
    }
}
