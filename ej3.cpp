#include <stdio.h>
#include <stdbool.h>

/*Función que determina si un número n es primo o no.
 *Retorna verdadero si n es primo y falso si no lo es.*/
bool es_primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void imprimir_divisores(int n) {
    printf("Divisores: ");
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) printf("%d ", i);
    }
    printf("\n");
}

/*Función que imprime los divisores. */
int main() {
    int n;
    printf("Ingrese un número entero: ");
    scanf("%d", &n);

    if (es_primo(n)) {
        printf("%d es primo\n", n);
    } else {
        printf("%d no es primo\n", n);
        imprimir_divisores(n);
    }

    return 0;
}