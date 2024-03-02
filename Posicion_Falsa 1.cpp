#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double a);
void posicionFalsa(double A, double B, double tolerancia);

int main() {
    double A = 0.0;
    double B = 1.0;

    cout << fixed << setprecision(4);
    cout << "A      B      R      F(a)   F(b)    F(R)    Error Relativo" << endl;

    posicionFalsa(A, B, 0.001);  // Tolerancia del 0.1%

    return 0;
}

double funcion(double a) {
    return exp(-a) - a;
}

void posicionFalsa(double A, double B, double tolerancia) {
    double Fa = funcion(A);
    double Fb = funcion(B);
    double R = B - (Fb * (B - A)) / (Fb - Fa);
    double FR = funcion(R);
    double Error_Relativo = 0;

    cout << A << " " << B << " " << R << " " << Fa << " " << Fb << " " << FR << " " << Error_Relativo << endl;

    do {
        if (Fa * FR < 0)
            B = R;
        else
            A = R;

        Fa = funcion(A);
        Fb = funcion(B);

        double R_anterior = R;
        R = B - (Fb * (B - A)) / (Fb - Fa);
        FR = funcion(R);

        Error_Relativo = (abs(R - R_anterior) / abs(R)) * 100;

        cout << A << " " << B << " " << R << " " << Fa << " " << Fb << " " << FR << " " << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}