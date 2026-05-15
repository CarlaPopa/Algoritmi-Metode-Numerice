#include <iostream>
#include <cmath>	
using namespace std;
float f(float x, float y) {
	return 2*y/x;
}
int main() {
	int n, i;
	float xi[100], yi[100];
	float y0, e;
	float X, Y, xx, yy, h, aux;
	cout << "n=";
	cin >> n;
	cout << "Introdux0...xn:";
	for (i = 0; i <= n; i++) {
		cin >> xi[i];
	}
		cout << "y0=";
		cin >> y0;
		cout << "Epsilon=";
		cin >> e;
		yi[0] = y0;
		i = 0;
		do{X=xi[i];
			xx = xi[i + 1];
			Y = yi[i];
			h = xx - X;
			yy = Y + h * f(X, Y);
			do {
				h = h / 2;
				aux = yy;
		
			}while(fabs(yy - aux) > e);
			yi[i + 1] = yy;
			cout << "Valoarea aproximartiva a lui y(" << xx << ") este " << yy << endl;
			i = i + 1;
			}
		while (i < n);
		return 0;
	}
