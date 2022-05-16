#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXSTACK 20
#define JML_PECAHAN 4

// deklarasi untuk menampung data menggunakan tree atau pohon
typedef struct tree
{
    int no_ATM;
    int PIN;
    char nama[35];
    char alamat[40];
    struct tree *left;
    struct tree *right;
    
} tree;


//queue
typedef struct queue{
    int data[20];
    int tail;
} queue;


//  saldo nasabah
FILE *fp  = NULL; // file saldo nasabah
FILE *fp1 = NULL; // backup data saldo nasabah

tree *get_new_node(int noatm, int pin, char nama[], char alamat[]){
    tree *newNode = (tree*)malloc(sizeof(tree));
    newNode->no_ATM = noatm;
    newNode->PIN = pin;
    strcpy(newNode->nama, nama);
    strcpy(newNode->alamat, alamat);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Masukan data BST
tree *insertsort(tree *rootPtr, int noatm, int pin, char nama[], char alamat[]){
    // jika tree masih kosong
    if(rootPtr == NULL) {
        rootPtr = get_new_node(noatm, pin, nama, alamat);
    } else if (noatm <= rootPtr->no_ATM){
        rootPtr->left = insertsort(rootPtr->left, noatm, pin, nama, alamat);

    } else{
        rootPtr->right = insertsort(rootPtr->right, noatm, pin, nama, alamat );
    }
    return rootPtr;
    
    
}

tree *buat_nasabah(tree *rootPtr){

    // masukin data nasabahnya disini contoh :
        //                              NO.ATM    PIN       NAMA                    Alamat           
        rootPtr = insertsort(rootPtr, 100100100, 1111, "I Made Ryan Prana Dhita", "Blahbatuh, Gianyar");
        rootPtr = insertsort(rootPtr, 210856110, 1823, "I Made Suma Gunawan", "Kintamani, Bangli");
        rootPtr = insertsort(rootPtr, 123456789, 1234, "Tom Delonge", "Texas, california");
        rootPtr = insertsort(rootPtr, 109236782, 8709, "Mark Hoppus", "Beverly hills, Los Angeles ");
        rootPtr = insertsort(rootPtr, 593689372, 5876, "Travis Barker", "kota tua, Jakarta ");
        rootPtr = insertsort(rootPtr, 593234567, 9123, "Harry kane", "Tottenham, london utara ");
        rootPtr = insertsort(rootPtr, 969829456, 7638, "Son Heung Min", "Soul, Korea Selatan ");
        rootPtr = insertsort(rootPtr, 989829456, 1285, "piere emile hojbierg", "kulukulu, Denmark ");
        rootPtr = insertsort(rootPtr, 265423421, 2167, "Iga Massardi", "depok, Jakarta Barat ");
        rootPtr = insertsort(rootPtr, 432156854, 6394, "Bhaskara Putra", "cakcuk, kalimantan uatara  ");
        return rootPtr;
}

tree *search(tree *rootPtr, int noatm){
    if(rootPtr == NULL) {
        return 0;
    } else if (rootPtr->no_ATM == noatm){
        // printf("No Atm: %d\n", rootPtr->no_ATM);
        // printf("PIN: %d\n", rootPtr->PIN);
        // printf("Nama: %s\n", rootPtr->nama);
        // printf("Alamat: %s\n", rootPtr->alamat);
        return rootPtr;
    } else if (noatm <= rootPtr->no_ATM) {
        return search(rootPtr->left, noatm);
    } else {
        return search(rootPtr->right, noatm);
    }
    
}

//CEK NOMINAL VALID ATAU TIDAK (untuk deposit dan oenarikan)
bool cek(int nominal) {
    if(nominal >= 50000 && (nominal % 25000) == 0){
        return true;
    } else if (nominal >= 20000 && (nominal % 20000 == 0)){
        return true;
    } else{
        return false;
    }
    
    
}

int cek_saldo(int noaAtm){
    fp = fopen("saldo_nasabah.txt", "r");

    //data yg dibaca file
    int noAtm_file, saldo_file;

    //baca file sampai no atm ketemu
    while (fscanf(fp, "%d %d\n", &noAtm_file, &saldo_file) != EOF){
        if (noAtm_file == noaAtm){
            fclose(fp);
            return saldo_file;
        }
        
        
    }
    return -1; //error
}

void tambah_saldo(int noAtm, int saldo_tambahan){
    fp = fopen("saldo_nasabah.txt", "r");
    fp1 = fopen("backup.txt", "w");

    // data yang di baca dari file
    int noAtm_file, saldo_file;

    while (fscanf(fp, "%d %d\n", &noAtm_file, &saldo_file) != EOF){
        //jika no atm sudah ditemukan, tambah saldonya
        if(noAtm_file == noAtm){
            saldo_file += saldo_tambahan;
        }
        //copy data ke file backup
        fprintf(fp1, "%d %d\n", noAtm_file, saldo_file);
    }
    fclose(fp);
    fclose(fp1);
    remove("saldo_nasabah.txt");
    rename("backup.txt", "saldo_nasabah.txt");
}

int kurangi_saldo(int noAtm, int nominal) {
    fp = fopen("saldo_nasabah.txt", "r");
    fp1 = fopen("backup.txt", "w");

    // data yg dibaca dari file
    int noAtm_file, saldo_file;

    int kode; // 1 = berhasil, -1 = gagal

    while (fscanf(fp, "%d %d\n", &noAtm_file, &saldo_file) != EOF) {
        //jika no atm ditemukan
        if(noAtm_file == noAtm){
            saldo_file -= nominal;
            //penarikan berhasil
            kode = 1;
        } else{
            // saldo tidak cukup (penarikan gagal)
            kode = -1;
        }
        // copy data file backup
        fprintf(fp1, "%d %d\n", noAtm_file, saldo_file);
    }
    fclose(fp);
    fclose(fp1);
    remove("saldo_nasabah.txt");
    rename("backup.txt", "saldo_nasabah.txt");

    return kode;
}

void transfer(tree *roorPtr, int noAtmAsal) {  // rootPtr agar bisa search bst
    //masukan no atm tujuan, search
    //jika gak ada break dari case
    // jika ada, masukin saldo nominal
    // kali cukup saldo asal kurangi, saldi tujuan


    // input rekening tujuan
    int noTujuan;
    printf("Masukan No Rekening Tujuan : ");
    scanf("%d", &noTujuan);

    // input nominal
    int nominal;
    printf("Masukan Nominal yang ingin di transfer : ");
    scanf("%d", &nominal);

    // print data, minta confirmasi
    struct tm *Sya_T;                                      
    time_t Tval;
    Tval = time(NULL);
    Sya_T = localtime(&Tval);
    tree *penerima = search(roorPtr, noTujuan);
    tree *asal = search(roorPtr, noAtmAsal);
    printf("  =========================================\n");
    printf("  <--------- Konfirmasi Transaksi -------->\n");
    printf("  =========================================\n");
    printf("   Tanggal : %d:%d:%d, %d/%d/%d\n", Sya_T->tm_hour, Sya_T->tm_min, Sya_T->tm_sec, Sya_T->tm_mday, Sya_T->tm_mon+1, 1900+Sya_T->tm_year);
    printf("  -----------------------------------------\n");
    printf("   Sumber Dana : %s\n", asal->nama);
    printf("   Rekening Tujuan : %d \n", penerima->no_ATM);
    printf("   Nama Tujuan : %s\n", penerima->nama);
    printf("  -----------------------------------------\n");
    printf("   Nominal : %d\n", nominal);
    printf("   Tax     : 5000 \n", nominal);
    printf("  -----------------------------------------\n");
    printf("   Total : %d \n", nominal + 5000);
    printf("  =========================================\n");
    
    int konfirm;
    if(konfirm != 1){
        printf("\n Transaksi Batal");
    } else{
        if (kurangi_saldo(noAtmAsal, nominal) == 1){
            tambah_saldo(noTujuan, nominal);
            printf("\nTransaksi Berhasil!!");
        } else {
            printf("\nTransakasi Gagal");
        }
        
    }
    
}

void header(){
    printf("||==========================================||\n");
    printf("|| **************  ATM BANK *************** ||\n");
    printf("||==========================================||\n");
}


int main(){
    // buat pohon kosong
    tree *rootPtr = NULL;

    // untuk local time
    struct tm *Sya_T;                                      
    time_t Tval;
    Tval = time(NULL);
    Sya_T = localtime(&Tval);

    //masukan data nasabah ke bst
    rootPtr = buat_nasabah(rootPtr);

    int noAtm, pin;
    int ada = 0;
    int i = 0;

    // menu pilihan user
    int pilih, pilih1;
    char ulang;

    tree *data_user; // data yang dicari user
        printf("||==========================================||\n");
        printf("|| **************  ATM BANK *************** ||\n");
        printf("||==========================================||\n");
        printf("||------------------------------------------||\n");
        printf("||                                          ||\n");
        printf("||                1. MASUK                  ||\n");
        printf("||                2. KELUAR                 ||\n");
        printf("||------------------------------------------||\n");
        printf("||==========================================||\n");
        printf("\tMasukan Pilihan : ");
        scanf("%d", &pilih);
        system("cls");
        switch (pilih)
        {
        case 1:
            header();
            while (i < 3 && ada == 0){
            printf("\nMasukan Nomor ATM : ");
            scanf("%d", &noAtm);
            printf("Masukan PIN : ");
            scanf("%d", &pin);

            data_user = search(rootPtr, noAtm);

            if (data_user != 0) {
                if(data_user->PIN != pin) {
                    printf("\n PIN salah !!!");
            } else {
                ada = 1;
            }
            
            } else {
                // jika sudah 3 kali salah maka exit
                if (i >= 2) {
                    printf("\nnomor ATM dan PIN tidak valid\n");
                    exit(1);
                }
                printf("\nno ATM tidak valid silahkan ulang . . .");
            }
            i++;
            
            
        }
        default:
            break;
        }

    int saldo;
    int nominal; // nominal yang di tabung, ditarik, dan di trasnfer
    do{
    system("cls");
    printf("||==========================================||\n");
    printf("|| **************  ATM BANK *************** ||\n");
    printf("||==========================================||\n");
    printf("||------------------------------------------||\n");
    printf("|| MENU :                                   ||\n");
    printf("|| 1. Cek Saldo                             ||\n");
    printf("|| 2. Deposit                               ||\n");
    printf("|| 3. Penarikan                             ||\n");
    printf("|| 4. Transfer                              ||\n");
    printf("|| 5. Keluar                                ||\n");
    printf("||------------------------------------------||\n");
    printf("||==========================================||\n");
    printf("  Input Pilihan : ");
    scanf("%d", &pilih1);
    switch (pilih1){
    case 1: // cek saldo

        saldo = cek_saldo(data_user->no_ATM);
        printf("||=========================================||\n");
        printf("   Tanggal : %d/%d/%d \n", Sya_T->tm_mday, Sya_T->tm_mon+1, 1900+Sya_T->tm_year);
        printf("||-----------------------------------------||\n");
        printf("   Saldo Anda : %d \n", saldo);
        printf("||=========================================||\n");

        break;
    case 2: // deposit
        // masukkan nominal dan akan diulang jika tidak valid
        do
        {
            printf("Masukan Nominal Yang Ingin Di Tabung : ");
            scanf("%d", &nominal);

            //cek valid atau tidak
            if (cek(nominal)){
                tambah_saldo(data_user->no_ATM, nominal);
                saldo = cek_saldo(data_user->no_ATM);
                printf("\nNominal valid\n");
                system("cls");
                printf("||=========================================||\n");
                printf("   Tanggal : %d/%d/%d \n", Sya_T->tm_mday, Sya_T->tm_mon+1, 1900+Sya_T->tm_year);
                printf("||-----------------------------------------||\n");
                printf("   Nominal : %d\n", nominal);
                printf("   Totals saldo : %d\n", saldo);
                printf("||-----------------------------------------||\n");
                printf("||   Deposit Yang Anda masukan berhasil    ||\n");
                printf("||   <---------> Dideposit <---------->    ||\n");
                printf("||=========================================||\n");
            } else
            {
                printf("\nNominal Tidak Valid!!\n");
            }
            printf("\n");
            
        } while (!cek(nominal));
        break;
    case 3: // penarikan

        do
        {
            printf("Masukan Nominal Yang Ingin Di Tarik : ");
            scanf("%d", &nominal);

            //cek valid atau tidak
            if (cek(nominal)){
                printf("\nNominal valid\n");
                kurangi_saldo(data_user->no_ATM, nominal);
                printf("\nPena Berhasil!!\n");
            } else
            {
                printf("\nNominal Tidak Valid!!\n");
            }
            printf("\n");
            
        } while (!cek(nominal));
        break;
    case 4: // transfer

        transfer(rootPtr, data_user->no_ATM);
        break;

    case 5:
        exit(0);
    default:
        printf("\nMenu Tidak Tersedia\n");
    }
    fflush(stdin);
    printf("Lanjutkan Transaksi?? (y/n) : ");
    scanf("%c", &ulang);
        
    } while(ulang == 'y' || ulang == 'Y');

    return 0;
    
}



















