#include <stdio.h>

/*Función para calcular el determinante de matriz 3x3.
  Se utiliza la regla de Sarrus para calcular el determinante.*/
double determinante(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

/*Función para resolver sistemas de ecuaciones lineales de 3x3 utilizando el 
  método de Cramer*/
void resolverSistema(double matriz[3][4]) {
        double a[3][3] = {{matriz[0][0], matriz[0][1], matriz[0][2]},
                          {matriz[1][0], matriz[1][1], matriz[1][2]},
                          {matriz[2][0], matriz[2][1], matriz[2][2]}};
    double detA = determinante(a);
    double x, y, z;
    if (detA != 0) {
        double matrizX[3][3] = {{matriz[0][0], matriz[0][1], matriz[0][3]},
                                {matriz[1][0], matriz[1][1], matriz[1][3]},
                                {matriz[2][0], matriz[2][1], matriz[2][3]}};
        double matrizY[3][3] = {{matriz[0][0], matriz[0][2], matriz[0][3]},
                                {matriz[1][0], matriz[1][2], matriz[1][3]},
                                {matriz[2][0], matriz[2][2], matriz[2][3]}};
        double matrizZ[3][3] = {{matriz[0][1], matriz[0][2], matriz[0][3]},
                                {matriz[1][1], matriz[1][2], matriz[1][3]},
                                {matriz[2][1], matriz[2][2], matriz[2][3]}};
        x = determinante(matrizX) / detA;
        y = determinante(matrizY) / detA;
        z = determinante(matrizZ) / detA;
        printf("x = %lf, y = %lf, z = %lf\n", x, y, z);
    } else {
        printf("El sistema no tiene solución única.\n");
    }
}

int main() {
    double matriz[3][4];
    int i, j;
    /*Se pide al usuario que introduzca los elementos de la matriz*/
    printf("Introduzca los elementos de la matriz 3x3 y el término independiente:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 3) {
                printf("Introduzca el término independiente para la ecuación %d: ", i+1);
            } else {
                printf("Introduzca el elemento [%d][%d]: ", i+1, j+1);
            }
            scanf("%lf", &matriz[i][j]);
        }
    }
    resolverSistema(matriz);
    return 0;
}
