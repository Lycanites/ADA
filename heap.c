#include <stdio.h>
#include <string.h>

// Función auxiliar para intercambiar dos caracteres en el arreglo A
int swap(char A[], int i, int j) {
    char temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return 0;
}

// Algoritmo de Heap recursivo para la generación de permutaciones
int heap_permutar(int k, char A[], int *contador) {
    // Caso base: se ha formado una nueva permutación
    if (k == 1) {
        printf("%s\n", A);
        (*contador)++;
        return 1;
    }

    // Procesa el subproblema de tamaño k - 1
    heap_permutar(k - 1, A, contador);

    // Ciclo de intercambios minimizados según la paridad de k
    for (int i = 0; i < k - 1; i++) {
        if (k % 2 == 0) {
            swap(A, i, k - 1);   // Si k es par: intercambia posición i con k - 1
        } else {
            swap(A, 0, k - 1);   // Si k es impar: intercambia posición 0 con k - 1
        }
        heap_permutar(k - 1, A, contador);
    }

    return 0;
}

int main() {
    char A[16]; // Buffer para máximo 15 caracteres + carácter nulo '\0'
    int total_permutaciones = 0;

    printf("Ingresa una cadena (maximo 15 caracteres sin repetir): ");
    if (scanf("%15s", A) != 1) {
        printf("Error al leer la entrada.\n");
        return 1;
    }

    int n = strlen(A);

    printf("\nPermutaciones Generadas: \n");
    heap_permutar(n, A, &total_permutaciones);

    printf("\nTotal de permutaciones generadas: %d\n", total_permutaciones);

    return 0;
}