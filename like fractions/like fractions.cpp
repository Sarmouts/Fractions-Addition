#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double LCM(double a, double b)
{
	if (a / b == round(a / b) || b / a == round(b / a))
	{
		return fmax(a, b);
	}
	else if (a / 2 == round(a / 2) && b / 2 == round(b / 2))
	{
		return a * b / 2;
	}
	else
	{
		return a * b;
	}
}
string simplification(double num, double den)
{
	if (num / den == round(num / den))
	{
		return to_string(static_cast<int>(num / den));
	}
	else if (num != round(num) || den != round(den))
	{
		return to_string(num / den) + "(~" + to_string(round(num / den)) + ")";
	}
	else
	{
		double MKD;
		int x = num;
		int y = den;
		for (int i = 0; i >= 0; i++)
		{
			if (x == 0)
			{
				MKD = abs(y);
				break;
			}
			else if (y == 0)
			{
				MKD = abs(x);
				break;
			}
			else if (abs(x) > abs(y))
			{
				x %= abs(y);
			}
			else if (abs(x) < abs(y))
			{
				y %= abs(x);
			}
		}
		if (num < 0 && den < 0) return to_string(static_cast<int>(-num / MKD)) + "/" + to_string(static_cast<int>(-den / MKD));
		else if (num > 0 && den > 0) return to_string(static_cast<int>(num / MKD)) + "/" + to_string(static_cast<int>(den / MKD));
		else return "-" + to_string(static_cast<int>(abs(num) / MKD)) + "/" + to_string(static_cast<int>(abs(den) / MKD));
	}
}
string likeFraction(double x, double y, double a, double b)
{
	double lcm, kapelaki1, kapelaki2;
	lcm = LCM(abs(y), abs(b));
	kapelaki1 = lcm / abs(y);
	kapelaki2 = lcm / abs(b);
	x *= kapelaki1;
	y *= kapelaki1;
	a *= kapelaki2;
	b *= kapelaki2;
	if (y < 0 && b < 0)
	{
		return simplification(-x - a, abs(y));
	}
	else if (b < 0)
	{
		return simplification(x - a, abs(y));
	}
	else if (y < 0)
	{
		return simplification(-x + a, abs(y));
	}
	else
	{
		return simplification(x + a, abs(y));
	}
}
int main()
{
	cout << "Welcome to Fraction Addition calculator" << endl;
	cout << "---------------------------------------" << endl;
	while (true)
	{
		double x, y, a, b;
		cout << "x/y + a/b" << endl;
		cout << "---------" << endl;
		cout << "Enter numerator x: ";
		cin >> x;
		cout << "Enter denoverator y: ";
		cin >> y;
		cout << "Enter numerator a: ";
		cin >> a;
		cout << "Enter denoverator b: ";
		cin >> b;
		if (x != round(x) || y != round(y) || a != round(a) || b != round(b))
		{
			cout << "All values must be integers" << endl;
			cout << "======================================" << endl;
		}
		else
		{
			cout << likeFraction(x, y, a, b) << endl;
			cout << "======================================" << endl;
		}
	}
}

