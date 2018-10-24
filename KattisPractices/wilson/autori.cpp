#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{

	// Str tok in c++ using string type 
	std::string s;
	std::string delimiter = "-";

	cin >> s;


	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		std::cout << token.at(0);
		s.erase(0, pos + delimiter.length());
	}
	std::cout << s.at(0);

	cout << endl;

	return 0;
}