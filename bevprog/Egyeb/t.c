/*
Kulcs: [asdas]
Tiszta szoveg: [A kecskék megjelenése, köztük mérete, színe, és más jellemzői fajtára jellemzők. Törpe fajtáknál, mint a Boer a nőstények testsúlya 20-27 kg, a nagytestű fajtáknál a bakok akár a 140 kg-ot is elérhetik.[8] A fajtákon belül leszármazási ágakra is jellemzőek a méretek. Az afrikai pigmeus törpekecske vállmagassága 41-58 cm.[9] Felnőttkori testméretét a fajta mellett az elérhető tápanyag mennyisége is befolyásolja. Növendék korban a tápanyagnak 10 - 14% fehérjét és elegendő kalóriát kell tartalmaznia, hogy elérje a genetikája serinti testméretet.[10] A nagytestű fajták 36-42, kisebb testű fajták 18-24 hónap alatt érik el felnőttkori méretüket ha nem
]
*/
#define MAX_TITKOS 4096
#define OLVASAS_BUFFER 256
#define KULCS_MERET 5
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double
atlagos_szohossz (const char *titkos, int titkos_meret)
{
  int sz = 0;
  for (int i = 0; i < titkos_meret; ++i)
    if (titkos[i] == ' ')
      ++sz;

  return (double) titkos_meret / sz;
}

int
tiszta_lehet (const char *titkos, int titkos_meret)
{
  // a tiszta szoveg valszeg tartalmazza a gyakori magyar szavakat
  // illetve az átlagos szóhossz vizsgálatával csökkentjük a
  // potenciális töréseket

  double szohossz = atlagos_szohossz (titkos, titkos_meret);

  return szohossz > 6.0 && szohossz < 9.0
    && strcasestr (titkos, "hogy") && strcasestr (titkos, "nem")
    && strcasestr (titkos, "az") && strcasestr (titkos, "ha");

}

void
exor (const char kulcs[], int kulcs_meret, char titkos[], int titkos_meret)
{

  int kulcs_index = 0;

  for (int i = 0; i < titkos_meret; ++i)
    {

      titkos[i] = titkos[i] ^ kulcs[kulcs_index];
      kulcs_index = (kulcs_index + 1) % kulcs_meret;

    }

}

int
exor_tores (const char kulcs[], int kulcs_meret, char titkos[],
	    int titkos_meret)
{

  exor (kulcs, kulcs_meret, titkos, titkos_meret);

  return tiszta_lehet (titkos, titkos_meret);

}

int
main (void)
{

  char kulcs[KULCS_MERET];
  char titkos[MAX_TITKOS];
  char *p = titkos;
  int olvasott_bajtok;

  // titkos fajt berantasa
  while ((olvasott_bajtok =
	  read (0, (void *) p,
		(p - titkos + OLVASAS_BUFFER <
		 MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p)))
    p += olvasott_bajtok;

  // maradek hely nullazasa a titkos bufferben  
  for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i)
    titkos[p - titkos + i] = '\0';

  // osszes kulcs eloallitasa
  for (int ii = 'a'; ii <= 'z'; ++ii)
    for (int ji = 'a'; ji <= 'z'; ++ji)
      for (int ki = 'a'; ki <= 'z'; ++ki)
	for (int li = 'a'; li <= 'z'; ++li)
	  for (int mi = 'a'; mi <= 'z'; ++mi)
		  {
		    kulcs[0] = ii;
		    kulcs[1] = ji;
		    kulcs[2] = ki;
		    kulcs[3] = li;
		    kulcs[4] = mi;

		    if (exor_tores (kulcs, KULCS_MERET, titkos, p - titkos))
		      printf
			("Kulcs: [%c%c%c%c%c]\nTiszta szoveg: [%s]\n",
			 ii, ji, ki, li, mi, titkos);

		    // ujra EXOR-ozunk, igy nem kell egy masodik buffer  
		    exor (kulcs, KULCS_MERET, titkos, p - titkos);
		  }

  return 0;
}
