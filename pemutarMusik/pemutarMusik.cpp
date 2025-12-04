#include "pemutarMusik.h"

adrAkun createakun(string username, string password, string role){
/* IS: terdefinisi string username, password, dan role
FS: mengembalikan elemen akun (A) yang sudah terisi username, password, dan role
*/
    adrAkun A = new Akun;

    A->username = username;
    A->password = password;
    A->role = role
    A->next = nullptr;
    A->prev = nullptr;

    return LA;
}
void createListAkun(listAkun &LA){
/* IS: -
FS: list akun (LA)
*/
    LA.first = nullptr;
    LA.last = nullptr;
}
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
FS: list lagu (LL)
*/
    LL.first = nullptr;
    LL.last = nullptr;
}
adrPlaylist createPlaylist(string nama, string id){
/* IS: terdefinisi nama playlist dan id playlist
FS: mengembalikan elemen playlist (P) yang sudah terisi playlist dan id playlist
*/
    adrPlaylist P = new Playlist;

    P->nama = nama;
    P->idPlaylist = id;
    P->next = nullptr;
    P->prev = nullptr;
    P->relasiToLagu = nullptr;
    P->relastiToAkun = nullptr;

    return P;
}
void createListPlaylist(listPlaylist &LP){
/* IS: -
FS: list playlist (LP)
*/
    LP->first = nullptr;
    LP->last = nullptr;
}
bool isEmptyPlaylist(listPlaylist LP){
/* IS: -
FS: mengembalikan TRUE jika list playlist kosong
*/
    return LP.first == nullptr && LP.last == nullptr;
}
bool isEmptyAkun(listAkun LA){
/* IS: -
FS: mengembalikan TRUE jika list akun kosong
*/
    return LA.first == nullptr && LA.last == nullptr;
}
bool isEmptyLagu(listLagu LL){
/* IS: -
FS: mengembalikan TRUE jika list lagu kosong
*/
    return LL.first == nullptr && LL.last == nullptr;
}

