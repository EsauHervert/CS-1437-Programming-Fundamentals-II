//Author: Esau Hervert
//Course: COSC 1437
//Project 1 Problem 2
//Reference/Option: http://www.cplusplus.com/reference/cstdlib/rand/

#include <iostream>
#include <string>
//These are for the random number generator.
#include <stdio.h>      
#include <stdlib.h>
#include <time.h> 

using namespace std;

//I choose to just prototype the functions to make my program cleaner.
int Computer();
void menu();
int test(int,int);

int main()
{
	//This string will help with outputting the data back to the user.
	string RPSLK[5] = { "Rock", "Paper", "Scissors", "Lizard", "Spock" };

	//This is where all the variables are initialized.
	int choice = 0, truechoice = 0, Comchoice = 0, Userscore = 0, Computerscore = 0, Draw = 0, flag = 1, flag2 = 0;
	bool winner = false;

	//The program is to crown a winner once someone hits 2 wins.
	cout << "Winner is 2 out of 3." << endl << endl;
	do
	{
		//Function displays the menu.
		menu();
		cin >> choice;

		//User Validation.
		if (choice < 1 || choice > 5)
		{
			cout << "The value " << choice << " is not a valid option." << endl << endl;
			menu();
			cin >> choice;
		}

		//Adjusting the values so that they will work with the program.
		Comchoice = Computer();
		truechoice = choice - 1;

		//Displaying the information back to the user.
		cout << "\nYour choice was: " << RPSLK[truechoice] << endl;
		cout << "The computer's choice was: " << RPSLK[Comchoice] << endl;

		//Run the test for the results of who won and what beat what.
		flag = test(truechoice, Comchoice);

		//Tallying up the score.
		if (flag == 1)
			Userscore += 1;
		else if (flag == 0)
			Computerscore += 1;
		else if (flag == 2)
			Draw += 1;

		cout << "\nThe score is: \nUser: " << Userscore << "\nComputer: " << Computerscore << "\nDraw: " << Draw;
		cout << string(2, '\n');

		//Terminates the loop once someone reaches 1.
		if (Userscore == 2)
		{
			flag2 = 0;
			winner = true;
		}
		else if (Computerscore == 2)
		{
			flag2 = 1;
			winner = true;
		}


	} while (winner == false);

	//Crowning the winner.
	string Players[2] = { "User", "Computer" };

	cout << "The winner is " << Players[flag2] << ". Thanks for playing." << endl;
	return 0;
}

//Displays the menu.
void menu()
{
	cout << "The options are the following: " << endl;
	cout << "(1) - Rock" << endl;
	cout << "(2) - Paper" << endl;
	cout << "(3) - Scissors" << endl;
	cout << "(4) - Lizard" << endl;
	cout << "(5) - Spock" << endl;
	cout << "\nYour choice is: ";
}

//Generates a random number which will be used to be the computer's choice.
int Computer()
{
	int randomnumber = 0;

	srand(time(NULL));

	randomnumber = rand() % 5;

	return randomnumber;
}

//This will test the choices that were made to see who won or if it was a tie.
int test(int x, int y)
{
	int flag = 0;

	if (x == y)
	{
		cout << "The Choices are the same." << endl;
		flag = 2;
	}
	else if (x == 0)
	{
		switch (y)
		{
		case 1:
			cout << "Paper Covers Rock." << endl;
			flag = 0;
			break;
		case 2:
			cout << "Rock Crushes Scissors." << endl;
			flag = 1;
			break;
		case 3:
			cout << "Rock Crushes Lizard." << endl;
			flag = 1;
			break;
		case 4:
			cout << "Spock Vaporizes Rock." << endl;
			flag = 0;
			break;
		}
	}
	else if (x == 1)
	{
		switch (y)
		{
		case 0:
			cout << "Paper Covers Rock." << endl;
			flag = 1;
			break;
		case 2:
			cout << "Scissors Cuts Paper." << endl;
			flag = 0;
			break;
		case 3:
			cout << "Lizard Eats Paper." << endl;
			flag = 0;
			break;
		case 4:
			cout << "Paper Disproves Spock." << endl;
			flag = 1;
			break;
		}
	}
	else if (x == 2)
	{
		switch (y)
		{
		case 0:
			cout << "Rock Crushes Scissors." << endl;
			flag = 0;
			break;
		case 1:
			cout << "Scissors Cuts Paper." << endl;
			flag = 1;
			break;
		case 3:
			cout << "Scissors Decapitate Lizard." << endl;
			flag = 1;
			break;
		case 4:
			cout << "Spock Smashes Scissors." << endl;
			flag = 0;
			break;
		}
	}
	else if (x == 3)
	{
		switch (y)
		{
		case 0:
			cout << "Rock Crushes Lizard." << endl;
			flag = 0;
			break;
		case 1:
			cout << "Lizard Eats Paper." << endl;
			flag = 1;
			break;
		case 2:
			cout << "Scissors Decapitate Lizard." << endl;
			flag = 0;
			break;
		case 4:
			cout << "Lizard Poisons Spock." << endl;
			flag = 1;
			break;
		}
	}
	else if (x == 4)
	{
		switch (y)
		{
		case 0:
			cout << "Spock Vaporizes Rock." << endl;
			flag = 1;
			break;
		case 1:
			cout << "Paper Disproves Spock." << endl;
			flag = 0;
			break;
		case 2:
			cout << "Spock Smashes Scissors" << endl;
			flag = 1;
			break;
		case 3:
			cout << "Lizard Poisons Spock." << endl;
			flag = 0;
			break;
		}
	}

	return flag;
}