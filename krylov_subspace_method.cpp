#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    float a[100][100], y[100][101];
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    cout << "Introduceti vectorul initial y^(0) (coloana n):\n";
    for (int i = 1; i <= n; i++) {
        cout << "y[" << i << "][" << n << "]= ";
        cin >> y[i][n];
    }
    for (int j = n - 1; j >= 1; j--) {
        for (int i = 1; i <= n; i++) {
            y[i][j] = 0; // 3.1.1
            for (int k = 1; k <= n; k++) {
                y[i][j] += a[i][k] * y[k][j + 1]; // 3.1.2.1
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        y[i][n + 1] = 0; // 4.1
        for (int k = 1; k <= n; k++) {
            y[i][n + 1] += a[i][k] * y[k][1]; // 4.2.1
        }
        y[i][n + 1] = -y[i][n + 1]; 
    }

    for (int i = 1; i <= n; i++) {
        int pivot_row = i;
        for (int k = i + 1; k <= n; k++) {
            if (abs(y[k][i]) > abs(y[pivot_row][i])) {
                pivot_row = k;
            }
        }
        for (int j = 1; j <= n + 1; j++) {
            swap(y[i][j], y[pivot_row][j]);
        }

        if (abs(y[i][i]) < 1e-6) {
            cout << "\nSistemul nu are solutie unica. Alegeti alt y^(0) conform observatiei i)." << endl;
            return 0;
        }
        for (int k = i + 1; k <= n; k++) {
            float factor = y[k][i] / y[i][i];
            for (int j = i; j <= n + 1; j++) {
                y[k][j] -= factor * y[i][j];
            }
        }
    }
    float c[100];
    for (int i = n; i >= 1; i--) {
        float suma = 0;
        for (int j = i + 1; j <= n; j++) {
            suma += y[i][j] * c[j];
        }
        c[i] = (y[i][n + 1] - suma) / y[i][i];
    }
    cout << "\nCoeficientii polinomului caracteristic (c1, c2, ..., cn) sunt:\n";
    cout << fixed << setprecision(4);
    for (int i = 1; i <= n; i++) {
        cout << "c" << i << " = " << c[i] << endl;
    }

    return 0;
}
