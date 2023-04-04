#include <stdio.h>
#include <stdlib.h>

unsigned int* Fibonacci(unsigned int n) {
    void* temp = malloc(n * sizeof(unsigned int)); // Se reserva memoria para el array con tamaño n
    unsigned int* sequence = (unsigned int*)temp; // Se convierte el puntero de tipo void a 
                                                  //puntero de tipo unsigned int
    sequence[0] = 0; // Se define primer término de la sucesión
    sequence[1] = 1; // Se define segundo término de la sucesión

    for (unsigned int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2]; // Se calcula el siguiente 
                                                         // término de la sucesión utilizando 
                                                         // la fórmula F(n) = F(n-1) + F(n-2)
    }
    return sequence; // Se devuelve el puntero al array generado
}

int main() {
    unsigned int n;
    printf("Introduce el numero de terminos de la sucesion de Fibonacci a generar: ");
    scanf("%u", &n); // Se leen del teclado el numero de términos que se quieren generar
    if (n < 2) {
        printf("El numero de terminos debe ser mayor o igual a 2\n");
        return 1;
    }
    unsigned int* sequence = Fibonacci(n); // Se llama a la funcion Fibonacci y 
                                           // se guarda el puntero en la secuencia generada
    printf("La sucesion de Fibonacci generada es: \n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%u ", sequence[i]); // Se imprimen los términos de la sucesión
    }
    free(sequence); // Se libera la memoria reservada
    return 0;
}