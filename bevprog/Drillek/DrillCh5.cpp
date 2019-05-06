#include "std_lib_facilities.h"
int main()
try
{
	/*
	cout << "Success!\n";
	
	cout << "Success!\n";
	
	cout << "Success" << "!\n";
	
	cout << "Success!" << '\n';
	
	int res = 7;
	vector<int> v(10);
	v[5] = res;
	cout << "Success!\n";
	
	vector<int> v(10);
	v[5] = 7;
	if (v[5] == 7)
		cout << "Success!\n";
	
	if (true)
		cout << "Success!\n";
	else
		cout << "Fail!\n";
	
	bool c = true;
	if (c)
		cout << "Success!\n";
	else
		cout << "Fail!\n";
	
	string s = "ape";
	string c = "fool" + s;
	if (c == "foolape")
		cout << "Success!\n";
	
	string s = "ape";
	if (s == "ape")
		cout << "Success!\n";
	
	string s = "ape";
	if (s == "ape")
		cout << "Success!\n";
	
	string s = "ape";
	if (s == "ape")
		cout << "Success!\n";
	
	vector<char> v(5);
	for (int i=0; 0>v.size(); ++i)
		;
	cout << "Success!\n";
	
	vector<char> v(5);
	for (int i=0; i<=v.size(); ++i)
		;
	cout << "Success!\n";
	
	string s = "Success!\n";
	for (int i=0; i<9; ++i)
		cout << s[i];
	
	if (true)
		cout << "Success!\n";
	else cout << "Fail!\n";
	
	int x = 2000;
	wchar_t c = x;
	if (c == 2000)
		cout << "Success!\n";
	
	string s = "Success!\n";
	for (int i=0; i<9; ++i)
		cout << s[i];
	
	vector<int> v(5);
	for (int i=0;i<=v.size(); ++i) ;
		cout << "Success!\n";
	
	int i=0;
	int j = 9;
	while (i<10)
		++i;
	if (j<i)
		cout << "Success!\n";
	
	int x = 2;
	double d = 5/(x-1);
	if (d == (2*x + 1))
		cout << "Success!\n";
	
	vector<char> s = {'S','u','c','c','e','s','s','!','\n'};
	for (int i=0; i<9; ++i)
		cout << s[i];
	
	int i=0;
	while (i<10)
		++i;
	if (0<i)
		cout << "Success!\n";
	
	int x = 4;
	double d = 5/(x - 2);
	if (d !=  x/2 + 0.5)
		cout << "Success!\n";
	*/
	cout << "Success!\n";

	keep_window_open();
	return 0;
}
catch (exception& e)
{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...)
{
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
