extern void *ft_print_memory(void *addr, unsigned int size);
#include <stdio.h>
#include <string.h>
int main(void){
    void    *addr;
    char    str[100] = "Bonjour les aminches...c  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. .";
    str[20] = 9;
    str[21] = 10;
    str[22] = 9;
    str[33] = 9;
    str[38] = 9;
    str[63] = 9;
    str[64] = 10;
    str[65] = 9;
    str[79] = 10;
    str[80] = 10;
    str[81] = 10;
    str[89] = 10;
    str[90] = 32;
    str[91] = 0;
    addr = str;
    addr = ft_print_memory(addr, strlen(str));
    char str2[3];
    str2[0] = 16 * 2 + 2;
    str2[1] = '\0';
    addr = str2;
    ft_print_memory(addr, 1);
    char str3[5];
    str3[0] = -6;
    str3[1] = -2;
    str3[2] = 0;
    addr = str3;
    ft_print_memory(addr, 2);
}
