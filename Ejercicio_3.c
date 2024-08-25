/*
 * Archivo: Ejercicio_3.c
 * Descripción: Este es un programa en C que ejecute tres funciones diferentes en paralelo usando la
 * directiva #pragma omp sections. Cada sección es independiente.
 * 
 * Funcionalidad:
 * - Genera la serie de Fibonacci
 * - Calcula el factorial de un número
 * - Encuentra el máximo de un arreglo
 *
 * Fecha modificación: 08-24-2024
 */
#include <stdio.h>
#include <omp.h>

#define N 10
#define MAX_SIZE 1000

// Función para calcular el factorial de un número
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Función para generar la serie de Fibonacci
void fibonacci(int n) {
    unsigned long long fib[MAX_SIZE];
    fib[0] = 0;
    fib[1] = 1;

    printf("Serie de Fibonacci de los primeros %d números:\n", n);
    printf("%llu, %llu", fib[0], fib[1]);

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        printf(", %llu", fib[i]);
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = i + 1;  // Llenar el arreglo con valores del 1 al MAX_SIZE
    }

    // Ejecutar las tres funciones en paralelo usando omp sections
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            unsigned long long fact = factorial(N);
            printf("El factorial de %d es: %llu\n", N, fact);
        }

        #pragma omp section
        {
            fibonacci(N);
        }

        #pragma omp section
        {
            int max_value = find_max(arr, MAX_SIZE);
            printf("El valor máximo en el arreglo es: %d\n", max_value);
        }
    }

    return 0;
}