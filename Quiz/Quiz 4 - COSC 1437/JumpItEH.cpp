// Esau Hervert
// COSC 1437
// Quiz 4 Extra Credit
// Options/References: None

#include <iostream>
#include <vector>

using namespace std;

void path(vector<int>, int);

int main()
{
	int size; // Size of the board.
	int value; // Values of the squares.
	vector<int> game; // Vector for the game.

	game.push_back(0); // Start filling the vector.
	
	// Purpose of the program.
	cout << "Welcome to the game of Jump It." << endl;
	cout << "You will enter a path and out will come the shortest path that can be taken." << endl;
	
	cout << endl;

	// Ask the user the size and values of the path.
	cout << "Enter the size of the path: ";
	cin >> size;

	cout << endl; 

	cout << "The value of the path at position 1: 0" << endl; // Initial position.

	// Create the vector that will be the path.
	for (int i = 0; i < size - 1; i++)
	{
		cout << "Enter the value of the path at position " << (i + 2) << ": ";
		cin >> value;
		game.push_back(value);
	}

	cout << endl;

	// Display the general path.
	cout << "The path that you entered is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "[" << game[i] << "]" << " ";
	}

	cout << endl << endl;

	path(game, game.size()); // Find the shortest path.

	cout << endl;

	return 0;
}

void path(vector<int> game, int size) // Function that will fins the shortest path.
{
	int i = 0, sum = 0; // Values that will be used in the program.

	// Find the shortest path.
	cout << "The Shortest path is: ";
	cout << "[" << game[i] << "]" << " ";
	i++;

	// Loop that will read three points at a time until the end to find the shortest path.
	while (i < size)
	{
		if (i < size - 3)
		{
			if (game[i] + game[i + 2] < game[i + 1])
			{
				cout << "[" << game[i] << "]" << " " << "[" << game[i + 2] << "]" << " ";
				sum += game[i] + game[i + 2];
				i += 3;
			}
			else if (game[i] + game[i + 1] < game[i + 2])
			{
				cout << "[" << game[i] << "]" << " " << "[" << game[i + 1] << "]" << " ";
				sum += game[i] + game[i + 1];
				i += 3;
			}
			else if (game[i] + game[i + 2] > game[i + 1])
			{
				cout << "[" << game[i + 1] << "]" << " ";
				sum += game[i + 1];
				i += 3;
			}
		}
		else if (i >= size - 3 && i != size - 1)
		{
			cout << "[" << game[i + 1] << "]";
			sum += game[i + 1];
			i += 2;
			cout << endl;
		}
		else if (i = size - 1)
		{
			cout << "[" << game[i] << "]";
			sum += game[i];
			i += 1;
			cout << endl;
		}
	}

	cout << endl;

	cout << "The sum of this path is: " << sum << endl; // Sum of the path.
}