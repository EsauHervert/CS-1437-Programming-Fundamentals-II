// Esau Hervert
// COSC 1437
// Project 4: Problem 1
// Options/References: http://www.cplusplus.com/reference/ios/fixed/ : outputting to the precision I needed.
// Gladdis C++: For the Error Catch.

#include <iostream>
#include <cstdlib> // For the EXIT_FAILURE.
#include <iomanip> // For the Precision.

using namespace std;

//*********************************************************************************************************************************************
//This is the class that will be used, named "Population".
class Population
{
	// All the fields will be private.
	private:
		int Popul;
		int Births;
		int Deaths;

	//All the methods will be public.
	public:
		//Constructor.
		Population(){};

		//Will set the values.
		void setPop(int);
		void setBirths(int);
		void setDeaths(int);

		//Will get the values.
		int getPop() const;
		int getBirths() const;
		int getDeaths() const;

		//Birthrates and Deathrates.
		double Birthrate(int, int);
		double Deathrate(int, int);

		//Display the information.
		void Info();
};
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
int main()
{
	//Here the object will be created and the values will be assigned.
	Population p1;
	p1.setPop(420000);
	p1.setBirths(69);
	p1.setDeaths(34);

	p1.Info();
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//Set Methods.
//Note that if the value is not in the range that is acceptable, the method will throw an error.
void Population::setPop(int Pop)
{
	if (Pop > 1)
		Popul = Pop;
	else
	{
		cout << "Not a valid value. Population must be greater than 1." << endl;
		exit(EXIT_FAILURE);
	}
}

void Population::setBirths(int B)
{
	if (B > 0)
		Births = B;
	else
	{
		cout << "Not a valid value. Population must be greater than 1." << endl;
		exit(EXIT_FAILURE);
	}
}

void Population::setDeaths(int D)
{
	if (D > 0)
		Deaths = D;
	else
	{
		cout << "Not a valid value. Population must be greater than 1." << endl;
		exit(EXIT_FAILURE);
	}
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//Get Methods.
int Population::getPop() const
{
	return Popul;
}

int Population::getBirths() const
{
	return Births;
}

int Population::getDeaths() const
{
	return Deaths;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//This method will calculate the Birthrate.
double Population::Birthrate(int P, int B)
{
	double Birthrate;

	Birthrate = ((double)B) / ((double)P); // Cast to double so that the output is a double.
	return Birthrate;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//This method will calculate the Deathrate.
double Population::Deathrate(int P, int D)
{
	double Deathrate;

	Deathrate = ((double)D) / ((double)P); // Cast to double so that the output is a double.
	return Deathrate;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//The information will be displayed to the user.
void Population::Info()
{
	double BR, DR; // The rates will be doubles.

	BR = Birthrate(Popul, Births);
	DR = Deathrate(Popul, Deaths);

	cout << "Population Statistics" << endl;
	cout << "	Population: " << Popul << endl;
	//Note that the precision was adjusted to match the output in the test run.
	cout << "	Birth Rate: " << fixed << setprecision(4) << BR << endl;
	cout << "	Death Rate: " << fixed << setprecision(4) << DR << endl;
}