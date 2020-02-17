// Esau Hervert
// COSC 1437
// Program Set 6 - Problem 1
// Reference: http://www.cplusplus.com/reference/algorithm/rotate/ - Change the order of a vector.
// http://www.cplusplus.com/reference/vector/vector/erase/ - How to erase an element in a vector.
// http://people.scs.carleton.ca/~dehne/projects/cpp-doc/tutorial/tut5-3.html - Try/Catch statement.

#include <iostream>
#include <vector> // For the vector of players.

using namespace std;

int It(int); // Function that will see who is it.

int main()
{
	int players = 0; // Value that the user will input.

	cout << "Enter the number of players (between 1 and 500): "; // Prompt the user.
	cin >> players; // Get the value.

	// Try/Catch for validation.
	try 
	{
		if (players > 500 || players < 1) // Out of range.
			throw "Value out of bounds.";

		cout << It(players) << " is it." << endl; // Call the function.
	}
	catch (char * str)
	{
		cout << "Exception: " << str << endl; // Display the exception.
	}

	return 0; // End.
}

int It(int players)
{
	vector<int> P; // This vector will have all the players.
	int R = 0; // Remainder.

	// Fill up the vector with the players.
	for (int i = 0; i < players; i++)
	{
		P.push_back(i + 1);
	}

	while (P.size() > 1) // This loop will reduce down the vector to one element.
	{
		if (P.size() < 20)
		{
			R = 20 % P.size();

			if (R > 0) // The remainder is the person that leaves.
			{
				cout << P[R - 1] << " leaves." << endl;
				P.erase(P.begin() + (R - 1));
				rotate(P.begin(), P.begin() + (R - 1), P.end());
			}
			else // If the amount of players divides 20, then the last person in the group leaves.
			{
				R = P.size() - 1;
				cout << P[R] << " leaves." << endl;
				P.erase(P.begin() + R);
			}
		}
		else if (P.size() >= 20) // If the array is bigger than 20, then the 20th person will be the person that leaves.
		{
			cout << P[19] << " leaves." << endl;
			P.erase(P.begin() + 19);
			rotate(P.begin(), P.begin() + 19, P.end());
		}
	}

	cout << endl;

	return P[0]; // It.
}