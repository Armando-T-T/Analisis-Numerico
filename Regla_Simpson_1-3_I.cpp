#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
typedef vector<double> Vector;

double integracion_numerica(double h, const Vector& vectorFXi);

int main() {
    int n;
    double a, b;

    cout << setprecision(10);

    cout << "Ingrese la cantidad de intervalos (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "El n�mero de intervalos debe ser positivo." << endl;
        return 1;
    }

    cout << "Ingrese el l�mite superior (b): ";
    cin >> b;
    cout << "Ingrese el l�mite inferior (a): ";
    cin >> a;

    if (a >= b) {
        cout << "El l�mite inferior debe ser menor que el l�mite superior." << endl;
        return 1;
    }

    Vector vectorXi(n + 1, 0.0);
    Vector vectorFXi(n + 1, 0.0);

    cout << "Ingrese los pares ordenados de datos (x, f(x)):" << endl;
    for (int i = 0; i < n + 1; i++) {
        cout << "x" << i << ": ";
        cin >> vectorXi[i];
        cout << "f(x" << i << "): ";
        cin >> vectorFXi[i];
    }

    double h = (b - a) / n;

    double respuesta = integracion_numerica(h, vectorFXi);
    cout << "El resultado de la integraci�n es: " << respuesta << endl;

    return 0;
}

double integracion_numerica(double h, const Vector& vectorFXi) {
    double sumatoria_multiplos_3 = 0;
    double sumatoria_no_multiplos_3 = 0;
    int n = vectorFXi.size();

    for (int i = 1; i < n - 1; i++) {
        if (i % 3 == 0) {
            sumatoria_multiplos_3 += vectorFXi[i];
        }
        else {
            sumatoria_no_multiplos_3 += vectorFXi[i];
        }
    }

    double total = vectorFXi[0] + 3 * sumatoria_multiplos_3 + 2 * sumatoria_no_multiplos_3 + vectorFXi[n - 1];

    return (3 * h / 8) * total;
}
