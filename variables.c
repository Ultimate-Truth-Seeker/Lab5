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