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
struct PlaylistToLagu{
    adrLagu lagu;
    adrPlaylist playlist;
    adrLaguToPlaylist next;
    adrLaguToPlaylist prev;
};
struct listPlaylistToLagu{
    adrPlaylistToLagu first;
    adrPlaylistToLagu last;
};
struct Playlist{
    string namaPlaylist;
    string idPlaylist;

    adrPlaylist next;
    adrPlaylist prev;
    adrPlaylistToLagu relasiToLagu;
    adrPlaylistToAkun relastiToAkun;
    adrLagu lagu;
};
struct listPlaylist{
    adrPlaylist first;
    adrPlaylist last;
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


adrAkun createakun(string username, string password, string role);
void createListAkun(listAkun &LA);
adrLagu createLagu(string idLagu, string judul, string artis, string genre, int durasi);
void createListLagu(listLagu &LL);
adrPlaylist createPlaylist(string nama, string id);
void createListPlaylist(listPlaylist &LP);
bool isEmptyPlaylist(listPlaylist LP);
bool isEmptyAkun(listAkun LA);
bool isEmptyLagu(listLagu LL);
// relasi
adrPlaylistToLagu createRelasiPlaylistToLagu(adrPlaylist p, adrLagu l);
void createListPlaylistToLagu(listPlaylistToLagu lpl);
adrPlaylistToAkun createRelasiPlaylistToAkun(adrPlaylist p, adrAkun a);
void createListPlaylistToAkun(listPlaylistToAkun lpa);
// insert list
void insertAkun(listAkun &LA, adrAkun A);
void insertPlaylist(listPlaylist &LP, adrPlaylist P);
void insertLagu(listLagu &LL, adrLagu L);
// delete list
void deleteFirstAkun(listAkun &LA, adrAkun &A);
void deleteAfterAkun(listAkun &LA,adrAkun prec, adrAkun &A);
void deleteLastAkun(listAkun &LA, adrAkun &A);
void deleteFirstLagu(listLagu &LL, adrLagu &L);
void deleteAfterLagu(listLagu &LL,adrLagu prec, adrLagu &L);
void deleteLastLagu(listLagu &LL, adrLagu &L);
void deleteFirstPlaylist(listPlaylist &LP, adrPlaylist &P);
void deleteAfterPlaylist(listPlaylist &LP,adrPlaylist prec, adrPlaylist &P);
void deleteLastPlaylist(listPlaylist &LP, adrPlaylist &P);
// find list
adrAkun findAkun(listAkun A, string username);
adrlagu findLaguByID(listLagu L, string id);
adrLagu findLaguByJudul(listLagu L, string judul);
adrPlaylist findPlaylist(listPlaylist P, string namaPlaylist);
//insert relasi
void insertPlaylistToLagu(listPlaylistToLagu &lpl, adrLagu L, adrPlaylist P);
void insertPlaylistToAkun(listPlaylistToAkun &lpa, adrAkun a, adrPlaylist p);
//delete relasi
void deleteFirstPlaylistToLagu(listPlaylistToLagu &lpl, adrPlaylistToLagu &LPL);
void deleteAfterPlaylistToLagu(listPlaylistToLagu &lpl,adrPlaylistToLagu prec, adrPlaylistToLagu &LPL);
void deleteLastPlaylistToLagu(listPlaylistToLagu &lpl, adrPlaylistToLagu &LPL);
void deleteFirstPlaylistToAkun(listPlaylistToAkun &lpa, adrPlaylistToAkun &LPA);
void deleteAfterPlaylistToAkun(listPlaylistToAkun &lpa,adrPlaylistToAkun prec, adrPlaylistToAkun &LPA);
void deleteLastPlalistToAkun(listPlaylistToAkun &lpa, adrPlaylistToAkun &LPA);
//show list
void showAkun(listAkun LA);
void showLagu(listLagu LL);
void showPlaylist(listPlaylist LP);
//update list
void updateLagu(listLagu &LL, string id, string judul, string artis, string genre, int durasi);
void updateAkun(listAkun &LA, string username, string password);
void updatePlaylist(listPlaylist &LP, string id, string namaPlaylist);
//fitur
void addLaguToPlaylist(listPlaylist &LP, adrLagu L);
void removeLaguToPlaylist(listPlaylist &LP, string judul);
void removeLaguToAllPlaylist(listAkun &LA, string judul);



#endif // PEMUTARMUSIK_H_INCLUDED
