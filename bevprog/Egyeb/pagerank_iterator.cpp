#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

void kiir(vector <double> tomb)
{
	for (vector <double>::iterator tomb_iterator = tomb.begin(); tomb_iterator != tomb.end(); tomb_iterator++)
	{
		printf("%f\n", *tomb_iterator);
	}
}

double tavolsag(vector <double> PR, vector <double> PRv)
{
    double osszeg = 0.0;
    vector <double>::iterator PRv_iterator = PRv.begin();
    vector <double>::iterator PR_iterator = PR.begin();
    while(PRv_iterator != PRv.end() && PR_iterator != PR.end())
    {
    	osszeg += (*PRv_iterator-*PR_iterator)*(*PRv_iterator-*PR_iterator);
    	PRv_iterator++;
    	PR_iterator++;
    }
    return sqrt(osszeg);
}

int main(void)
{
	vector <vector <double>> L =
	{
		{0.0, 0.0, 1.0 / 3.0, 0.0},
		{1.0, 1.0 / 2.0, 1.0 / 3.0, 1.0},
		{0.0, 1.0 / 2.0, 0.0, 0.0},
		{0.0, 0.0, 1.0 / 3.0, 0.0}
	};

	vector <double> PR = {0.0, 0.0, 0.0, 0.0};
	vector <double> PRv = {1.0/4.0,1.0/4.0,1.0/4.0,1.0/4.0};

	int i,j;
	for (;;)
	{
		for (int i = 0; i<L.size(); ++i)
		{
			PR[i] = 0.0;
			for (int j = 0; j<L[i].size(); ++j)
			{
				PR[i] += (L[i][j]*PRv[j]);
			}
		} 
		if(tavolsag(PR, PRv)<0.0000001)
		{
			break;
		}
		for(int i = 0; i<PRv.size(); i++)
		{
			PRv[i] = PR[i];
		}		
	}
	kiir(PR);
	return 0;
}
