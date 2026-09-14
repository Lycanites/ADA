#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1, a2, a3;

    printf("Ingrese los datos: ");
    while (scanf("%d %d %d", &a1, &a2, &a3) == 3)
    {
        if (a1 == 0 && a2 == 0 && a3 == 0)
        {
            break;
        }

        if ((a2 - a1) == (a3 - a2))
        {
            int diferencia = a2 - a1;
            printf("AP %d\n", a3 + diferencia);
        }
        else
        {
            int razon = a2 / a1;
            printf("GP %d\n", a3 * razon);
        }
    }
}