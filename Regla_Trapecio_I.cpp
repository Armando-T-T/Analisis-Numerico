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
        cout << "El numero de intervalos debe ser positivo." << endl;
        return 1;
    }

    cout << "Ingrese el limite superior (b): ";
    cin >> b;
    cout << "Ingrese el limite inferior (a): ";
    cin >> a;

    if (a >= b) {
        cout << "El límite inferior debe ser menor que el límite superior." << endl;
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
    cout << "El resultado de la integracion es: " << respuesta << endl;

    return 0;
}

double integracion_numerica(double h, const Vector& vectorFXi) {
    double sumatoria = 0;
    int n = vectorFXi.size();

    for (int i = 1; i < n - 1; i++) {
        sumatoria += vectorFXi[i];
    }

    sumatoria *= 2;

    double total = vectorFXi[0] + sumatoria + vectorFXi[n - 1];

    return (h / 2) * total;
}
