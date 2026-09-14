#include <stdio.h>
#include <stdlib.h>

int solve(int n);

int main()
{
    int n;
    printf("Ingrese el tamaño de los palitos (No ingrese comas entre los numeros, separelos por espacios): ");
    while (scanf("%d", &n) == 1)
    {
        int resultado = solve(n);
        printf("%d\n", resultado);
    }

    return 0;
}

int solve(int n)
{
    int palos[1005];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &palos[i]);
    }
    // En este apartado se ordena por medio del algoritmo de "Burbuja (Bubble sort)"
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (palos[j] < palos[j + 1])
            {
                int temp = palos[j];
                palos[j] = palos[j + 1];
                palos[j + 1] = temp;
            }
        }
    }
    // Este For se encarga de buscar las parejas para construir el rectángulo
    int lado1 = 0, lado2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (palos[i] == palos[i + 1])
        {
            if (lado1 == 0)
            {
                lado1 = palos[i];
            }
            else if (lado2 == 0)
            {
                lado2 = palos[i];
                break;
            }
            i++;
        }
    }

    // Si se encontraron las piezas necesarias para la correcta construcción del rectángulo, se imprimira el area máxima posiblo. Si no, se imprime -1
    printf("El area máxima posible es: ");
    if (lado1 > 0 && lado2 > 0)
    {
        return lado1 * lado2;
    }
    else
    {
        return -1;
    }
}