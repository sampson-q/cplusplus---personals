// Author: Hash

#include <iostream>
using namespace std;

int main() {
	int swit = 1;
	int number = 0;
	cout << "Press Ctrl + C => to Exit\n\n";
	
	while (true) {
		cout << "Enter Number: ";
		
		cin >> number;
		swit += 1;
		
		cout << "\nThis is swit " << swit;
		if (swit == 2) {
			// print: second player's turn
			swit--;
		}
		
		cout << "\nThis is swit " << swit << endl;
	}
}