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

int main() {

int x = 5, y = 10;

printf("Antes: __x=%d_y=%d\n", x, y);

intercambiarValor(x, y);
printf("Sin_puntero: Lux=%d_y=%d (NO1cambio)\n", x, y);

intercambiar Puntero (&x, &y);
printf("Con puntero:x=%d_y=%d(SI1cambio)\n", x, y);

return 0;

}

