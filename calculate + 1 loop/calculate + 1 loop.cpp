#include <iostream>
#include <fstream>

int anycount = 0;
int max = 1000;
int pluus = 1;
int or1or2 = 0;

using namespace std;

int main()
{
	ofstream F;
	F.open("count.txt", ios::out);
	system("title BEST SASAVN PROJECT!");
	cout << "Start number (default 0): ";
	cin >> anycount;
	cout << "Add number (default 1): ";
	cin >> pluus;
	cout << "End number (default 1000): ";
	cin >> max;
	cout << "Select mode: \n 1.Progress Bar \n 2.Live Print \n 1 or 2: ";
	cin >> or1or2;
	if (or1or2 == 1)
	{
		int op = max / 100;
		int oldop = op;
		cout << "[";
		while (anycount != max + pluus)
		{
			if (anycount < max)
			{
				F << anycount << ", ";
			}
			if (anycount == max)
			{
				F << anycount;
			}
			if (op == anycount / 2)
			{
				op = op + oldop;
				cout << "=";
			}
			anycount = anycount + pluus;
		}
		cout << "]";
	}
	else 
	{
		while (anycount != max + pluus)
		{
			if (anycount < max)
			{
				F << anycount << ", ";
				cout << anycount << ", ";
			}
			if (anycount == max)
			{
				F << anycount;
				cout << anycount;
			}

			anycount = anycount + pluus;
		}
	}
	F.close();
	system("count.txt");
	cout << "\n";
	system("pause");
}
