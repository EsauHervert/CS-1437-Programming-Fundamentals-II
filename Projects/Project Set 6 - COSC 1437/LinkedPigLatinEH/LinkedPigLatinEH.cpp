// Esau Hervert
// COSC 1437
// Program set 6, Problem 3
// References: https://www.youtube.com/watch?v=o5wJkJJpKtM - Linked List basics.

#include <iostream>
#include <string>

using namespace std;

// Node.
//******************************************************************************************************
struct Node
{
	char Letter;
	Node *next;
};
//******************************************************************************************************

bool IsVowel(char); // Function to determine if a vowel is a char.

int main()
{
	// Starting point.
	//******************************************************************************************************
	string English = "Test";

	cout << "Enter a string: ";
	cin >> English;
	cout << endl;

	cout << "The string you entered is: ";
	cout << English << endl;
	//******************************************************************************************************

	// Some initialized nodes.
	//******************************************************************************************************
	Node *n;
	Node *t;
	Node *h;
	//******************************************************************************************************

	// turn the string into a linked list.
	//******************************************************************************************************
	if (English.length() > 0)
	{
		n = new Node;
		h = n; // Head.

		n->Letter = English[0];

		t = n;

		for (int i = 1; i < English.length(); i++)
		{
			n = new Node;
			n->Letter = English[i];

			t->next = n;
			t = n;
		}
		//******************************************************************************************************

		n->next = NULL; // Ends the linked list.

		if (IsVowel(h->Letter)) // For the simple case were the word starts with a vowel.
		{
			// Add the string char by char to the linked list.
			//******************************************************************************************************
			string Append = "-way";

			for (int i = 0; i < Append.length(); i++)
			{
				n = new Node;
				n->Letter = Append[i];

				t->next = n;
				t = n;
			}
			//******************************************************************************************************
		}
		else
		{
			int counter = 0; // Will be used for the - and in case there are no vowels.

			while (!IsVowel(h->Letter) && counter != English.length())
			{
				// Add a - to the string.
				//******************************************************************************************************
				if (counter == 0)
				{
					n = new Node;
					n->Letter = '-';

					t->next = n;
					t = n;
				}
				//******************************************************************************************************

				// Shufle the characters.
				//******************************************************************************************************
				n = new Node;
				n->Letter = h->Letter;

				t->next = n;
				t = n;

				h = h->next;
				//******************************************************************************************************

				counter += 1;
			}

			if (counter != English.length())
			{
				// Add the string char by char to the linked list.
				//******************************************************************************************************
				string Append = "ay";

				for (int i = 0; i < Append.length(); i++)
				{
					n = new Node;
					n->Letter = Append[i];

					t->next = n;
					t = n;
				}
				//******************************************************************************************************
			}
			else
			{
				// Adjust the ordering of the list.
				//******************************************************************************************************
				n = new Node;
				n->Letter = h->Letter;

				t->next = n;
				t = n;
								
				h = h->next;
				//******************************************************************************************************

				string Append = "way"; // What needs to be added at the end of the linked list.

				// Add the string char by char to the linked list.
			    //******************************************************************************************************
				for (int i = 0; i < Append.length(); i++)
				{
					n = new Node;
					n->Letter = Append[i];

					t->next = n;
					t = n;
				}
				//******************************************************************************************************
			}

		}

		n->next = NULL; // Ends the linked list.

		// Display the results.
		//******************************************************************************************************
		cout << "The Pig Latin form of the string: ";

		cout << h->Letter; // Initial letter.

		while (h->next != NULL) // Will display the letter if there is one.
		{
			h = h->next;
			cout << h->Letter;
		}
		//******************************************************************************************************
	}

	cout << endl;
	return 0;
}

// Will test to see if the characters are vowels.
//******************************************************************************************************

bool IsVowel(char C)
{
	bool B;

	if (C == 'A' || C == 'a' || C == 'E' || C == 'e' || C == 'I' || C == 'i' || C == 'O' || C == 'o' || C == 'U' || C == 'u' || C == 'Y' || C == 'y')
		B = true;
	else
		B = false;

	return B;
}
//******************************************************************************************************