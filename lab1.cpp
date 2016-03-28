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
	ifstream fin1("file1.txt");
	ifstream fin2("file2.txt");
	for (int i = 0; i < lines(); i++)
	{
		fin1 >> buff1;
		fin2 >> buff2;
		if (strcmp(buff1,buff2) != 0 )
		{
			cout << "file1.txt" << " " << i + 1  << " " << buff1 <<"\n";
			cout << "file2.txt" <<" "<< i + 1  << " " << buff2 << "\n";
		}

	}
	system("pause");
	return 0;
}
