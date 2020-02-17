// Author: Esau Hervert
// Course: COSC 1437
// Project 1 Problem 3.
// References/Option: None

//These are the libraries that I used in this program.
//<math.h> is used for the natural logarithm.
#include <iostream>
#include <math.h>

using namespace std;

//This is the function that calculates the date of the sample.
//It outputs the result but returns no values thus it is a void function.
void CarbonDating(double drp)
{
	double t = 0, T = 5730.0;
	t = (T / log(2) * log(1 + drp));

	cout << "The approximate age of this sample is: " << t << " years\n\n";
}

int main()
{
	//DRP is the ratio that the user will submit.
	double DRP;

	//These flags will be used to either continue or terminate the loop.
	bool flag = false, flag2 = true;

	//This is just letting the user know what the program does and how it does it.
	cout << "This program will calculate the estimated age of a sample using Carbon-14." << endl;
	cout << "The formula to be used will be:\n\nt = (T / ln(2) * ln(1 + D / P))\n" << endl;
	cout << "Where:" << endl;
	cout << "t	-  age of the sample in years" << endl;
	cout << "T	-  half-life of Carbon-14 ,5730 years" << endl;
	cout << "ln	-  natural logarithm" << endl;
	cout << "D	-  amount of Carbon-14 in a given dead sample" << endl;
	cout << "P	-  amount of Carbon-14 in a living species today\n" << endl;

	//This do loop will go through the process of attaining the ratio.
	do
	{
		cout << "Please enter the ratio D / P: ";
		cin >> DRP;
		cout << endl;

		CarbonDating(DRP);

		//Here we will see if the user wants to run the program again.
		cout << "would you like to calculate a different sample?\n" << endl;
		cout << "Enter y for yes and n for no." << endl;
		char Answer = 'n';
		cin >> Answer;

		//This loop will test the inputs for the "wish to play again" option.
		do
		{
			if (Answer == 'n' || Answer == 'N')
			{
				flag = false;
				flag2 = false;
				cout << endl;
			}
			else if (Answer == 'y' || Answer == 'Y')
			{
				flag = true;
				flag2 = false;
				cout << endl;
			}
			else
			{
				cout << "\nThat was not a valid input, please enter either y or n." << endl;
				flag2 = true;
				cin >> Answer;
			}
		} while (flag2 == true);
		

	} while (flag == true);

	cout << "Thank you for using this program. Have a wonderful day.\n" << endl;

	return 0;
}