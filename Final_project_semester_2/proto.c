#include <stdio.h>
void menu()
{

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

}
void struct_transfer()
{
    printf("||=========================================||\n");
    printf("|| <-------- Transaksi Berhasil ---------->||\n");
    printf("||=========================================||\n");
    printf("|| Tanggal :                               ||\n");
    printf("||-----------------------------------------||\n");
    printf("|| Sumber Dana :                           ||\n");
    printf("|| Rekening Tujuan :                       ||\n");
    printf("|| Nama Tujuan :                           ||\n");
    printf("||-----------------------------------------||\n");
    printf("|| Nominal :                               ||\n");
    printf("||-----------------------------------------||\n");
    printf("|| Total :                                 ||\n");
    printf("||=========================================||\n");
}

void info_saldo()
{
    printf("||=========================================||\n");
    printf("|| Tanggal :                               ||\n");
    printf("||-----------------------------------------||\n");
    printf("|| Saldo Anda :                            ||\n");
    printf("||=========================================||\n");

}
void tampilan_deposit()
{
    printf("||=========================================||\n");
    printf("|| Tanggal :                               ||\n");
    printf("||-----------------------------------------||\n");
    printf("|| Masukan Nominal Tabungan :              ||\n");
    printf("||-----------------------------------------||\n");
    printf("||   Deposit Yang Anda masukan berhasil    ||\n");
    printf("||   <---------> Dideposit <---------->    ||\n");
    printf("||=========================================||\n");
}
void tampilan_penarikan()
{
    printf("||========================================||\n");
    printf("|| Tanggal :                              ||\n");
    printf("|| No. Rekening :                         ||\n");
    printf("||----------------------------------------||\n");
    printf("|| Tarik Tunai                            ||\n");
    printf("||----------------------------------------||\n");
    printf("|| Jumlah :                               ||\n");
    printf("|| Saldo :                                ||\n");
    printf("||----------------------------------------||\n");
    printf("||########## Transaksi Berhasil ##########||\n");
    printf("||========================================||\n");
}
