#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct char_funcs - Struct to find function based on char
 * @c: char parameter
 * @f: Pointer to function to call
 */

typedef struct char_funcs
{
	char *c;
	int (*f)();
} char_funcs_t;

void print_buffer(char buffer[], int *buff_len, int *buff_ind);
void init_buffer(char buffer[]);
int _printf(const char *format, ...);
int print_c(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_s(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_num(int n, char buffer[], int *buff_len, int *buff_ind);
int print_int(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
char *binConverter(unsigned int n);
char *octConverter(unsigned int n);
char *hexConverter(char type, unsigned int n);
char *size_tHex(char type, size_t n);
int print_Unum(unsigned int n, char buffer[], int *buff_len, int *buff_ind);
int print_u(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_oct(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_hex(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_heX(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_bin(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_S(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_rev(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_rot13(va_list args_list, char buffer[], int *buff_len, int *buff_ind);
int print_p(va_list args_list, char buffer[], int *buff_len, int *buff_ind);

#endif
