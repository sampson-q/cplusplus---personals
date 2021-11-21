// Author: Hash

#include <iostream>
using namespace std;

void DrawDash(string, string, string, string, string, string, string, string, string);
bool CheckWin(string, string, string, string, string, string, string, string, string, string);

int main() {
	string Player0 = ""; string Player1 = ""; string ActivePlayer = "X"; string AnyKey; string PlayerError;
	int Player, BoardSection;
	int PlayerSwitch = 1; int PlayCount = 0;
	
	string A1 = " "; string B1 = " "; string C1 = " ";
	string A2 = " "; string B2 = " "; string C2 = " ";
	string A3 = " "; string B3 = " "; string C3 = " ";
	
	cout << "[1] Player X\n[2] Player O\nSelect Player: ";
	cin >> Player;
	
	if (Player == 1) {
		Player0 = "X";
		Player1 = "O";
		ActivePlayer = Player0;
	} else if (Player == 2) {
		Player0 = "X";
		Player1 = "O";
		PlayerSwitch += 1;
		ActivePlayer = Player1;
	} else {
		cout << "You made a wrong choice!" << endl;
	}
	
	while (true) {
		system("cls");
		DrawDash(A1, B1, C1, A2, B2, C2, A3, B3, C3);
		
		cout << "\nPlayer ("<< ActivePlayer <<"): ";
		cin >> BoardSection;
		
		if (BoardSection == 1) {
			if (A1 == " ") { A1 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 2) {
			if (B1 == " ") { B1 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 3) {
			if (C1 == " ") { C1 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 4) {
			if (A2 == " ") { A2 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 5) {
			if (B2 == " ") { B2 = ActivePlayer; }
				else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 6) {
			if (C2 == " ") { C2 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 7) {
			if (A3 == " ") { A3 = ActivePlayer;	}
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 8) {
			if (B3 == " ") { B3 = ActivePlayer; }
				else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else if (BoardSection == 9) {
			if (C3 == " ") { C3 = ActivePlayer; }
			else {
				cout << "\n\nSection Occupied! Enter any number: ";
				cin >> AnyKey;
				PlayerSwitch += 1;
				PlayCount--;
			}
		} else { cout << "\nYou made a wrong choice! Press Ctrl + C to exit"; }
		
		PlayerSwitch += 1;
		
		if (PlayerSwitch % 2 == 0) { ActivePlayer = "O"; }
		else { ActivePlayer = "X"; }
		
		PlayCount += 1;
		
		if (CheckWin(Player0, A1, B1, C1, A2, B2, C2, A3, B3, C3)) {
			system("cls");
			DrawDash(A1, B1, C1, A2, B2, C2, A3, B3, C3);
			cout << "\n\nPlayer " << Player0 << " WINS!";
			break;
		} else if (CheckWin(Player1, A1, B1, C1, A2, B2, C2, A3, B3, C3)) {
			system("cls");
			DrawDash(A1, B1, C1, A2, B2, C2, A3, B3, C3);
			cout << "\n\nPlayer " << Player1 << " WINS!";
			break;
		} else if (!CheckWin(Player1, A1, B1, C1, A2, B2, C2, A3, B3, C3) && !CheckWin(Player0, A1, B1, C1, A2, B2, C2, A3, B3, C3) && PlayCount == 9) {
			system("cls");
			DrawDash(A1, B1, C1, A2, B2, C2, A3, B3, C3);
			cout << "\n\nIT'S A TILE!!!";
			break;
		}
	}
}

void DrawDash(string A1, string B1, string C1, string A2, string B2, string C2, string A3, string B3, string C3) {
	cout << "-------------------------" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   "<< A1 <<"   |   "<< B1 <<"   |   "<< C1 <<"   |" << endl;
	cout << "|       |       |       |" << endl;
	
	cout << "-------------------------" << endl;
	cout << "|       |       |       |" << endl;
	cout << "|   "<< A2 <<"   |   "<< B2 <<"   |   "<< C2 <<"   |" << endl;
	cout << "|       |       |       |" << endl;
	cout << "-------------------------" << endl;
	
	cout << "|       |       |       |" << endl;
	cout << "|   "<< A3 <<"   |   "<< B3 <<"   |   "<< C3 <<"   |" << endl;
	cout << "|       |       |       |" << endl;
	cout << "-------------------------" << endl;
}

bool CheckWin(string Player, string A1, string B1, string C1, string A2, string B2, string C2, string A3, string B3, string C3) {
	if (
		(A1 == Player && B1 == Player && C1 == Player) || (A1 == Player && A2 == Player && A3 == Player) ||
		(A2 == Player && B2 == Player && C2 == Player) || (B1 == Player && B2 == Player && B3 == Player) ||
		(A3 == Player && B3 == Player && C3 == Player) || (C1 == Player && C2 == Player && C3 == Player) ||
		(A1 == Player && B2 == Player && C3 == Player) || (A3 == Player && B2 == Player && C1 == Player)
	) { return true; }
	
	return false;
}