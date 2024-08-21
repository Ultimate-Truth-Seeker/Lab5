#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 131072
#define THRESHOLD 1000  // Umbral para dividir las tareas

// Función recursiva para contar la clave en paralelo usando tareas
long count_key_parallel(long Nlen, long *a, long key) {
    if (Nlen <= THRESHOLD) {  // Caso base: si el tamaño es pequeño, contar secuencialmente
        long count = 0;
        for (long i = 0; i < Nlen; i++)
            if (a[i] == key) count++;
        return count;
    } else {
        long mid = Nlen / 2;
        long count1 = 0, count2 = 0;

        #pragma omp task shared(count1)
        count1 = count_key_parallel(mid, a, key);  // Contar en la primera mitad

        #pragma omp task shared(count2)
        count2 = count_key_parallel(Nlen - mid, a + mid, key);  // Contar en la segunda mitad

        #pragma omp taskwait  // Esperar a que ambas tareas terminen

        return count1 + count2;
    }
}

int main() {
    long a[N], key = 42, nkey = 0;
    for (long i = 0; i < N; i++) a[i] = rand() % N;
    a[N % 43] = key; 
    a[N % 73] = key; 
    a[N % 3] = key;

    // Ejecutar el conteo en paralelo
    #pragma omp parallel
    {
        #pragma omp single
        {
            nkey = count_key_parallel(N, a, key);
        }
    }

    printf("Numero de veces que 'key' aparece en paralelo: %ld\n", nkey);

    return 0;
}