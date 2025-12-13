#include "pemutarMusik.h"
listLagu LL;
listAkun LA;
listPlaylist LP;

adrAkun A;
adrLagu L;
adrPlaylist P;
void adminMenu() {
    int pilih;
    bool admin = true ;
    cout << "--- Admin Menu ---" << endl;
    cout << "1. Tambah lagu\n";
    cout << "2. Lihat semua lagu\n";
    cout << "3. Edit lagu\n";
    cout << "4. Hapus lagu\n";
    cout << "5. Lihat semua akun\n";
    cout << "6. Logout\n";
    cout << "Pilih 1/2/3/4/5/6: ";
    cin >> pilih;
while (admin){
    if (pilih == 1){
        insertLagu(LL, L);
    }else if (pilih == 2){
        showLagu(LL);
    }else if (pilih == 3){
        updateLagu(LL);
    }else if (pilih == 4){
        deleteLagu(LL, L);
    }else if (pilih == 5){
        showAkun(LA);
    }else if(pilih == 6){
        admin = false;
    }
}
}

void userMenu(listLagu &LL, listPlaylist &LP, listAkun &LA) {
    int pilih;
    bool user = true;
    string judulLagu;

    cout << "\n--- User Menu ---\n";
    cout << "1. Lihat Library\n";
    cout << "2. Cari lagu berdasarkan judul\n";
    cout << "3. Play lagu dari library\n";
    cout << "4. Kelola Playlist (buat/hapus/lihat/tambah/hapus lagu)\n";
    cout << "5. Lihat playlist akun lain\n";
    cout << "6. Mengambil Playlist user lain \n";
    cout << "7. Logout\n";
    cout << "Pilih 1/2/3/4/5/6: ";
    cin >> pilih;
while (user){
    if(pilih == 1){
        showLagu(LL);
        cout << "Kembali ke menu";
    }else if (pilih == 2){
        cout << "--- Cari Lagu Berdasarkan Judul ---";
        cout << "Masukkan judul lagu yang ingin dicari: ";
        cin >> judulLagu;
        if (findLaguByJudul(LL, judulLagu) != nullptr){
            cout << "Lagu ditemukan!" << endl;
        }else{
            cout << "Lagu tidak ditemukan " << endl;
        }
    }else if(pilih == 3){
        playLaguFromLibrary(LL);
    }else if(pilih == 4){
        //kelola playlist();
    }else if(pilih == 5){
        //PlaylistAkunLain();
    }else if (pilih == 6){
        //malingplaylist
    }else if(pilih == 7){
        user = false;
    }
}
}

void menuUtama() {
    listAkun LA;
    createListAkun(LA);
    listPlaylist LP;
    listLagu LL;
    adrAkun A, cariAkun;
    string username, password;

    while (true) {
        int pilihan;
        cout << "Selamat Datang" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih 1/2/3 : ";
        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            int x;
            cout << "1. Login as user" << endl;
            cout << "2. Login as admin" << endl;
            cout << "Pilih 1/2 : ";
            cin >> x;
            cout << endl;

            if (x == 1) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                cariAkun = findAkun(LA, username);
				if(cariAkun->role != "user"){
                    cout << "Akun tidak ditemukan sebagai user!";
				}else{
                    userMenu(LL, LP, LA);
				}
            } else if (x == 2) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                cariAkun = findAkun(LA, username);
				if(cariAkun->role != "admin"){
                    cout << "Akun tidak ditemukan sebagai admin!";
				}else{
                    adminMenu();
				}
            } else {
                cout << "Pilihan salah!\n";
            }

            cout << endl;
        }
        else if (pilihan == 2) {
            string username, password, role;

            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;
            cout << "Role (User/Admin) : ";
            cin >> role;

            adrAkun A = createakun(username, password, role);
            insertAkun(LA, A);

            cout << "\nRegistrasi berhasil! Kembali ke menu utama...\n\n";
            // otomatis kembali ke atas karena while(true)
        }
        else if (pilihan == 3) {
            cout << "Keluar program...\n";
            break;      // keluar dari while → program selesai
        }
        else {
            cout << "Pilihan tidak valid!\n\n";
        }
    }
}
int main()
{

    listAkun LA;
    listPlaylist LP;
    listLagu LL;
    menuUtama();
  //  displayUtama(LA, LP, LL);
    return 0;

}
