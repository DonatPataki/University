#include "lzwbinfa.h"
#include <iostream>
#include <fstream>
#include <cmath>

LZWBinFa::LZWBinFa(){
	fa = &gyoker;
	maxMelyseg = 0;
	tmpMelyseg = 0;
}

LZWBinFa::~LZWBinFa(){
	szabadit(gyoker.getBal());
	szabadit(gyoker.getJobb());
}

void LZWBinFa::felepitFajlbol(std::string fajlnev, bool elsoSortKihagy){

	std::fstream fajl(fajlnev, std::fstream::in);
	
	if(!fajl.is_open()){
		std::cerr << "Hiba a '" << fajlnev << "' nevu fajl megnyitasakor!" << std::endl;
		return;
	}

	unsigned char c;
	bool komment = false;

	if(elsoSortKihagy){
		while(fajl.read((char*) &c, sizeof(unsigned char)))
			if(c==0x0a)
				break;
	}

	while(fajl.read((char*) &c, sizeof(unsigned char))){

		if(c==0x3e){	// > karakter
			komment = true;
			continue;
		}
		if(c==0x0a){	// sor vége
			komment = false;
			continue;
		}
		if(komment){
			continue;
		}
		if(c==0x4e)		// N betű
			continue;

		for(int i=0; i<8; i++){
			if(c & 0x80)
				*this << '1';
			else
				*this << '0';
			c <<= 1;
		}

	}

	fajl.close();

}

void LZWBinFa::kiirFajlba(std::string fajlnev){
	std::fstream fajl(fajlnev, std::fstream::out);

	if(!fajl.is_open()){
		std::cerr << "Nem sikerult kiirni az adatokat a '" << fajlnev << "' nevu fajlba!" << std::endl;
		return;
	}

	fajl << "Melyseg: " << getMelyseg() << std::endl;
	fajl << "Atlag: " << getAtlag() << std::endl;
	fajl << "Szoras: " << getSzoras() << std::endl;
	fajl << *this;
	fajl.close();
}

void LZWBinFa::szabadit(Csomopont* cs){
	if(cs!=NULL){
		szabadit(cs->getBal());
		szabadit(cs->getJobb());
		delete cs;
	}
}

// kiírató függvények
void LZWBinFa::kiir(void){
	melyseg = 0;
	kiir(&gyoker, std::cout);
}

void LZWBinFa::kiir(std::ostream & os){
	melyseg = 0;
	kiir(&gyoker, os);
}

void LZWBinFa::kiir(Csomopont* cs, std::ostream & os){
	if(cs!=NULL){
		melyseg++;
		kiir(cs->getJobb(), os);
		for(int i=0; i<melyseg; i++)
			os << "---";
		os << cs->getBetu() << " (" << melyseg-1 << ")" << std::endl;
		kiir(cs->getBal(), os);
		melyseg--;
	}
}

int LZWBinFa::getMelyseg() const{
	return maxMelyseg;
}

double LZWBinFa::getAtlag(){
	melyseg = atlagOsszeg = atlagdb = 0;
	rAtlag(&gyoker);
	return ((double) atlagOsszeg / atlagdb);
}

void LZWBinFa::rAtlag(Csomopont* cs){
	if(cs!=NULL){
		melyseg++;
		rAtlag(cs->getBal());
		rAtlag(cs->getJobb());
		melyseg--;

		if(cs->getBal()==NULL && cs->getJobb()==NULL){
			atlagdb++;
			atlagOsszeg+=melyseg;
		}
	}
}

double LZWBinFa::getSzoras(){
	atlag = getAtlag();
	szorasOsszeg = 0.0;
	melyseg = atlagdb = 0;

	rSzoras(&gyoker);

	if(atlagdb-1>0)
		return std::sqrt(szorasOsszeg / (atlagdb-1));
	else
		return std::sqrt(szorasOsszeg);
}

void LZWBinFa::rSzoras(Csomopont* cs){
	if(cs!=NULL){
		melyseg++;
		rSzoras(cs->getBal());
		rSzoras(cs->getJobb());
		melyseg--;

		if(cs->getBal()==NULL && cs->getJobb()==NULL){
			atlagdb++;
			szorasOsszeg+=((melyseg-atlag)*(melyseg-atlag));
		}
	}
}

void LZWBinFa::operator<<(char c){

	tmpMelyseg++;
	if(tmpMelyseg>maxMelyseg)
		maxMelyseg = tmpMelyseg;

	if(c=='0'){

		if(!fa->getBal()){

			Csomopont* cs = new Csomopont('0');
			fa->ujBal(cs);
			fa = &gyoker;
			tmpMelyseg = 0;

		}else{
			fa = fa->getBal();
		}

	}else{

		if(!fa->getJobb()){

			Csomopont* cs = new Csomopont('1');
			fa->ujJobb(cs);
			fa = &gyoker;
			tmpMelyseg = 0;

		}else{
			fa = fa->getJobb();
		}

	}

}

std::ostream & operator<<(std::ostream & os, LZWBinFa & bf){
	bf.kiir(os);
	return os;
}

// Csomopont osztály deklarálása

LZWBinFa::Csomopont::Csomopont(char c){
	betu = c;
	bal = 0;
	jobb = 0;
}

void LZWBinFa::Csomopont::ujBal(Csomopont* cs){
	bal = cs;
}

void LZWBinFa::Csomopont::ujJobb(Csomopont* cs){
	jobb = cs;
}

char LZWBinFa::Csomopont::getBetu() const{
	return betu;
}

LZWBinFa::Csomopont* LZWBinFa::Csomopont::getBal() const{
	return bal;
}

LZWBinFa::Csomopont* LZWBinFa::Csomopont::getJobb() const{
	return jobb;
}
