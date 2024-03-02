#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double x);
void biseccion(double A, double B, double tolerancia);

int main() {
    double A = 1.0;  // Intervalo inferior
    double B = 2.0;   // Intervalo superior

    cout << fixed << setprecision(4);
    cout << "A      B      R      F(a)       F(b)       F(R)       Error Relativo" << endl;

    biseccion(A, B, 0.01);  // Tolerancia del 0.1

    return 0;
}

double funcion(double x) {
    return pow(x, 2) - cos(x) - 1;
}

void biseccion(double A, double B, double tolerancia) {
    double R = (A + B) / 2.0;
    double Error_Relativo = 0;

    cout << A << " " << B << " " << R << " " << funcion(A) << " " << funcion(B) << " " << funcion(R) << " " << Error_Relativo << endl;

    do {


        if (funcion(A) * funcion(R) < 0)
            B = R;
        else
            A = R;

        double R_anterior = R;
        R = (A + B) / 2.0;

        Error_Relativo = (abs(R - R_anterior) / abs(R)) * 100;

        cout << A << " " << B << " " << R << " " << funcion(A) << " " << funcion(B) << " " << funcion(R) << " " << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}
