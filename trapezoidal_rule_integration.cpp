#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float f(float x)
{
	return 1. / (x + 1);
}
int main() {
	float a, b, eps;
	int i;
	int n = 1;
	cout << "Introduceti a(capat stanga):";
	cin >> a;
	cout << "Introduceti b(capat dreapra):";
	cin >> b;
	cout << "Introduceti precizia(Epsioln):";
	cin >> eps;
	float integr, integr0, h, S;
	 integr = (f(a) + f(b)) * (b - a) / 2;
	do {
		n = 2 * n;
		h = (b - a) / n;
		 integr0 = integr;
		float S = 0;
		for (i = 1; i < n ; i++)
			S = S + f(a + i*h);
		integr = (f(a) + 2*S + f(b)) * h / 2;
	} while (fabs(integr - integr0) > eps);
	
	cout << "Valoarea integralei, optinuta cu prcizia " << eps << "este" << integr << "" << endl;
}
