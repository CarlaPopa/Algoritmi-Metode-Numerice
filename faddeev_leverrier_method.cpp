#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    float a[100][100], b[100][100], d[100][100], c[101];
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = 0;
            }
        }
    }
    for (int k = 1; k <= n - 1; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = 0; 
                for (int h = 1; h <= n; h++) {
                    d[i][j] = d[i][j] + a[i][h] * b[h][j]; 
                }
            }
        }
        c[k] = 0; 
        for (int i = 1; i <= n; i++) {
            c[k] = c[k] + d[i][i]; 
        }
        c[k] = -c[k] / k; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    b[i][j] = d[i][j] + c[k]; 
                }
                else {
                    b[i][j] = d[i][j]; 
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = 0;
            for (int h = 1; h <= n; h++) {
                d[i][j] = d[i][j] + a[i][h] * b[h][j];
            }
        }
    }
    c[n] = 0; 
    for (int i = 1; i <= n; i++) {
        c[n] = c[n] + d[i][i]; 
    }
    c[n] = -c[n] / n; 
    if (c[n] == 0) {
        cout << "Matricea nu este inversabila" << endl; 
    }
    else {
        cout << "Matricea inversabila este:" << endl; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << setw(10) << -b[i][j] / c[n] << " ";
            }
            cout << endl;
        }
    }
    cout << "\nCoeficientii polinomului caracteristic sunt: ";
    for (int i = 1; i <= n; i++) {
        cout << "c" << i << "=" << c[i] << (i < n ? ", " : "");
    }
    cout << endl;

    return 0;
}
