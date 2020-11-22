#include <iostream>
#include <fstream>

int anycount = 0;
int max = 1000;
int pluus = 1;
int or1or2 = 0;
bool anycount_bigger = false;

int main()
{
	std::ofstream F;
	F.open("count.txt", std::ios::out);
	system("title BEST SASAVN PROJECT!");
	std::cout << "Start number (default 0): ";
	std::cin >> anycount;
	std::cout << "Add number (default 1): ";
	std::cin >> pluus;
	std::cout << "End number (default 1000): ";
	std::cin >> max;
	std::cout << "Select mode: \n 1.Progress Bar \n 2.Live Print \n 1 or 2: ";
	std::cin >> or1or2;

	if (pluus == 0)
		pluus = 1;
	if (pluus < 0)
	{
		pluus = -pluus;
		int temp = max;
		max = anycount;
		anycount = temp;
	}

	if (max < anycount)
		anycount_bigger = true;

	if (or1or2 == 1)
	{
		int op = (max - anycount) / 100;
		int oldop = op;
		std::cout << "[";
		while (!anycount_bigger ? anycount < max + pluus : anycount > max - pluus)
		{
			if (!anycount_bigger ? anycount < max : anycount > max)
			{
				F << anycount << ", ";
			}
			else if (!anycount_bigger ? anycount >= max : anycount <= max)
			{
				F << anycount;
			}
			if (anycount > 0 ? op == anycount / 2 : op == -anycount / 2)
			{
				op = op + oldop;
				std::cout << "=";
			}
			if (!anycount_bigger)
				anycount = anycount + pluus;
			else
				anycount = anycount - pluus;
		}
		std::cout << "]";
	}
	else 
	{
		while (!anycount_bigger ? anycount < max + pluus : anycount > max - pluus)
		{
			if (!anycount_bigger ? anycount < max : anycount > max)
			{
				F << anycount << ", ";
				std::cout << anycount << ", ";
			}
			else if (!anycount_bigger ? anycount >= max : anycount <= max)
			{
				F << anycount;
				std::cout << anycount;
			}
			if (!anycount_bigger)
				anycount = anycount + pluus;
			else
				anycount = anycount - pluus;
		}
	}
	F.close();
	system("count.txt");
	std::cout << std::endl;
	system("pause");
}
