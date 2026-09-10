#include <stdio.h>
// Version A: sin puntero (paso por valor)
void intercambiarValor(int a, int b) {
int temp = a;
a = b;
b = temp;
}

// Version B: con puntero (paso por referencia)
void intercambiarPuntero(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}
