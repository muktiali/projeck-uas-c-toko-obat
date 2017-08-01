#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

#define PAUSE {cout << ("\n"); system("pause");}


struct data_obat {
 char kode_obat[5];
 char nama_obat[15];
 int stock;
 struct data_obat *next;
};
struct data_obat *awal, *akhir, *p, *Psbl, *baru;

                         //sorting kode obat ascending
void sort_kode_obat(int jml){

    int stock;
    char kode[5], nama[15];
    p=awal;

for (int a=1;a<jml;a++){        //melakukan looping sebanyak data obat
    while (p->next != NULL){    //melakukan looping jika pointer p->next tidak bernilai NUUL
        if (strcmp(p->kode_obat, p->next->kode_obat) ==1 ){//membandingkan array kode obat jika birnilai 1 berarti (array p->kode_obat) lebih besar dari (array p->next->kode_obat)

                strcpy(kode, p->kode_obat);   //menyalin (array p->kode_buku) ke array kode;
                strcpy(p->kode_obat, p->next->kode_obat);  //menyalin (array p->next->kode_buku) ke array kode (array p->kode_obat);
                strcpy(p->next->kode_obat, kode);       //menyalin array kode ke (array p->next->kodeobat)

                strcpy(nama, p->nama_obat);
                strcpy(p->nama_obat, p->next->nama_obat);
                strcpy(p->next->nama_obat, nama);

                stock=p->stock;
                p->stock=p->next->stock;
                p->next->stock=stock;

            }
            p=p->next;
        }
        p=awal;
    }

}

void sort_nama_obat(int jml)
{
    int stock;
    char kode[5], nama[15];
    p=awal;

    for (int a=1;a<jml;a++){                    //melakukan looping sebanyak data kode
        while (p->next != NULL){                //melakukan looping jika pointer p->next tidak bernilai NUUL
            if (strcmp(p->nama_obat, p->next->nama_obat) ==1 ){     //membandingkan array nama_obat jika birnilai 1 berarti (array p->nama obat) lebih besar dari (array p->next->nama obat)

                strcpy(kode, p->nama_obat);         //menyalin (array p->nama_obat) ke array nama;
                strcpy(p->nama_obat, p->next->nama_obat);       //menyalin (array p->next->nama_obat) ke array kode (array p->nama_obat);
                strcpy(p->next->nama_obat, kode);       //menyalin array kode ke (array p->next->nama obat)

                strcpy(nama, p->nama_obat);
                strcpy(p->nama_obat, p->next->nama_obat);
                strcpy(p->next->nama_obat, nama);

                stock=p->stock;
                p->stock=p->next->stock;
                p->next->stock=stock;

            }
            p=p->next;
        }
        p=awal;
    }

}

void update_stock(){
    int up_stok;
    char kode[5];
    data_obat *prv;
    p=awal;

    if (p == NULL) {
        cout << "\n List Kosong\n";
        cout << "\n------------------------------------------\n";
    } else {
        while (p != NULL) {
                 cout << "\n==========================================\n";
            cout << "\nKode obat   : " << p->kode_obat;
            cout << "\nnama_obat  : " << p->nama_obat;
            cout << "\nStock : " << p->stock;

            p = p->next;
        }

        cout<<"\nmasukan kode obat yang ingin di update : ";
        cin>>kode;
        cout<<"\nmasukan stok yang ingin di update : ";
        cin>>up_stok;

        p=awal;
        while (p!=NULL){
            if (strcmp(kode, p->kode_obat)==0 ){         //membandingkan aray kode dengan array (p->kode_obat) jika bernilai 0 maka data tersebut sama
                p->stock=up_stok;                           //lalu mengupdate stok obat
                cout<<"stok obat berhasil di update"<<endl;
                break;
            }
            p=p->next;
        }

        if (p==NULL){
            cout<<"kode obat tidak ada"<<endl;
        }

    }

}

// membandingkan sebuah string (ignore case)

int compare(char *x1, char *x2) {
    int len = strlen(x1);
    int beda = 0;

    for (int i=0; i<len; i++) {
        if (x1[i] >= 'A' && x1[i] <= 'Z') x1[i] += 32;
        if (x2[i] >= 'A' && x2[i] <= 'Z') x2[i] += 32;

        if (x1[i] != x2[i]) beda++;
        if (x2[i] == 'beda') {
            beda++;
                return beda;
        }
    }
    if (strlen(x2) < len) {
        beda += strlen(x2) - len;
    }
    return beda;
}

int main()
{

    awal = akhir = NULL;

    int pilihan = 1, posisi, posisi_sekarang,posisi_data, jml;
    char cari[50], konfirmasi;

            do {
             cout <<  "\n\t=================================================================="
                   "\n\tSELAMAT DATANG DI toko obat bapak hartono";

               cout << "\n\t=================================================================="
                    "\n\t1. Tambah Data obat    "
                    "\t2. delete          "
                    "\n\t3. Cari obat           "
                    "\t4. Tampilkan Data obat "
                    "\n\t5. update stok obat    "
                    "\t0. EXIT                "
                    "\n\t===================================================================";
            cout << "\n\n\t\t\t\t\t\t\tMasukkan pilihan anda : ";
            cin >> pilihan;
            system("cls");

        switch (pilihan) {
            case 1: // tambah data kedalam list
                baru = (struct data_obat*) malloc(sizeof(struct data_obat)); // alokasikan list baru di memori
                if (baru == NULL) {
                    cout << "\nMemori tidak cukup.";
                    PAUSE;
                    break;
                }
                cout << "Kode obat: ";
                cin >> baru->kode_obat;
//                getchar();
                cout << "nama obat  : ";
                cin >> baru->nama_obat;
                cout << "Stock : ";
                cin >> baru->stock;

                if (awal == NULL) {
                    baru->next = NULL;
                    awal = baru;
                    akhir = baru;
                } else {
                    cout << "\nTambahkan Data di (Default = akhir) : \n";
                    cout << "1. Awal\n2. Tengah\n3. Akhir\n\nPilihan Anda : ";
                    cin >> posisi;
                    switch(posisi) {
                        case 1:
                            // tambah data di awal list
                            baru->next = awal;
                            awal = baru;
                            PAUSE;
                            break;
                        case 2:
                            cout << "Masukan posisi data : ";
                            cin >> posisi_data;
                            p = awal;
                            Psbl = NULL;
                            posisi_sekarang = 1;
                            while (p != NULL && posisi_sekarang < posisi_data) {
                                //Psbl = p;
                                p = p->next;
                                posisi_sekarang++;
                            }
                            if (p != NULL) {
                                // tambahkan data di tengah (posisi_data)
                                Psbl = p;
                                baru->next = p->next;
                                Psbl->next = baru;
                            }
                            break;
                        case 3:
                        default:
                            // tambah data di akhir list
                            akhir->next = baru;
                            akhir = baru;
                            baru->next = NULL;
                            PAUSE;
                            break;
                    }
                }
                break;
        case 2:
                p = awal;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                    break;
                } else {
                    while (p != NULL) {
                        cout << "\nkode obat  : " << p->kode_obat;
                        cout << "\nnama obat  : " << p->nama_obat;
                        cout << "\nStock : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                    }
                }
                cout << "\nMasukan Kode obat/nama obat dari data yang ingin dihapus : ";
                cin >> cari;
                Psbl = NULL;
                p = awal;
                while (p != NULL) {
                    if (compare(p->kode_obat, cari) == 0 || compare(p->nama_obat, cari) == 0) {
                        cout << "\n==========================================\n";
                        cout << "\nKode obat   : " << p->kode_obat;
                        cout << "\nnama obat  : " << p->nama_obat;
                        cout << "\nStock : " << p->stock;
                        cout << "\n==========================================\n";
                        cout << "\nIngin menghapus data di atas (y/n) : ";
                        cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                            if (awal->next == NULL) {
                                awal = NULL;
                                akhir = awal;
                            } else if (p == awal) {
                                // hapus di awal
                                Psbl = awal;
                                awal = Psbl->next;
                            } else if (p == akhir) {
                                // hapus di akhir
                                Psbl->next = NULL;
                                akhir = Psbl;
                            }
                            else {
                                // hapus di tengah
                                Psbl->next = p->next;
                            }
                            cout << "\nData berhasil dihapus.\n\n";
                        } else {
                            cout << "\nData tidak jadi dihapus.\n\n";
                        }
                        break;
                    }
                    Psbl = p;
                    p = p->next;
                }

                if (p == NULL) {
                    cout << "\n\nKode obat/nama obat tidak ada !\n\n";
                }
                PAUSE;
                break;
            case 3:
                cout << "\nMasukan Kode obat/nama obat yang akan di cari : ";
                cin >> cari;
                p = awal;
                while (p != NULL) {
                    if (compare(p->kode_obat, cari) == 0 || compare(p->nama_obat, cari) == 0) {


                        cout << "\nKode obat   : " << p->kode_obat
                               << "\nnama obat  : " << p->nama_obat
                                <<"\nStock : " << p->stock
                                <<"\n==========================================\n";
                        PAUSE;
                        break;
                    }
                    p = p->next;
                }
                if (p == NULL) {
                    cout << "\nData tidak ada ! \n\n";
                    PAUSE;
                }
                break;
        case 4: // tampilkan list
                int sort_pilih;
                p = awal;
                jml = 0;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                } else {
                    while (p != NULL) {
                        cout << "\nKode obat  : " << p->kode_obat;
                        cout << "\nnama obat  : " << p->nama_obat;
                        cout << "\nStock       : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                        jml++;
                    }
                    do{
                    cout<<"\n1. Sorting Kode "
                   "\n2. Sorting nama "
                   "\n3. kembali ke menu awal";
                    cout<<"\n\nPilihan anda : ";
                    cin>>sort_pilih;
                    switch (sort_pilih){
                        case 1:
                            sort_kode_obat(jml);
                            system("cls");
                            cout<<"sorting kode obat  \n\n";
                                while (p != NULL) {
                                cout << "\nKode obat  : " << p->kode_obat;
                                cout << "\nnama obat  : " << p->nama_obat;
                                cout << "\nStock       : " << p->stock;
                                cout << "\n==========================================\n";
                                p = p->next;
                                jml++;
                            }
                            break;
                        case 2:
                            sort_nama_obat(jml);
                            system("cls");
                            cout<<"sorting nama obat \n\n";
                                while (p != NULL) {
                                cout << "\nKode obat   : " << p->kode_obat;
                                cout << "\nnama obat  : " << p->nama_obat;
                                cout << "\nStock       : " << p->stock;
                                cout << "\n==========================================\n";
                                p = p->next;
                                jml++;
                            }
                            break;
                        case 3:
                            break;

                    }
                    }while (sort_pilih!=3);

                }
                cout << "\n";
                PAUSE;
                break;
        case 5:
            update_stock();
            break;

        case 0: break;
            default:
                cout << "\nPilihan salah !\n";
                break;
        }
    } while (pilihan > 0);

    return 0;
}
