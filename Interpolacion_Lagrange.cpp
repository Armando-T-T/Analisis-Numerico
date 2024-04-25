#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> Vector;

void Resolver_Lagrange(double x, const Vector& vectorX, Vector& vectorL);
double Solucion(const Vector& vectorY, const Vector& vectorL);

int main() {
    int tamano;
    cout << "Ingrese la cantidad de datos: ";
    cin >> tamano;

    Vector vectorX(tamano);
    Vector vectorY(tamano);
    Vector vectorL(tamano);

    for (int i = 0; i < tamano; ++i) {
        cout << "Ingrese el valor de x[" << i << "]: ";
        cin >> vectorX[i];
        cout << "Ingrese el valor de y[" << i << "]: ";
        cin >> vectorY[i];
    }

    double x;
    cout << "Ingrese el valor de X para interpolar: ";
    cin >> x;

    Resolver_Lagrange(x, vectorX, vectorL);
    double solucion = Solucion(vectorY, vectorL);

    cout << "Solucion: " << fixed << setprecision(10) << solucion << endl;

    return 0;
}

void Resolver_Lagrange(double x, const Vector& vectorX, Vector& vectorL) {
    int n = vectorX.size();
    for (int i = 0; i < n; i++) {
        double t1 = 1.0, t2 = 1.0, total = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                t1 *= (x - vectorX[j]);
                t2 *= (vectorX[i] - vectorX[j]);
            }
        }
        if (t2 != 0) {
            total = t1 / t2;
        }
        else {

            cerr << "Error." << endl;
            exit(1);
        }
        vectorL[i] = total;
    }
}

double Solucion(const Vector& vectorY, const Vector& vectorL) {
    double temporal = 0.0;
    int n = vectorY.size();
    for (int i = 0; i < n; i++) {
        temporal += vectorY[i] * vectorL[i];
    }
    return temporal;
}










