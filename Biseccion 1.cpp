#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double a);
void biseccion(double A, double B, double tolerancia);

int main() {
    double A = 0.0;
    double B = 1.0;

    cout << fixed << setprecision(4);
    cout << "A      B      R      F(a)   F(b)    F(R)  Error Relativo" << endl;

    biseccion(A, B, 0.001);  /

    return 0;
}

double funcion(double a) {
    return exp(-a) - a;
}

void biseccion(double A, double B, double tolerancia) {
    double R = (A + B) / 2.0;
    double anterior = funcion(R); 
    double Error_Relativo = 0;

    cout << A << " " << B << " " << R << " " << funcion(A) << " " << funcion(B) << " " << funcion(R) << " " << Error_Relativo << endl;

    do {

        if (funcion(A) * funcion(R) < 0)
            B = R;
        else
            A = R;

        anterior = R;

        R = (A + B) / 2.0;

        Error_Relativo = (abs(R - anterior) / R) * 100;

        cout << A << " " << B << " " << R << " " << funcion(A) << " " << funcion(B) << " " << funcion(R) << " " << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}
