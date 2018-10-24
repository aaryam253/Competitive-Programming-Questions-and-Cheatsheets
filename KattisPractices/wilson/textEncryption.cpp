#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int step;

	do {
		int d = 0;
		char input[10001] = {0}, output[10001] = {0}, line[10001] = {0};
		
		scanf ("%d", &step);

		fgets (input, 10000, stdin);

		for (int i = 0; i < strlen(input); ++i)
		{
			if (input[i] == '\n') input[i] = '\0';
		}

		const char s[2] = " ";
		char *token;

		token = strtok(input, s);
		while( token != NULL ) {
			strcat (line, token);
			token = strtok(NULL, s);
		}
		strcpy (output, line);

		for (int i = 0; i < strlen(line); ++i)
		{
			output[i] = ' ';
		}
		int current = 0;
		for (int i = 0; i < strlen(line); ++i)
		{	
			if (d < strlen(line)) {
				output[d] = toupper(line[i]);
				d += step;
			}else {
				i--;
				current++;
				d = current;
			}

		}
		cout << output << endl;

	}while (step != 0);
	

	return 0;
}