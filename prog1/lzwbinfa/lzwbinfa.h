#ifndef LZWBINFA
#define LZWBINFA

#include <iostream>

class LZWBinFa{

public:

	LZWBinFa();
	~LZWBinFa();

	void felepitFajlbol(std::string fajlnev, bool elsoSortKihagy = false);
	void kiirFajlba(std::string fajlnev);

	// kiírató függvények
	void kiir(void);
	void kiir(std::ostream & os);

	int getMelyseg() const;
	double getAtlag();
	double getSzoras();

	void operator<<(char c);
	friend std::ostream & operator<<(std::ostream & os, LZWBinFa & bf);

private:

	class Csomopont{

	public:
		Csomopont(char c = '/');

		void ujBal(Csomopont* cs);
		void ujJobb(Csomopont* cs);

		char getBetu() const;
		Csomopont* getBal() const;
		Csomopont* getJobb() const;

	private:
		char betu;
		Csomopont* bal;
		Csomopont* jobb;

		Csomopont(const Csomopont &);
		Csomopont & operator=(const Csomopont &);

	};

	Csomopont* fa;
	int melyseg;
	int atlagdb;
	int atlagOsszeg;
	int tmpMelyseg;
	double atlag;
	double szorasOsszeg;

	void kiir(Csomopont* cs, std::ostream & os);

	void szabadit(Csomopont* cs);

	LZWBinFa(const LZWBinFa &);
	LZWBinFa & operator=(const LZWBinFa &);

protected:

	Csomopont gyoker;
	int maxMelyseg;

	void rAtlag(Csomopont* cs);
	void rSzoras(Csomopont* cs);

};

#endif
