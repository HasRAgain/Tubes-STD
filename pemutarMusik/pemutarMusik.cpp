#include "pemutarMusik.h"

// LIST AKUN
adrAkun createakun(string username, string password, string role){
// Membuat elemen akun
    adrAkun A = new Akun;

    A->username = username;
    A->password = password;
    A->role = role;
    A->next = nullptr;
    A->prev = nullptr;

    return A;
}
void createListAkun(listAkun &LA){
// Membuat list akun
    LA.first = nullptr;
    LA.last = nullptr;
}
bool isEmptyAkun(listAkun LA){
// Mengecek apakah listAkun kosong atau tidak. listAkun kosong -> TRUE
    return LA.first == nullptr && LA.last == nullptr;
}
void insertAkun(listAkun &LA, adrAkun A){
// Memasukkan elemen akun ke bagian terakhir listAkun
    adrAkun username;
    if (isEmptyAkun(LA)){
        LA.first = A;
        LA.last = A;
    }else {
        //Mengecek apakah username akun sudah dipakai atau belum
        username = findAkun(LA, A->username);
        if(username != nullptr){
            cout << "Username sudah dipakai" << endl;
        }else {
            LA.last->next = A;
            A->prev = LA.last;
            LA.last = A;
        }
    }
}
void deleteFirstAkun(listAkun &LA, adrAkun A){
// Menghapus elemen pertama listAkun
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
        delete A;
    }else{
        A = LA.first;
        LA.first = A->next;
        A->prev = nullptr;
        A->next = nullptr;
        delete A;
    }
}
void deleteAfterAkun(listAkun &LA,adrAkun prec, adrAkun A){
// Menghapus elemen setelah prec pada listAkun
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun yang terdaftar" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
        delete A;
    }else{
        A = prec->next;
        prec->next = A->next;
        (A->next)->prev = prec;
        A->next = nullptr;
        A->prev = nullptr;
        delete A;
    }
}
void deleteLastAkun(listAkun &LA, adrAkun A){
//Menghapus elemen terakhir listAkun
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun yang terdaftar" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
        delete A;
    }else{
        A = LA.last;
        LA.last = A->prev;
        LA.last->next = nullptr;
        A->prev = nullptr;
        delete A;
    }
}
void deleteAkun(listAkun &LA, adrAkun A){
//menghapus elemen akun
    if(A == LA. first){
        deleteFirstAkun(LA, A);
    }else if (A == LA.last){
        deleteLastAkun(LA, A);
    }else{
        deleteAfterAkun(LA, A->prev, A);
    }
}
adrAkun findAkun(listAkun &LA, string username){
//Mencari akun berdasarkan username dan mengembalikan alamat elemen akun
    adrAkun A = LA.first;
    while(A != nullptr){
        if(A->username == username){
            return A;
        }
        A = A->next;
    }
    return nullptr;
}
void showAkun(listAkun LA){
//Menampilkan akun-akun yang terdaftar
    adrAkun A = LA.first;
    cout << "-----------------------------" << endl;
    cout << "      AKUN YANG TERDAFTAR    " << endl;
    cout << "-----------------------------" << endl;
    while (A != nullptr){
        cout << "- " << A->username << "(" << A->role << ")" << endl;
        A = A->next;
    }
    cout << endl;
}
void updateAkun(listAkun &LA, string userAktif){
//Mengubah username dan password akun yang sudah dicari berdasarkan username lama
    string usernameLama, usernameBaru, passwordBaru;
    adrAkun statusAkun;
    adrAkun A = LA.first;

    cout << "-----------------------------" << endl;
    cout << "         UPDATE AKUN         " << endl;
    cout << "-----------------------------" << endl;
    cout << "Masukkan username kamu: ";
    cin >> usernameLama;
    cout << "-----------------------------" << endl;
    statusAkun = findAkun(LA, usernameLama);

    if(statusAkun->username == userAktif){
        if(userAktif == statusAkun->username){
            cout << "-----------------------------" << endl;
            cout << "           Edit Akun         " << endl;
            cout << "-----------------------------" << endl;
            cout << "Masukkan username baru: ";
            cin >> usernameBaru;
            cout << "Masukkan password baru: ";
            cin >> passwordBaru;
            cout << "-----------------------------" << endl;

            statusAkun->username = usernameBaru;
            statusAkun->password = passwordBaru;

            cout << "Akun berhasil diubah" << endl;

        }else{
            cout << "Akun tidak ditemukan!" << endl;
            return;
        }
    }else{
        cout << "Anda bukan pemiliki akun " << usernameLama << endl;
    }

}
//LIST LAGU
adrLagu createLagu(string idLagu, string judul, string artis, string genre, int durasi){
//Membuat elemen lagu
    adrLagu L = new Lagu;

    L->idLagu = idLagu;
    L->judul = judul;
    L->artis = artis;
    L->genre = genre;
    L->durasi = durasi;
    L->next = nullptr;
    L->prev = nullptr;

    return L;
}
void createListLagu(listLagu &LL){
//Membuat list lagu
    LL.first = nullptr;
    LL.last = nullptr;
}
bool isEmptyLagu(listLagu LL){
//Mengecek apakah listLagu kosong atau tidak. listLagu kosong -> TRUE
    return LL.first == nullptr && LL.last == nullptr;
}
void insertLagu(listLagu &LL, adrLagu L){
//Memasukkan elemen lagu ke bagian akhir list lagu
    if (isEmptyLagu(LL)){
        LL.first = L;
        LL.last = L;
    }else {
        //Mengecek apakah idLagu sudah ada atau tidak
        adrLagu id = findLaguByID(LL, L->idLagu);
        if (id != nullptr){
            cout << "ID lagu sudah dipakai" << endl;
        }else{
            LL.last->next = L;
            L->prev = LL.last;
            LL.last = L;
        }
    }
}
void deleteFirstLagu(listLagu &LL, adrLagu L){
//Menghapus elemen pertama listLagu
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
        delete L;
    }else{
        L = LL.first;
        LL.first = L->next;
        L->prev = nullptr;
        L->next = nullptr;
        delete L;
    }
}
void deleteAfterLagu(listLagu &LL,adrLagu prec, adrLagu L){
//Menghapus elemen setelah prec pada listLagu
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
        delete L;
    }else{
        L = prec->next;
        prec->next = L->next;
        (L->next)->prev = prec;
        L->next = nullptr;
        L->prev = nullptr;
        delete L;
    }
}
void deleteLastLagu(listLagu &LL, adrLagu L){
//Menghapus elemen terakhir listLagu
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
        delete L;
    }else{
        L = LL.last;
        LL.last = L->prev;
        LL.last->next = nullptr;
        L->prev = nullptr;
        delete L;
    }
};
void deleteLagu(listLagu &LL, listPlaylistToLagu &LPL, adrLagu L){
//menghapus elemen lagu
    //menghapus lagu dari semua playlist
    deleteLaguFromAllPlaylist(LPL, L);
    if (L == LL.first){
        deleteFirstLagu(LL, L);
    }else if(L == LL.last){
        deleteLastLagu(LL, L);
    }else {
        deleteAfterLagu(LL, L->prev, L);
    }
}
adrLagu findLaguByID(listLagu LL, string id){
//Mencari elemen lagu berdasarkan id lagu
    adrLagu L = LL.first;
    while (L != nullptr){
        if(L->idLagu == id){
            return L;
        }
        L = L->next;
    }
    return nullptr;
}
adrLagu findLaguByJudul(listLagu LL, string judul){
//Mencari elemen lagu berdasarkan judul lagu
    adrLagu L = LL.first;
    while (L != nullptr){
        if(L->judul == judul){
            return L;
        }
        L = L->next;
    }
    return nullptr;
}
void showLagu(listLagu LL){
//menampilkan lagu di dalam library
    adrLagu L = LL.first;
    cout << "-----------------------------" << endl;
    cout << "      Lagu Yang Tersedia     " << endl;
    cout << "-----------------------------" << endl;
    while(L != nullptr){
        cout << "[" << L->idLagu << "] " << L->judul << " by " << L->artis << " | Genre: " << L->genre << " | Durasi: " << L->durasi << endl;
        L = L->next;
    }
    cout << endl;
}
void updateLagu(listLagu &LL){
//mengubah atribut lagu
    string idLagu, judulBaru, artisBaru, genreBaru;
    int durasiBaru;
    adrLagu statusLagu;

    cout << "-----------------------------" << endl;
    cout << "         UPDATE LAGU         " << endl;
    cout << "-----------------------------" << endl;
    cout << "Masukkan ID Lagu yang ingin diupdate: ";
    cin >> idLagu;
    cout << "-----------------------------" << endl;
    statusLagu = findLaguByID(LL, idLagu);

    if(statusLagu == nullptr){
        cout << "ID lagu tidak ditemukan!" << endl;
        return;
    }else{
        cout << "-----------------------------" << endl;
        cout << "          Edit Lagu          " << endl;
        cout << "-----------------------------" << endl;
        cout << "judul baru: ";
        cin >> judulBaru;
        cout << "Artis baru: ";
        cin >> artisBaru;
        cout << "genre baru: ";
        cin >> genreBaru;
        cout << "durasi baru: ";
        cin >> durasiBaru;
        cout << "-----------------------------" << endl;

        statusLagu->judul = judulBaru;
        statusLagu->artis = artisBaru;
        statusLagu->genre = genreBaru;
        statusLagu->durasi = durasiBaru;

        cout << "Lagu berhasil diubah!" << endl;
    }
}
//LIST PLAYLIST
adrPlaylist createPlaylist(string nama, string id){
//Membuat elemen plalist
    adrPlaylist P = new Playlist;

    P->namaPlaylist = nama;
    P->idPlaylist = id;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}
void createListPlaylist(listPlaylist &LP){
//membuat listPlaylist
    LP.first = nullptr;
    LP.last = nullptr;
}
bool isEmptyPlaylist(listPlaylist LP){
//Mengecek apakah listPlaylist kosong atau tidak. Jika kosong, maka true
    return LP.first == nullptr && LP.last == nullptr;
}
void insertPlaylist(listPlaylist &LP, adrPlaylist P){
//Memasukkan elemen playlist pada akhir list
    adrPlaylist idPlaylist;
    if (isEmptyPlaylist(LP)){
        LP.first = P;
        LP.last = P;
    }else {
        //mengecek apakah id playlist sudah dipakai atau belum
        idPlaylist = findPlaylistById(LP, P->idPlaylist);
        if(idPlaylist != nullptr){
            cout << "ID playlist sudah dipakai" << endl;
        }else{
            LP.last->next = P;
            P->prev = LP.last;
            LP.last = P;
        }
    }
}
void deleteFirstPlaylist(listPlaylist &LP, adrPlaylist P){
//Menghapus elemen pertama pada listPlaylist
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
        delete P;
    }else{
        P = LP.first;
        LP.first = P->next;
        P->prev = nullptr;
        P->next = nullptr;
        delete P;
    }
}
void deleteAfterPlaylist(listPlaylist &LP,adrPlaylist prec, adrPlaylist P){
//Menghapus elemen setelah prec pada listPlaylist
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
        delete P;
    }else{
        P = prec->next;
        prec->next = P->next;
        (P->next)->prev = prec;
        P->next = nullptr;
        P->prev = nullptr;
        delete P;
    }
}
void deleteLastPlaylist(listPlaylist &LP, adrPlaylist P){
//menghapus elemen terakhir pada listPlaylist
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
        delete P;
    }else{
        P = LP.last;
        LP.last = P->prev;
        LP.last->next = nullptr;
        P->prev = nullptr;
        delete P;
    }
};
void deletePlaylist(listPlaylist &LP, adrPlaylist P){
//menghapus elemen playlist
    if(P == LP.first){
        deleteFirstPlaylist(LP, P);
    }else if(P == LP.last){
        deleteLastPlaylist(LP, P);
    }else {
        deleteAfterPlaylist(LP, P->prev, P);
    }
}
adrPlaylist findPlaylistByName(listPlaylist LP, string namaPlaylist){
//mencari palyalist berdasarkan nama playlist
    adrPlaylist P = LP.first;

    while(P != nullptr){
        if(P->namaPlaylist == namaPlaylist){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
adrPlaylist findPlaylistById(listPlaylist LP, string idPlaylist){
//mencari playlist berdasarkan id playlist
    adrPlaylist P = LP.first;

    while(P != nullptr){
        if(P->idPlaylist == idPlaylist){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void showPlaylist(listPlaylist LP, listPlaylistToAkun LPA, string userAktif){
//menampilkan playlist yang terdaftar
    adrPlaylist P = LP.first;
    cout << "-----------------------------" << endl;
    cout << "   PLAYLIST YANG TERDAFTAR   " << endl;
    cout << "-----------------------------" << endl;
    while (P != nullptr){
        if(findPlaylistAkun(LPA, P->idPlaylist, userAktif) != nullptr){
            cout << "[" << P->idPlaylist << "] " << P->namaPlaylist << endl;
        }
        P = P->next;
    }
    cout << endl;
}
void updatePlaylist(listPlaylist &LP, listPlaylistToAkun LPA, string userAktif){
//mengupadate atribut playlist
    string namaLama, namaBaru;
    adrPlaylist statusPlaylist;
    adrPlaylist P = LP.first;
    adrPlaylistToAkun cekPlaylistAkun;

    cout << "-----------------------------" << endl;
    cout << "        UPDATE PLAYLIST      " << endl;
    cout << "-----------------------------" << endl;
    cout << "Masukkan nama playlist yang ingin diubah: ";
    cin >> namaLama;
    cout << "-----------------------------" << endl;
    statusPlaylist = findPlaylistByName(LP, namaLama);
    cekPlaylistAkun = findPlaylistAkun(LPA, statusPlaylist->idPlaylist, userAktif);
    if(cekPlaylistAkun != nullptr && statusPlaylist != nullptr){
        cout << "-----------------------------" << endl;
        cout << "          Edit Playlist      " << endl;
        cout << "-----------------------------" << endl;
        cout << "Masukkan nama playlist baru: ";
        cin >> namaBaru;
        cout << "-----------------------------" << endl;

        statusPlaylist->namaPlaylist = namaBaru;

        cout << "nama playlist berhasil diubah" << endl;
    }
}

//LIST RELASI PLAYLIST TO LAGU
adrPlaylistToLagu createRelasiPlaylistToLagu(adrPlaylist P, adrLagu L){
//membuat elemen relasi playlistToLagu
    adrPlaylistToLagu PL = new PlaylistToLagu;

    PL->playlist = P;
    PL->lagu = L;
    PL->next = nullptr;
    PL->prev = nullptr;

    return PL;
};
void createListPlaylistToLagu(listPlaylistToLagu &LPL){
//Membuat list relasi PlaylistToLgu
    LPL.first = nullptr;
    LPL.last = nullptr;
};
bool isEmptyPlaylistToLagu(listPlaylistToLagu LPL){
//mengecek apakah list playlistToLagu kosong atau tidak. jika kosong, maka mengembalikan true
    return LPL.first == nullptr && LPL.last == nullptr;
}
void insertPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL){
//memasukkan elemen playlistToLagu ke bagian akhir listPlaylistToLagu
    if(isEmptyPlaylistToLagu(LPL)){
        LPL.first = PL;
        LPL.last = PL;
    }else{
        LPL.last->next = PL;
        PL->prev = LPL.last;
        LPL.last = PL;
    }
}
void deleteFirstPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL){
//menghapus elemen pertama list PlaylistToLagu
    if(LPL.first == LPL.last){
        PL = LPL.first;
        LPL.first = nullptr;
        LPL.last = nullptr;
        delete PL;
    }else if(LPL.first->next != nullptr){
        PL = LPL.first;
        LPL.first = PL->next;
        PL->next = nullptr;
        LPL.first->prev = nullptr;
        delete PL;
    }
};
void deleteLastPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL){
//menghapus elemen terakhir list PlaylistToLagu
     if(LPL.first == LPL.last){
        PL = LPL.last;
        LPL.first = nullptr;
        LPL.last = nullptr;
        delete PL;
    }else if(LPL.last->prev != nullptr){
        PL = LPL.last;
        LPL.last = PL->prev;
        PL->prev = nullptr;
        LPL.last->next = nullptr;
        delete PL;
    }
};
void deleteAfterPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu prec, adrPlaylistToLagu PL){
//menghapus elemen setelah prec pada list playlistToLagu
    PL = prec->next;
    prec->next = PL->next;
    (PL->next)->prev = prec;
    PL->next = nullptr;
    PL->prev = nullptr;
    delete PL;
}
void deletePlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL){
// menghapus elemen relasi playlistToLagu
    if(PL == LPL.first){
        deleteFirstPlaylistToLagu(LPL, PL);
    }else if(PL == LPL.last){
        deleteLastPlaylistToLagu(LPL, PL);
    }else{
        deleteAfterPlaylistToLagu(LPL, PL->prev, PL);
    }
}
adrPlaylistToLagu findPlaylistLagu(listPlaylistToLagu LPL, adrPlaylist P, adrLagu L){
// mencari elemen PlaylistToLagu berdasarkan address playlist dan lagu
    adrPlaylistToLagu PL = LPL.first;

    while (PL != nullptr){
        if(PL->playlist == P && PL->lagu == L){
            return PL;
        }
        PL = PL->next;
    }
    return nullptr;

}
adrPlaylistToLagu findPlaylistLagu(listPlaylistToLagu LPL, string idPlaylist, string judulLagu){
//mencari elemen PlaylistToLagu berdasarkan idPlaylist dan judulLagu
    adrPlaylistToLagu PL = LPL.first;

    while (PL != nullptr){
        if(PL->playlist->idPlaylist == idPlaylist && PL->lagu->judul == judulLagu){
            return PL;
        }
        PL = PL->next;
    }
    return nullptr;

}
void connectPlaylistToLagu(listPlaylistToLagu &LPL, listPlaylist LP, listLagu LL, string idPlaylist, string judulLagu){
// menghubungkan playlist dengan lagu
    //mencari elemen playlist dan lagu yang ingin dihubugnkan dengan findPlaylist dan findLagu
    adrPlaylist p = findPlaylistById(LP, idPlaylist);
    adrLagu l = findLaguByJudul(LL, judulLagu);
    if(p != nullptr && l != nullptr){
        //memasukkan elemen playlistToLagu ke dalam list
        insertPlaylistToLagu(LPL, createRelasiPlaylistToLagu(p, l));
    }
}
void disconnectPlaylistToLagu(listPlaylistToLagu &LPL, string idPlaylist, string judulLagu, listPlaylistToAkun LPA, string username){
//memutus hubungan antara lagu dengan playlist
     adrPlaylistToLagu pl;
     if(findPlaylistAkun(LPA, idPlaylist, username) != nullptr){
        pl = findPlaylistLagu(LPL, idPlaylist, judulLagu);
        if(pl != nullptr){
            if(pl == LPL.first){
                deleteFirstPlaylistToLagu(LPL, pl);
            }else if(pl == LPL.last){
                deleteLastPlaylistToLagu(LPL, pl);
            }else{
                deleteAfterPlaylistToLagu(LPL, pl->prev, pl);
            }
        }
     }else{
        cout << "Belum ada playlist yang terdaftar!" << endl;
     }

}

// LIST PLAYLIST TO AKUN
adrPlaylistToAkun createRelasiPlaylistToAkun(adrPlaylist P, adrAkun A){
//membuat elemen relasi playlistToAkun
    adrPlaylistToAkun pta = new PlaylistToAkun;

    pta->playlist = P;
    pta->akun = A;
    pta->next = nullptr;
    pta->prev = nullptr;

    return pta;
};
void createListPlaylistToAkun(listPlaylistToAkun &LPA){
//membuat list relasi playlistToAkun
    LPA.first = nullptr;
    LPA.last = nullptr;
};
bool isEmptyPlaylistToAkun(listPlaylistToAkun LPA){
//mengembalikan true jika list playlistToAkun kosong
    return LPA.first == nullptr && LPA.last == nullptr;
};
void insertPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun PA){
//memasukkan elemen playlistToAkun ke bagian akhir list
    if(isEmptyPlaylistToAkun(LPA)){
        LPA.first = PA;
        LPA.last = PA;
    }else{
        LPA.last->next = PA;
        PA->prev = LPA.last;
        LPA.last = PA;
    }
};
void deleteFirstPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun PA){
//menghapus elemen pertama list PlaylistToAkun
    if(LPA.first == LPA.last){
        PA = LPA.first;
        LPA.first = nullptr;
        LPA.last = nullptr;
        delete PA;
    }else if(LPA.first->next != nullptr){
        PA = LPA.first;
        LPA.first = PA->next;
        PA->next = nullptr;
        LPA.first->prev = nullptr;
        delete PA;
    }
};
void deleteAfterPlaylistToAkun(listPlaylistToAkun &LPA,adrPlaylistToAkun prec, adrPlaylistToAkun PA){
//Menghapus elemen setelah prec pada list PlaylistToAkun
    PA = prec->next;
    prec->next = PA->next;
    (PA->next)->prev = prec;
    PA->next = nullptr;
    PA->prev = nullptr;
    delete PA;
};
void deleteLastPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun PA){
//menghapus elemen terakhir list PlaylistToAkun
    if(LPA.first == LPA.last){
        PA = LPA.last;
        LPA.first = nullptr;
        LPA.last = nullptr;
        delete PA;
    }else if(LPA.last->prev != nullptr){
        PA = LPA.last;
        LPA.last = PA->prev;
        PA->prev = nullptr;
        LPA.first->next = nullptr;
        delete PA;
    }
};
void deletePlaylistToAkun(listPlaylistToAkun LPA, adrPlaylistToAkun PA){
// menghapus elemen relasi playlistToLagu
    if(PA == LPA.first){
        deleteFirstPlaylistToAkun(LPA, PA);
    }else if(PA == LPA.last){
        deleteLastPlaylistToAkun(LPA, PA);
    }else{
        deleteAfterPlaylistToAkun(LPA, PA->prev, PA);
    }
}
adrPlaylistToAkun findPlaylistAkun(listPlaylistToAkun LPA, adrPlaylist P, adrAkun A){
//mencari elemen playlistToAkun berdasarkan address playlist dan akun
    adrPlaylistToAkun PA = LPA.first;

    while (PA != nullptr){
        if(PA->playlist == P && PA->akun == A){
            return PA;
        }
        PA = PA->next;
    }
    return nullptr;

};
adrPlaylistToAkun findPlaylistAkun(listPlaylistToAkun LPA, string idPlaylist, string username){
//mencari elemen playlistToAkun berdasarkan idPlaylist dan akun
    adrPlaylistToAkun PA = LPA.first;

    while (PA != nullptr){
        if(PA->playlist->idPlaylist == idPlaylist && PA->akun->username == username){
            return PA;
        }
        PA = PA->next;
    }
    return nullptr;

};
void connectPlaylistToAkun(listPlaylistToAkun &LPA, listPlaylist LP, listAkun LA, string idPlaylist, string username){
//menghubungkan playlist dengan akun
    //mencari alaman playlist dan akun berdasrkan idPlaylist dan username akun dengan findPlaylistById dan findAkun
    adrPlaylist p = findPlaylistById(LP, idPlaylist);
    adrAkun A = findAkun(LA, username);

    if(p != nullptr && A != nullptr){
        //memasukkan elemen playlistToAkun ke dalam list
        insertPlaylistToAkun(LPA, createRelasiPlaylistToAkun(p, A));
    }
};
void disconnectPlaylistToAkun(listPlaylistToAkun &LPA, string idPlaylist, string username){
//memutus hubungan playlist dengan akun
    adrPlaylistToAkun pa = findPlaylistAkun(LPA, idPlaylist, username);

    if(pa != nullptr){
        if(pa == LPA.first){
            deleteFirstPlaylistToAkun(LPA, pa);
        }else if(pa == LPA.last){
            deleteLastPlaylistToAkun(LPA, pa);
        }else{
            deleteAfterPlaylistToAkun(LPA, pa->prev, pa);
        }
    }
};

void playLaguFromLibrary(listLagu LL){
//Memainkan lagu dari listLagu utama (library)
    string idlagu, pilih;
    adrLagu ceklagu;
    bool playing = true;

    cout << "-----------------------------" << endl;
    cout << " MEMAINKAN LAGU DARI LIBRARY " << endl;
    showLagu(LL);
    cout << "-----------------------------" << endl;
    cout << "Masukan ID Lagu untuk dimainkan: ";
    cin >> idlagu;
    cout << "-----------------------------";

    ceklagu = findLaguByID(LL,idlagu);
    cout << endl;
    cout << "[Now Playling] " << ceklagu->judul << " By " << ceklagu->artis << endl;

    while (playing){
        cout << "|(p)rev|(n)ext|(s)top| : ";
        cin >> pilih;
        cout << "-----------------------------" << endl;

        if (pilih == "p"){
            if (ceklagu->prev == nullptr){
                cout << "Tidak ada lagu sebelum lagu ini! " << endl;
                cout << "-----------------------------";
            }else {
                cout << "[Now Playling]" << ceklagu->prev->judul << " By " << ceklagu->prev->artis << endl;
                ceklagu = ceklagu->prev;
            }
        }else if (pilih == "n"){
            if (ceklagu->next == nullptr){
                cout << "Tidak ada lagu setelah lagu ini! " << endl;
                cout << "-----------------------------";
            }else {
                cout << "[Now Playling]" << ceklagu->next->judul << " By " << ceklagu->next->artis << endl;
                ceklagu = ceklagu->next;
            }
        }else if (pilih == "s"){
            playing = false;
            //userMenu(LL, LP, LA, LPL, LPA);
        }
    }
}
void printPlaylistToLagu(listPlaylistToLagu LPL, listPlaylist LP, listPlaylistToAkun LPA, string username){
    adrPlaylist p = LP.first;
    adrPlaylistToLagu pl;

    cout << "------------------------------" << endl;
    cout << "LIST PLAYLIST DAN LAGU-LAGUNYA" << endl;
    cout << "------------------------------" << endl;
    while (p != nullptr){
        if(findPlaylistAkun(LPA, p->idPlaylist, username) != nullptr){
            cout << "[" << p->idPlaylist << "] " << p->namaPlaylist << " - ";
            pl = LPL.first;
            while(pl != nullptr){
                if(pl->playlist == p){
                    cout << pl->lagu->judul << ", ";
                }
                pl = pl->next;
            }
            cout << endl;
        }
        p = p->next;
    }
    cout << endl;
}
void playLaguFromPlaylist(listPlaylist LP, listPlaylistToLagu LPL, listPlaylistToAkun LPA, string userAktif){
// memainkan lagu di dalam playlist
    string idPlaylist, pilihLagu, idLagu, pilih;
    adrPlaylist playlist;
    adrPlaylistToLagu PL, temp;
    bool adaLagu = false, playingLagu, foundLagu = false;
    adrLagu nowLagu = nullptr, prevLagu;

    printPlaylistToLagu(LPL, LP, LPA, userAktif);
    cout << "Masukkan ID playlist yang ingin dimainkan: ";
    cin >> idPlaylist;
    playlist = findPlaylistById(LP, idPlaylist);

    if(playlist == nullptr){
        cout << "Playlist tidak ditemukan!" << endl;
    }
    if(findPlaylistAkun(LPA, idPlaylist, userAktif) == nullptr){
        cout << "Playlist " << playlist->namaPlaylist << " bukan milik anda" << endl;
    }else{
        //Menampilkan lagu dalam playlist
        PL = LPL.first;
        cout << "------------------------------" << endl;
        cout << "          Daftar Lagu         " << endl;
        cout << "------------------------------" << endl;
        while(PL != nullptr){
            if(PL->playlist == playlist){
                cout << "[" << PL->lagu->idLagu << "] " << PL->lagu->judul << " by " << PL->lagu->artis << endl;
                adaLagu = true;
            }
            PL = PL->next;
        }
        if(!adaLagu){
            cout << "Playlist masih kosong!" << endl;
            return;
        }

        cout << "Pilih id Lagu: ";
        cin >> pilihLagu;
        //mengambil lagu sesuai pilihan
        PL = LPL.first;

        while(PL != nullptr){
            if(PL->playlist == playlist && PL->lagu->idLagu == pilihLagu){
                nowLagu = PL->lagu;
            }
            PL = PL->next;
        }
        if(nowLagu == nullptr){
            cout << "Lagu tidak daitemukan di playlist" << endl;
        }else{
            playingLagu = true;
            while(playingLagu){
                if(!foundLagu){
                    cout << "[Now Playing] " << nowLagu->judul << " by " << nowLagu->artis<< endl;
                }
                cout << "|(p)rev|(n)ext|(s)top| : ";
                cin >> pilih;
                cout << "------------------------------" << endl;

                if(pilih == "p"){
                    prevLagu = nullptr;
                    temp = LPL.first;
                    while(temp != nullptr){
                        if(temp->playlist == playlist){
                            if(temp->lagu == nowLagu){
                                break;
                            }
                            prevLagu = temp->lagu;
                        }
                        temp = temp->next;
                    }
                    if(prevLagu != nullptr){
                        nowLagu = prevLagu;
                    }else{
                        cout << "Tidak ada lagu sebelumnya di playlist!" << endl;
                    }
                }else if(pilih == "n"){
                    temp = LPL.first;
                    foundLagu = false;
                    while(temp != nullptr){
                        if(temp->playlist == playlist){
                            if(foundLagu){
                                nowLagu = temp->lagu;
                                foundLagu = false;
                                break;
                            }
                            if(temp->lagu == nowLagu){
                                foundLagu = true;
                            }
                        }
                        temp = temp->next;
                    }
                    if(foundLagu){
                        cout << "tidak ada lagu selanjutnya di playlist" << endl;
                    }
                }else if(pilih == "s"){
                    playingLagu = false; // balik ke menu user
                }
            }
        }
    }
}
void deleteLaguFromAllPlaylist(listPlaylistToLagu &LPL, adrLagu L){
//menghapus lagu dari semua playlist
    adrPlaylistToLagu PL = LPL.first;
    adrPlaylistToLagu hapus;

    while(PL != nullptr){
        if(PL->lagu == L){
            hapus = PL;
            PL = PL->next;
            deletePlaylistToLagu(LPL, hapus);
        }else{
            PL = PL->next;
        }
    }
}


