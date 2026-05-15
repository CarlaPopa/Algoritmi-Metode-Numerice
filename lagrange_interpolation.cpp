#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    double z, L = 0;

 
    cout << "Introduceti n : ";
    cin >> n;

    vector<double> x(n + 1);
    vector<double> f(n + 1);

    cout << "Introduceti valorile nodurilor x_i:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }

    cout << "Introduceti valorile functiei f_i:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "f[" << i << "] = ";
        cin >> f[i];
    }

    cout << "Introduceti punctul z in care doriti aproximarea: ";
    cin >> z;

    L = 0;

    for (int k = 0; k <= n; k++) {
       
        double P = 1;

        for (int i = 0; i <= n; i++) {
           
            if (i != k) {
               
                P = P * (z - x[i]) / (x[k] - x[i]);
            }
        }
        
        L = L + f[k] * P;
    }

    cout << "Valoarea aproximativa a functiei f in " << z << " este " << L << endl;

    return 0;
}
