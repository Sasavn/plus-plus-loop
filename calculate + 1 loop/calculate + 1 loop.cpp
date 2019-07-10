#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cmath>
#include <stdio.h>
#include <direct.h>

int anycount = 0;
int max = 1000;//10000000;
int pluus = 1;
float progress = 0.0;
int barWidth = 70;
int or1or2 = 0;

using namespace std;

const char* getcd()
{
	char cCurrentPath[FILENAME_MAX];

	if (!_getcwd(cCurrentPath, sizeof(cCurrentPath)))
	{
		return false;
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	return cCurrentPath;
}

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
		int op;
		op = max / 100;
		int oldop = op;
		cout << "[";
		while (anycount != max + 1)
		{
			if (anycount < max - 1)
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
	}
	if (or1or2 == 2)
	{
		while (anycount != max + 1)
		{
			if (anycount < max - 1)
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
	if (or1or2 == 1)
	{
		cout << "]";
	}
	F.close();
	system("count.txt");
	cout << "\n";
	system("pause");
}