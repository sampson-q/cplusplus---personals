// Author: Hash

#include <iostream>
#include <Windows.h>
using namespace std;

void DrawDash(), FlagError(string), RefreshBoard(); // display game's board, diplay error, clear screen and display board with new values
bool CheckWin(string); // check for winner

// player0 && player1 => the two players of the game, activeplayer => determines which player's turn to make a move
string Player0 = ""; string Player1 = ""; string ActivePlayer = "X";

// player helps players to choose who makes the first move, boardsection represents the divisions of the game board
// xcoord && ycoord helps the program to position both players' moves
int Player, BoardSection, xcoord, ycoord;

// playerswitch helps players to take turns to make their moves, playcount helps to determing the number of moves both players make in the game
int PlayerSwitch = 1; int PlayCount = 0;

// dash array helps us to keep the moves of both players
string dash[3][3];

// program starts here
int main() {
	
	// setting all values in the dash array to empty space... this helps to tell the players that a particular section of the game's board is empty or available for input
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dash[i][j] = " ";
		}
	}
	
	// let players accept their ids i.e X or O
	cout << "[1] Player X\n[2] Player O\nSelect Player: ";
	cin >> Player;
	
	// first player to choose makes the first move. the program assigns the first choice's id to the active player
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
	
	// starting the main part of the program in a loop
	while (true) {
		RefreshBoard(); // helps to refresh the board
		
		/*
		
		time for active player to make a move
		Player makes his moves by selecting the number which represents his choice of section on the board. this is how the board looks like
		
					+-------+-------+-------+
					|		|		|		|
					|	1   |	2   |	3   |
					|		|		|		|
					+-------+-------+-------+
					|		|		|		|
					|	4   |	5   |	6   |
					|		|		|		|
					+-------+-------+-------+
					|		|		|		|
					|	7   |	8   |	9   |
					|		|		|		|
					+-------+-------+-------+
		
		*/
		// tell the players who's turn it is to make a move
		cout << "\nPlayer ("<< ActivePlayer <<"): ";
		cin >> BoardSection;
		
		if (BoardSection > 0 && BoardSection <= 3) xcoord = 0; // if the player's move ranges from 1 to 3, the input will belong to any of the sections on the first row
		else if (BoardSection <= 6) xcoord = 1; // if move ranges from 4 to 6, the input will belong to any of the sections on the second row
		else if (BoardSection <= 9) xcoord = 2; // if move ranges from 7 to 9, the input will belong to any of the sections on the third row
		else FlagError("Invalid Entry"); // else, flag and "Invalid Entry" error
		
		// this condition helps us to pinpoint the exact section the player chose
		if (BoardSection % 3 == 0) ycoord = 2; // that, if the board section mod 3 == 0, the last section on the selected row contains the player's choice
		else ycoord = ((BoardSection % 3) - 1); // else, the << decrement of the boardsection mod 3 >> section on the selected row contains the player's choice
		
		// this condition will help us flag a "Section Occupied" error if the player tries making a move which has already been made
		if (dash[xcoord][ycoord] == " ") dash[xcoord][ycoord] = ActivePlayer;
		else FlagError("Section Occupied");
		
		// increment of playerswitch... this helps to make the next player take his turn
		PlayerSwitch += 1;
		
		// as player switch increases, one of the states we can derive from it is whether it's even or odd
		if (PlayerSwitch % 2 == 0) ActivePlayer = "O"; // so if the player switch lands on an even number, the active player should be O
		else ActivePlayer = "X"; // else, it should be X
		
		// play count increases... play count actually helps us to keep track of the number of times both players took turns... it plays an important role in determining if the
		// games ends as a tile
		PlayCount += 1;
		
		if (CheckWin(Player0)) { // if 'true' in terms of Player0 winning:
			system("cls");
			
			cout << "\t\t+-------+-------+-------+\n\t\t";
			cout << "|	|	|	|\n\t\t";
			cout << "|   "<< dash[0][0] <<"   |   "<< dash[0][1] <<"   |   "<< dash[0][2] <<"   |\n\t\t";
			cout << "|	|	|	|\n";
			cout << "\t\t+-------+-------+-------+\n";
			
			cout << "\t___  ___   ___  __  ___   ____     __   __\n\t\\  \\/  /   \\  \\/  \\/  /  / __ \\   |  |\\|  |\n";
			cout << "\t \\    /     \\        /  ( /  \\ )  |       |\n\t /    \\	     \\  /\\  /   ( \\__/ )  |  |\\   |\n\t/__/\\__\\      \\/  \\/     \\____/   |__| \\__|\n\n";
			
			cout << "\t\t+-------+-------+-------+\n\t\t";
			cout << "|	|	|	|\n\t\t";
			cout << "|   "<< dash[2][0] <<"   |   "<< dash[2][1] <<"   |   "<< dash[2][2] <<"   |\n\t\t";
			cout << "|	|	|	|\n";
			cout << "\t\t+-------+-------+-------+\n\n";
			
			break; // stop the game
			
		} else if (CheckWin(Player1)) { // if 'true' in terms of player1 winning:
			system("cls");
			
			cout << "\t\t+-------+-------+-------+\n\t\t";
			cout << "|	|	|	|\n\t\t";
			cout << "|   "<< dash[0][0] <<"   |   "<< dash[0][1] <<"   |   "<< dash[0][2] <<"   |\n\t\t";
			cout << "|	|	|	|\n";
			cout << "\t\t+-------+-------+-------+\n";
			
			cout << "\t  ____     ___  __  ___   ____     __   __\n\t / __ \\    \\  \\/  \\/  /  / __ \\   |  |\\|  |\n\t( /  \\ )    \\        /  ( /  \\ )  |       |\n";
			cout << "\t( \\__/ )     \\  /\\  /   ( \\__/ )  |  |\\   |\n\t \\____/       \\/  \\/     \\____/   |__| \\__|\n\n";
			
			cout << "\t\t+-------+-------+-------+\n\t\t";
			cout << "|	|	|	|\n\t\t";
			cout << "|   "<< dash[2][0] <<"   |   "<< dash[2][1] <<"   |   "<< dash[2][2] <<"   |\n\t\t";
			cout << "|	|	|	|\n";
			cout << "\t\t+-------+-------+-------+\n\n";
			
			break; // end the game
			
		} else if (!CheckWin(Player1) && !CheckWin(Player0) && PlayCount == 9) { // if none of the players win and the play count gets to 9
			RefreshBoard(); // refreshboard
			cout << "\t\t No Winner. It's a Tile!\n"; // tell them it's a tile
			break; // end the program
		}
	}
	
	return 0;
}

// this method helps to flag errors... Takes the error message as a parameter and displays it
void FlagError(string ErrorMessage) {
	cout << "\n"<< ErrorMessage <<"";
	sleep(1); // this pauses the program for 1 second
	PlayerSwitch++; // then it increases the player switch so the the player making the error get's the chance to make his move again
	PlayCount--; // since it's an error, the play count is not considered... therefore, it get's decreased by 1
}

// refresh board clears the screen and draw the dashboard again
void RefreshBoard() {
	system("cls");
	DrawDash();
}

void DrawDash() {
	cout << "\t\t+-------+-------+-------+\n\t\t|       |       |       |" << endl;
	
	for (int i = 0; i < 3; ++i) {
		cout << "\t";
		for (int j = 0; j < 3; j++) cout << "\t|   " << dash[i][j] << " ";
		cout << "  |\n\t\t|       |       |       |\n\t\t+-------+-------+-------+" << endl;
		if (i == 2) break;
		else cout << "\t\t|       |       |       |" << endl;
	}
}

// this method checks up the all the sections for the consistent appearing of any player in a row, column or diagonally
bool CheckWin(string Player) {
	if (
		(dash[0][0] == Player && dash[0][1] == Player && dash[0][2] == Player) || (dash[0][0] == Player && dash[1][0] == Player && dash[2][0] == Player) ||
		(dash[1][0] == Player && dash[1][1] == Player && dash[1][2] == Player) || (dash[0][1] == Player && dash[1][1] == Player && dash[2][1] == Player) ||
		(dash[2][0] == Player && dash[2][1] == Player && dash[2][2] == Player) || (dash[0][2] == Player && dash[1][2] == Player && dash[2][2] == Player) ||
		(dash[0][0] == Player && dash[1][1] == Player && dash[2][2] == Player) || (dash[2][0] == Player && dash[1][1] == Player && dash[0][2] == Player)
	) { return true; }
	
	return false;
}