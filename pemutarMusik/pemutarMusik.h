#ifndef PEMUTARMUSIK_H_INCLUDED
#define PEMUTARMUSIK_H_INCLUDED

#include <iostream>
using namespace std;

// address list utama
typedef struct Lagu *adrLagu;
typedef struct Akun *adrAkun;
typedef struct Playlist *adrPlaylist;

// address list relasi
typedef struct PlaylistToLagu *adrPlaylistToLagu;
typedef struct PlaylistToAkun *adrPlaylistToAkun;

//ADT list lagu, playlist, akun
struct Lagu{
    string idLagu;
    string judul;
    string artis;
    string genre;
    int durasi;

    adrLagu next;
    adrLagu prev;
};
struct listLagu{
    adrLagu first;
    adrLagu last;
};
struct Playlist{
    string namaPlaylist;
    string idPlaylist;
    adrLagu laguInPlaylist;

    adrPlaylist next;
    adrPlaylist prev;
};
struct listPlaylist{
    adrPlaylist first;
    adrPlaylist last;
};
struct Akun{
    string username;
    string password;
    string role;

    adrAkun next;
    adrAkun prev;
};
struct listAkun{
    adrAkun first;
    adrAkun last;
};

//ADT list relasi playlist to akun dan playlist to lagu
struct PlaylistToLagu{
    adrLagu lagu;
    adrPlaylist playlist;

    adrPlaylistToLagu next;
    adrPlaylistToLagu prev;
};
struct listPlaylistToLagu{
    adrPlaylistToLagu first;
    adrPlaylistToLagu last;
};
struct PlaylistToAkun{
    adrPlaylist playlist;
    adrAkun akun;

    adrPlaylistToAkun next;
    adrPlaylistToAkun prev;
};
struct listPlaylistToAkun{
    adrPlaylistToAkun first;
    adrPlaylistToAkun last;
};

//Subprogram list Akun
adrAkun createakun(string username, string password, string role);
void createListAkun(listAkun &LA);
bool isEmptyAkun(listAkun LA);
void insertAkun(listAkun &LA, adrAkun A);
void deleteFirstAkun(listAkun &LA, adrAkun &A);
void deleteAfterAkun(listAkun &LA,adrAkun prec, adrAkun &A);
void deleteLastAkun(listAkun &LA, adrAkun &A);
adrAkun findAkun(listAkun LA, string username);
void showAkun(listAkun LA);
void updateAkun(listAkun &LA);

//subprogram list lagu
adrLagu createLagu(string idLagu, string judul, string artis, string genre, int durasi);
void createListLagu(listLagu &LL);
bool isEmptyLagu(listLagu LL);
void insertLagu(listLagu &LL, adrLagu L);
void deleteFirstLagu(listLagu &LL, adrLagu &L);
void deleteAfterLagu(listLagu &LL,adrLagu prec, adrLagu &L);
void deleteLastLagu(listLagu &LL, adrLagu &L);
adrLagu findLaguByID(listLagu LL, string id);
adrLagu findLaguByJudul(listLagu LL, string judul);
void showLagu(listLagu LL);
void updateLagu(listLagu &LL);

//subprogram list playlist
adrPlaylist createPlaylist(string nama, string id);
void createListPlaylist(listPlaylist &LP);
bool isEmptyPlaylist(listPlaylist LP);
void insertPlaylist(listPlaylist &LP, adrPlaylist P);
void deleteFirstPlaylist(listPlaylist &LP, adrPlaylist &P);
void deleteAfterPlaylist(listPlaylist &LP,adrPlaylist prec, adrPlaylist &P);
void deleteLastPlaylist(listPlaylist &LP, adrPlaylist &P);
adrPlaylist findPlaylist(listPlaylist P, string namaPlaylist);
void showPlaylist(listPlaylist LP);
void updatePlaylist(listPlaylist &LP);

//subprogram list relasi PlaylistToLagu
adrPlaylistToLagu createRelasiPlaylistToLagu(adrPlaylist P, adrLagu L);
void createListPlaylistToLagu(listPlaylistToLagu &LPL);
bool isEmptyPlaylistToLagu(listPlaylistToLagu LPL);
void insertPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL);
void deleteFirstPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL);
void deleteLastPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu PL);
void deleteAfterPlaylistToLagu(listPlaylistToLagu &LPL, adrPlaylistToLagu prec, adrPlaylistToLagu PL);
// mencari elemen playlist & lagu
// a. menggunakan address playlist & lagu
adrPlaylistToLagu findPlaylistLagu(listPlaylistToLagu LPL, adrPlaylist P, adrLagu L);
// b. menggunakan idPlaylist dan judul lagu
adrPlaylistToLagu findPlaylistLagu(listPlaylistToLagu LPL, string idPlaylist, string judulLagu);
/* Connect: menyambung list playlist dengan list lagu
Disconnect: memutus hubungan list playlist dengan list lagu
*/
void connectPlaylistToLagu(listPlaylistToLagu &LPL, listPlaylist LP, listLagu LL, string idPlaylist, string judulLagu);
void disconnectPlaylistToLagu(listPlaylistToLagu &LPL, string idPlaylist, string judulLagu);
// Menampilkan list relasi playlistToLagu terhadap playlist
//void printPlaylistToLagu(listPlaylistToLagu LPL, listPlaylist LP)

//subprogram list relasi playlistToAkun
adrPlaylistToAkun createRelasiPlaylistToAkun(adrPlaylist P, adrAkun A);
void createListPlaylistToAkun(listPlaylistToAkun &LPA);
bool isEmptyPlaylistToAkun(listPlaylistToAkun LPA);
void insertPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun PA);
void deleteFirstPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun &PA);
void deleteAfterPlaylistToAkun(listPlaylistToAkun &LPA,adrPlaylistToAkun prec, adrPlaylistToAkun &PA);
void deleteLastPlaylistToAkun(listPlaylistToAkun &LPA, adrPlaylistToAkun &PA);
// mencari elemen playlist & akun
// a. menggunakan address playlist & akun
adrPlaylistToAkun findPlaylistAkun(listPlaylistToAkun LPA, adrPlaylist P, adrAkun A);
// b. menggunakan idPlaylist dan username akun
adrPlaylistToAkun findPlaylistAkun(listPlaylistToAkun LPA, string username);
/* Connect: menyambung list playlist dengan list akun
Disconnect: memutus hubungan list playlist dengan list akun
*/
void connectPlaylistToAkun(listPlaylistToAkun &LPA, listPlaylist LP, listAkun LA, string idPlaylist, string username);
void disconnectPlaylistToAkun(listPlaylistToAkun &LPA, string idPlaylist, string username);
// Menampilkan list relasi playlistToLagu terhadap playlist
//void printPlaylistToAkun(lsitPlaylistToAkun LPA, listPlaylist LP)

//void displayUtama(listAkun &LA, listPlaylist &LP, listLagu &LL);
void menuUtama();
void adminMenu();
void userMenu(listLagu &LL, listPlaylist &LP, listAkun &LA);

//fitur
void rekomendasiLagu();
void kelolaPlaylist();
void playLaguFromLibrary();
void playlistAkunLain();


/*
void addLaguToPlaylist(listPlaylist &LP, adrLagu L);
void removeLaguToPlaylist(listPlaylist &LP, string judul);
void removeLaguToAllPlaylist(listAkun &LA, string judul);
*/
void deleteLagu(listLagu LL,adrLagu L);
void deleteAkun(listAkun LA,adrAkun A);
void deletePlaylist(listPlaylist LP,adrPlaylist P);

#endif // PEMUTARMUSIK_H_INCLUDED
