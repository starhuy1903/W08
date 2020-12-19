#include <iostream>
#include <string>
using namespace std;
#define Max 101 
void erase(char s[], int vt) {
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++) {
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}
void trimMidCharacter(char s[]) {
	for (int i = 0; i <= strlen(s) - 1; i++) {
		if (s[i] == '/' && s[i + 1] == '/') {
			erase(s, i);
			i--;
		}
		else if (s[i] == '/' && s[i + 1] == '\0' && i > 0) {
			erase(s, i);
			i--;
		}
	}
}
void inputString(char s[]) {
	do {
		cin.getline(s, Max);
	} while (strlen(s) == 0);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 32;
		}
	}
}

void outputString(char s[]) {
	cout << s << endl;
}
int main() {
	char s[Max];
	inputString(s);
	trimMidCharacter(s);
	outputString(s);
}