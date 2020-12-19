#include <iostream>
#include <cstring>
using namespace std;
#define Max 1000000
void input(char s[]) {
	do{
		cin.getline(s, Max);
	} while (strlen(s) == 0);
}
int count(char s[]) {
	int count = 1;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			count += 1;
		}
	}
	return count;
}
void output(int r) {
	cout << r << endl;
}
int main() {
	char s[Max];
	input(s);
	int r = count(s);
	output(r);
}