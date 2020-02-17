//Esau Hervert
//COSC 1437
//Extra Credit
////Reference/Option: http://stackoverflow.com/questions/83439/remove-spaces-from-stdstring-in-c - remove the spaces.
//http://stackoverflow.com/questions/5838711/stdcin-in-input-with-spaces - getline function.
//http://www.cplusplus.com/reference/cctype/tolower/ - tolower function.
//http://www.cplusplus.com/reference/iomanip/setprecision/ - decimal precision.

#include <iostream>
#include <string> //for the string.
#include <algorithm> //To remove the spaces.
#include <iomanip> // std::setprecision

using namespace std;

//This function will calculate the coincidence.
double coincidence(string, string, int);

int main()
{
	//initialize the strings.
	string S1 = "";
	string S2 = "";
	double C = 0;

	//Purpose of the program.
	cout << "This program will compare two strings excluding spaces and see how similar they are." << endl;
	cout << endl;

	//Take the user's string.
	//Have to use getline since the user can use spaces.
	cout << "Enter the first string: ";
	getline(cin, S1);

	cout << "Enter the second string: ";
	getline(cin, S2);

	//This function will get rid of all the spaces.
	S1.erase(remove_if(S1.begin(), S1.end(), isspace), S1.end());
	S2.erase(remove_if(S2.begin(), S2.end(), isspace), S2.end());

	cout << endl;

	//Check if their lengths are the same.
	if (S1.length() == S2.length())
	{
		//Now to calculate the coincidence.
		C = coincidence(S1, S2, S1.length());
		cout << "The index of coincidence is: " << setprecision(3) << C << "%" << endl;
	}
	else //If they are not the same.
	{
		cout << "The strings are not of the same length." << endl;
	}

}

//Function that will find the coincidence.
double coincidence(string S1, string S2, int L)
{
	//The values in question.
	double C = 0;
	double counter = 0;

	//Loop that will measure the amount of sameness two strings have.
	for (int i = 0; i < L; i++)
	{
		if (tolower(S1[i]) == tolower(S2[i]))
		{
			counter++;
		}
	}

	C = 100 * (counter / L);
	return C;
}