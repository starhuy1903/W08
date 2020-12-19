#include "InputOutput.h"
#include "Date.h"
#include "Menu.h"
#include "Process.h"
int main() {
	int choise;
	do {
		menu();
		cin >> choise; cout << "\n";
		system("cls");
		switch (choise)
		{
		case 1: mainCompare(); break;

		case 2: mainTomorrow(); break;

		case 3: mainYesterday(); break;

		case 4: mainIncreaseDay(); break;

		case 5: main5(); break;

		case 6: main6(); break;

		case 7: main7(); break;

		case 8: main8(); break;

		case 0: exit(0);
		}
		do cout << "-Nhan Enter de tro ve Menu-";
		while (cin.get() != '\n');
		cin.get();
		system("cls");
	} while (choise != 0);
	return 0;
}