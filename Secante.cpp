#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double x);
void Secante(double A, double S, double tolerancia);

int main() {
    double A = 0.0;  // Intervalo inferior
    double S = 1.0;

    cout << fixed << setprecision(9);
    cout << setw(10) << "Xi-1" << setw(15) << "Xi" << setw(15) << "Xi+1" << setw(15) << "Error Relativo" << endl;

    Secante(A, S, 0.1);  // Tolerancia del 0.1

    return 0;
}

double funcion(double x) {
    return pow(x,2)-x-1;
}

void Secante(double A, double S, double tolerancia) {
    double R = 0, R_anterior = 0, R_siguiente = 0;
    double Error_Relativo = 0;

    R_anterior = A;
    R = S;
    R_siguiente = R - ((funcion(R) * (R_anterior - R)) / (funcion(R_anterior) - funcion(R)));

    cout << setw(10) << R_anterior << setw(15) << R << setw(15) << R_siguiente << setw(15) << Error_Relativo << endl;

    do {
        R_anterior = R;
        R = R_siguiente;
        R_siguiente = R - ((funcion(R) * (R_anterior - R)) / (funcion(R_anterior) - funcion(R)));

        Error_Relativo = (abs(R_siguiente - R) / abs(R_siguiente)) * 100;

        cout << setw(10) << R_anterior << setw(15) << R << setw(15) << R_siguiente << setw(15) << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}