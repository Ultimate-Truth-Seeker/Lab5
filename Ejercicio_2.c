/*
 * Archivo: Ejercicio_2.c
 * Descripción: Este es un programa en C que calcule la suma de los primeros N números naturales
 * utilizando un ciclo for paralelo. Utiliza la cláusula reduction con + para acumular la suma en una
 * variable compartida
 * 
 * Funcionalidad:
 * - Define N como una constante grande, por ejemplo, N = 1000000
 * - Usa omp_get_wtime() para medir los tiempos de ejecución
 *
 * Fecha modificación: 08-24-2024
 */
#include <stdio.h>
#include <omp.h>

#define N 1000000

int main() {
    int sum = 0;

    // Medir el tiempo inicial
    double start_time = omp_get_wtime();

    // Paralelizar el ciclo for con la cláusula reduction para sumar
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    // Medir el tiempo final
    double end_time = omp_get_wtime();

    // Calcular el tiempo transcurrido
    double time_taken = end_time - start_time;

    // Imprimir el resultado
    printf("La suma de los primeros %d números naturales es: %d\n", N, sum);
    printf("Tiempo de ejecución: %f segundos\n", time_taken);

    return 0;
}