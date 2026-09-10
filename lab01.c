#include <stdio.h>

struct Proceso {
int pid;
char nombre [20];
int prioridad; // 1 (alta) a 5 (baja)
};

int buscarMayorPrioridad(struct Proceso *procesos, int n) {
    if (n <= 0) return -1;

    int indiceMayor = 0; // Asumimos inicialmente que el primer proceso es el prioritario

    // Recorremos el arreglo empleando aritmética de punteros (procesos + i)
    for (int i = 1; i < n; i++) {

        // En sistemas Unix/xv6, un valor numérico menor indica mayor prioridad
        if ((procesos + i)->prioridad < (procesos + indiceMayor)->prioridad) {
            indiceMayor = i;
        }
    }
    return indiceMayor;
}
