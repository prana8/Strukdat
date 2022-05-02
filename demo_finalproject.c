#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct rekening
{
    int saldo;
};

void cek_saldo_indo(rekening rek){
    time_t waktu;
    time (&waktu);
    system("cls");
    printf(ctime(&waktu));
    printf("=========================\n");
    printf("=      Program Atm      =\n");
    printf("=========================\n");
    printf("   INFORMASI SALDO\n\n");
    printf("SALDO : Rp.%d\n\n", rek.saldo);
}
void cek_saldo_ing(rekening rek){
    time_t waktu;
    time (&waktu);
    system("cls");
    printf(ctime(&waktu));
    printf("=========================\n");
    printf("=      Program Atm      =\n");
    printf("=========================\n");
    printf("   INQUIRY INFORMATION\n\n");
    printf("BALANCE : Rp.%d\n\n", rek.saldo);
}

int main(){
    int bahasa, menu, n = 0,  i, setor;
    rekening rek;
    char yn;
    
    printf("=========================\n");
    printf("=      Program Atm      =\n");
    printf("=========================\n");
    printf("Selamat Datang Di Bank Kami\n");
    printf("Pilih Bahasa\n");
    printf("[1]. INDONESIA\n");
    printf("[2]. ENGLISH\n");

    printf("Masukan Pilihan ([1]/[2]) : ");
    scanf("%d", &bahasa);

    switch (bahasa)
    {
    case 1:
    awal:
    system("cls");
    printf("=========================\n");
    printf("=      Program ATM      =\n");
    printf("=========================\n");

    printf("Menu : \n");
    printf("1. Cek Saldo\n");
    printf("2. Penyimpanan\n");
    printf("3. Penarikan\n");
    printf("4. Transfer\n");
    printf("5. Selesai\n");
    printf("Masukan Pilihan Menu : ");
    scanf("%d", &menu);
    if (menu==1){
        cek_saldo_indo(rek);
        lanjut1:
        fflush(stdin);
        printf("Lanjutkan Transaksi?? (y/n) : ");
        scanf("%c", &yn);
        if ((yn == 'y' || yn == 'Y')){
            goto awal;
        } else if ((yn == 'n' || yn == 'N')){
            break;
        }else{
            goto lanjut1;
        }
        
    }
    else if (menu==2)
    {
        system("cls");
        printf("=========================\n");
        printf("=      Program ATM      =\n");
        printf("=========================\n\n");
        printf("Masukan uang : Rp. ");
        scanf("%d", &setor);
        rek.saldo = rek.saldo + setor;
        printf("Uang Berhasil Tersimpan!!\n");
        printf("________________________\n");
        printf("Total Saldo : %d\n", rek.saldo);
        lanjut2:
        fflush(stdin);
        printf("Lanjutkan Transaksi?? (y/n) : ");
        scanf("%c", &yn);
        if ((yn == 'y' || yn == 'Y')){
            goto awal;

        } else if ((yn == 'N' || yn == 'n')){
            break;
        } else{
            goto lanjut2;
        }
        
    }
        break;
    case 2 :
    awal1:
    system("cls");
    printf("=========================\n");
    printf("=      ATM Program      =\n");
    printf("=========================\n");

    printf("Menu : \n");
    printf("1. Balance Inquiry\n");
    printf("2. Top Up\n");
    printf("3. Withdrawal\n");
    printf("4. Transfer\n");
    printf("5. Exit\n");

    printf("Input The Menu : ");
    scanf("%d",&menu);
     if (menu==1){
        cek_saldo_ing(rek);
        lanjut3:
        fflush(stdin);
        printf("continue transaction?? (y/n) : ");
        scanf("%c", &yn);
        if ((yn == 'y' || yn == 'Y')){
            goto awal1;
        } else if ((yn == 'n' || yn == 'N')){
            break;
        }else{
            goto lanjut3;
        }
        
    }
    else if (menu==2)
    {
        system("cls");
        printf("=========================\n");
        printf("=      Program ATM      =\n");
        printf("=========================\n\n");
        printf("Enter Amount : Rp. ");
        scanf("%d", &setor);
        rek.saldo = rek.saldo + setor;
        printf("done!!\n");
        printf("________________________\n");
        printf("Total Balance : %d\n", rek.saldo);
        lanjut4:
        fflush(stdin);
        printf("continue transaction (y/n) : ");
        scanf("%c", &yn);
        if ((yn == 'y' || yn == 'Y')){
            goto awal;

        } else if ((yn == 'N' || yn == 'n')){
            break;
        } else{
            goto lanjut4;
        }
        
    }

    default:
        break;
    
    }
    return 0;
}
