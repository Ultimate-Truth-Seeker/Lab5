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