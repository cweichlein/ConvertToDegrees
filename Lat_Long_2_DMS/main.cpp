/*
	Convert the other two of the three main systems to decimal degrees.
	The three systems are DMS, decimal degrees, and Tim believes something called "nautical," but he's not sure if thats
	the name of the third system or another term for DMS or decimal degrees.
	So figure out the three systems, and re-write this code so that it will convert all data entered to decimal degrees.
	IDEA: Use overloaded functions!
	Upload this cpp file to a repo Robert will create.
	Thingiverse.com
	Use the orange 3d printer for experimenting.
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

double toDecimalDegree(int degree, int minutes, double seconds);//DMS to decimal
double toDecimalDegree(int degree, double minutes);//Degree decimal minutes to decimal 

int main()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "Input choice: " << endl;
		cout << "1: Convert Degree to DMS." << endl;
		cout << "2: Convert DMS to decimal degree." << endl;
		cout << "3: Convert Degree Decimal Minutes to decimal degree." << endl;
		cout << "4: Quit." << endl;
		cin >> choice;
		if (choice != 4)
		{
			double a;
			if (choice == 1)
			{
				cout << "Input coordinate: ";
				cin >> a;
				int b = a;
				a -= b;
				if (a > 0) { a *= 60; }
				int c = a;
				a -= c;
				if (a > 0) { a *= 60; }
				cout << b << "d " << c << "' " << a << "\" ";
				cout << endl;
			}
			else if (choice == 2)
			{
				cout << "Input DMS (numbers seperated by space): ";
				double a;
				double b;
				double c;
				cin >> a;
				cin >> b;
				cin >> c;
				cout << "In decimal: " << fixed << setprecision(10) << right << toDecimalDegree(a, b, c) << endl;
			}
			else if (choice == 3)
			{
				cout << "Input dsegree decimal minutes (numbers seperated by space): ";
				int a;
				double b;
				cin >> a;
				cin >> b;
				cout << "In decimal: " << fixed << setprecision(10) << right << toDecimalDegree(a, b) << endl;
			}
			else
			{
				cout << "ERROR: invalid choice." << endl;
			}
		}
	}
	cout << "Goodbye!" << endl;

	cout << endl;
	system("Pause");
	return 0;
}

double toDecimalDegree(int degree, int minutes, double seconds)
{
	return (degree + (minutes/60.0) + (seconds / 3600));
}

double toDecimalDegree(int degree, double minutes)
{
	return (degree + (minutes/60));
}