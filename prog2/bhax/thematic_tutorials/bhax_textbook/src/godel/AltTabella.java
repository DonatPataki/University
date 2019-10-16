import static java.lang.System.out;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;


class Csapat implements Comparable<Csapat> {

	private String nev = "Nincs";
	private double ertek = '0';

	public Csapat(String nev, double ertek) {
		this.setNev(nev);
		this.setErtek(ertek);
	}

	public Csapat() {
		// TODO Auto-generated constructor stub
	}

	public int compareTo(Csapat a) {
		if (this.getErtek() < a.getErtek()) {
			return 1;
		} else if (this.getErtek() > a.getErtek()) {
			return -1;
		} else {
			return 0;
		}
	}

	protected String getNev() {
		return nev;
	}

	protected void setNev(String nev) {
		this.nev = nev;
	}

	protected double getErtek() {
		return ertek;
	}

	protected void setErtek(double ertek) {
		this.ertek = ertek;
	}

	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append(this.nev);
		sb.append("\t");
		sb.append(this.ertek);
		return sb.toString();
	}

}

public class AltTabella {

	public static void main(String[] args) {

		double[][] Lnk = {
				{ 0.0, 0.08333333333333333, 0.0, 0.1111111111111111,
						0.14285714285714285, 0.0, 0.1111111111111111, 0.0, 0.0,
						0.08333333333333333, 0.1111111111111111, 0.0625, 0.0,
						0.16666666666666666, 0.16666666666666666, 0.0, },
				{ 0.0, 0.0, 0.08333333333333333, 0.1111111111111111,
						0.14285714285714285, 0.08333333333333333,
						0.1111111111111111, 0.0, 0.0, 0.0, 0.1111111111111111,
						0.0625, 0.07692307692307693, 0.0, 0.16666666666666666,
						0.1111111111111111, },
				{ 0.07142857142857142, 0.16666666666666666, 0.0, 0.0, 0.0,
						0.16666666666666666, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0625,
						0.07692307692307693, 0.08333333333333333,
						0.16666666666666666, 0.0, },
				{ 0.0, 0.0, 0.08333333333333333, 0.0, 0.14285714285714285, 0.0,
						0.1111111111111111, 0.1, 0.2, 0.08333333333333333,
						0.2222222222222222, 0.0625, 0.0, 0.08333333333333333,
						0.16666666666666666, 0.1111111111111111, },
				{ 0.0, 0.08333333333333333, 0.08333333333333333, 0.0, 0.0,
						0.08333333333333333, 0.1111111111111111, 0.2, 0.1,
						0.08333333333333333, 0.1111111111111111, 0.0625,
						0.07692307692307693, 0.0, 0.16666666666666666, 0.0, },
				{ 0.14285714285714285, 0.08333333333333333, 0.0,
						0.1111111111111111, 0.0, 0.0, 0.0, 0.1, 0.0,
						0.08333333333333333, 0.0, 0.0625, 0.07692307692307693,
						0.16666666666666666, 0.16666666666666666, 0.0, },
				{ 0.07142857142857142, 0.08333333333333333,
						0.08333333333333333, 0.0, 0.0, 0.08333333333333333,
						0.0, 0.1, 0.1, 0.08333333333333333, 0.0, 0.0625,
						0.07692307692307693, 0.0, 0.0, 0.2222222222222222, },
				{ 0.07142857142857142, 0.08333333333333333,
						0.08333333333333333, 0.1111111111111111, 0.0, 0.0, 0.0,
						0.0, 0.0, 0.08333333333333333, 0.0, 0.0625,
						0.07692307692307693, 0.08333333333333333, 0.0, 0.0, },
				{ 0.07142857142857142, 0.08333333333333333,
						0.08333333333333333, 0.1111111111111111, 0.0,
						0.08333333333333333, 0.0, 0.1, 0.0, 0.0, 0.0, 0.125,
						0.07692307692307693, 0.08333333333333333, 0.0,
						0.1111111111111111, },
				{ 0.07142857142857142, 0.16666666666666666,
						0.08333333333333333, 0.1111111111111111, 0.0,
						0.08333333333333333, 0.0, 0.1, 0.1, 0.0,
						0.1111111111111111, 0.0, 0.0, 0.08333333333333333, 0.0,
						0.0, },
				{ 0.07142857142857142, 0.0, 0.08333333333333333,
						0.1111111111111111, 0.14285714285714285,
						0.08333333333333333, 0.1111111111111111, 0.1, 0.1,
						0.08333333333333333, 0.0, 0.0625, 0.07692307692307693,
						0.08333333333333333, 0.0, 0.1111111111111111, },
				{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
						0.08333333333333333, 0.1111111111111111, 0.0,
						0.07692307692307693, 0.0, 0.0, 0.0, },
				{ 0.07142857142857142, 0.08333333333333333, 0.0,
						0.1111111111111111, 0.0, 0.08333333333333333,
						0.1111111111111111, 0.0, 0.0, 0.08333333333333333, 0.0,
						0.125, 0.0, 0.0, 0.0, 0.2222222222222222, },
				{ 0.14285714285714285, 0.08333333333333333,
						0.08333333333333333, 0.1111111111111111,
						0.14285714285714285, 0.08333333333333333,
						0.2222222222222222, 0.0, 0.0, 0.0, 0.0, 0.0625,
						0.07692307692307693, 0.0, 0.0, 0.0, },
				{ 0.14285714285714285, 0.0, 0.16666666666666666, 0.0,
						0.14285714285714285, 0.08333333333333333,
						0.1111111111111111, 0.1, 0.1, 0.16666666666666666,
						0.1111111111111111, 0.0625, 0.07692307692307693,
						0.08333333333333333, 0.0, 0.1111111111111111, },
				{ 0.07142857142857142, 0.0, 0.08333333333333333, 0.0,
						0.14285714285714285, 0.08333333333333333, 0.0, 0.1,
						0.1, 0.08333333333333333, 0.1111111111111111, 0.0625,
						0.15384615384615385, 0.08333333333333333, 0.0, 0.0, } };

		String[] eredetinev = { "Videoton", "Ferencvαros", "Paks",
				"Debreceni VSC", "Zalaegerszegi TE", "Kaposvαri Rαkσczi",
				"Lombard Pαpa", "Kecskemιti TE", "Ϊjpest", "Gyυri ETO",
				"Budapest Honvιd", "MTK Budapest", "Vasas",
				"Szombathelyi Haladαs", "BFC Siσfok", "Szolnoki MΑV" };
		int[] eredetipont = { 40, 34, 31, 31, 30, 29, 27, 24, 23, 23, 22, 22,
				21, 20, 18, 9 };
		String[] ujnev = { "BFC Siσfok", "Budapest Honvιd", "Vasas",
				"Debreceni VSC", "Ferencvαros", "Gyυri ETO",
				"Kaposvαri Rαkσczi", "Kecskemιti TE", "Lombard Pαpa",
				"MTK Budapest", "Paksi FC", "Szolnoki MΑV FC",
				"Szombathelyi Haladαs", "Ϊjpest", "Videoton",
				"Zalaegerszegi TE" };

		
		ArrayList<Csapat> regi = new ArrayList<Csapat>(eredetinev.length);
		ArrayList<Csapat> uj = new ArrayList<Csapat>(ujnev.length);
		

		for (int i = 0; i < eredetinev.length; i++) {
			regi.add(new Csapat(eredetinev[i],eredetipont[i]));
		}
		

		double[] hv = new double[Lnk.length];
		double[] h = new double[Lnk.length];

		for (int i = 0; i < h.length; ++i) {
			hv[i] = 1.0 / Lnk[i].length;
			h[i] = 0.0;
		}

		double reginorma = 0.0, regiosszeg = 0.0;

		boolean amig = true;

		while (true) {

			for (int i = 0; i < Lnk.length; i++) {
				for (int j = 0; j < Lnk[i].length; j++) {
					h[i] += Lnk[i][j] * hv[j];
				}
			}

			double osszeg = 0.0;

			for (int i = 0; i < h.length; i++) {
				osszeg += Math.pow(hv[i] - h[i], 2);
			}

			out.println("Iteracio...");

			double norma = Math.sqrt(osszeg);
			out.println("norma = " + norma);

			if (norma < .000000000001) {
				amig = false;

				out.println("+++");
				double osszegEll = 0.0;
				for (int i = 0; i < h.length; i++) {

					osszegEll += h[i];
					out.println(h[i]);

				}
				out.println("osszeg ell. = " + osszegEll);
				out.println("++++");

			}

			double d = 0.87;

			osszeg = 0.0;
			for (int i = 0; i < h.length; ++i) {

				hv[i] = d * h[i] + (1.0 - d) / Lnk.length;

				osszeg += hv[i];
				h[i] = 0.0;
			}

			out.println("osszeg =" + osszeg);

			if (osszeg == regiosszeg && norma == reginorma) {
				amig = false;

				System.out.println("***");
				for (int i = 0; i < h.length; i++) {
					System.out.println(hv[i]);
				}

				System.out.println("****");

				for (int i = 0; i < ujnev.length; i++) {
					uj.add(new Csapat(ujnev[i],hv[i]));
				}
				Collections.sort(uj);

			}
			reginorma = norma;
			regiosszeg = osszeg;

			if (!amig)
				break;
		}
		
		Iterator<Csapat> Ir = regi.iterator();
		Iterator<Csapat> Iuj = uj.iterator();
		
		
		for (int i=0; Iuj.hasNext();i++) {
			
			Csapat csapat = (Csapat) Iuj.next();
			Csapat csapat2 = (Csapat) Ir.next();
			out.print(i+1+"   ");out.println(csapat);
			out.print(i+1+"   ");out.println(csapat2);
						
		}
		
	}

}
