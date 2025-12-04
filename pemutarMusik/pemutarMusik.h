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

#endif // PEMUTARMUSIK_H_INCLUDED
