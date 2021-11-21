// Author: Hash

#include <iostream>
using namespace std;

void DrawRow(string, string, string);

int main() {
	string A1 = "0";
	string B1 = "1";
	string C1 = "2";
	DrawRow(A1, B1, C1);
}

void DrawRow(string A1, string B1, string C1) {
	cout << "-------------------------" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   "<< A1 <<"   |   "<< B1 <<"   |   "<< C1 <<"   |" << endl;
	cout << "|       |       |       |" << endl;
	cout << "-------------------------" << endl;
}