#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef vector<double> Vector;

double funcion(double x);
double cuadratura_gauss_legendre(int puntos, double a, double b, Vector& fx_values);
double pesos_gauss_legendre(int puntos, double x);
double raices_gauss_legendre(int puntos, int i);
double map_range(double x, double min_in, double max_in, double min_out, double max_out);

int main() {
    double a, b;
    int puntos;

    cout << setprecision(10);

    cout << "Ingrese el límite inferior (a): ";
    cin >> a;
    cout << "Ingrese el límite superior (b): ";
    cin >> b;

    cout << "Seleccione el número de puntos de la cuadratura de Gauss-Legendre (2, 3 o 4): ";
    cin >> puntos;

    if (puntos < 2 || puntos > 4) {
        cout << "El número de puntos debe ser 2, 3 o 4." << endl;
        return 1;
    }

    Vector fx_values;
    double resultado = cuadratura_gauss_legendre(puntos, a, b, fx_values);

    cout << "El resultado de la integración es: " << resultado << endl;

    cout << "Valores de la función en los puntos dados:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < fx_values.size(); ++i) {
        cout << "f(x" << i << ") = " << fx_values[i] << endl;
    }

    return 0;
}

double funcion(double x) {
    return cos(pow(x, 2));
}

double cuadratura_gauss_legendre(int puntos, double a, double b, Vector& fx_values) {
    double sum = 0.0;
    for (int i = 1; i <= puntos; i++) {
        double xi = map_range(raices_gauss_legendre(puntos, i), -1, 1, a, b);
        double fi = funcion(xi);
        fx_values.push_back(fi);
        double wi = pesos_gauss_legendre(puntos, xi);
        sum += wi * fi;
    }
    return sum;
}

double pesos_gauss_legendre(int puntos, double x) {
    double w = 0.0;
    if (puntos == 2) {
        w = 1.0;
    }
    else if (puntos == 3) {
        w = 0.5;
    }
    else if (puntos == 4) {
        if (x != 0) {
            w = 0.652145;
        }
        else {
            w = 0.347855;
        }
    }
    return w;
}

double raices_gauss_legendre(int puntos, int i) {
    double x = 0.0;
    if (puntos == 2) {
        if (i == 1) {
            x = -0.577350269;
        }
        else if (i == 2) {
            x = 0.577350269;
        }
    }
    else if (puntos == 3) {
        if (i == 1) {
            x = -0.774596669;
        }
        else if (i == 2) {
            x = 0.0;
        }
        else if (i == 3) {
            x = 0.774596669;
        }
    }
    else if (puntos == 4) {
        if (i == 1) {
            x = -0.861136312;
        }
        else if (i == 2) {
            x = -0.339981044;
        }
        else if (i == 3) {
            x = 0.339981044;
        }
        else if (i == 4) {
            x = 0.861136312;
        }
    }
    return x;
}

double map_range(double x, double min_in, double max_in, double min_out, double max_out) {
    return min_out + (max_out - min_out) * (x - min_in) / (max_in - min_in);
}