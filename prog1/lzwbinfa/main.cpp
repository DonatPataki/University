// Copyright (C) 2015, Veres Dávid, veres.david11@gmail.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Ez a program szabad szoftver; terjeszthetõ illetve módosítható a
// Free Software Foundation által kiadott GNU General Public License
// dokumentumában leírtak; akár a licenc 3-as, akár (tetszõleges) késõbbi
// változata szerint.
//
// Ez a program abban a reményben kerül közreadásra, hogy hasznos lesz,
// de minden egyéb GARANCIA NÉLKÜL, az ELADHATÓSÁGRA vagy VALAMELY CÉLRA
// VALÓ ALKALMAZHATÓSÁGRA való származtatott garanciát is beleértve.
// További részleteket a GNU General Public License tartalmaz.
//
// A felhasználónak a programmal együtt meg kell kapnia a GNU General
// Public License egy példányát; ha mégsem kapta meg, akkor
// tekintse meg a <http://www.gnu.org/licenses/> oldalon.

#include "lzwbinfa.h"
#include <string>

void parancs(){
	std::cout << "Az alabbi minta szerint futtasd a programot:" << std::endl;
	std::cout << "./main be.fajl -o ki.fajl" << std::endl;
}

int main(int argc, char* argv[]){

	// megnézzük hogy helyesen futtatjuk-e a programot
	if(argc!=4){
		std::cerr << "Nem megfelelo a parameterek szama!" << std::endl;
		parancs();
		return -1;
	}

	if(argv[2][1]!='o'){
		std::cerr << "Hasznald a -o kapcsolot masodik paramterkent!" << std::endl;
		parancs();
		return -2;
	}

	// a fa felépítése
	LZWBinFa binFa;
	binFa.felepitFajlbol(argv[1], true);

	binFa.kiirFajlba(argv[3]);

	return 0;
}
