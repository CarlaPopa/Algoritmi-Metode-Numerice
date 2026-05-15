#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    double z, L = 0;
    float N, p, s;


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

    N = f[0];
    for (int k = 1; k <= n; k++) {
        double s = 0;
        for (int j = 0; j <= k; j++) {
            p = 1;
            for (int i = 0; i <= k; i++) {
           
                if (i != j) {
                   
                    p = p * (x[j] - x[i]);
                }
            }
     
            s = s + f[j] / p;
        }
        double p = 1;

 
        for (int i = 0; i <= k - 1; i++) {
  
            p = p * (z - x[i]);
        }

        N = N + s * p;
    }


    cout << "Valoarea aproximativa a functiei f in " << z << " este " << N << endl;

    return 0;
}
