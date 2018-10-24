#include <iostream>
#include <ctype.h>
#include <cstring>

using namespace std;


int checkEligibility (string name, char date1[], char date2[], int courses) {
	const char s[2] = "/";
	char *token;
	char *token2;
	token = strtok(date1, s);
	token2 = strtok(date2, s);

	if (atoi(token) >= 2010) return 1;
	if (atoi(token2) >= 1991) return 1;
	if (courses < 41) return 2;
	return 0;

}



int main(int argc, char const *argv[])
{
	int numCases;
	cin >> numCases;
	for (int i = 0; i < numCases; i++) {
		string name;
		char date1[20];
		char date2[20];
		int courses;
		cin >> name >> date1 >> date2 >> courses;
		cout << name << " ";
		int eligibility = checkEligibility (name, date1, date2, courses);
		switch (eligibility) {
			case 1:
			cout << "eligible" << endl;
			break;
			case 2:
			cout << "coach petitions" << endl;
			break;
			default:
			cout << "ineligible" << endl;
		}
		
	}




	return 0;
}
