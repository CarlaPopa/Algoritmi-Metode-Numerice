#include <iostream>
using namespace std;
int main() {
	//Citim n, dimensiunea matricei A si matricea extinsa (A|b)
	int n, i, j, k;
	cout << "Introduceti dimenisunea n:";
	cin >> n;
	double a[101][102];
	cout << "Introduceti elementele matricei extinse(n linii/n+1 coloane):" << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n + 1; j++) {
			cout << "a[" << i << "][" << j << "]=";
			cin >> a[i][j];
		}}
	for (k = 1; k <= n - 1; k++) {
		//Gestionare pivot nul
		if (a[k][k] == 0) {
			int lin = k;
			do {
				lin = lin + 1;
			} while (lin <= n && a[lin][k] == 0);
			if (lin > n) {
				cout << "Sistemul nu are solutie unica" << endl;
				return 0;
			}
			else {
				for (j = k; j <= n + 1; j++) {
					double aux = a[k][j];
					a[k][j] = a[lin][j];
					a[lin][j] = aux;
				}}}
		//Aplicam regula dreptunghiului
		for (i = k + 1; i <= n; i++) {
			for (j = k + 1; j <= n + 1; j++) {
				a[i][j] = a[i][j] - a[i][k] / a[k][k] * a[k][j];
			}
			a[i][k] = 0.0;
		}}
	//Verificare pivot n
	if (a[n][n] == 0) {
		cout << "Sistemul nu are solutie unica!" << endl;
		return 0;
	}
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	for (i = n - 1; i >= 1; i--) {
		double s = 0;
		for (j = i + 1; j <= n; j++) {
			s = s + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = (a[i][n + 1] - s) / a[i][i];
	}
	for (i = 1; i<= n; i++) {
		cout << "x" << i << '=' << a[i][n + 1] << endl;
	}
	return 0;
}
