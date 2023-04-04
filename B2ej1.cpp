#include <stdio.h>

/*Función para calcular el determinante de matriz 3x3.
  Se utiliza la regla de Sarrus para calcular el determinante.*/
double determinante(double a[3][3]) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int main() {
    double matriz[3][3];
    int i, j;
    /*Se pide al usuario que introduzca los elementos de la matriz*/
    printf("Introduzca los elementos de la matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Ingresa el elemento [%d][%d]: ", i+1, j+1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    printf("El determinante de la matriz es: %lf\n", determinante(matriz));
    return 0;
}