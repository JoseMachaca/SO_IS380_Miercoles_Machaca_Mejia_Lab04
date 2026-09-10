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


int main() {
    int totalProcesos = 5;
    struct Proceso listaProcesos[5];

    printf("===================================================\n");
    printf(" SIMULADOR DE PLANIFICADOR DE PROCESOS - IS-380    \n");
    printf("===================================================\n");
    printf("Ingrese los datos para %d procesos (Prioridad de 1 a 5):\n\n", totalProcesos);


	for (int i = 0; i < totalProcesos; i++) {
        	printf("--- Proceso [%d] ---\n", i + 1);
        	printf("PID: ");
		scanf("%d", &listaProcesos[i].pid);
        	printf("Nombre: ");
        	scanf("%s", listaProcesos[i].nombre);
        	printf("Prioridad (1-alta a 5-baja): ");
        	scanf("%d", &listaProcesos[i].prioridad);
        	printf("\n");
   	 }

	int idxOptimo = buscarMayorPrioridad(listaProcesos, totalProcesos);
