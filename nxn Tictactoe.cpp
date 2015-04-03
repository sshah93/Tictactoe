#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

//function prototypes
int newGame();
bool validWinSeq(int, int);
void printBoard(vector<vector<char> > arr, int nrRows, int nrColumns);
int rowSelect();
int columnSelect();
bool validMove(int row, int column);
void playerMove(int start);
int loadGame();
void saveGame(int, int);
void checkWin(int winSeq, int player, char character);

//Global Variables
int nrPlayers;
int nrRows;
int winSeq;
vector<vector <char> > myArray;
vector<char> symbols; 
vector<char> players;

bool validMove(int row, int column)
{
	if (myArray[row-1][column-1] == ' ')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void playerMove(int moves)
{
	int nrMoves = moves;
	int playerMove = nrMoves % nrPlayers;
	
	vector<char> my_players(nrPlayers);

	for(int i = 0; i < nrPlayers; i++)
	{
		my_players[i] = symbols[i];
	}

	if(nrMoves == (nrRows*nrRows))
	{
		cout << endl << endl << "TIE GAME!" << endl;
		cout << endl << "Press 1 to exit" << endl;

		while(1)
		{
			int i;
			cin >> i;
				
			if(i != 1)
			{
				continue;
			}
			else 
			{
				exit(1); 
			}
		}
	}

	for(int i = playerMove; i < nrPlayers; i++)
	{
		cout << endl << "Player " << i+1 << " time for you to make a move." << endl;

		cout << endl;
		cout << "Press 1 to save the game and exit." << endl;
		cout << "Press 2 to make your move." << endl;

		int temp1;
		cin >> temp1;

		while(!cin.good() || temp1 < 1 || temp1 > 2)
		{
			cout << endl << "Press 1 to save the game and exit." << endl;
			cout << "Press 2 to make your move." << endl;
			cin.clear();
			cin.sync();
			cin >> temp1;
		}

		if(temp1 == 1)
		{
			saveGame(nrMoves, winSeq);
			exit(1);
		}

		int row,column;
		row = rowSelect();
		column = columnSelect();
		bool check1;
		check1 = validMove(row, column);

		while(!check1)
		{
			cout << endl << "This is an INVALID MOVE Player " << i+1 << " !" << endl << endl << "Make your move based on the current status of the game:" << endl << endl;

			printBoard(myArray, nrRows, nrRows);
			cout << endl << "PLAYER " << i+1 << " : " << endl;
			row = rowSelect();
			column = columnSelect();
			check1 = validMove(row, column);
		}

		myArray[row-1][column-1] = symbols[i];
		nrMoves++;

		printBoard(myArray,nrRows, nrRows);
		
		checkWin(winSeq, i+1, symbols[i]);

		if(nrMoves == (nrRows*nrRows))
		{
			cout << endl << endl << "TIE GAME!" << endl;
			cout << endl << "Press 1 to exit" << endl;

			while(1)
			{
				int i;
				cin >> i;
				
				if(i != 1)
				{
					continue;
				}
				else 
				{
					exit(1); 
				}
			}
		}

		if(playerMove == nrPlayers)
		{
			playerMove = 0;
		}
		else
		{
			playerMove++;
		}
		if(i == nrPlayers-1)
		{
			i = -1;
		}
	}
}

int main()
{
	symbols.push_back('X');
	symbols.push_back('O');
	symbols.push_back('A');
	symbols.push_back('B');
	symbols.push_back('C');
	symbols.push_back('D');
	symbols.push_back('E');
	symbols.push_back('F');
	symbols.push_back('G');
	symbols.push_back('H');
	symbols.push_back('I');
	symbols.push_back('J');
	symbols.push_back('K');
	symbols.push_back('L');
	symbols.push_back('M');
	symbols.push_back('N');
	symbols.push_back('P');
	symbols.push_back('Q');
	symbols.push_back('R');
	symbols.push_back('S');
	symbols.push_back('T');
	symbols.push_back('U');
	symbols.push_back('V');
	symbols.push_back('W');
	symbols.push_back('Y');
	symbols.push_back('Z');

	cout << "Game of TicTacToe" << endl << endl;
	cout << "Would you like to resume a saved game?" << endl << endl; 
	cout << "Press Y/y for a saved game or N/n for for a new game?" << endl;
	string response;
	cin >> response;

	while(!(response == "Y" || response == "N" || response == "y" || response == "n"))
	{
		cout << endl << "Press Y (or y) if you would like to resume a game or N (or n) for a new game!" << endl; 
		cin.clear();
		cin.sync();
		cin >> response;
	}

	int playerTurn;

	if (response == "Y" || response == "y")
	{
		cout << endl << "Loading your saved game. Please wait..." << endl;
		playerTurn = loadGame();
	}

	else
	{
		cout << endl << "Lets play a NEW GAME of Tictactoe" << endl; 
		playerTurn = newGame();
	}

	playerMove(playerTurn); 
}

// saves the current game
void saveGame(int nrMoves, int winSeq)
{
	//int playerMoves = playerMove+1;
	ofstream output;
	output.open("saving.txt");
	
	output << nrRows << endl;
	output << nrPlayers << endl;
	output << nrMoves << endl;
	output << winSeq << endl;

	for(int i = 0; i < nrRows; i++) 
	{
		for (int j = 0; j < nrRows; j++)
		{
			if (myArray[i][j] == ' ')
			{
				myArray[i][j] = '1';
				output << myArray[i][j] << endl;
			}
			else
			{
				output << myArray[i][j] << endl;
			}
		}
	}

	output.close();
}

// loads an existing game
int loadGame()
{
	ifstream infile("saving.txt");

	if (infile.fail())
	{
		cout << endl << "No saved game" << endl;
		cout << "Press 1 to exit" << endl;

		while(1)
		{
			int i;
			cin >> i;
				
			if(i != 1)
			{
				continue;
			}
			else 
			{
				exit(1); 
			}
		}
	}

	int nrMove; //to tell us which player has to make a move
	int nrColumns;
	
	infile >> nrRows;
	nrColumns = nrRows;
	infile >> nrPlayers;
	infile >> nrMove;
	infile >> winSeq;
	//playerTurn++;

	cout << endl << "Number of rows: " << nrRows << endl;
	cout << "Number of Players: " << nrPlayers << endl;
	cout << "Number of moves: " << nrMove << endl;
	cout << "Winning Sequence: " << winSeq << endl;

	myArray.resize(nrRows, vector <char>(nrColumns,' '));

	char temp;

	for(int i = 0; i < nrRows; i++ )
	{
		for(int j = 0; j < nrColumns; j++)
		{
			infile >> temp;

			if(temp == '1')
			{
				myArray[i][j] = ' ';
			}
			else
			{
				myArray[i][j] = temp;
			}
			
			temp = ' ';
		}
	}

	for(int i = 0; i < nrRows; i++)
	{
		for(int j = 0; j < nrColumns; j++)
		{
			if(myArray[i][j] == 0)
			{
				myArray[i][j] = ' ';
			}
		}
	}

	printBoard(myArray, nrRows, nrColumns);
	infile.close();
	return nrMove;
}

// starts a brand new game
int newGame()
{
	//Local variables
	cout << endl << "How many players are playing? You need minimum 2 players and maximum 26 players" << endl;
	cin >> nrPlayers;

	while (!cin.good() || (nrPlayers < 2) || (nrPlayers > 26)) 
	{
		cin.clear();
		cin.sync();
		cout << endl << "Please enter the number of players again: " ;
		cin >> nrPlayers;
	}
		
	//cout << endl<< "Number of players: " << nrPlayers << endl;
	cout << endl << "What would be the size of your tictactoe board i.e. number of rows and columns?" << endl; 
	cout <<	"You need at least 3 rows and columns!" << endl;
	cin >> nrRows;

	myArray.resize(nrRows, vector <char>(nrRows,' '));

	while (!cin.good() || nrRows < 3) 
	{
		cin.clear();
		cin.sync();
		cout <<	endl << "You need at least 3 rows and columns!" << endl;
		cout << "Please enter the size of your board again: ";
		cin >> nrRows;
	}

	cout << endl << "What is your win sequence (has to be >= to 2 and <= " << nrRows << ")?" << endl;
	cin >> winSeq;

	while(!cin.good() || winSeq < 2)
	{
		cin.clear();
		cin.sync();
		cout << endl << "Please enter a valid win sequence i.e. must be greater than 1." << endl;
		cin >> winSeq;
	}

	bool check;
	check = validWinSeq(nrRows, winSeq);

	if(check == 0)
	{
		cout << endl << "You have fewer rows compared to your win sequence" << endl;
		cout << "Enter your win sequence again. Remember it has to be less than or equal to your size of the board." << endl;
		cin >> winSeq;

		while(!cin.good() || winSeq < 2 || winSeq > nrRows)  
		{
			cin.clear();
			cin.sync();
			cout << endl << "Please enter a valid win sequence i.e. must be greater than 2 and less then " << nrPlayers << "." << endl;
			cin >> winSeq;
		}
	}
	printBoard(myArray,nrRows,nrRows);
	return 0;
}

bool validWinSeq(int rows, int winningSequence)
{
	if (rows >= winningSequence)
	{
		return true;
	}

	cout << "INVALID win sequence" << endl;
	return false;
}

void printBoard(vector<vector<char> > myArray, int nrRows, int nrColumns)
{
	cout << endl;
	cout << "    ";

	for(int i = 0; i < nrRows; i++)
	{
		if(i<10)
		{
			cout << " " << i+1 << setprecision(5) << "  ";
		}
		else if(i>=10 && i<100)
		{
			cout << "" << i+1 << setprecision(5) << "  ";
		}
		else if(i>= 100 && i<1000)
		{
			cout << " " << i+1 << setprecision(5) << "";
		}
	}

	cout << endl;

	for (int i = 0; i < nrRows; i++)
	{
		cout <<  i+1 << "   "; 
		
		for (int j = 0; j < nrColumns; j++)
		{
			cout << " " << myArray[i][j] << " " << "|" ;
		}
		
		cout << endl << "    ";

		if(i != nrRows - 1)
		{
			for (int i = 0; i < nrColumns; i++)
			{
				//cout << "---+";
				if(i == nrColumns-1)
				{
					cout << "---" ;
				}	
				else
				{
					cout << "---+";
				}
			}
			cout << endl;
		}
	}
}

//function to select the row number
int rowSelect()
{
	int row;
	cout << endl << "Eenter the row number between 1 and " << nrRows << ": ";
	cin >> row;

	while (!cin.good() || row < 1 || row > nrRows)
	{
		cout << endl;
		cout << "Invalid row number. Please enter the row number again: ";
		cin.clear();
		cin.sync();
		cin >> row;
	}
	return row;
}

//function to select column number
int columnSelect()
{
	int column;
	cout << endl << "Enter the column number between 1 and " << nrRows << ": ";
	cin >> column;

	while (!cin.good() || column < 1 || column > nrRows)
	{
		cout << endl; 
		cout << "Invalid column number. Please enter the column number again: ";
		cin.clear();
		cin.sync();
		cin >> column;
	}	
	return column;
}

void checkWin(int winSeq, int player, char character)
{
	int counter;
	counter = 0;

	//horizontal case
	for(int i = 0; i < nrRows; i++)
	{
		for(int j = 0; j < nrRows; j++)
		{
			if (myArray[i][j] == character)
			{
				counter++;
			}
			else
			{
				counter = 0;
			}
				
			if (counter == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
		counter = 0;
	}

	int counter1;
	counter1 = 0;

	// vertical case
	for(int i = 0; i < nrRows; i++)
	{
		for(int j = 0; j < nrRows; j++)
		{
			if (myArray[j][i] == character)
			{
				counter1++;
			}
			else
			{
				counter1 = 0;
			}
				
			if (counter1 == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
		counter1 = 0;
	}

	// diagonal with negative slope case (\)
	int counter2;
	counter2 = 0;

	for(int k = 0; k < nrRows; k++)
	{
		for(int i = 0, j = k; i < nrRows, j < nrRows; i++, j++)
		{
			if (myArray[i][j] == character)
			{
					counter2++;
			}
			else
			{
				counter2 = 0;
			}
				
			if (counter2 == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
	}

	int counter4;
	counter4 = 0;

	for(int k = 0; k < nrRows; k++)
	{
		for(int i = 0, j = k; i < nrRows, j < nrRows; i++, j++)
		{
			if (myArray[j][i] == character)
			{
					counter4++;
			}
			else
			{
				counter4 = 0;
			}
				
			if (counter4 == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
	}

	// diagonal with positive slope case (/)
	int counter3;
	counter3 = 0;

	for(int k = nrRows-1; k >= 0; k--)
	{
		for(int i = 0, j = k; i<nrRows, j>=0; i++, j--)
		{
			if (myArray[i][j] == character)
			{
					counter3++;
			}
			else
			{
				counter3 = 0;
			}
				
			if (counter3 == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
	}

	int counter5;
	counter5 = 0;

	for(int k = 0; k < nrRows-1; k++)
	{
		for(int i = k, j = nrRows-1; j >= 0, i<nrRows-1; j--, i++)
		{
			if (myArray[i][j] == character)
			{
					counter5++;
			}
			else
			{
				counter5 = 0;
			}
				
			if (counter5 == winSeq)
			{
				cout << endl << "Congratulations Player " << player << ", You've won!" << endl;
				cout << endl << "Press 1 to exit" << endl;

				while(1)
				{
					int i;
					cin >> i;
				
					if(i != 1)
					{
						continue;
					}
					else 
					{
						exit(1); 
					}
				}
			}
		}
	}
}