#include <iostream>
#include <cstring>
using namespace std;
int main() {

	char s[101];
	int numMessageCharacters = 0;
	int numAvailable(0);
	for (int i = 0; i < 100; i++) {
		cin.getline(s, 101);
		if (strlen(s) == 0) break;
		if (s[0] == '+') {
			numAvailable += 1;
		}
		else if (s[0] == '-')
			numAvailable -= 1;
		else {
				int messageLength = 0;
				for (int j = 0; j < strlen(s); j++) {
					if (s[j] == ':') {
						messageLength = strlen(s) - j - 1;
						break;
					}
				}
				numMessageCharacters += messageLength * numAvailable;
			}
		
		}
	cout << numMessageCharacters;
	return 0;
}
	
