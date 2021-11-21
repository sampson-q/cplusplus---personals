// Author: Hash

#include <iostream>
using namespace std;

int main() {
	string Player = "";
	int Num;
	int PlayerSwitch = 0;
	
	while (true) {
		cout << "Enter Num: ";
		cin >> Num;
		PlayerSwitch += 1;
		
		if (PlayerSwitch % 2 == 0) {
			Player = "X";
		} else {
			Player = "O";
		}
		
		cout << "\nIt's Player " << Player << "'s turn.\n\n";
	}
}