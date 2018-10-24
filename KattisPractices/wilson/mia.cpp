#include <iostream>
#include <string>
using namespace std;


int winner (char s0, char s1, char r0, char r1);
int converter (char a, char b) ;



int main(int argc, char const *argv[])
{
	char s0, s1, r0, r1;
	int win;
	do {
		cin >> s0;
		cin >> s1;
		cin >> r0;
		cin >> r1;

		win = winner(s0, s1, r0, r1);

		if (win > 0) {
			cout << "Player " << win << " wins." << endl;
		}else if (win == -1) {
			cout << "Tie." << endl;
		}
	}while (win != 0);
	

	return 0;
}

int winner (char s0, char s1, char r0, char r1) {
	// Check for 21 or 12 first 
	int playerA_int, playerB_int;
	
	playerA_int = converter(s0, s1);
	playerB_int = converter(r0, r1);

	if (playerA_int == playerB_int) {
		if (playerA_int == 0) return 0;
		return -1; // Draw
	}

	if (playerA_int == 21) return 1;
	if (playerB_int == 21) return 2;

	if (s0 == s1 && r0 == r1) {
		// When both are doubles 
		if (playerA_int > playerB_int) return 1;
		if (playerB_int > playerA_int) return 2;
	}

	if (s0 == s1) {
		return 1; // Double
	}

	if (r0 == r1) {
		return 2; // Double
	}

	if (playerA_int > playerB_int) return 1;
	if (playerB_int > playerA_int) return 2;

	return 0;
}

int converter (char a, char b) {
	string result;
	if (a > b) {
		result += a;
		result += b;
	}
	if (b > a) {
		result += b;
		result += a;

	}
	if (b == a) {
		result += a;
		result += b;
	}

	return stoi (result);
}