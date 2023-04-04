#include <stdio.h>

/*Función para calcular el producto escalar de dos vectores*/
void productoEscalar(double vec1[3], double vec2[3], double resultado[1]) {
    resultado[0] = (vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]);
}

/*Función para calcular el producto vectorial de dos vectores*/
void productoVectorial(double vec1[3], double vec2[3], double resultado[3]) {
    resultado[0] = (vec1[1] * vec2[2]) - (vec1[2] * vec2[1]);
    resultado[1] = (vec1[2] * vec2[0]) - (vec1[0] * vec2[2]);
    resultado[2] = (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]);
}

/*Función para calcular el producto mixto de tres vectores*/
void productoMixto(double vec1[3], double vec2[3], double vec3[3], double resultado[1]) {
    //Vector temporal para almacenar el resultado del producto vectorial entre vec1 y vec2
    double vecTemp[3];
    //Calcula el producto vectorial entre vec1 y vec2 y almacenar el resultado en vecTemp
    productoVectorial(vec1, vec2, vecTemp);
    //Calcular el producto mixto entre vecTemp, vec3 y almacenar el resultado en resultado[0]
    resultado[0] = vecTemp[0] * vec3[0] + vecTemp[1] * vec3[1] + vecTemp[2] * vec3[2];
}

int main() {
    //Vectores de entrada y vectores para almacenar resultados
    double vec1[3], vec2[3], vec3[3], resultadoPE[1], resultadoPV[3], resultadoPM[1];

    printf("Ingresa los valores del primer vector: ");
    scanf("%lf %lf %lf", &vec1[0], &vec1[1], &vec1[2]);

    printf("Ingresa los valores del segundo vector: ");
    scanf("%lf %lf %lf", &vec2[0], &vec2[1], &vec2[2]);

    productoEscalar(vec1, vec2, resultadoPE);
    printf("Producto escalar: %lf\n", resultadoPE[0]);

    productoVectorial(vec1, vec2, resultadoPV);
    printf("Producto vectorial: (%lf, %lf, %lf)\n", resultadoPV[0], resultadoPV[1], resultadoPV[2]);

    printf("Ingresa los valores del tercer vector: ");
    scanf("%lf %lf %lf", &vec3[0], &vec3[1], &vec3[2]);

    productoMixto(vec1, vec2, vec3, resultadoPM);
    printf("Producto mixto: %lf\n", resultadoPM[0]);

    return 0;
}