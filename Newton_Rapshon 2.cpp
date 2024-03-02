#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double x);
double funcionDerivada(double x);
void Newton_Raphson(double A, double tolerancia);

int main() {
    double A = 0.0;  // Intervalo inferior

    cout << fixed << setprecision(9);
    cout << "Xi           f(xi)       f'(xi)       Xi+1         Error Relativo" << endl;

    Newton_Raphson(A, 0);  // Tolerancia del 0.1

    return 0;
}

double funcion(double x) {
    return exp(-x) - x;
}

double funcionDerivada(double x) {
    return -((1 + exp(x)) / exp(x));
}

void Newton_Raphson(double A, double tolerancia) {
    double R = A;
    double Error_Relativo = 0;
    double F = 0, F2 = 0;
    double R_anterior = 0;

    do {
        F = funcion(R);
        F2 = funcionDerivada(R);

        R_anterior = R;
        R = R_anterior - (F / F2);

        Error_Relativo = (abs(R - R_anterior) / abs(R)) * 100;

        cout << setw(10) << R_anterior << setw(13) << F << setw(13) << F2 << setw(12) << R << setw(15) << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}