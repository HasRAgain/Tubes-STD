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
            cout << "Username sudah dipakai";
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
adrAkun findAkun(listAkun LA, string username){
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
    cout << endl << "--- AKUN YANG TERDAFTAR ---" << endl;
    while (A != nullptr){
        cout << "- " << A->username << "(" << A->role << ")" << endl;
        A = A->next;
    }
    cout << endl;
}
void updateAkun(listAkun &LA){
//Mengubah username dan password akun yang sudah dicari berdasarkan username lama
    string usernameLama, usernameBaru, passwordBaru;
    adrAkun statusAkun;
    adrAkun A = LA.first;

    cout << "--- UPDATE AKUN ---" << endl;
    cout << "Masukkan username kamu: ";
    cin >> usernameLama;
    statusAkun = findAkun(LA, usernameLama);

    while(A != nullptr){
        if(A != statusAkun){
            cout << "Akun tidak ditemukan!";
            return;
        }else{
            cout << "=== Edit Akun ===" << endl;
            cout << "Masukkan username baru: ";
            cin >> usernameBaru;
            cout << "Masukkan password baru: ";
            cin >> passwordBaru;

            A->username = usernameBaru;
            A->password = passwordBaru;

            cout << "Akun berhasil diubah" << endl << endl;
        }
        A = A->next;
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
            cout << "ID lagu sudah dipakai";
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
void deleteLagu(listLagu &LL, adrLagu L){
//menghapus elemen lagu
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
    cout << endl << "--- LAGU YANG TERSEDIA ---" << endl;
    while(L != nullptr){
        cout << "[" << L->idLagu << "] " << L->judul << " by " << L->artis << ". Genre: " << L->genre << ". Durasi: " << L->durasi << endl;
        L = L->next;
    }
    cout << endl;
}
void updateLagu(listLagu &LL){
//mengubah atribut lagu
    string idLagu, judulBaru, artisBaru, genreBaru;
    int durasiBaru, pilih;
    adrLagu statusLagu;
    adrLagu L = LL.first;

    cout << "--- UPDATE LAGU ---" << endl;
    cout << "Masukkan Judul yang ingin diupdate: ";
    cin >> idLagu;
    statusLagu = findLaguByID(LL, idLagu);

    while(L != nullptr){
        if(L->idLagu != idLagu){
            cout << "Judul lagu tidak ditemukan!";
            return;
        }else{
            cout << "=== Edit Lagu ===" << endl;
            cout << "judul baru: ";
            cin >> judulBaru;
            cout << "Artis baru: ";
            cin >> artisBaru;
            cout << "genre baru: ";
            cin >> genreBaru;
            cout << "durasi baru: ";
            cin >> durasiBaru;

            L->judul = judulBaru;
            L->artis = artisBaru;
            L->genre = genreBaru;
            L->durasi = durasiBaru;

            cout << "Lagu berhasil diubah!";
        }
        L = L->next;
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
            cout << "ID playlist sudah dipakai";
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
void showPlaylist(listPlaylist LP){
//menampilkan playlist yang terdaftar
    adrPlaylist P = LP.first;
    cout << endl << "--- PLAYLIST YANG TERDAFTAR ---" << endl;
    while (P != nullptr){
        cout << "[" << P->idPlaylist << "] " << P->namaPlaylist << endl;
        P = P->next;
    }
    cout << endl;
}
void updatePlaylist(listPlaylist &LP){
//mengupadate atribut playlist
    string namaLama, namaBaru;
    adrPlaylist statusPlaylist;
    adrPlaylist P = LP.first;

    cout << "--- UPDATE PLAYLIST ---" << endl;
    cout << "Masukkan nama playlist yang ingin diubah: ";
    cin >> namaLama;
    statusPlaylist = findPlaylistByName(LP, namaLama);

    while(P != nullptr){
        if(P != statusPlaylist){
            cout << "Playlist tidak ditemukan!";
            return;
        }else{
            cout << "=== Edit Playlist ===" << endl;
            cout << "Masukkan nama playlist baru: ";
            cin >> namaBaru;

            P->namaPlaylist = namaBaru;

            cout << "nama playlist berhasil diubah" << endl << endl;
        }
        P = P->next;
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
        LPL.first->next = nullptr;
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
void disconnectPlaylistToLagu(listPlaylistToLagu &LPL, string idPlaylist, string judulLagu){
//memutus hubungan antara lagu dengan playlist
     adrPlaylistToLagu pl;
     if(pl != nullptr){
        if(pl == LPL.first){
            deleteFirstPlaylistToLagu(LPL, pl);
        }else if(pl == LPL.last){
            deleteLastPlaylistToLagu(LPL, pl);
        }else{
            deleteAfterPlaylistToLagu(LPL, pl->prev, pl);
        }
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

    cout << "=== MEMAINKAN LAGU DARI LIBRARY ===" << endl;
    showLagu(LL);

    cout << "Masukan ID Lagu untuk dimainkan: ";
    cin >> idlagu;

    ceklagu = findLaguByID(LL,idlagu);
    cout << endl;
    cout << "[Now Playling] " << ceklagu->judul << " By " << ceklagu->artis << endl;

    while (playing){
        cout << "|(p)rev|(n)ext|(s)top| : ";
        cin >> pilih;

        if (pilih == "p"){
            if (ceklagu->prev == nullptr){
                cout << "Tidak ada lagu sebelum lagu ini! " << endl;
            }else {
                cout << "[Now Playling]" << ceklagu->prev->judul << " By " << ceklagu->prev->artis << endl;
                ceklagu = ceklagu->prev;
            }
        }else if (pilih == "n"){
            if (ceklagu->next == nullptr){
                cout << "Tidak ada lagu setelah lagu ini! " << endl;
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
void printPlaylistToLagu(listPlaylistToLagu LPL, listPlaylist LP){
    adrPlaylist p = LP.first;
    adrPlaylistToLagu pl = LPL.first;

    cout << "--- LIST PLAYLIST DAN LAGU-LAGUNYA ---" << endl;
    while (p != nullptr){
        cout << "[" << p->idPlaylist << "] " << p->namaPlaylist << " - ";
        while(pl != nullptr){
            if(pl->playlist == p){
                cout << pl->lagu->judul << ", ";
            }
            pl = pl->next;
        }
        cout << endl;
        p = p->next;
    }
    cout << endl << endl;
}

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
    connectPlaylistToLagu(LPL, LP, LL, "2", "Nocture-Op.9-No.2");
    connectPlaylistToLagu(LPL, LP, LL, "2", "Dream-On");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Pump-It");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Rolling-In-The-Deep");
    connectPlaylistToLagu(LPL, LP, LL, "3", "Creep");

    connectPlaylistToAkun(LPA, LP, LA, "2", "hasna");
    connectPlaylistToAkun(LPA, LP, LA, "3", "irfan");

};
void adminMenu(listLagu &LL, listAkun &LA) {
    int pilih;
    adrLagu L, cekLagu;
    string idLagu, judulLagu, artisLagu, genreLagu;
    int durasiLagu;
    bool admin = true;
    while (admin){
        cout << "--- ADMIN MENU ---" << endl;
        cout << "1. Tambah lagu\n";
        cout << "2. Lihat semua lagu\n";
        cout << "3. Edit lagu\n";
        cout << "4. Hapus lagu\n";
        cout << "5. Lihat semua akun\n";
        cout << "6. Logout\n";
        cout << "Pilih 1/2/3/4/5/6: ";
        cin >> pilih;

        if (pilih == 1){
            showLagu(LL);
            cout << "=== MENAMBAH LAGU ===" << endl;
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

            adrLagu cekLagu = findLaguByID(LL, L->idLagu);
            if (cekLagu != nullptr){
                cout << "ID lagu sudah dipakai";
            }else{
                insertLagu(LL, createLagu(idLagu, judulLagu, artisLagu, genreLagu, durasiLagu));
                cout << "Lagu berhasil ditambahkan!";
            }
            showLagu(LL);
        }else if (pilih == 2){
            showLagu(LL);
        }else if (pilih == 3){
            showLagu(LL);
            updateLagu(LL);
        }else if (pilih == 4){
            cout << "=== HAPUS LAGU ===" << endl;
            showLagu(LL);
            cout << "ID lagu yang ingin dihapus: ";
            cin >> idLagu;
            cekLagu = findLaguByID(LL, idLagu);
            if(cekLagu != nullptr){
                deleteLagu(LL, cekLagu);
                cout << "Lagu berhasil dihapus!" << endl;
            }
        }else if (pilih == 5){
            showAkun(LA);
        }else if(pilih == 6){
            admin = false;
        }else{
            cout << "Pilihan salah!";
        }
    }
}
void userMenu(listLagu &LL, listPlaylist &LP, listAkun &LA, listPlaylistToLagu &LPL, listPlaylistToAkun &LPA) {
    int pilih, opsiPlaylist;
    bool user = true;
    bool playlist = true;
    string judulLagu, namaPlaylist, idPlaylist, idLagu;
    adrLagu lagu;
    adrPlaylist cekPlaylist;
    while (user){
        cout << "\n--------------------------USER MENU -----------------------|\n";
        cout << "| 1. Lihat Library\n";
        cout << "| 2. Cari lagu berdasarkan judul\n";
        cout << "| 3. Play lagu dari library\n";
        cout << "| 4. Kelola Playlist (buat/hapus/lihat/tambah/hapus lagu)\n";
        cout << "| 5. Lihat playlist akun lain\n";
        cout << "| 6. Mengambil Playlist user lain \n";
        cout << "| 7. Logout\n";
        cout << "------------------------------------------------------------|"<<endl;
        cout << "| Pilih 1/2/3/4/5/6: ";
        cin >> pilih;

        if(pilih == 1){
            showLagu(LL);
        }else if (pilih == 2){
            cout << "--- CARI LAGU BERDASARKAN JUDUL ---" << endl;
            cout << "Masukkan judul lagu yang ingin dicari: ";
            cin >> judulLagu;
            lagu = findLaguByJudul(LL, judulLagu);
            if (lagu != nullptr){
                cout << "Lagu ditemukan!" << endl;
                cout << "[" << lagu->idLagu << "] " << lagu->judul << " by " << lagu->artis << ". Genre: " << lagu->genre << ". Durasi: " << lagu->durasi << endl;
            }else{
                cout << "Lagu tidak ditemukan!" << endl;
            }
        }else if(pilih == 3){
            playLaguFromLibrary(LL);
        }else if(pilih == 4){
            while (playlist){
                cout << " === Kelola Playlist ===" << endl;
                cout << "1. Membuat playlist baru \n";
                cout << "2. Menghapus playlist \n";
                cout << "3. Lihat playlist \n";
                cout << "4. Menambah lagu ke playlist \n";
                cout << "5. Hapus lagu dari playlist \n";
                cout << "6. kembali ke menu utama \n";
                cin >> opsiPlaylist;

                if (opsiPlaylist == 1){
                    cout << "=== Membuat Playlist ===" << endl << "Nama Playlist: ";
                    cin >> namaPlaylist;
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    cekPlaylist = findPlaylistById(LP, idPlaylist);
                    if(cekPlaylist != nullptr){
                        cout << "ID playlist sudah dipakai";
                    }else{
                        insertPlaylist(LP, createPlaylist(namaPlaylist, idPlaylist));
                        cout << "Playlist berhasil dibuat!" << endl;
                    }
                }else if(opsiPlaylist == 2){
                    cout << "=== Menghapus Playlist ===" << endl;
                    showPlaylist(LP);
                    cout << "nama playlist: ";
                    cin >> namaPlaylist;
                    cekPlaylist = findPlaylistByName(LP, namaPlaylist);
                    deletePlaylist(LP, cekPlaylist);
                    cout << namaPlaylist << " berhasil dihapus!" << endl;
                }else if(opsiPlaylist == 3){
                    showPlaylist(LP);
                }else if(opsiPlaylist == 4){
                    cout << "--- MENAMBAHKAN LAGU KE PLAYLIST ---" << endl;
                    showPlaylist(LP);
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    showLagu(LL);
                    cout << "Judul Lagu: ";
                    cin >> judulLagu;
                    connectPlaylistToLagu(LPL, LP, LL, idPlaylist, judulLagu);
                    cout << judulLagu << " berhasil ditambahan ke " << namaPlaylist << endl;
                    printPlaylistToLagu(LPL, LP);
                }else if(opsiPlaylist == 5){
                    cout << "--- MENGHAPUS LAGU PADA PLAYLIST ---" << endl;
                    printPlaylistToLagu(LPL, LP);
                    cout << "Masukkan ID Playlist dan judul lagu yang ingin dihapus";
                    cout << "ID Playlist: ";
                    cin >> idPlaylist;
                    cout << "Judul Lagu: ";
                    cin >> judulLagu;
                    disconnectPlaylistToLagu(LPL, idPlaylist, judulLagu);
                    cout << judulLagu << " berhasil dihapus dari playlist ber-ID " << idPlaylist;
                    printPlaylistToLagu(LPL, LP);
                }else if(opsiPlaylist == 6){
                    playlist = false;
                }
            }

        }else if(pilih == 5){
            //PlaylistAkunLain();
        }else if (pilih == 6){
            //malingplaylist
        }else if(pilih == 7){
            user = false;
        }
    }
}
void menuUtama(listLagu &LL, listPlaylist &LP, listAkun &LA, listPlaylistToLagu &LPL, listPlaylistToAkun &LPA) {
    adrAkun A, cariAkun;
    string username, password;

    while (true) {
        int pilihan;
        cout << endl << "-----SELAMAT DATANG-----|" << endl;
        cout << "|  1. Login" << endl;
        cout << "|  2. Register" << endl;
        cout << "|  3. Exit" << endl;
        cout << "------------------------|"<< endl;
        cout << "|  Pilih 1/2/3 : ";

        cin >> pilihan;
        cout << endl;

        if (pilihan == 1) {
            int x;
            cout << "--------------------|"<<endl;
            cout << "| 1. Login as User" << endl;
            cout << "| 2. Login as Admin" << endl;
            cout << "--------------------|"<<endl;
            cout << "| Pilih 1/2 : ";
            cin >> x;
            cout << endl;

            if (x == 1) {
                cout << "---------------|"<<endl;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                cariAkun = findAkun(LA, username);

                if(cariAkun == nullptr){
                    cout << "Username tidak ditemukan!\n";
                }else if(cariAkun->password != password){
                    cout << "Password salah!\n";
                }else if(cariAkun->role == "user"){
                    userMenu(LL, LP, LA, LPL, LPA);
                }else{
                    cout << "Akun bukan user!\n";
                }
            } else if (x == 2) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                cariAkun = findAkun(LA, username);

                if(cariAkun == nullptr){
                    cout << "Username tidak ditemukan!\n";
                }else if(cariAkun->password != password){
                    cout << "Password salah!\n";
                }else if(cariAkun->role == "admin"){
                    adminMenu(LL, LA);
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

            cout << "----------------------------------------------|"<<endl;
            cout << "| Username : ";
            cin >> username;
            cout << "| Password : ";
            cin >> password;
            cout << "| Role (User/Admin) : ";
            cin >> role;
            cariAkun = findAkun(LA, username);
            if(cariAkun != nullptr){
                cout << "Username sudah dipakai! \n";
                cout << "----------------------------------------------|"<<endl;
            }else{
                insertAkun(LA, createakun(username, password, role));
                cout << "\nRegistrasi berhasil! Kembali ke menu utama...\n";
                cout << "----------------------------------------------|"<<endl;
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
