#include <iostream>
#include <array>
#include <string>

using namespace std;

//global variables
int nrMoves = 0;
const int nrRows = 3;
const int nrColumns = 3;
char myArray[nrRows][nrColumns] = {'\0'};

//method prototypes
void player1Move();
void player2Move();
bool checkTie(char arr[3][3]);
bool checkWin(char arr[3][3]);

int main()
{
	for (int i = 0; i < nrColumns; i++)
	{
		for (int j = 0; j < nrRows; j++)
		{
			myArray[i][j] = ' ';
		}
	}
	player1Move();
}

//prints out the entire board game
void printBoard(char arr[3][3])
{
	/*cout << "    1\t    2\t    3" << endl;
	cout << "1   " << arr[0][0] << "   |   " << arr[0][1] << "   |   " << arr[0][2] << endl;
	cout << "----------------------" << endl;
	cout << "2   " << arr[1][0] << "   |   " << arr[1][1] << "   |   " << arr[1][2] << endl;
	cout << "----------------------" << endl;
	cout << "3   " << arr[2][0] << "   |   " << arr[2][1] << "   |   " << arr[2][2] << endl;*/

	//game board as required in the assignment description

	cout << "  1   2   3" << endl;
	//cout << endl;
	cout << "1 " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;  
	//cout << endl;
	cout << " ---+---+--- " << endl;
	//cout << endl;
	cout << "2 " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl; 
	//cout << endl;
	cout << " ---+---+--- " << endl;
	//cout << endl;
	cout << "3 " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl; 
}

//function to select the row number
int rowSelect()
{
	int row;

	cout << endl << "Eenter the row number between 1 and 3: ";
	cin >> row;

	while (row < 1 || row > nrRows)
	{
		cout << endl;
		cout << "Invalid row number. Please enter the row number again: ";
		cin >> row;
	}

	return row;
}

//function to select column number
int columnSelect()
{
	int column;
	cout << "Enter the column number between 1 and 3: ";
	cin >> column;

	while (column < 1 || column > nrColumns)
	{
		cout << endl; 
		cout << "Invalid column number. Please enter the column number again: ";
		cin >> column;
	}
	
	return column;
}

//function to check if a player's making a valid move or not
bool validMove(char arr[3][3], int row, int column)
{
	if (arr[row-1][column-1] == ' ')
		return true;

	else 
		return false;
		//cout << "This is not a valid move" << endl; 
}

bool checkTie(char arr[3][3])
{
	bool checkTie = false;

	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i-1][j-1] == 'X' || arr[i-1][j-1] == 'Y')
				{
					checkTie = true;
					continue;
				}

				else
				{
					checkTie = false;
					break;
				}
			}
		}
	return checkTie;
}
//checks for the winning combination if available
bool checkWin(char board[3][3])
{
	//bool ignore = false; //boolean to keep the function iterating
	bool win = false; //boolean to continue the game in case there's no winner yet

	for(int x = 0; x<3; x++)             //Horizontal 
	{
		if (board[x][0] == board[x][1] && board[x][0] == board[x][2])
		{
			if (board[x][0] == 'X')
			{
				cout << endl << "Congratulations Player 1, You've won!" << endl;
				cout << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
						continue;
					else 
						exit(1); 
				}

				//win = true;
				//ignore = true; 
				//int board[nrRows][nrColumns] = {0,}; //Clear the board so can start a new game. Assignment Part 2
				return 0;
			}

			else if (board[x][0] == 'O')
			{
				cout << endl << "Congratulations Player 2, You've won!" << endl;
				cout << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
						continue;
					else 
						exit(1); 
				}

				/*win = true;
				ignore = true;
				int board[nrRows][nrColumns] = {0,};*/
				return 0; 
			}
		}
	}

	for(int y = 0; y<3; y++)				//Vertical 
	{                                        
		if (board[0][y] == board[1][y] && board[0][y] == board[2][y])
		{
			if (board[0][y] == 'X')
			{
				cout << endl << "Congratulations Player 1, You've won!" << endl;
				cout << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
						continue;
					else 
						exit(1); 
				}
			
				/*exit(1);
				win = true;
				ignore = true;
				int board[nrRows][nrColumns] = {0,};*/
				return 0;
			}

			else if (board[0][y] == 'O')
			{
				cout << endl << "Congratulations Player 2, You've won!" << endl;
				cout << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
						continue;
					else 
						exit(1); 
				}

				/*win = true;
				ignore = true;
				int board[nrRows][nrColumns] = {0,};*/
				return 0; 
			}
		}
	}

	if(board[0][0] == board[1][1] && board[0][0] == board[2][2])   //Horizontal
	{
		if (board[0][0] == 'X')
		{
			cout << endl << "Congratulations Player 1, You've won!" << endl;
			cout << "Press 1 to exit" << endl;

			while(1)
			{
				int i;
				cin >> i;
				
				if(i != 1)
					continue;
				else 
					exit(1); 
			}

			/*win = true;
			ignore = true;
			int board[nrRows][nrColumns] = {0,};*/
			return 0;
		}

		else if (board[0][0] == 'O')
		{
			cout << endl << "Congratulations Player 2, You've won!" << endl;
			cout << "Press 1 to exit" << endl;

			while(1)
			{
				int i;
				cin >> i;
				
				if(i != 1)
					continue;
				else 
					exit(1); 
			}
			
			/*win = true;
			ignore = true;
			int board[nrRows][nrColumns] = {0,};*/
			return 0; 
		}
	}

	if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
	{
		if (board[0][2] == 'X') 
		{
			cout << endl << "Congratulations Player 1, You've won!" << endl;
			cout << "Press 1 to exit" << endl;

			while(1)
			{
				int i;
				cin >> i;
				
				if(i != 1)
					continue;
				else 
					exit(1); 
			}

			/*win = true;
			ignore = true;
			int board[nrRows][nrColumns] = {0,};*/
			return 0;
		}

		else if (board[0][2] == 'O') 
		{
			cout << endl << "Congratulations Player 2, You've won!" << endl;
			cout << "Press 1 to exit" << endl;

			while(1)
			{
				int i;
				cin >> i;
				
				if(i != 1)
					continue;
				else 
					exit(1); 
			}
			
			/*win = true;
			ignore = true;
			int board[nrRows][nrColumns] = {0,};*/
			return 0;
		}
	}
	win = false;   
	return win;
}

//function that directs player 1's moves. 
void player1Move()
{
	int row, column;
	bool check1, check2;

	if (nrMoves == 9)
	{
		cout << endl << "TIE GAME!!" << endl;
		cout << "Press 1 to exit" << endl;

		while(1)
		{
			int i;
			cin >> i;
				
			if(i != 1)
				continue;
			else 
				exit(1); 
		}
	}

	/*bool check3 = checkTie(myArray);
	if (check3)
	{
		cout << "TIE GAME!!" << endl;
		exit(1);
	}*/
	
	cout << endl << "PLAYER 1: Time for you to make a move. The current status of the board is: " << endl << endl;
	
	printBoard(myArray);
	row = rowSelect();
	column = columnSelect();
	check1 = validMove(myArray, row, column);

	while(check1 == 0)
	{
		cout << endl << "This is an INVALID MOVE Player 1!" << endl << endl << "Make your move based on the current status of the game:" << endl << endl;

		printBoard(myArray);
		cout << endl << "PLAYER 1: " << endl;
		row = rowSelect();
		column = columnSelect();
		check1 = validMove(myArray, row, column);
	}

	myArray[row-1][column-1] = 'X';
	nrMoves++;

	cout << endl << "So here's the status of the current game after your move Player 1:" << endl << endl;

	printBoard(myArray);
	check2 = checkWin(myArray);

	if (check2)
	{
		cout << "Player1,  you've won!!" << endl;
		exit(1);
	}

	else 
		player2Move();
}

//function that directs player 2's moves
void player2Move()
{
	int row, column; 
	bool check1, check2;

	/*bool check3 = checkTie(myArray);
	if (check3)
	{
		cout << "TIE GAME!!" << endl;
		exit(1);
	}*/

	if (nrMoves == 9)
	{
		cout << endl << "TIE GAME!!" << endl;
		cout << "Press 1 to exit" << endl;

		while(1)
		{
			int i;
			cin >> i;
				
			if(i != 1)
				continue;
			else 
				exit(1); 
		}
	}

	cout << endl << "PLAYER 2: Time for you to make a move. The current status of the board is: " << endl << endl;
	
	printBoard(myArray);
	row = rowSelect();
	column = columnSelect();
	check1 = validMove(myArray, row, column);

	while(check1 == 0)
	{
		cout << endl << "This is an INVALID MOVE Player 2!" << endl << endl << "Make your move based on the current status of the game:" << endl << endl;

		printBoard(myArray);
		cout << endl << "PLAYER 2: " << endl;
		row = rowSelect();
		column = columnSelect();
		check1 = validMove(myArray, row, column);
	}

	myArray[row-1][column-1] = 'O';
	nrMoves++;

	cout << endl << "So here's the status of the current game after your move Player 2:" << endl << endl;
	printBoard(myArray);
	check2 = checkWin(myArray);
	//check3 = checkTie(myArray);

	if (check2)
	{
		cout << "Player2 you have won!" << endl;
		exit(1);
	}

	else 
		player1Move();
}