//Esau Hervert
//COSC 1437
//Project 4: Problem 2
//Options/References: http://introcs.cs.princeton.edu/java/92symbolic/Polynomial.java.html : Java version of this Program.

#include <iostream>
#include <vector> // For the vector.
#include <iomanip>// For outputting the numbers.

using namespace std;

//*********************************************************************************************************************************************
// Here is the Polynomial Class.
class Polynomial
{
	//I choose to use a vector since it can be resized as needed.
	vector<double> Pol;

	private:
		int degree = 0;

	public:
		Polynomial() {}; // Constructor.

		//Get and set methods.
		int getDegree();
		double getCoefficient(int);

		void setDegree(int);
		void setCoefficients(int, double);

		//These are all the functions that will be used.
		// The were all overloaded for clenliness.
		void Addition(Polynomial);
		void Addition(double);
		void Subtraction(Polynomial);
		void Subtraction(double, bool);
		void Product(Polynomial);
		void Product(double);

		//This functions returns the polynomial in question.
		void getPolynomial();
};
//*********************************************************************************************************************************************

int main()
{
	//*********************************************************************************************************************************************
	// Here are some polynomials.
	cout << "First set of Polynomials." << endl;

	Polynomial r0;
	r0.setDegree(1);
	r0.setCoefficients(0, 0);
	r0.setCoefficients(1, 1);

	cout << "r0:: ";
	r0.getPolynomial();

	Polynomial r1;
	r1.setDegree(0);
	r1.setCoefficients(0, -5);

	cout << "r1:: ";
	r1.getPolynomial();

	Polynomial r2;
	r2.setDegree(1);
	r2.setCoefficients(0, -2.5);
	r2.setCoefficients(1, 17);

	cout << "r2:: ";
	r2.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;

	//*********************************************************************************************************************************************
	// Addition:
	cout << "First Addition:: " << endl;

	r0.Addition(r1);
	cout << "r0 + r1:: ";
	r0.getPolynomial();

	cout << endl;

	r2.Addition(r1);
	cout << "r2 + r1:: ";
	r2.getPolynomial();

	cout << endl;

	r1.Addition(-5);
	cout << "r1 + (- 5) = (-5) + r1:: ";
	r1.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;
	cout << endl;

	//*********************************************************************************************************************************************
	// Here are some polynomials.
	cout << "Second set of Polynomials::" << endl;

	Polynomial r4;
	r4.setDegree(1);
	r4.setCoefficients(0, 2);
	r4.setCoefficients(1, 4);

	cout << "r4:: ";
	r4.getPolynomial();

	Polynomial r5;
	r5.setDegree(3);
	r5.setCoefficients(0, 1);
	r5.setCoefficients(1, 2);
	r5.setCoefficients(2, 3);
	r5.setCoefficients(3, 4);

	cout << "r5:: ";
	r5.getPolynomial();

	Polynomial r6;
	r6.setDegree(1);
	r6.setCoefficients(0, 0);
	r6.setCoefficients(1, -1);

	cout << "r6:: ";
	r6.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;

	//*********************************************************************************************************************************************
	// Subtraction.
	cout << "Next Subtraction:: " << endl;

	r4.Subtraction(r5);
	cout << "r4 - r5:: ";
	r4.getPolynomial();

	cout << endl;

	r5.Subtraction(-9, true);
	cout << "(-9) - r5:: ";
	r5.getPolynomial();

	cout << endl;

	r6.Subtraction(8, false);
	cout << "r6 - 8:: ";
	r6.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;
	cout << endl;

	//*********************************************************************************************************************************************
	// Here are some polynomials.
	cout << "Third set of Polynomials::" << endl;

	Polynomial r7;
	r7.setDegree(4);
	r7.setCoefficients(0, 1);
	r7.setCoefficients(1, -1);
	r7.setCoefficients(2, 0);
	r7.setCoefficients(3, 4);
	r7.setCoefficients(4, -2.7);

	cout << "r7:: ";
	r7.getPolynomial();

	Polynomial r8;
	r8.setDegree(3);
	r8.setCoefficients(0, -1);
	r8.setCoefficients(1, -2);
	r8.setCoefficients(2, -3);
	r8.setCoefficients(3, -4);

	cout << "r8:: ";
	r8.getPolynomial();

	Polynomial r9;
	r9.setDegree(2);
	r9.setCoefficients(0, -1);
	r9.setCoefficients(1, 0);
	r9.setCoefficients(2, 1);

	cout << "r9:: ";
	r9.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;

	//*********************************************************************************************************************************************
	// Product.
	cout << "Lastly Product:: " << endl;

	r7.Product(r8);
	cout << "r7 * r8:: ";
	r7.getPolynomial();

	cout << endl;

	r9.Product(r8);
	cout << "r9 * r8:: ";
	r9.getPolynomial();

	cout << endl;
	r8.Product(3.75);
	cout << "r8 * 3.75 = 3.75 * r8:: ";
	r8.getPolynomial();
	//*********************************************************************************************************************************************

	cout << endl;

	return 0;
}
//*********************************************************************************************************************************************
// Get and set method for degree.
int Polynomial::getDegree()
{
	return degree;
}

void Polynomial::setDegree(int D)
{
	degree = D;

	for (int i = 0; i <= D; i++)
		Pol.push_back(0);
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// Get and set methods for coefficients.
void Polynomial::setCoefficients(int D, double C)
{
	Pol[D] = C;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// Returns the coefficient of a particular power.
double Polynomial::getCoefficient(int D)
{
	return Pol[D];
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// Returns the polynomial.
void Polynomial::getPolynomial()
{
	int D = degree;

	for (int i = 0; i <= D; i++)
	{
		if (Pol[i] != 0)
		{
			cout << fixed << setprecision(2) << Pol[i];
			if (i > 0)
			{
				cout << " * (x ^ " << i << ")";
			}
			if (i != D)
			{
				cout << " + ";
			}
		}
	}
	
	cout << endl;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// This will perform the polynomial addition.
void Polynomial::Addition(Polynomial P2)
{

	int D2 = P2.getDegree(); // Degree of the Second Polynomial.

	// For the case where the first polynomial has higher order or they are of the same order.
	if (degree > D2 || degree == D2)
	{
		for (int i = 0; i <= D2; i++)
		{
			Pol[i] += P2.getCoefficient(i);
		}
	}
	// For the case where if the order of the second polynomial is higher than the first.
	else if (degree < D2)
	{
		for (int i = 0; i <= degree; i++)
		{
			Pol[i] += P2.getCoefficient(i);
		}
		for (int i = degree + 1; i <= D2; i++)
		{
			Pol.push_back(P2.getCoefficient(i));

			degree = D2;
		}
	}
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// Since addition is commutative, c + p_n = p_n + c.
void Polynomial::Addition(double c)
{
	Pol[0] += c;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// This will subtract two polynomials.
void Polynomial::Subtraction(Polynomial P2)
{

	int D2 = P2.getDegree(); // Degree of the Second Polynomial.

							 // For the case where the first polynomial has higher order or they are of the same order.
	if (degree > D2 || degree == D2)
	{
		for (int i = 0; i <= D2; i++)
		{
			Pol[i] -= P2.getCoefficient(i);
		}
	}
	// For the case where if the order of the second polynomial is higher than the first.
	else if (degree < D2)
	{
		for (int i = 0; i <= degree; i++)
		{
			Pol[i] -= P2.getCoefficient(i);
		}
		for (int i = degree + 1; i <= D2; i++)
		{
			Pol.push_back((-1) * P2.getCoefficient(i));

			degree = D2;
		}
	}
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
// Subtraction by a constant.
void Polynomial::Subtraction(double c, bool boolean)
{
	// For the c - p_n.
	if (boolean)
	{
		Pol[0] = c - Pol[0];
	}
	// For the p_n - c.
	else
	{
		Pol[0] -= c;
		
		for (int i = 1; i <= degree; i++)
			Pol[i] *= -1;
	}
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//p_n * p_m.
void Polynomial::Product(Polynomial P2)
{
	int D2 = P2.getDegree();
	int D = degree + D2;

	vector<double> Product;

	for (int i = 0; i <= D; i++)
	{
		Product.push_back(0);
	}


	//for the case where one is the zero polynomial.
	if (degree == 0 || D2 == 0)
	{
		if (Pol[0] == 0 || P2.getCoefficient(0) == 0)
		{
			degree = 0;
			setCoefficients(0, 0);
		}
	}
	else
	{
		for (int i = 0; i <= D2; i++)
		{
			for (int j = 0; j <= degree; j++)
			{
				Product[j + i] += getCoefficient(j) * P2.getCoefficient(i);

			}
		}
	}

	for (int i = degree + 1; i <= D; i++)
	{
		Pol.push_back(0);
	}

	for (int i = 0; i <= D; i++)
	{
		Pol[i] = Product[i];
	}

	degree = D;
}
//*********************************************************************************************************************************************

//*********************************************************************************************************************************************
//Scalar Product.
//Note that multiplication is commutative.
void Polynomial::Product(double c)
{
	for (int i = 0; i <= degree; i++)
	{
		Pol[i] *= c;
	}
}
//*********************************************************************************************************************************************