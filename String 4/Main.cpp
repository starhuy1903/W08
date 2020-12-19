#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#define Max 101
void input(char s[]) {
	do {
		cin.getline(s, Max);
	} while (strlen(s) == 0);
}
	
void erase(char s[], int vt) {
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++) {
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}

bool exist(char c, char letter[], int appear[], int counter) {
	for (int i = 0; i < counter; i++) {
		if (c == letter[i]) return true;
	}
	return false;
}

void check(char s[], char letter[], int appear[], int& counter) {
	char c;
	int k = 0;
	for (int i = 1; i < strlen(s); i++) {
		c = s[i - 1];
		if (c < 97 || c > 122) continue;
		if (c == s[i]) {
			for (k = 0; k < 2; k++) {		
					erase(s, i - 1);
			}
			i -= 2;
		}
	}
}

void output(char s[]) {
	if (strlen(s) != 0) {
		cout << s << endl;
	}
	else cout << "Empty String" << endl;
	
}
int main() {
	char s[Max], letter[27];
	int appear[27];
	int counter = 0;
	input(s);
	check(s, letter, appear, counter);
	output(s);
}