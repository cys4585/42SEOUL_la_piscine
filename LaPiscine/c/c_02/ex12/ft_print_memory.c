/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngcho <youngcho@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:02:18 by youngcho          #+#    #+#             */
/*   Updated: 2022/01/27 19:30:33 by youngcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
unsigned int    g_i;
unsigned int    g_size;
void    change_hex(int num)
{
    char    *hex;
    hex = "0123456789abcdef";
    write(1, &hex[num / 16], 1);
    write(1, &hex[num % 16], 1);
}
void    print_addr(unsigned long long addr, int zero)
{
    char    *hex;
    char    c;
    hex = "0123456789abcdef";
	printf("%llu\n", addr);
    if (addr / 16 > 15)
        print_addr(addr / 16, --zero);
    else
    {
        while (--zero)
            write(1, "0", 1);
        c = hex[addr / 16];
        write(1, &c, 1);
		printf("\n");
    }
    c = hex[addr % 16];
    write(1, &c, 1);
}
void    print_hex(char *addr)
{
    int     i;
    i = 0;
    while (i < 16)
    {
        if (g_i < g_size)
            change_hex((int)((unsigned char)addr[i]));
        else
        {
            write(1, "  ", 2);
        }
        i++;
        g_i++;
        if (i % 2 == 0)
            write(1, " ", 1);
    }
    g_i -= 16;
}
void    print_string(char *addr)
{
    int i;
    i = 0;
    while (i < 16)
    {
        if (g_i == g_size)
            break ;
        if (32 <= addr[i] && addr[i] <= 126)
            write(1, &addr[i], 1);
        else
            write(1, ".", 1);
        i++;
        g_i++;
    }
    g_i -= 16;
}
void    *ft_print_memory(void *addr, unsigned int size)
{
    g_i = 0;
    g_size = size;
    while (g_i < g_size)
    {
        print_addr((unsigned long long)addr, 16);
        write(1, ": ", 2);
        print_hex((char *)addr);
        print_string((char *)addr);
        write(1, "\n", 1);
		printf("%p\n",addr);
        addr += 16;
        g_i += 16;
    }
    return (addr);
}
