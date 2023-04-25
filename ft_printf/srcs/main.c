#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
    int num = 123;

    ft_printf("character : %c\n", 'c');
    printf("character : %c\n", 'c');

    ft_printf("string : %s\n", "abcd");
    printf("string : %s\n", "abcd");

    ft_printf("void * hex : %p\n", &num);
    printf("void * hex : %p\n", &num);

    ft_printf("decimal : %d\n", 0xff); //decimal integer 차이
    printf("decimal : %d\n", 0xff);

    ft_printf("integer : %i\n", 0xff);
    printf("integer : %i\n", 0xff);

    ft_printf("u_decimal : %u\n", -123);
    printf("u_decimal : %u\n", -123);

    ft_printf("lowercase_hex : %8x\n", 255); //이거맞나?
    printf("lowercase_hex : %8x\n", 255);

    ft_printf("uppercase_hex : %X\n", 255);
    printf("uppercase_hex : %X\n", 255);

    ft_printf("percent : %%\n");
    printf("percent : %%\n");

    //gcc main.c -o test -L.(라이브러리위치) -lftprintf(라이브러리이름) 
    return (0);
}