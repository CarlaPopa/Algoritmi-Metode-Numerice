#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, itmax, it;
    double eps, S, max_diff, x_vechi;

    cout << "n = "; cin >> n;

    vector<vector<double>> a(n + 1, vector<double>(n + 1));
    vector<double> b(n + 1), x(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "] = "; cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << "b[" << i << "] = "; cin >> b[i];
    }
    cout << "epsilon = "; cin >> eps;
    cout << "itmax = "; cin >> itmax;
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = "; cin >> x[i];
    }

    it = 0;
    do {
        max_diff = 0; 

        for (int i = 1; i <= n; i++) {
            S = 0;
            for (int j = 1; j <= n; j++) {
                if (j != i) {
                   
                    S = S + a[i][j] * x[j];
                }
            }

            x_vechi = x[i]; 
            x[i] = (b[i] - S) / a[i][i];

            if (max_diff < abs(x[i] - x_vechi)) {
                max_diff = abs(x[i] - x_vechi);
            }
        }

        it++;

    } while (max_diff > eps && it <= itmax);

    if (it > itmax) {
        cout << "Nu converge" << endl;
    }
    else {
        cout << fixed << setprecision(6);
        cout << "Solutie gasita in " << it << " iteratii:" << endl;
        for (int i = 1; i <= n; i++) cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
