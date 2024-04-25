#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<double> Vector;
typedef vector<vector<double>> Matriz;

void Resolver_Newton(Matriz& matriz, Vector& vector);
double Solucion(Vector& vector, Vector& vectorX);
void imprimirMatriz(Matriz& matriz);
void imprimirVector(Vector& vector);


int main() {
    int tamano;
    cout << "Ingrese la cantidad de datos: ";
    cin >> tamano;

    Matriz matriz(tamano, vector<double>(tamano, 0.0));
    Vector vector(tamano);
    Vector vectorX(tamano);

    for (int i = 0; i < tamano; ++i) {
        cout << "Ingrese el valor de x[" << i << "]: ";
        cin >> vectorX[i];
    }

    for (int i = 0; i < tamano; ++i) {
        cout << "Ingrese el valor de y[" << i << "]: ";
        cin >> matriz[i][0];
    }

    double x;
    cout << "Ingrese el valor de X para interpolar: ";
    cin >> x;

    Resolver_Newton(matriz, vectorX);

    for (int i = 0; i < tamano; i++) {
        vector[i] = matriz[i][i];
    }

    cout << "Matriz:" << endl;
    imprimirMatriz(matriz);

    cout << "Vector:" << endl;
    imprimirVector(vector);

    cout << "Vector X:" << endl;
    imprimirVector(vectorX);

    double solucion = Solucion(vector, vectorX);

    cout << "Solucion: " << fixed << setprecision(10) << solucion << endl;

    return 0;
}

void Resolver_Newton(Matriz& matriz, Vector& vectorX) {
    int n = vectorX.size();
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            matriz[j][i] = (matriz[j][i - 1] - matriz[j - 1][i - 1]) / (vectorX[j] - vectorX[j - i]);
        }
    }
}

double Solucion(Vector& vector, Vector& vectorX) {
    double total = vector[0];
    int n = vector.size();

    for (int i = 1; i < n; i++) {
        double temporal = 1.0; // Reiniciar temporal en cada iteración
        for (int j = 0; j < i; j++) {
            temporal = temporal * (vectorX[i] - vectorX[j]);
        }
        total = total + (vector[i] * temporal);
    }

    return total;
}

void imprimirMatriz(Matriz& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << setw(10) << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void imprimirVector(Vector& vector) {
    int n = vector.size();
    for (int i = 0; i < n; i++) {
        cout << setw(10) << vector[i] << endl;
    }
}