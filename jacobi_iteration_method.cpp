#include <iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;
int main() {
    int n, itmax;
    double eps;

    cout << "n = ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n), x(n), y(n);

    cout << "Introdu matricea A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "Introdu vectorul b:\n";
    for (int i = 0; i < n; i++) {
        cout << "b[" << i + 1 << "] = ";
        cin >> b[i];
    }

    cout << "Introdu aproximatia initiala x:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = ";
        cin >> x[i];
    }

    cout << "eps = ";
    cin >> eps;

    cout << "itmax = ";
    cin >> itmax;

    for (int i = 0; i < n; i++) {
        if (a[i][i] == 0) {
            cout << "Eroare: element diagonal nul la a[" << i + 1 << "][" << i + 1 << "].\n";
            return 1;
        }
    }

    int it = 0;
    double maxim;

    do {
        maxim = 0.0;

        for (int i = 0; i < n; i++) {
            double S = 0.0, S2;
            for (int j = i + 1; i < n; i++) {
                S2 = a[i][j] * x[j];
            }
            for (int j = 0; j < i - 1; j++) 

                S = S + a[i][j] * y[j];

                for (int j = i + 1; j < n; j++) {
                    S += a[i][j] * x[j];

                }

                y[i] = (b[i] - S) / a[i][i];

                if (maxim < fabs(y[i] - x[i])) {
                    maxim = fabs(y[i] - x[i]);
                }
            }

            for (int i = 0; i < n; i++) {
                x[i] = y[i];
            }

            it = it + 1;

        } while ((maxim > eps) && (it < itmax));

        if (it > itmax) {
            cout << "Nu se poate obtine solutia in " << itmax
                << " iteratii, cu precizia " << eps << ".\n";
            return 0;
        }

        cout << fixed << setprecision(10);
        cout << "Solutia obtinuta in " << it
            << " iteratii cu precizia " << eps << " este:\n";

        for (int i = 0; i < n; i++) {
            cout << "x[" << i + 1 << "] = " << x[i] << "\n";
        }

        return 0;
    }
