// Author: Esau Hervert
// Course: COSC 1437
// Project 3 Problem 4
// This is the second option. 
// References/Option: None
// Note: I could not get the unicodes for the suits to work for some reason.

#include <iostream>
#include <string>

using namespace std;

//Here are the functons that I will be using in the program.
string TakeCard(int);
bool Test(string, char[], char[]);
int Poker(string[], char[], char[]);
void winner(int, int, string, string);

int main()
{
	//This is the array that has the cards.
	char CardValue[13] = { 'A','2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	char Suit[4] = { 'C', 'D', 'H', 'S' };

	//Player's Name.
	int Name1H = 0, Name2H = 0;

	//Boolean to see if they would like to play again.
	bool PlayAgain = true, flag = true;

	//*******************************************************************************************
	//Get the name of the users.
	string Name1 = "Name1", Name2 = "Name2";

	cout << "Enter player 1 name: ";
	cin >> Name1;

	cout << "Enter player 2 name: ";
	cin >> Name2;

	cout << endl;
	//*******************************************************************************************
	//Let's Play poker.

	//This loop will run once and run as long as the player wants to play.
	do {
		//*******************************************************************************************
		//Now for their cards.

		//Name1's Cards
		string Name1C[5] = { "1H","2H","3H","4H","5H" };

		//Name2's Cards
		string Name2C[5] = { "1D","2D","3D","4D","5D" };

		//Take Name1's Cards.
		cout << Name1 << endl;

		//Taking their cards.
		for (int i = 0; i < 5; i++)
		{
			Name1C[i] = TakeCard(i + 1);
			for (int j = 0; j < i; j++)
			{
				//Check for duplicate.
				if (Name1C[i] == Name1C[j])
				{
					cout << "Duplicate Card, Try again." << endl;
					Name1C[i] = TakeCard(i + 1);
					j = 0;
				}
			}

			//Make sure that the card is valid.
			while (!Test(Name1C[i], CardValue, Suit))
			{
				cout << "Bad Card. Try again." << endl;
				Name1C[i] = TakeCard(i + 1);
			}
		}

		cout << endl;

		//Take Name2's Cards.
		cout << Name2 << endl;
		for (int i = 0; i < 5; i++)
		{
			Name2C[i] = TakeCard(i + 1);

			//First test it againts Name1's Cards.
			for (int k = 0; k < 5; k++)
			{
				//Check if there is a copied card.
				if (Name2C[i] == Name1C[k])
				{
					cout << "Duplicate Card, Try again." << endl;
					Name2C[i] = TakeCard(i + 1);
					k = 0;
				}
			}

			//Now make sure it is not a duplicate of Name2's other cards.
			for (int j = 0; j < i; j++)
			{
				if (Name2C[i] == Name2C[j])
				{
					cout << "Duplicate Card, Try again." << endl;
					Name2C[i] = TakeCard(i + 1);
					j = 0;
				}
			}

			//Check if the cards Name2 have are valid.
			while (!Test(Name2C[i], CardValue, Suit))
			{
				cout << "Bad Card. Try again." << endl;
				Name2C[i] = TakeCard(i + 1);

			}

		}
		//*******************************************************************************************

		cout << endl;

		//*******************************************************************************************
		//Display their cards.

		//Name1 cards.
		cout << Name1 << ": ";
		for (int i = 0; i < 5; i++)
		{
			cout << Name1C[i] << " ";
		}
		cout << ": ";
		Name1H = Poker(Name1C, CardValue, Suit);

		cout << endl;

		//Name2 cards.
		cout << Name2 << ": ";
		for (int i = 0; i < 5; i++)
		{
			cout << Name2C[i] << " ";
		}
		cout << ": ";
		Name2H = Poker(Name2C, CardValue, Suit);
		//*******************************************************************************************

		cout << endl;

		//*******************************************************************************************
		//This function will determine the winner.
		winner(Name1H, Name2H, Name1, Name2);
		//*******************************************************************************************

		cout << endl;

		//*******************************************************************************************
		//This is where we will see if the user wants to play again.
		//Here we will see if the user wants to run the program again.
		cout << "Play again (Y/N)? ";
		char Answer = 'n';
		cin >> Answer;

		//This loop will test the inputs for the "wish to play again" option.
		do
		{
			if (Answer == 'n' || Answer == 'N')
			{
				PlayAgain= false;
				flag = false;
				cout << endl;
			}
			else if (Answer == 'y' || Answer == 'Y')
			{
				PlayAgain = true;
				flag = false;
				cout << endl;
			}
			else
			{
				cout << "\nThat was not a valid input, please enter either (Y|y) or (N|n): ";
				flag = true;
				cin >> Answer;
			}
		} while (flag);
		//*******************************************************************************************

	} while (PlayAgain);

	return 0;
}

//This fucntion will take the card from the user.
string TakeCard(int n)
{
	string Card = "XY";
	cout << "Enter card " << n << ": ";
	cin >> Card;
	return Card;
}

//This function will test to see if the card the user inputted is valid.
bool Test(string s, char r[], char t[])
{
	bool value = true;
	int counter1 = 0, counter2 = 0;
	
	//Make sure the length is correct.
	if (s.length() > 2 || s.length() < 2)
	{
		value = false;
	}

	//Testing the card's values.
	for (int i = 0; i < 14; i++)
	{
		if (r[i] == s[0])
		{
			counter1 += 1;
		}
	}

	//Testing the card's suit.
	for (int i = 0; i < 4; i++)
	{
		if (t[i] == s[1])
		{
			counter2 += 1;
		}
	}

	//If the value or suit is invalid, it will let the user know.
	if (counter1 == 0 || counter2 == 0)
	{
		value = false;
	}
		
	return value;
}

int Poker(string N[], char V[], char S[])
{
	//Values used.
	int value = 0, highest = 0, highestvalue = 0, highestcard = 0;

	//Arrays that will count the cards they have and what suits they have.
	int values[13] = { };
	int suits[4] = { };
	
	//counter for the pairs.
	int counter = 0;

	//Highest in the power tier for when two hands of the same tier occur.
	int PairH = 0, SFHigh = 0, ToKHigh = 0, FHHigh = 0, STHigh = 0, FoKHigh = 0;


	//booleans for each of the possible hands.
	bool RF = false, SF = false, FoK = false, FH = false, FL = false, ST = false,
		ToK = false, TP = false, OP = false;

	//*******************************************************************************************
	//This Loop will determine the winner when it comes to considering the highest card.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (N[i][0] == V[j])
			{
				values[j]++;
				//Here we will give each card a value such that (j + 1) > (4 * j).
				value += pow((j + 1), 4);
			}
		}
	}
	//*******************************************************************************************

	//suit count
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (N[i][1] == S[j])
			{
				suits[j]++;
			}
		}
	}
	//*******************************************************************************************
	if (suits[0] == 5 || suits[1] == 5 || suits[2] == 5 || suits[3] == 5)
	{
		//Royal.
		if (values[0] == 1 && values[12] == 1 && values[11] == 1 && values[10] == 1 && values[9] == 1)
		{
			RF = true;
		}

		//Straight Flush.
		for (int k = 0; k < 9; k++)
		{
			if (values[k] == 1 && values[k + 1] == 1 && values[k + 2] == 1
				&& values[k + 3] == 1 && values[k + 4] == 1)
			{
				SF = true;
				SFHigh = (k + 4);
			}
		}

		//Flush
		FL = true;
	}
	//*******************************************************************************************

	//*******************************************************************************************
	//Straight for when the ace wraps around.
	if (values[0] == 1 && values[12] == 1 && values[11] == 1 && values[10] == 1 && values[9] == 1)
	{
		ST = true;
		STHigh = 12;
	}
	//Straight for the other cases.
	for (int k = 0; k < 9; k++)
	{
		if (values[k] == 1 && values[k + 1] == 1 && values[k + 2] == 1
			&& values[k + 3] == 1 && values[k + 4] == 1)
		{
			ST = true;
			STHigh = (k + 4);
		}
	}

	//*******************************************************************************************
	//Four of a kind, Full House, Three of a Kind.
	for (int i = 0; i < 13; i++)
	{
		if (values[i] == 4)
		{
			FoK = true;
			//For in case there is two hands with the same hand.
			value += values[i] * 5e5;
			FoKHigh = i;

		}
		else if (values[i] == 3)
		{
			//For in case there is two hands with the same hand.
			value += values[i] * 5e4;

			FHHigh = i;

			for (int k = 0; k < 13; k++)
				if (values[k] == 2)
				{
					FH = true;
					//For in case there is two hands with the same hand.
					value += values[k] * 1e4;
				}
				else
				{
					ToK = true;
					ToKHigh = i;
				}
		}
	}
	//*******************************************************************************************

	//*******************************************************************************************
	//Highest card.
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (N[i][0] == V[j])
				if ((j + 1) > highest)
				{
					highest = (j + 1);
					highestcard = i;
				}
		}
	}

	//*******************************************************************************************

	//*******************************************************************************************
	//Two Pair, One Pair.
	for (int o = 0; o < 13; o++)
	{
		if (values[o] == 2)
		{
			//For in case there is two hands with the same hand.
			value += values[o] * 5e3;
			counter++;
			PairH = o;
		}
	}
	if (counter == 2)
	{
		TP = true;
	}
	else if (counter == 1)
	{
		OP = true;
	}
	//*******************************************************************************************

	//*******************************************************************************************
	//This is where the hand is displayed and the score of their hand is displayed.
	if (RF)
	{
		cout << "Royal Flush!" << endl;
		value += 2e9;
	}
	else if (SF)
	{
		cout << "Straight Flush, ";
		cout << V[SFHigh] << "'s High." << endl;
		value += 1e9;
	}
	else if (FoK)
	{
		cout << "Four of a Kind, ";
		cout << V[FoKHigh] << "'s High." << endl;
		value += 5e8;
	}
	else if (FH)
	{
		cout << "Full House, ";
		cout << V[FHHigh] << "'s High." << endl;
		value += 1e8;
	}
	else if (FL)
	{
		cout << "Flush, ";

		//Display the suit.
		for (int l = 0; l < 4; l++)
		{
			if (suits[l] == 5)
			{
				switch (l)
				{
				case 0:
				{
					cout << "Clubs, ";
					break;
				}
				case 1:
				{
					cout << "Diamonds, ";
					break;
				}
				case 2:
				{
					cout << "Hearts, ";
					break;
				}
				case 3:
				{
					cout << "Spades, ";
					break;
				}

				}
			}
		}

		cout << N[highestcard][0] << " High." << endl;
		value += 7e7;
	}
	else if (ST)
	{
		cout << "Straight, ";
		cout << V[STHigh] << "'s High." << endl;

		value += 5e7;
	}
	else if (ToK)
	{
		cout << "Three of a Kind, ";
		cout << V[ToKHigh] << "'s High." << endl;
		value += 1e7;

	}
	else if (TP)
	{
		cout << "Two Pair, ";
		cout << V[PairH] << "'s High." << endl;
		value += 5e6;
	}
	else if (OP)
	{
		cout << "One Pair, ";
		cout << V[PairH] << "'s High." << endl;
		value += 1e6;
	}
	else
	{
		cout << "High Card, ";
		cout << N[highestcard][0] << " High." << endl;
	}
	//*******************************************************************************************

	//Return the score of the hand.
	return value;
}

//Determines the winner. N1 and N2 are the player's scores. Nm1 and Nm2 are the player's names.
void winner(int N1, int N2, string Nm1, string Nm2)
{

	if (N1 > N2)
	{
		cout << Nm1 << " Winner!" << endl;
	}
	else if (N2 > N1)
	{
		cout << Nm2 << " Winner!" << endl;
	}
	else if (N1 == N2)
	{
		cout << "Tie- split pot!!" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
}
