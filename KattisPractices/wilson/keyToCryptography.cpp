#include <iostream>
#include <cstring>

#define MAX 500

using namespace std;

char converter (char a, char b);
void decrypt (char input[], char output[], char secret[]);



int main(int argc, char const *argv[])
{
	char input[MAX], output[MAX], secret[MAX];

	cin >> input;
	cin >> secret;

	decrypt (input, output, secret); 
	cout << output << endl;


	return 0;
}

char converter (char a, char b) {
	char convert;
	if (a - b < 0) {
		convert = a - b + ('Z' - 'A' + 1);
	}else {
		convert = a - b;
	}
	char out = (convert+ 'A');
	return out;
}
	

void decrypt (char input[], char output[], char secret[]) {
	int i, secret_length = strlen(secret);
	for (i = 0; input[i] != '\0'; i++) {
		if (secret[i] == '\0') {
			// Get next set of characters
			secret[i] = output[i-secret_length];
			secret[i+1] = '\0';
		}
		output[i] = converter(input[i], secret[i]);
	}
} 