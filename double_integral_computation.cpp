#include <iostream>
#include <cmath>
using namespace std;
double f(double x, double y) {
	return sqrt(3 * x * y + 2);
}
int main() {
	double x1, y1, x2, y2, x3, y3;
	double l1, l2, l3, p, S, I;
	cout << "Introdu x1 y1 x2 y2 x3 y3: ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	l1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	l2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	l3 = sqrt(pow(x3 - x1, 2) + pow(y2 - y1, 2));
	p = (l1 + l2 + l3) / 2;
	S = sqrt(p * (p - l1) * (p - l2) * (p - l3));
	I = S / 12 * (f(x1, y1) + f(x2, y2) + f(x3, y3)+9*f((x1+x2+x3)/3, (y1+y2+y3)/3));
	cout << "Valorea integralei este: " << I;
	return 0;
}
