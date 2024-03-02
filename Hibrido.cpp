#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double funcion(double x);
double funcionDerivada(double x);
void Hibrido(double A, double B, double tolerancia);

int main() {
    double A = 0.0;
    double B = 1.0;

    cout << fixed << setprecision(9);
    cout << setw(10) << "A" << setw(10) << "B" << setw(10) << "Xi" << setw(15) << "f(xi)" << setw(15) << "f'(xi)" << setw(15) << "Xi+1" << setw(18) << "Error Relativo" << endl;

    Hibrido(A, B, 0.00000001);  // Tolerancia del 0.1

    return 0;
}

double funcion(double x) {
    return atan(x)-cos(x);
}

double funcionDerivada(double x) {
    return (1/(1+pow(x,2))+sin(x);
}

void Hibrido(double A, double B, double tolerancia) {
    double R = A;
    double Error_Relativo = 0;
    double F = 0, F2 = 0;
    double R_anterior = 0;

    do {
        F = funcion(R);
        F2 = funcionDerivada(R);

        R_anterior = R;
        R = R_anterior - (F / F2);

        if (R >= A && R <= B) {
            // Actualizar límites
            if (funcion(A) * funcion(R) < 0)
                B = R;
            else
                A = R;
        }
        else {
            // Actualizar límites usando bisección
            R = (A + B) / 2.0;
            if (funcion(A) * funcion(R) < 0)
                B = R;
            else
                A = R;
        }

        // Calcular error relativo y mostrar resultados
        Error_Relativo = (abs(R - R_anterior) / abs(R)) * 100;
        cout << setw(10) << A << setw(14) << B << setw(13) << R_anterior << setw(15) << F << setw(15) << F2 << setw(15) << R << setw(18) << Error_Relativo << endl;

    } while (Error_Relativo > tolerancia);
}