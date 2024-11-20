// gcc -pedantic -std=c99 -g insercionBinaria.c -o insercionBinaria

#include <stdio.h>

// Función para realizar búsqueda binaria
int busquedaBinaria(int arreglo[], int elemento, int inicio, int fin)
{
    while(inicio <= fin)
	{
        int medio = (inicio + fin) / 2;
		printf("\n%i == %i?", arreglo[medio], elemento);
        if(arreglo[medio] == elemento)
		{
            return medio + 1;
		}
		else if(arreglo[medio] < elemento)
		{
			printf("\n%i < %i\n", arreglo[medio], elemento);
            inicio = medio + 1;
		}
		else
		{
			printf("\n%i > %i\n", arreglo[medio], elemento);
            fin = medio - 1;
		}
    }
    return inicio;
}

// Función para ordenamiento por inserción binaria
void ordenamientoInsercionBinaria(int arreglo[], int n) {
    for (int i = 1; i < n; i++)
	{
        int elemento = arreglo[i];
        // Encuentra la posición correcta usando búsqueda binaria
		
		printf("\n=========================\nVuelta: %i", i);
        int posicion = busquedaBinaria(arreglo, elemento, 0, i - 1);

        // Mover los elementos mayores hacia la derecha
        for (int j = i; j > posicion; j--)
		{
            arreglo[j] = arreglo[j - 1];
        }
        // Inserta el elemento en la posición correcta
        arreglo[posicion] = elemento;
		
		printf("Arreglo hasta ahora: ");
		for (int k = 0; k < n; k++) {
			printf("%d ", arreglo[k]);
			if (k == i)
			{
				printf(" / ");
			}
		}
		printf("\n");
    }
}

int main() {
    //int arreglo[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    //int arreglo[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int arreglo[] = {45, 65, 17, 94, 16, 84, 53, 04, 58, 12, 80, 35, 04, 24, 24, 93, 79};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    printf("Arreglo original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    ordenamientoInsercionBinaria(arreglo, n);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}

