#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int NMAX = 100;
int main() {
    int n;
    cout << "n= ";
    if (!(cin >> n) || n <= 0 || n > NMAX) return 0;

    static double a[NMAX+1][NMAX+2];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
    for (int k = 1; k <= n - 1; ++k) {
        int piv = k;
        double maxv = fabs(a[k][k]);
        for (int i = k + 1; i <= n; ++i) {
            double v = fabs(a[i][k]);
            if (v > maxv) { maxv = v; piv = i; }
        }
        if (fabs(a[piv][k]) < 1e-12) {
            cout << "Sistemul nu are solutie unica\n";
            return 0;
        }
        if (piv != k) {
            for (int j = k; j <= n + 1; ++j) {
                double aux = a[k][j];
                a[k][j] = a[piv][j];
                a[piv][j] = aux;
            }
        }
        for (int i = k + 1; i <= n; ++i) {
            double factor = a[i][k] / a[k][k];
            a[i][k] = 0.0;
            for (int j = k + 1; j <= n + 1; ++j) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    if (fabs(a[n][n]) < 1e-12) {
        cout << "Sistemul nu are solutie unica\n";
        return 0;
    }
    double x[NMAX+1];
    x[n] = a[n][n+1] / a[n][n];
    for (int i = n - 1; i >= 1; --i) {
        double S = 0.0;
        for (int j = i + 1; j <= n; ++j) S += a[i][j] * x[j];
        x[i] = (a[i][n+1] - S) / a[i][i];
    }

    for (int i = 1; i <= n; ++i) {
        cout << "x[" << i << "]=" << setprecision(4) << fixed << x[i] << endl;
    }
    return 0;
}
