#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Vector; 

double calcularPromedio(const Vector& valores) {
    double suma = 0.0;
    for (double valor : valores) {
        suma += valor;
    }
    return suma / valores.size();
}

void calcularRegresionLineal(const Vector& x, const Vector& y, double& a, double& b) {
    
    // Calculando promedios
    double promedioX = calcularPromedio(x);
    double promedioY = calcularPromedio(y);

    // Calculando sumatorias
    double sumaXY = 0.0;
    double sumaXcuadrado = 0.0;
    for (int i = 0; i < x.size(); ++i) {
        sumaXY += x[i] * y[i];
        sumaXcuadrado += x[i] * x[i];
    }

    b = (sumaXY - x.size() * promedioX * promedioY) / (sumaXcuadrado - x.size() * promedioX * promedioX);
    a = promedioY - b * promedioX;
}

int main() {
    int cantidadValores;
    cout << "Ingrese la cantidad de valores: ";
    cin >> cantidadValores;

    Vector valoresX(cantidadValores);
    Vector valoresY(cantidadValores);


    cout << "Ingrese los valores de X:\n";
    for (int i = 0; i < cantidadValores; ++i) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valoresX[i];
    }

    cout << "Ingrese los valores de Y:\n";
    for (int i = 0; i < cantidadValores; ++i) {
        cout << "Valor " << i + 1 << ": ";
        cin >> valoresY[i];
    }

    double a, b;
    calcularRegresionLineal(valoresX, valoresY, a, b);

    cout << "La ecuacion de regresion lineal es: Y = " << a << " + " << b << " * X\n";

    return 0;
}