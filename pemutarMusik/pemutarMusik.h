#ifndef PEMUTARMUSIK_H_INCLUDED
#define PEMUTARMUSIK_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Lagu *adrLagu;
typedef struct Akun *adrAkun;
typedef struct Playlist *adrPlaylist;
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
    string passwrod;
    string role;

    adrAkun next;
    adrAkun prev;
};
struct listAkun{
    adrAkun first;
    adrAkun last;
};


adrAkun createakun(string username, string password, string role);
void createListAkun(listAkun &La);
adrLagu createLagu(string idLagu, string judul, string artis, string genre, int durasi);
void createListLagu(listLagu &Ll);
adrPlaylistToLagu createRelasiPlaylistToLagu(adrPlaylist p, adrLagu l);
void createListPlaylistToLagu(listPlaylistToLagu lpl);
adrPlaylistToAkun createRelasiPlaylistToAkun(adrPlaylist p, adrAkun a);
void createListPlaylistToAkun(listPlaylistToAkun lpa);


#endif // PEMUTARMUSIK_H_INCLUDED
