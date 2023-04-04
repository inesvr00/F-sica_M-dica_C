#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    int count[5] = {0}; // Array para contar las letras donde la posición 
                        //representa una letra diferente
    char c;

    fp = fopen("Capitulo_I_Quijote.txt", "r"); // Abre el archivo en modo lectura

    if (fp == NULL) {
        printf("Error al abrir el archivo.\n"); // Si no se puede abrir el 
                                                // archivo, se imprime un 
                                                // mensaje de error y se 
                                                // finaliza el programa
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) { // Bucle para leer letra por letra
        switch(tolower(c)) { // Convierte todas las letras en minúsculas
            case 'p':
                count[0]++; // Contadores
                break;
            case 'b':
                count[1]++;
                break;
            case 'j':
                count[2]++;
                break;
            case 'h':
                count[3]++;
                break;
            case 'z':
                count[4]++;
                break;
        }
    }

    // Se imprimen los resultados obtenidos
    printf("Numero de letras 'p': %d\n", count[0]);
    printf("Numero de letras 'b': %d\n", count[1]);
    printf("Numero de letras 'j': %d\n", count[2]);
    printf("Numero de letras 'h': %d\n", count[3]);
    printf("Numero de letras 'z': %d\n", count[4]);

    fclose(fp); // Se cierra el archivo
    return 0;
}