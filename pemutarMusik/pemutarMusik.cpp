#include "pemutarMusik.h"

// LIST AKUN
adrAkun createakun(string username, string password, string role){
/* IS: terdefinisi string username, password, dan role
FS: mengembalikan elemen akun (A) yang sudah terisi username, password, dan role
*/
    adrAkun A = new Akun;

    A->username = username;
    A->password = password;
    A->role = role;
    A->next = nullptr;
    A->prev = nullptr;

    return A;
}
void createListAkun(listAkun &LA){
/* IS: -
FS: first dan last list akun berisi null
*/
    LA.first = nullptr;
    LA.last = nullptr;
}
bool isEmptyAkun(listAkun LA){
/* IS: -
FS: mengembalikan TRUE jika list akun kosong
*/
    return LA.first == nullptr && LA.last == nullptr;
}
void insertAkun(listAkun &LA, adrAkun A){
/* IS: terdefinisi list akun yang mungkin kosong dan elemen akun yang ingin dimasukkan
FS: list akun dengan elemen akun A berada di akhir list.
*/
    if (isEmptyAkun(LA)){
        LA.first = A;
        LA.last = A;
    }else {
        LA.last->next = A;
        A->prev = LA.last;
        LA.last = A;
    }
}
void deleteFirstAkun(listAkun &LA, adrAkun &A){
/* IS: terdefinisi list akun yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam A.
*/
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
    }else{
        A = LA.first;
        LA.first = A->next;
        A->prev = nullptr;
        A->next = nullptr;
    }
}
void deleteAfterAkun(listAkun &LA,adrAkun prec, adrAkun &A){
/* IS: terdefinisi list akun yang mungkin kosong dan hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam A.
*/
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun yang terdaftar" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
    }else{
        A = prec->next;
        prec->next = A->next;
        (A->next)->prev = prec;
        A->next = nullptr;
        A->prev = nullptr;
    }
}
void deleteLastAkun(listAkun &LA, adrAkun &A){
/* IS: terdefinisi list akun yang mungkin kosong dan hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam A.
*/
    if(isEmptyAkun(LA)){
        cout << "tidak ada akun yang terdaftar" << endl;
    }else if(LA.first == LA.last){
        A = LA.first;
        LA.first = nullptr;
        LA.last = nullptr;
    }else{
        A = LA.last;
        LA.last = A->prev;
        LA.last->next = nullptr;
        A->prev = nullptr;
    }
}
adrAkun findAkun(listAkun LA, string username){
/*IS: terdefinisi list akun yang tidak kosong dan username akun yang ingin dicari
FS: mengembalikan address akun sesuai username
*/
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
/*IS: terdefinisi list akun yang tidak kosong
FS: menampilkan list username akun yang terdaftar
*/
    adrAkun A = LA.first;
    cout << "--- AKUN YANG TERDAFTAR ---" << endl;
    while (A != nullptr){
        cout << "- " << A->username << "(" << A->role << ")" << endl;
        A = A->next;
    }
    cout << endl;
}
void updateAkun(listAkun &LA){
/* IS: terdefinisi list akun yang tidak kosong
FS: Akun sudah terisi dengan username dan password baru
User akan memasukkan username sebelumnya, jika ditemukan, user dapat mengedit akunnya
*/
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
/* IS: terdefinisi idLagu, judul, artis, genre, dan durasi
FS: mengembalikan elemen lagu (L) yang sudah terisi idLagu, judul, artis, genre, dan durasi
*/
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
/* IS: -
FS: first dan last list lagu berisi null
*/
    LL.first = nullptr;
    LL.last = nullptr;
}
bool isEmptyLagu(listLagu LL){
/* IS: -
FS: mengembalikan TRUE jika list lagu kosong
*/
    return LL.first == nullptr && LL.last == nullptr;
}
void insertLagu(listLagu &LL, adrLagu L){
/* IS: terdefinisi list lagu yang mungkin kosong dan elemen lagu yang ingin dimasukkan
FS: list akun dengan elemen lagu L berada di akhir list.
*/
    if (isEmptyLagu(LL)){
        LL.first = L;
        LL.last = L;
    }else {
        adrLagu id = findLaguByID(LL, L->idLagu);
        if (id == nullptr){
            LL.last->next = L;
            L->prev = LL.last;
            LL.last = L;
        }else{
            cout << "ID already exist";
        }

    }
}
void deleteFirstLagu(listLagu &LL, adrLagu &L){
/* IS: terdefinisi list lagu yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam L.
*/
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
    }else{
        L = LL.first;
        LL.first = L->next;
        L->prev = nullptr;
        L->next = nullptr;
    }
}
void deleteAfterLagu(listLagu &LL,adrLagu prec, adrLagu &L){
/* IS: terdefinisi list lagu yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam L.
*/
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
    }else{
        L = prec->next;
        prec->next = L->next;
        (L->next)->prev = prec;
        L->next = nullptr;
        L->prev = nullptr;
    }
}
void deleteLastLagu(listLagu &LL, adrLagu &L){
/* IS: terdefinisi list lagu yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam L.
*/
    if(isEmptyLagu(LL)){
        cout << "tidak ada lagu yang terdaftar" << endl;
    }else if(LL.first == LL.last){
        L = LL.first;
        LL.first = nullptr;
        LL.last = nullptr;
    }else{
        L = LL.last;
        LL.last = L->prev;
        LL.last->next = nullptr;
        L->prev = nullptr;
    }
};
adrLagu findLaguByID(listLagu LL, string id){
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
    adrLagu L = LL.first;

    cout << "--- LAGU YANG TERSEDIA ---" << endl;
    while(L != nullptr){
        cout << "[" << L->idLagu << "] " << L->judul << " by " << L->artis
            << ". Genre: " << L->genre << ". Durasi: " << L->durasi << endl;
        L = L->next;
    }
    cout << endl;
}
void updateLagu(listLagu &LL){
    string judulLama, judulBaru, artisBaru, genreBaru;
    int durasiBaru, pilih;
    adrLagu statusLagu;
    adrLagu L = LL.first;

    cout << "--- UPDATE LAGU ---" << endl;
    cout << "Masukkan Judul yang ingin diupdate: ";
    cin >> judulLama;
    statusLagu = findLaguByJudul(LL, judulLama);

    while(L != nullptr){
        if(L->judul != judulLama){
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
/* IS: terdefinisi nama playlist dan id playlist
FS: mengembalikan elemen playlist (P) yang sudah terisi playlist dan id playlist
*/
    adrPlaylist P = new Playlist;

    P->namaPlaylist = nama;
    P->idPlaylist = id;
    P->next = nullptr;
    P->prev = nullptr;

    return P;
}
void createListPlaylist(listPlaylist &LP){
/* IS: -
FS: first dan last list playlist berisi null
*/
    LP.first = nullptr;
    LP.last = nullptr;
}
bool isEmptyPlaylist(listPlaylist LP){
/* IS: -
FS: mengembalikan TRUE jika list playlist kosong
*/
    return LP.first == nullptr && LP.last == nullptr;
}
void insertPlaylist(listPlaylist &LP, adrPlaylist P){
/* IS: terdefinisi list p yang mungkin kosong dan elemen playlist yang ingin dimasukkan
FS: list akun dengan elemen playlist P berada di akhir list.
*/
    if (isEmptyPlaylist(LP)){
        LP.first = P;
        LP.last = P;
    }else {
        LP.last->next = P;
        P->prev = LP.last;
        LP.last = P;
    }
}
void deleteFirstPlaylist(listPlaylist &LP, adrPlaylist &P){
/* IS: terdefinisi list playlist yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam P.
*/
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    }else{
        P = LP.first;
        LP.first = P->next;
        P->prev = nullptr;
        P->next = nullptr;
    }
}
void deleteAfterPlaylist(listPlaylist &LP,adrPlaylist prec, adrPlaylist &P){
/* IS: terdefinisi list playlist yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam P.
*/
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    }else{
        P = prec->next;
        prec->next = P->next;
        (P->next)->prev = prec;
        P->next = nullptr;
        P->prev = nullptr;
    }
}
void deleteLastPlaylist(listPlaylist &LP, adrPlaylist &P){
/* IS: terdefinisi list playlist yang mungkin kosong atau hanya satu elemen
FS: akun sudah terhapus dari list dan di simpan di dalam P.
*/
    if(isEmptyPlaylist(LP)){
        cout << "tidak ada Playlist yang terdaftar" << endl;
    }else if(LP.first == LP.last){
        P = LP.first;
        LP.first = nullptr;
        LP.last = nullptr;
    }else{
        P = LP.last;
        LP.last = P->prev;
        LP.last->next = nullptr;
        P->prev = nullptr;
    }
};
adrPlaylist findPlaylist(listPlaylist LP, string namaPlaylist){
    adrPlaylist P = LP.first;

    while(P != nullptr){
        if(P->namaPlaylist == namaPlaylist){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
void showPlaylist(listPlaylist LP){
    adrPlaylist P = LP.first;
    cout << "--- PLAYLIST YANG TERDAFTAR ---" << endl;
    while (P != nullptr){
        cout << "[" << P->idPlaylist << "] " << P->namaPlaylist << endl;
        P = P->next;
    }
    cout << endl;
}
void updatePlaylist(listPlaylist &LP){
    string namaLama, namaBaru;
    adrPlaylist statusPlaylist;
    adrPlaylist P = LP.first;

    cout << "--- UPDATE PLAYLIST ---" << endl;
    cout << "Masukkan nama playlist yang ingin diubah: ";
    cin >> namaLama;
    statusPlaylist = findPlaylist(LP, namaLama);

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
    adrPlaylistToLagu ptl = new PlaylistToLagu;

    ptl->playlist = P;
    ptl->lagu = L;
    ptl->next = nullptr;
    ptl->prev = nullptr;

    return ptl;
};
void createListPlaylistTosLagu(listPlaylistToLagu &LPL){
    LPL.first = nullptr;
    LPL.last = nullptr;
};
bool isEmptyPlaylistToLagu(listPlaylistToLagu LPL){
    return LPL.first == nullptr && LPL.last == nullptr;
}
void insertPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL){
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
      PL = prec->next;
    prec->next = PL->next;
    (PL->next)->prev = prec;
    PL->next = nullptr;
    PL->prev = nullptr;
    delete PL;
}
adrPlaylistToLagu findPlaylistLagu(listPlaylistToLagu LPL, adrPlaylist P, adrLagu L){
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
      adrPlaylist p = findPlaylist(LP, idPlaylist);
    adrLagu l = findLaguByJudul(LL, judulLagu);
    adrPlaylistToLagu pl;
    if(p != nullptr && l != nullptr){
        pl = createRelasiPlaylistToLagu(p, l);
        insertPlaylistToLagu(LPL, pl);
    }

}
void disconnectPlaylistToLagu(listPlaylistToLagu &LPL, string idPlaylist, string judulLagu){
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
    adrPlaylistToAkun pta = new PlaylistToAkun;

    pta->playlist = P;
    pta->akun = A;
    pta->next = nullptr;
    pta->prev = nullptr;

    return pta;
};
void createListPlaylistToAkun(listPlaylistToAkun &LPA){
    LPA.first = nullptr;
    LPA.last = nullptr;
};
bool isEmptyPlaylistToAkun(listPlaylistToAkun LPA){
    return LPA.first == nullptr && LPA.last == nullptr;
};
void insertPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun PA){
    if(isEmptyPlaylistToAkun(LPA)){
        LPA.first = PA;
        LPA.last = PA;
    }else{
        LPA.last->next = PA;
        PA->prev = LPA.last;
        LPA.last = PA;
    }
};
void deleteFirstPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun &PA){
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
void deleteAfterPlaylistToAkun(listPlaylistToAkun &LPA,adrPlaylistToAkun prec, adrPlaylistToAkun &PA){
    PA = prec->next;
    prec->next = PA->next;
    (PA->next)->prev = prec;
    PA->next = nullptr;
    PA->prev = nullptr;
    delete PA;
};
void deleteLastPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun &PA){
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
    adrPlaylistToAkun PA = LPA.first;

    while (PA != nullptr){
        if(PA->playlist == P && PA->akun == A){
            return PA;
        }
        PA = PA->next;
    }
    return nullptr;

};
adrPlaylistToAkun findPlaylistAkun(listPlaylistToAkun LPA, string username){
     adrPlaylistToAkun PA = LPA.first;

    while (PA != nullptr){
        if(PA->akun->username == username){
            return PA;
        }
        PA = PA->next;
    }
    return nullptr;

};
void connectPlaylistToAkun(listPlaylistToAkun &LPA, listPlaylist LP, listAkun LA, string idPlaylist, string username){
    adrPlaylist p = findPlaylist(LP, idPlaylist);
    adrAkun A = findAkun(LA, username);

    if(p != nullptr && A != nullptr){
        adrPlaylistToAkun pa = createRelasiPlaylistToAkun(p, A);
        insertPlaylistToAkun(LPA, pa);
    }

};
void disconnectPlaylistToAkun(listPlaylistToAkun &LPA, string idPlaylist, string username){
     adrPlaylistToAkun pa = findPlaylistAkun(LPA, username);

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
/*
void displayUtama(listAkun &LA, listPlaylist &LP, listLagu &LL){
    string username, password, role, idLagu, judulLagu, artisLagu, genreLagu, idPlaylist, namaPlaylist;
    int durasiLagu, i;
    adrAkun A;
    adrPlaylist P;
    adrLagu L;
    createListAkun(LA);
    for (i = 0; i<3; i++){
        cout << "username akun: ";
        cin >> username;
        cout << "Passwarod akun: ";
        cin >> password;
        cout << "role: ";
        cin >> role;
        A = createakun(username, password, role);
        insertAkun(LA, A);
    }
    showAkun(LA);

    createListLagu(LL);
    for (i = 0; i<3; i++){
        cout << "ID Lagu: ";
        cin >> idLagu;
        cout << "Judul Lagu: ";
        cin >> judulLagu;
        cout << "Artis: ";
        cin >> artisLagu;
        cout << "genre : ";
        cin >> genreLagu;
        cout << "Durasi: ";
        cin >> durasiLagu;

        L = createLagu(idLagu, judulLagu, artisLagu, genreLagu, durasiLagu);
        insertLagu(LL, L);
    }
    showLagu(LL);

    createListAkun(LA);
    for (i = 0; i<3; i++){
        cout << "ID Playlist: ";
        cin >> idPlaylist;
        cout << "Nama Playlist: ";
        cin >> namaPlaylist;
        P = createPlaylist(idPlaylist, namaPlaylist);
        insertPlaylist(LP, P);
    }
    showPlaylist(LP);
}
*/
void deleteLagu(listLagu LL, adrLagu L){
    if (L == LL.first){
        deleteFirstLagu(LL, L);
    }else if(L == LL.last){
        deleteLastLagu(LL, L);
    }else {
        deleteAfterLagu(LL, L->prev, L);
    }
}
void deleteAkun(listAkun LA, adrAkun A){
    if(A == LA. first){
        deleteFirstAkun(LA, A);
    }else if (A == LA.last){
        deleteLastAkun(LA, A);
    }else{
        deleteAfterAkun(LA, A->prev, A);
    }
}
void deletePlaylist(listPlaylist LP, adrPlaylist P){
    if(P == LP.first){
        deleteFirstPlaylist(LP, P);
    }else if(P == LP.last){
        deleteLastPlaylist(LP, P);
    }else {
        deleteAfterPlaylist(LP, P->prev, P);
    }
}
