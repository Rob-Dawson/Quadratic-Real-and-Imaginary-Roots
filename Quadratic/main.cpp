#include <iostream>
#include <string>
#include <cmath>
#include <complex>
using namespace std;

/*
* Calculates the roots for a quadratic equation
* No account is taken of floating point overflows
*/



//Exercise 1
void quadratic(double a, double b, double c, double &root1, double &root2)
{
	const double zero = 1e-8;

	double operand = b * b - 4.0*a*c;
	if (operand > zero)
	{
		double squareRoot = sqrt(operand);
		double denominator = 2.0*a;

		if (fabs(denominator) <= zero)
		{
			cout << "Divide by Zero Error\n";
		}
		else
		{
			double root1 = (-b + squareRoot) / denominator;
			double root2 = (-b - squareRoot) / denominator;

			cout << "The roots of the equation "
				<< a << "x^2 + " << b << "x + " << c << "\n"
				<< "are " << root1 << " and " << root2 << endl;
		}
	}
	else if (operand == zero)
	{
		//double squareRoot = sqrt(operand); //Dont need this as square root is 0
		double denominator = 2.0*a;

		if (fabs(denominator) <= zero)
		{
			cout << "Divide by Zero Error\n";
		}
		else
		{
			root1 = b / denominator;

			cout << "The root of the equation "
				<< a << "x^2 + " << b << "x + " << c << "\n"
				<< "are " << root1;
		}
	}
	
	else
	{
		cout << "Imaginary Roots\n";
		double denominator = 2.0*a;
		double squareRoot = sqrt(fabs(operand));

		if (fabs(denominator) <= zero)
		{
			cout << "Divide by Zero Error\n";
		}
		complex<double> root1( -b / denominator, squareRoot);
		complex<double> root2 (-b / denominator, -squareRoot);
		cout << "Complex Root 1 " << root1 << " Complex Root2 " << root2 << "\n";
	}
}

//Excercise 2
/*void quadratic(double a, double b, double c, double &root1, double &root2)
{
	cout << "The roots of the equation "
		<< a << "x^2 + " << b << "x + " << c << "\n"
		<< "are " << root1 << " and " << root2 << endl;
}*/

void main (int argc, char **argv) {
	cout << "Enter the coefficiants for a quadratic equation" << endl;
	double a, b, c, root1, root2;
	cin >> a >> b >> c;

	quadratic(a, b, c, root1, root2); //Exercise 1 
	
	//Excercise 2
	//double operand = b * b - 4.0*a*c;
	//double root1 = (-b + sqrt(operand)) / (2.0 * a);
	//double root2 = (-b - sqrt(operand)) / (2.0 * a);
	//
	//quadratic(a, b, c, root1, root2);
	int keypress; cin >> keypress;
}