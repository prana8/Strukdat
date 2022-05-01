#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct List
{
    int saldo;
};
void penyimpanan(int n, List uang){
    printf("Masukan Jublah Uang : Rp. ");
    scanf("%d", &uang.saldo);
    printf("Uang berhasil tersimpan!!!\n");
    printf("Jumblah Saldo : %d\n", uang.saldo);

};




int main(){
    int bahasa, menu, n;
    List uang;
    char yn;
    
    printf("========================\n");
    printf("=     Program Atm      =\n");
    printf("========================\n");

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
    printf("========================\n");
    printf("=     Program ATM      =\n");
    printf("========================\n");

    printf("Menu : \n");
    printf("1. Cek Saldo\n");
    printf("2. Penyimpanan\n");
    printf("3. Penarikan\n");
    printf("4. Transfer\n");
    printf("Masukan Pilihan Menu : ");
    scanf("%d", &menu);
    if (menu==2)
    {
        penyimpanan(n, uang);
        lanjut:
        printf("Lanjutkan Transaksi?? (y/n) : ");
        scanf("%c", &yn);
        if ((yn == 'y' || yn == 'Y'))
        {
            goto awal;
        }
        else if ((yn == 'n' || yn == 'N'))
        {
            break;
        }
        else
        {
            goto lanjut;
        }
        
        
        
    }
    

        break;
    case 2 :
    system("cls");
    printf("========================\n");
    printf("=     ATM Program      =\n");
    printf("========================\n");

    printf("Menu : \n");
    printf("1. Inquiry\n");
    printf("1. Top Up\n");
    printf("2. Withdrawal\n");
    printf("3. Transfer\n");

    printf("Input The Menu : ");
    scanf("%d",&menu);

    default:
        break;
    
    }
}
