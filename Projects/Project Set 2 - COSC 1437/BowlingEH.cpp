// Author: Esau Hervert
// Course: COSC 1437
// Project 2 Problem 4
// This is the second option. 
// References/Option: None

#include <iostream>
#include <string> // for the string that will have the score.
#include <vector>

using namespace std;

void Game(string, int); //This will calculate the score in bowling.

int main()
{
	//initialize some variables.
	string score = "0000000000";
	int j = 0;
	bool flag = true;

	//Purpose of the program.
	cout << "This program will calculate the score of a bowling game.\n" << endl;

	//This loop will test the inputs for the "wish to play again" option.
	do
	{
		cout << "Enter bowling score for a game: ";
		cin >> score;

		j = score.length();

		Game(score, j);

		//Here we will see if the user wants to run the program again.
		cout << "\nRun again(Y/N): ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'n' || Answer == 'N')
		{
			flag = false;
			cout << endl;
		}
		else if (Answer == 'y' || Answer == 'Y')
		{
			flag = true;
			cout << endl;
		}

	} while (flag == true);
}

void Game(string score, int j)
{
	//Variables in the function.
	int frame[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int Frame = 1;
	int counter = 0;
	int Total = 0;
	int k = 0;

	//***************************************************************************************
	//Heading

	cout << endl;
	cout << "FRAMES" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << (i + 1) << "	";
	}

	cout << endl;

	for (int m = 0; m < 10; m++)
	{
		cout << "--------";
	}

	cout << endl;
	//***************************************************************************************
		
	//Calculating the scores for the first 9 frames.
	while (Frame < 10)
	{
		if (((int)score[k] - 48) < 10 && ((int)score[k] - 48) >= 0) // numeric pins.
		{
			if (counter == 0)
			{
				frame[Frame] = ((int)score[k] - 48);
				cout << ((int)score[k] - 48);
				k++;
				counter = 1;
			}
			else if (counter == 1)
			{
				frame[Frame] += ((int)score[k] - 48);
				cout << "-" << ((int)score[k] - 48) << "	";
				k++;
				counter = 0;
				Frame++;
			}
		}
		else if (score[k] == 'X') // Strike.
		{
			frame[Frame] = 10;

			if (score[k + 1] == 'X')
			{
				frame[Frame] += 10;
			}
			else
			{
				frame[Frame] += ((int)score[k + 1] - 48);
			}

			if (score[k + 2] == 'X')
			{
				frame[Frame] += 10;
			}
			else if (score[k + 2] == '/')
			{
				frame[Frame] += 10 - ((int)score[k + 1] - 48);
			}
			else
			{
				frame[Frame] += ((int)score[k + 2] - 48);
			}

			cout << score[k] << "  " << "	";
			Frame++;
			k++;
		}
		else //Spare.
		{
			frame[Frame] += 10 - ((int)score[k - 1] - 48);

			if (score[k + 1] == 'X')
			{
				frame[Frame] += 10;
			}
			else
			{
				frame[Frame] += ((int)score[k + 1] - 48);
			}
			cout << " " << score[k] << "	";
			Frame++;
			k++;
			counter = 0;
		}
			
	}

	//For the 10th frame.
	for (k; k < j; k++)
	{
		if (score[k] == 'X')
		{
			frame[10] += 10;
			cout << score[k] << " ";
		}
		else if (score[k] == '/')
		{
			frame[10] += 10 - ((int)score[k - 1] - 48);
			cout << " " << score[k] << " ";
		}
		else
		{
			frame[10] += ((int)score[k] - 48);
			cout << score[k] << " ";
		}
	}

	cout << endl << endl;

	//Now to display the scores as they go along.
	for (int i = 1; i < 11; i++)
	{
		Total += frame[i];
		cout << Total << "	";
	}

	cout << endl;
}