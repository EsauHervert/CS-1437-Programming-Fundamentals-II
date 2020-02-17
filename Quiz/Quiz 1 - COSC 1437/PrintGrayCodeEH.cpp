//Author: Esau Hervert
//Course: COSC 1437
//Quiz 1 Extra Credit
//Reference/Option: None.

//Standard start of a program.
#include <iostream>

using namespace std;

/*
Note: This program only works for numbers 0-3.
*/

int main()
{
	//These are all the variables and counters that I will be using
	int total = 0, number = 0, counter1 = 0, counter2 = 0, counter3 = 0;
	bool flag = true;
	const int largest = 8;

	//This is the array that I will be using to create the output.
	//It will hold up to 8 digits.
	//I initialized the numbers so that when the output is done, it can check the values.
	int array[largest] = { 10,20,30,40,50,60,70,80 };

	//Here is the output and where we take the numbers from the user.
	cout << "Enter Gray Code size (-1 to quit): ";
	cin >> number;
	cout << endl;

	//This is where the sentinel value of 1 is going to be.
	if (number == -1)
		flag = false;

	//This will check if the user wants to continue.
	while (flag == true)
	{
		//For the special case of number = 0.
		while (number == 0)
		{
			cout << 0 << endl;
			cout << "\nEnter Gray Code size (-1 to quit): ";
			cin >> number;
			cout << endl;
		}

		//Everytime the loop loops back, the counters must be reinitialized.
		counter1 = 0;
		counter2 = 0;
		counter3 = 0;

		//This is for if we changed the value of number to be our sentinel.
		if (number == -1)
		{
			flag = false;
			return 0;
		}

		//This total will be used in the program for the total amount of outputs.
		total = pow(2, number);

		//This is where the first output which is all zero's will be done.
		for (int i = 0; i < number; i++)
		{
			array[i] = 0;
			cout << array[i];
		}
		//Output style.
		if (number > 0)
			cout << endl;

		//For the Cases of number being between 1 and three.
		if (number > 0)
		{
			for (int k = 1; k < total; k++)
			{
				if (k % 2 == 1)
				{
					array[0] = array[0] + pow(-1, (k - 1) / 2);
				}
				else if (k == total / 2)
				{
					array[number - 1] = array[number - 1] + 1;
				}
				else if (k % (number - 1) == 0 && k < total / 2)
				{
					if (number - 2 > 0)
					{
						array[number - 2] = array[number - 2] + pow(-1, counter2);
						counter2++;
					}
				}
				else if (k % (number - 2) == 0)
				{
					if (number - 3 > 0)
					{
						array[number - 3] = array[number - 3] + pow(-1, counter3);
						counter3++;
					}
				}
				else
				{
					if (number != 0)
					{
						cout << endl;
					}
				}

				//This is where the new element will be outputted.
				for (int i = 0; i < number; i++)
				{
					cout << array[(number - 1) - i];
				}
				if (number != 0)
				{
					cout << endl;
				}

			}
			//Style.
			cout << endl;

			//This is where we ask the user to input a new number.
			cout << "Enter Gray Code size (-1 to quit): ";
			cin >> number;
		}
	}
	return 0;
}
