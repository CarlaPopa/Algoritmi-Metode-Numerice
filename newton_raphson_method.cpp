#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
float f(float x) {
	return pow(x, 3) + 4 * x * x - 10;
}
	float df(float x) {
		return 3*pow(x, 2) + 8 * x;
	}


int main(){
	float  x[1001], eps, dif;
	int it, itmax ;
	it = 0;
	cout << "Introduceti x0=" << endl;
	cin >> x[0];
	cout << "Introduceti epsilon=" << endl;
	cin >> eps;
	cout << "Introduceti numarul maxim de iteratii(itmax)=" << endl;
	cin >> itmax;
	do {
		x[1] = x[0] - (f(x[0]) / df(x[0]));
		dif = fabs(x[1] - x[0]);
		x[0] = x[1];
		it++;
	} while (dif > eps && it <= itmax);
	if (it>itmax){
		cout << "Nu se poate obtine solutia in " << it << " iteratii cu precizia " << eps;
		return 0;
	}
	cout << "Solutia obtinua in " << it << " iteratii cu precizia " << eps << " este " << x[1];
}
