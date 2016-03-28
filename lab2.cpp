#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	char buff[100];
	ifstream fin("fileff.txt");
	while (!fin.eof())
	{
		fin >> buff;
		if (strcmp(buff, "\\func") == 0)
		{
			while (strcmp(buff, "*/") != 0)
			{
				fin >> buff;
				cout << buff << " ";
			}
		}
		
	}
	system("pause");
	return 0;
}
