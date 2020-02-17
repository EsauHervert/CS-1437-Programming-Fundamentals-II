// Esau Hervert
// COSC 1437
// Quiz 3 Extra Credit
// References:
// https://www.youtube.com/watch?v=8vDcKtooN9c - Friend functions.
// https://www.programiz.com/cpp-programming/friend-function-class  -Foward Declaration.

#include <iostream>
#include <String>

using namespace std;

class Cities; // Fowards declaration.

class CustomerData
{
private:
	int CustomerNumber;
	int CustomerZip;

public:
	CustomerData(int CN, int CZ) // Constructor.
	{
		CustomerNumber = CN;
		CustomerZip = CZ;
	}

	friend void CustomerInformation(CustomerData, Cities); // Friend Function.
};

class Cities
{
private:
	string CityName;
	string State;
	int Zip;

public:
	Cities(string CN, string S, int Z) // Constructor.
	{
		CityName = CN;
		State = S;
		Zip = Z;
	}

	friend void CustomerInformation(CustomerData, Cities); // Friend Function.
};

// Define the friend function.
void CustomerInformation(CustomerData CD, Cities C)
{
	cout << CD.CustomerNumber << " from " << C.CityName << ", " << C.State << ", " << CD.CustomerZip << endl; // Display the information.
}

int main()
{
	// Information on the user.
	CustomerData CD1(1572, 60013);
	Cities C1("Cary", "Illinois", 60013);

	CustomerInformation(CD1, C1); // Using the friend function.

	return 0;
}