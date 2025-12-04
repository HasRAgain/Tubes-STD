#ifndef PEMUTARMUSIK_H_INCLUDED
#define PEMUTARMUSIK_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct Lagu *adrLagu;

struct Lagu{
    string idLagu;
    string judul;
    string artis;
    string genre;
    int durasi;

    adrLagu next;
    adrLagu prev;
};

struct ListLagu {
    Lagu* first;
    Lagu* last;
};

struct LaguPlaylist {
    Lagu* ref; // pointer ke node Lagu di library
    LaguPlaylist* next;
};

struct Playlist {
    int id;
    string nama;
    LaguPlaylist* firstLagu;
    Playlist* next;
};



#endif // PEMUTARMUSIK_H_INCLUDED
