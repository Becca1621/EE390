#include "HTTS221.h"
#include <math.h>

HC05_puts(char* str) {
	int size = getSize(str);
	HAL_UART_Transmit(&huart, str, size, 100);
}

HC05_putf(float f, int p) {
	char str[30];
	ftoa(f, str, p);
	int size = getSize(str);
	HAL_UART_Transmit(&huart, str, size, 100);
}

HC05_puti(int i) {
	char str[30];
	ftoa(i, str, 0);
	int size = getSize(str);
	HAL_UART_Transmit(&huart, str, size, 100);
}

HC05_newline() {
	char str[2] = "\n\r";
	HAL_UART_Transmit(&huart, str, 2, 100);
}

int getSize(char* str) {
	int size = 0;
	while (str[size] != '\0')
		size++;
	return size;
}

void reverse(char *str, int len) { 
    int i=0, j=len-1, temp; 
    while (i<j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; j--; 
    } 
}

int intToStr(int x, char str[], int d) { 
    int i = 0; 
    while (x) { 
        str[i++] = (x%10) + '0'; 
        x = x/10; 
    } 
    while (i < d) 
        str[i++] = '0'; 
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 

void ftoa(float n, char *res, int afterpoint) { 
    int ipart = (int)n;  
    float fpart = n - (float)ipart; 
    int i = intToStr(ipart, res, 0); 
    if (afterpoint != 0) { 
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint); 
        intToStr((int)fpart, res + i + 1, afterpoint); 
    } 
}
