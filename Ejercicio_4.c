/*
 * Archivo: Ejercicio_4.c
 * Descripción: Este es un programa en C que usa un ciclo for donde se modifiquen dos variables de
 * manera paralela usando #pragma omp parallel for. 
 * La variable 1 muestra la suma acumulada del ciclo y la variable 2 el número de iteración actual
 * 
 * Funcionalidad:
 * - Usa la cláusula shared para gestionar el acceso a la variable1 dentro del ciclo.
 * - Usa la cláusula private para gestionar el acceso a la variable2 dentro del ciclo.
 *
 * Fecha modificación: 08-24-2024
 */
#include <stdio.h>
#include <omp.h>

int main() {
    int variable1 = 0;  // Variable compartida
    int variable2 = 0;  // Variable privada en cada hilo
    int i;

    // Modificación de variable1 y variable2 en un ciclo for paralelo
    #pragma omp parallel for shared(variable1) private(variable2)
    for (i = 0; i < 10; i++) {
        variable2 = i;  // Cada hilo tiene su propia copia de variable2
        variable1 += i; // Todos los hilos comparten variable1

        // Mostrar el estado de las variables en cada iteración
        printf("Hilo %d, Iteración %d: variable1 = %d, variable2 = %d\n", omp_get_thread_num(), i, variable1, variable2);
    }

    // Imprimir el resultado final
    printf("\nResultado final: variable1 = %d\n", variable1);

    return 0;
}