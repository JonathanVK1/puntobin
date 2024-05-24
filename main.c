/**
@bierf Lo que realiza el programa es cambiar el bit seleccionado
@param set_bit32 es la funcion que realiza el cambio
@returns int 

*/




#include <stdio.h>
#include <stdint.h>

uint32_t set_bit32(uint32_t data, int bit_pos, int bit_value) {
    if(bit_value == 1) {
        return data | (1 << bit_pos);  // desplaza el bit y le aplica un or
    } else {
        return data & ~(1 << bit_pos); // desplaza el bit y le aplica un nand
    }
}

void show_bin8(uint32_t num) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if(i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}



int main() {
    uint32_t data = 0x00011001; // Ejemplo de variable de 32 bits
    int bit_pos = 1; // Posición del bit a modificar
    int bit_value = 1; // Valor del bit a escribir (0 o 1)

    printf("Valor original en binario: %08x\n", data);
    data = set_bit32(data, bit_pos, bit_value);
    printf("Valor modificado en binario: %08x\n", data);

    show_bin8(data);

    return 0;
}
