// Author: Hash

#include <iostream>
using namespace std;

int main() {
	
	for (int i = 0; i < 9; i++) {
		
		if (i % 3 == 0) {
			cout << "-------------------------" << endl;
		}
		
		cout << "|       |       |       |" << endl;
	}
	
	cout << "-------------------------" << endl;
}