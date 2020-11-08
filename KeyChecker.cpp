
#include <iostream>
#include <Windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void PrintStatus(short keys[]) {
	string names[] = { "Caps: ", "Scroll: ", "Num: " };
	for (short i = 0; i < (sizeof(keys) -1); i++) {
		if (keys[i] == 1) {
			SetConsoleTextAttribute(hConsole, 10);
			cout << names[i] << "ON" << endl;			
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 4);
			cout << names[i] << "OFF" << endl;			
		}
		//std::cout << keys[i] << std::endl;
	}
}

int main()
{			
	while (true) {		
		short key_array[] = { GetKeyState(VK_CAPITAL), GetKeyState(VK_SCROLL), GetKeyState(VK_NUMLOCK) };
		Sleep(200);
		system("cls");						
		PrintStatus(key_array);		
	}    
}


