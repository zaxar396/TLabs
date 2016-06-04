#include "iostream"
#include <cstring>
#include <stdexcept>
#include <stdio.h>

using namespace std;


int main()
{
	FILE* in = fopen("input2.txt", "r");
	char buf1[100];
	char buf2[100];

	int k = 0;

	int len1, len2;

	if (in == nullptr)
	{
		cout << "File not found" << endl;
		return 2;
	}

	while (!feof(in))
	{
		fgets(buf1, 99, in);

		len1 = strlen(buf1);

		if (strncmp(buf1, "/**", 3) == 0)
		{
			if (strncmp(buf1 + len1 - 3, "*/", 2) == 0)
			{
				if (strncmp(buf1 + 4, "\\func", 5) == 0)
				{
					++k;
					strncpy(buf2, buf1 + 9, len1 - 12);
					buf2[len1 - 12] = '\0';
					printf("%d.%s\n", k, buf2);

				}
			}

			else
			{
				bool f = false;
				while (!feof(in) && !f)
				{
					fgets(buf1, 99, in);

					int i = 0;
					while (buf1[i] == ' ')
						++i;

					len1 = strlen(buf1);

					if (strncmp(buf1 + len1 - 3, "*/", 2) == 0)
						f = true;

					if (strncmp(buf1 + i, "\\func", 5) == 0)
					{
						++k;
						if (f)
							len2 = len1 - i - 8;
						else
							len2 = len1 - i - 6;

						strncpy(buf2, buf1 + i + 5, len2);
						buf2[len2] = '\0';

						printf("%d.%s\n", k, buf2);
					}


				}

				if (!f)
					cout << "Error: unexpected end of file" << endl;
				
			}
		}

	}

	fclose(in);
	return 0;
}

