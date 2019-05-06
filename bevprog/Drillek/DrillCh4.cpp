#include "std_lib_facilities.h"

int main() 
{
	double  smallest,largest,d,sum=0,darab=0;//a,b;
	//alapértelmezett értékek elkerülése
	smallest = numeric_limits<double>::max();
	largest = numeric_limits<double>::min();
	string c;
	vector<double> ossz_szam;
	//bool print = false;
	bool reject = false;

	while(true)
	{
		cout << "Waiting for a number : ";
		cin >> c;
		if (c == "|")
		{
			break;
		}
		d = stod(c);
		cout << "Unit (cm,in,ft,m): ";
		cin >> c;
		switch (c[0])
		{
			case 'c':
					d = d/100;
			break;
			case 'i':
					d = d*2.54/100;
			break;
			case 'f':
					d = d*12*2.54/100;
			break;
			case 'm':
			break;
		}
		if(c != "cm" && c != "in" && c != "ft" && c != "m")
		{
			cout << "Unit rejected!\n";
			reject = true;
		}
		if (reject != true)
		{
			cout << "You entered: " << d << " m\n";
			if (smallest > d)
			{
				smallest = d;
				cout << "the smallest so far \n";
			}
			if (largest < d)
			{
				largest = d;
				cout << "the largest so far \n";
			}
		sum+=d;
		darab++;
		ossz_szam.push_back(d);
		}
		reject = false;
		/*
		if( print == false)
		{
			a = stod(c);
		}
		else
		{
			b = stod(c);
			if (a > b)
			{
				a+=b;
				b = a-b;
				a = a-b;
			}

			if(a != b)
			{
				cout << "The smaller value is: " << a << "\n" << "The larger value is: " << b << "\n";
			}
			else
			{
				cout << "The numbers are equal.\n" ;
			}
			if (abs(a-b)<1.0/100)
			{
				cout << "The numbers are almost equal!\n";
			}
		}
		print = !print;
		*/
	}
	cout << "\n\nSmallest number: " << smallest << "\nLargest number: " << largest << "\nNumber of values: " << darab << "\nSum of values: " << sum << " m\n";
	sort(ossz_szam);
	for (int i = 0; i < ossz_szam.size(); i++)
	{
		cout << ossz_szam[i] << " m\n";
	}
}
