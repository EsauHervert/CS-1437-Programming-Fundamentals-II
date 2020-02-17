// Esau Hervert
// COSC 1437
// Project 5, program 2
// Option/Reference: None.

#include <iostream>
#include <string> // For the string.

using namespace std;

//*************************************************************************************************
// Base Class.
class MusicalComposition
{
private:
	string Title;
	string Composer;
	int Year;

public:
	// Constructor.
	MusicalComposition() {}
	MusicalComposition(string T, string C, int Y)
	{
		Title = T;
		Composer = C;
		Year = Y;
	}
	//*************************************************************************************************
	// Get and set methods.
	string getTitle()
	{
		return Title;
	}

	void setTitle(string T)
	{
		Title = T;
	}

	string getComposer()
	{
		return Composer;
	}

	void setComposer(string C)
	{
		Composer = C;
	}
	int getYear()
	{
		return Year;
	}

	void setYear(int Y)
	{
		Year = Y;
	}
	//*************************************************************************************************

	// Display information.
	void getInfo()
	{
		cout << Title << " was written by " << Composer << " in " << Year << endl;
	}

};
//*************************************************************************************************

//*************************************************************************************************
// Derived class.
class NationalAnthem : public MusicalComposition
{
private:
	string Nation;

public: 
	//*************************************************************************************************
	NationalAnthem(string T, string C, int Y, string N) 
	{
		// Uses the set methods to set the values.
		setTitle(T);
		setComposer(C);
		setYear(Y);
		Nation = N;
	}
	//*************************************************************************************************

	string getNation()
	{
		return Nation;
	}

	// Display information. Overrides the previous method.
	void getInfo()
	{
		cout << getTitle() << " was written by " << getComposer() << " in " << getYear() << endl;
		cout << "It is the national anthem of " << Nation << endl;
	}
}; 
//*************************************************************************************************

int main()
{
	// Examples.
	MusicalComposition M1("Swan Lake", "Tchaikovsky", 1876);
	M1.getInfo();

	NationalAnthem N1("Amhran na bhFiann", "Kearney", 1907, "Ireland");
	N1.getInfo();

	return 0;
}