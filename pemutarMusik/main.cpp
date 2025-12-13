#include "pemutarMusik.h"
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
