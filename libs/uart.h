#include <stdio.h>

inline void init_uart();
void blink13(uint8_t count);
uint8_t uart_putchar(char c, FILE *stream);
