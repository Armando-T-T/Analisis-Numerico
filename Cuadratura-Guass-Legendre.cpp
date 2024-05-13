#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef vector<double> Vector;

double funcion(double x);
double cuadratura_gauss_legendre(int puntos, double a, double b, Vector& fx_values, Vector& x_values);
double pesos_gauss_legendre(int puntos, double x);
double raices_gauss_legendre(int puntos, int i);
double map_range(double x, double min_in, double max_in, double min_out, double max_out);

int main() {
    double a, b;
    int puntos;

    cout << setprecision(10);

    cout << "Ingrese el limite inferior (a): ";
    cin >> a;
    cout << "Ingrese el limite superior (b): ";
    cin >> b;

    cout << "Seleccione el numero de puntos de la cuadratura de Gauss-Legendre (2, 3 , 4 o 5): ";
    cin >> puntos;

    if (puntos < 2 || puntos > 5) {
        cout << "El numero de puntos debe ser 2, 3 , 4 o 5." << endl;
        return 1;
    }

    Vector fx_values;
    Vector x_values;
    double resultado = cuadratura_gauss_legendre(puntos, a, b, fx_values, x_values);
    resultado *= (b - a) / 2;

    cout << "El resultado de la integracion es: " << resultado << endl << endl;

    cout << "Valores de la funcion en los puntos dados:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < fx_values.size(); ++i) {
        cout << "x" << i << " = " << x_values[i] << endl;
        cout << "f(x" << i << ") = " << fx_values[i] << endl;
    }

    cout << "\nRaices (z) y Pesos (w) para cuadratura de Gauss-Legendre:" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 1; i <= puntos; ++i) {
        cout << "z" << i << " = " << raices_gauss_legendre(puntos, i) << endl;
        cout << "w" << i << " = " << pesos_gauss_legendre(puntos, raices_gauss_legendre(puntos, i)) << endl;
    }

    return 0;
}

double funcion(double x) {
    return exp(pow(x, 2));
}

double cuadratura_gauss_legendre(int puntos, double a, double b, Vector& fx_values, Vector& x_values) {
    double sum = 0.0;
    for (int i = 1; i <= puntos; i++) {
        double xi = map_range(raices_gauss_legendre(puntos, i), -1, 1, a, b);
        x_values.push_back(xi);
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
    else if (puntos == 5) {
        if (x == 0) {
            w = 0.5688888888;
        }
        else if (x == 0.5384693101 || x == -0.5384693101) {
            w = 0.4786286705;
        }
        else {
            w = 0.2369268851;
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
    else if (puntos == 5) {
        if (i == 1) {
            x = 0;
        }
        else if (i == 2) {
            x = -0.5384693101;
        }
        else if (i == 3) {
            x = 0.5384693101;
        }
        else if (i == 4) {
            x = -0.9061798459;
        }
        else if (i == 5) {
            x = 0.9061798459;
        }
    }
    return x;
}

double map_range(double x, double min_in, double max_in, double min_out, double max_out) {
    return min_out + (max_out - min_out) * (x - min_in) / (max_in - min_in);
}
