#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int lines()
{
	ifstream fin("file1.txt");
	string s;
	int count = 0;
	while (true)
	{
		getline(fin, s);
		if (!fin.eof())
			count++;
		else
			break;

	}
	return count + 1;
}

int main(int argc, char* argv[])
{
	char buff1[100]; 
	char buff2[100];
	int p1 = 0;
	int p2 = 0;
	ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");
	for (int i = 0; i < lines(); i++)
	{
		fin1 >> buff1;
		for (int j = 0; j < lines(); j++)
		{
			fin2 >> buff2;
			if (strcmp(buff1, buff2) == 0)
			{
				break;
			}
			else
			{
				p1++;
			}
		}

		if (p1 == lines())
		{
			cout << "file1.txt " << i + 1 << " " << buff1 << endl;
		}

	}

	fin1.close();
	fin1.close();

	ifstream fin3("file1.txt");
	ifstream fin4("file2.txt");

	for (int i = 0; i < lines(); i++)
	{
		fin4 >> buff2;
		for (int j = 0; j < lines(); j++)
		{
			fin3 >> buff1;
			if (strcmp(buff2, buff1) == 0)
			{
				break;
			}
			else
			{
				p2++;
			}
		}

		if (p2 == lines())
		{
			cout << "file2.txt " << i + 1 << " " << buff2 << endl;
		}
	}
	fin3.close();
	fin4.close();
	system("pause");
	return 0;
}
