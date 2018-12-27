/*
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
				if (abs(a) > 0) { a *= 60; }
				int c = a;
				a -= c;
				if (abs(a) > 0) { a *= 60; }
				cout << b << "d " << abs(c) << "' " << abs(a) << "\" ";
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
	if (degree < 0)
	{
		return -(abs(degree) + (minutes / 60.0) + (seconds / 3600));
	}
	return (degree + (minutes/60.0) + (seconds / 3600));
}

double toDecimalDegree(int degree, double minutes)
{
	if (degree < 0)
	{
		return -(abs(degree) + (minutes / 60));
	}
	return (degree + (minutes/60));
}