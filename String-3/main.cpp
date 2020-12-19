#include <iostream>
#include <string>
using namespace std;
#define Max 101

void inputString(char s[], char us[], char host[], char re[]) {
	int k(0), h(0), j(0);
	do {
		cin.getline(s, Max);
	} while (strlen(s) < 1 || strlen(s) > 100);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == '@' || (s[i] == '@' && i == 0)) break;
		else us[k++] = s[i];
	}
	us[k] = '\0';
	for (int i = strlen(us) + 1; i < strlen(s); i++) {
		if (s[i] == '/') break;
		else host[h++] = s[i];
	}
	host[h] = '\0';
	for (int i = strlen(us) + strlen(host) + 1; i < strlen(s); i++) {
		re[j++] = s[i];
	}
	re[j] = '\0';
}
void output(bool flag1, bool flag2, bool flag3) {
	if(flag1 && flag2 && flag3)
		cout << "YES" << endl;
}
void output1() {
	cout << "NO" << endl;
}


bool checkUser(char us[]) {
	if (strlen(us) < 1 || strlen(us) > 16) {
		output1();
		exit(0);
	}
	else {
		for (int i = 0; i < strlen(us); i++) {
			if ((us[i] >= 65 && us[i] <= 90) || (us[i] >= 97 && us[i] <= 122) || us[i] == 95 || (us[i] >= 48 && us[i] <= 57))
				continue;
			else {
				output1();
				exit(0);
			}
		}
		return true;
	}
}

bool checkHostName(char h[]) {
	if (strlen(h) < 1 || strlen(h) > 32) {
		output1();
		exit(0);
	}
	else {
		for (int i = 0; i < strlen(h); i++) {
			if ((h[i] >= 65 && h[i] <= 90) || (h[i] >= 97 && h[i] <= 122) ||
 h[i] == 95 ||
				(h[i] == 46 && h[i + 1] != '\0'&& h[i + 1] != 46 && i != 0) ||
				(h[i] >= 48 && h[i] <= 57))
				continue;
			else {
				output1();
				exit(0);
			}
		}
		return true;
	}
}
bool checkResourse(char re[]) {
	if (strlen(re) < 0 || strlen(re) > 17 ||(re[0] == '/' && strlen(re) == 1)) {
		output1();
		exit(0);
	}
	else if (strlen(re) == 0) return true;
	else {
		for (int i = 0; i < strlen(re); i++) {
			if ((re[i] >= 65 && re[i] <= 90) || (re[i] >= 97 && re[i] <= 122) || re[i] == '_'  || (re[i] >= 46 && re[i] <= 57))
				continue;
			else {
				output1();
				exit(0);
			}
		}
		return true;
	}
}

int main() {
	char s[Max], us[Max], host[Max], re[Max];
	inputString(s, us, host, re);
	bool flag1 = checkUser(us);
	bool flag2 = checkHostName(host);
	bool flag3 = checkResourse(re);
	output(flag1, flag2, flag3);
}