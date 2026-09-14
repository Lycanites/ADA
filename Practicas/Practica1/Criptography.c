#include <stdio.h>
#include <stdbool.h>

bool primo(int num);
int solve(int n);

int main()
{
    int k;
    printf("Ingrese la cantidad de numeros: ");
    if (scanf("%d", &k) == 1)
        printf("Ingrese los numeros (No ingrese comas entre los numeros, separelos por espacios): ");
    {

        while (k > 0)
        {
            int n;
            scanf("%d", &n);
            printf("%d\n", solve(n));
            k = k - 1;
        }
    }

    return 0;
}

// Funcion para verificar si un numero es primo
bool primo(int num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Funcion que encuentra el n- esimo primo
int solve(int n)
{
    if (n == 1)
        return 2;

    int contador = 1; // Ya contamos el 2
    int candidato = 3;

    while (contador < n)
    {
        if (primo(candidato))
        {
            contador++;
            if (contador == n)
                return candidato;
        }
        candidato += 2; // Solo probar numeros impares
    }

    return candidato;
}
