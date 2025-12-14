#include "pemutarMusik.h"

void dataDummy(listLagu &LL, listAkun &LA, listPlaylist &LP, listPlaylistToLagu &LPL, listPlaylistToAkun &LPA){
    insertAkun(LA, createakun("rai","123", "admin"));
    insertAkun(LA, createakun("hasna","123", "user"));
    insertAkun(LA, createakun("irfan","123", "user"));

    insertLagu(LL, createLagu("01", "Talking-To-The-Moon", "Bruno-Mars", "Pop", 3));
    insertLagu(LL, createLagu("02", "Creep", "Radiohead", "Alt-Rock", 3));
    insertLagu(LL, createLagu("03", "Bohemian-Rhapsody", "Queen", "Rock", 6));
    insertLagu(LL, createLagu("04", "Ocean-And-Engines", "NIKI", "RnB", 3));
    insertLagu(LL, createLagu("05", "Love.", "Wave-to-Earth", "RnB", 3));
    insertLagu(LL, createLagu("06", "Best-Friend", "Rex-Orange-County", "Pop", 4));
    insertLagu(LL, createLagu("07", "Promise", "Laufey", "Jazz", 3));
    insertLagu(LL, createLagu("08", "Nocturne-Op.9-No.2", "Frederic-Chopin", "Classical", 5));
    insertLagu(LL, createLagu("09", "Viva-La-Vida", "Coldplay", "Pop", 2));
    insertLagu(LL, createLagu("10", "Counting-Stars", "One-Republic", "Pop", 3));
    insertLagu(LL, createLagu("11", "Rolling-In-The-Deep", "Adele", "Pop", 4));
    insertLagu(LL, createLagu("12", "Pump-It", "The-Black-Eyed-Peas", "R&B", 3));
    insertLagu(LL, createLagu("13", "Dream-On", "Aerosmith", "Rock", 4));
    insertLagu(LL, createLagu("14", "That's-Life", "Frank-Sinatra", "Pop", 3));
    insertLagu(LL, createLagu("15", "Alone", "Alan-Walker", "Dance/Electronic", 3));

    insertPlaylist(LP, createPlaylist("asik", "1"));
    insertPlaylist(LP, createPlaylist("nostalgic", "2"));
    insertPlaylist(LP, createPlaylist("mixed", "3"));

    connectPlaylistToLagu(LPL, LP, LL, "1", "Viva-La-Vida");
    connectPlaylistToLagu(LPL, LP, LL, "1", "Alone");
    connectPlaylistToLagu(LPL, LP, LL, "1", "Pump-It");
    connectPlaylistToLagu(LPL, LP, LL, "1", "Counting-Stars");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Nocturne-Op.9-No.2");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Bohemian-Rhapsody");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Counting-Stars");
    connectPlaylistToLagu(LPL, LP, LL, "2", "That's-Life");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Alone");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Talking-To-The-Moon");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Pump-It");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Rolling-In-The-Deep");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Creep");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Best-Friend");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Promise");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Ocean-And-Engines");

    connectPlaylistToAkun(LPA, LP, LA, "2", "hasna");
    connectPlaylistToAkun(LPA, LP, LA, "3", "irfan");

};
void adminMenu(listLagu &LL, listAkun &LA, listPlaylistToLagu &LPL) {
    int pilih;
    adrLagu L, cekLagu;
    string idLagu, judulLagu, artisLagu, genreLagu;
    int durasiLagu;
    bool admin = true;
    while (admin){
        cout << "=============================" << endl;
        cout << "          ADMIN MENU         " << endl;
        cout << "=============================" << endl;
        cout << "| 1. Tambah lagu             |\n";
        cout << "| 2. Lihat semua lagu        |\n";
        cout << "| 3. Edit lagu               |\n";
        cout << "| 4. Hapus lagu              |\n";
        cout << "| 5. Lihat semua akun        |\n";
        cout << "| 6. Logout                  |\n";
        cout << "=============================" << endl;
        cout << "Pilih 1-6: ";
        cin >> pilih;
        cout << "-----------------------------" << endl;

        if (pilih == 1){
            showLagu(LL);
            cout << "-----------------------------" << endl;
            cout << "         MENAMBAH LAGU       " << endl;
            cout << "-----------------------------" << endl;
            cout << "ID lagu: ";
            cin >> idLagu;
            cout << "Judul Lagu: ";
            cin >> judulLagu;
            cout << "Penyanyi: ";
            cin >> artisLagu;
            cout << "Genre: ";
            cin >> genreLagu;
            cout << "Durasi: ";
            cin >> durasiLagu;
            cout << "-----------------------------" << endl;

            adrLagu cekLagu = findLaguByID(LL, idLagu);
            if (cekLagu != nullptr){
                cout << "ID lagu sudah dipakai" << endl;
            }else{
                insertLagu(LL, createLagu(idLagu, judulLagu, artisLagu, genreLagu, durasiLagu));
                cout << "Lagu berhasil ditambahkan!" << endl;
            }
            showLagu(LL);
        }else if (pilih == 2){
            showLagu(LL);
        }else if (pilih == 3){
            showLagu(LL);
            updateLagu(LL);
        }else if (pilih == 4){
            cout << "-----------------------------" << endl;
            cout << "          HAPUS LAGU         " << endl;
            cout << "-----------------------------" << endl;
            showLagu(LL);
            cout << "ID lagu yang ingin dihapus: ";
            cin >> idLagu;
            cout << "-----------------------------" << endl;
            cekLagu = findLaguByID(LL, idLagu);
            if(cekLagu != nullptr){
                deleteLagu(LL, LPL, cekLagu);
                cout << "Lagu berhasil dihapus!" << endl;
            }
        }else if (pilih == 5){
            showAkun(LA);
        }else if(pilih == 6){
            admin = false;
        }else{
            cout << "Pilihan salah!" << endl;
        }
    }
}
void userMenu(listLagu &LL, listPlaylist &LP, listAkun &LA, listPlaylistToLagu &LPL, listPlaylistToAkun &LPA, string username) {
    int pilih, opsiPlaylist;
    bool user = true;
    bool playlist;
    string judulLagu, namaPlaylist, idPlaylist, idLagu;
    string inputUsername, userAktif = username;
    adrLagu lagu;
    adrPlaylist cekPlaylist, P;
    adrPlaylistToAkun cekPlaylistAkun;
    adrPlaylistToLagu cekPlaylistLagu, currentPlaylist, nextPlaylist;
    adrAkun cekAkun;
    while (user){
        cout << "=============================" << endl;
        cout << "           USER MENU         " << endl;
        cout << "=============================" << endl;
        cout << "1. Lihat Library\n";
        cout << "2. Cari lagu berdasarkan judul\n";
        cout << "3. Play lagu dari library\n";
        cout << "4. Play lagu dari playlist \n";
        cout << "5. Kelola Playlist\n";
        cout << "6. Lihat playlist akun lain\n";
        cout << "7. Update Akun \n";
        cout << "8. Logout\n";
        cout << "=============================" << endl;
        cout << "Pilih 1-8: ";
        cin >> pilih;
        cout << "-----------------------------" << endl;
        if(pilih == 1){
            showLagu(LL);
        }else if (pilih == 2){
            cout << "-----------------------------" << endl;
            cout << " Cari Lagu Berdasarkan Judul " << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan judul lagu yang ingin dicari: ";
            cin >> judulLagu;
            cout << "-----------------------------" << endl;
            lagu = findLaguByJudul(LL, judulLagu);
            if (lagu != nullptr){
                cout << "Lagu ditemukan!" << endl;
                cout << "[" << lagu->idLagu << "] " << lagu->judul << " by " << lagu->artis << " | Genre: " << lagu->genre << " | Durasi: " << lagu->durasi << endl;
                cout << "-----------------------------" << endl;
            }else{
                cout << "Lagu tidak ditemukan!" << endl;
                cout << "-----------------------------" << endl;
            }
        }else if(pilih == 3){
            playLaguFromLibrary(LL);
        }else if(pilih == 4){
            playLaguFromPlaylist(LP, LPL, LPA, userAktif);
        }else if(pilih == 5){
            playlist = true;
            while (playlist){
                cout << "-----------------------------" << endl;
                cout << "        Kelola Playlist      " << endl;
                cout << "-----------------------------" << endl;
                cout << "1. Membuat playlist baru \n";
                cout << "2. Menghapus playlist \n";
                cout << "3. Lihat playlist \n";
                cout << "4. Menambah lagu ke playlist \n";
                cout << "5. Hapus lagu dari playlist \n";
                cout << "6. Ubah nama playlist \n";
                cout << "7. kembali ke menu utama \n";
                cout << "-----------------------------" << endl;
                cout << "Pilih opsi playlist 1-7: ";
                cin >> opsiPlaylist;
                cout << "-----------------------------" << endl;
                if (opsiPlaylist == 1){
                    cout << "-----------------------------" << endl;
                    cout << "       Membuat Playlist      " << endl;
                    cout << "-----------------------------" << endl;
                    cout << "Nama Playlist: ";
                    cin >> namaPlaylist;
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    cout << "-----------------------------" << endl;
                    cekPlaylist = findPlaylistById(LP, idPlaylist);
                    if(cekPlaylist != nullptr){
                        cout << "ID playlist sudah dipakai" << endl;
                    }else{
                        insertPlaylist(LP, createPlaylist(namaPlaylist, idPlaylist));
                        connectPlaylistToAkun(LPA, LP, LA, idPlaylist, username);
                        cout << "Playlist berhasil dibuat!" << endl;
                    }
                }else if(opsiPlaylist == 2){
                    cout << "-----------------------------" << endl;
                    cout << "      Menghapus Playlist     " << endl;
                    cout << "-----------------------------" << endl;
                    showPlaylist(LP, LPA, username);
                    cout << "id playlist: ";
                    cin >> idPlaylist;
                    cout << "-----------------------------" << endl;
                    if(findPlaylistById(LP, idPlaylist) != nullptr){
                        cekPlaylistAkun = findPlaylistAkun(LPA, idPlaylist, username);
                        P = cekPlaylistAkun->playlist;
                        currentPlaylist = LPL.first;
                        nextPlaylist = currentPlaylist->next;
                        if(currentPlaylist->playlist == P){
                            deletePlaylistToLagu(LPL, currentPlaylist);
                        }
                        currentPlaylist = nextPlaylist;
                        disconnectPlaylistToAkun(LPA, idPlaylist, username);
                        deletePlaylist(LP, cekPlaylistAkun->playlist);
                        cout << cekPlaylistAkun->playlist->namaPlaylist << " berhasil dihapus!" << endl;
                    }else{
                        cout << "ID Playlist tidak ditemukan!" << endl;
                    }
                }else if(opsiPlaylist == 3){
                    printPlaylistToLagu(LPL, LP, LPA, username);
                }else if(opsiPlaylist == 4){
                    cout << "----------------------------------" << endl;
                    cout << "Menambahkan Lagu ke Dalam Playlist" << endl;
                    cout << "----------------------------------" << endl;
                    showPlaylist(LP, LPA, username);
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    cout << "----------------------------------" << endl;
                    if(findPlaylistAkun(LPA, idPlaylist, username) != nullptr){
                        showLagu(LL);
                        cout << "Judul Lagu: ";
                        cin >> judulLagu;
                        if(findLaguByJudul(LL, judulLagu) != nullptr){
                            connectPlaylistToLagu(LPL, LP, LL, idPlaylist, judulLagu);
                            cout << judulLagu << " berhasil ditambahan ke playlist ID " << idPlaylist << endl;
                            printPlaylistToLagu(LPL, LP, LPA, username);
                        }else{
                            cout << "Lagu tidak ditemukan!" << endl;
                        }

                    }else{
                        cout << endl << "Belum ada playlist yang terdaftar!" << endl;
                    }

                }else if(opsiPlaylist == 5){
                    cout << "------------------------------" << endl;
                    cout << " Menghapus Lagu pada Playlist " << endl;
                    cout << "------------------------------" << endl;
                    printPlaylistToLagu(LPL, LP, LPA, username);
                    cout << "------------------------------" << endl;
                    cout << "Masukkan ID Playlist dan judul lagu yang ingin dihapus" << endl;
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    cout << "------------------------------" << endl;
                    if (findPlaylistAkun(LPA, idPlaylist, username) != nullptr){
                        cout << "Judul Lagu: ";
                        cin >> judulLagu;
                        disconnectPlaylistToLagu(LPL, idPlaylist, judulLagu, LPA, username);
                        cout << judulLagu << " berhasil dihapus dari playlist ber-ID " << idPlaylist << endl;
                        printPlaylistToLagu(LPL, LP, LPA, username);
                    }else{
                        cout << "Belum ada playlist yang terdaftar!" << endl;
                    }
                }else if(opsiPlaylist == 6){
                    printPlaylistToLagu(LPL, LP, LPA, userAktif);
                    updatePlaylist(LP, LPA, userAktif);
                }else if(opsiPlaylist == 7){
                    playlist = false;
                }
            }
        }else if(pilih == 6){
            cout << "------------------------------" << endl;
            cout << "  Melihat Playlist Akun Lain  " << endl;
            cout << "------------------------------" << endl;
            cout << "Masukan username: ";
            cin >> inputUsername;
            cout << "------------------------------" << endl;
            cekAkun = findAkun(LA, inputUsername);
            if(cekAkun->role == "user"){
                printPlaylistToLagu(LPL,LP, LPA, inputUsername);
                cout << endl;
            }else{
                cout << inputUsername << " bukan sebagai user" << endl;
            }
        }else if(pilih == 7){
            updateAkun(LA, userAktif);
        }else if(pilih == 8){
            user = false;
        }
    }
}
void menuUtama(listLagu &LL, listPlaylist &LP, listAkun &LA, listPlaylistToLagu &LPL, listPlaylistToAkun &LPA) {
    adrAkun A, cariAkun;
    string username, password;

    while (true) {
        int pilihan;
        cout << "=============================" << endl;
        cout << "|        SELAMAT DATANG     |" << endl;
        cout << "=============================" << endl;
        cout << "|  1. Login                 |" << endl;
        cout << "|  2. Register              |" << endl;
        cout << "|  3. Exit                  |" << endl;
        cout << "-----------------------------"<< endl;
        cout << "Pilih 1/2/3 : ";
        cin >> pilihan;


        if (pilihan == 1) {
            int x;
            cout << "-----------------------------" << endl;
            cout << "| 1. Login as User          |" << endl;
            cout << "| 2. Login as Admin         |" << endl;
            cout << "-----------------------------" << endl;
            cout << "| Pilih 1/2 : ";
            cin >> x;
            cout << "-----------------------------" << endl;

            if (x == 1) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                cout << "-----------------------------" << endl;

                cariAkun = findAkun(LA, username);
                if(cariAkun == nullptr){
                    cout << "Username tidak ditemukan!\n";
                }else if(cariAkun->password != password){
                    cout << "Password salah!\n";
                }else if(cariAkun->role == "user"){
                    userMenu(LL, LP, LA, LPL, LPA, username);
                }else{
                    cout << "Akun bukan user!\n";
                }
            } else if (x == 2) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                cout << "-----------------------------" << endl;

                cariAkun = findAkun(LA, username);
                if(cariAkun == nullptr){
                    cout << "Username tidak ditemukan!\n";
                }else if(cariAkun->password != password){
                    cout << "Password salah!\n";
                }else if(cariAkun->role == "admin"){
                    adminMenu(LL, LA, LPL);
                }else{
                    cout << "Akun bukan admin!\n";
                }
            } else {
                cout << "Pilihan salah!\n";
            }

            cout << endl;
        }
        else if (pilihan == 2) {
            string username, password, role;

            cout << "-----------------------------" << endl;
            cout << "| Username : ";
            cin >> username;
            cout << "| Password : ";
            cin >> password;
            cout << "| Role (User/Admin) : ";
            cin >> role;
            cout << "-----------------------------" << endl;

            cariAkun = findAkun(LA, username);
            if(cariAkun != nullptr){
                cout << "Username sudah dipakai! \n";
            }else{
                insertAkun(LA, createakun(username, password, role));
                cout << "\nRegistrasi berhasil! Kembali ke menu utama...\n";
            }
            cout << endl;
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
    listPlaylistToLagu LPL;
    listPlaylistToAkun LPA;

    createListAkun(LA);
    createListLagu(LL);
    createListPlaylist(LP);
    createListPlaylistToAkun(LPA);
    createListPlaylistToLagu(LPL);

    dataDummy(LL, LA, LP, LPL, LPA);
    menuUtama(LL, LP, LA, LPL, LPA);
  //  displayUtama(LA, LP, LL);
    return 0;

}
