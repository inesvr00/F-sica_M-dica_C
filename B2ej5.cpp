#include <stdio.h>
#include <math.h>

/* Función para calcular la integral aproximada de f(x) = ln(x)
   entre los valores a y b, utilizando un paso de tamaño h */
double integral(double a, double b, double h) {
    double sum = 0; // Inicializamos la suma en 0

    // Se recorren los valores de x desde a hasta b, con un incremento de h en cada iteración */
    for (double x = a; x < b; x += h) {
        /* En cada iteración, sumamos el área de un rectángulo (base h y altura log(x)) a la variable sum */
        sum += h * log(x);
    }
    // Devolvemos la suma como resultado de la integral aproximada */
    return sum;
}

int main() {
    double a = 1.0, b = 2.0, h;
    // Pedimos al usuario que introduzca el valor de h */
    printf("Introduce el valor de h: ");
    scanf("%lf", &h);
    // Calculamos el resultado de la integral con los valores especificados y lo imprimimos en pantalla */
    printf("El resultado de la integral es: %lf", integral(a, b, h));
    return 0;
}