#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "../inc/rsb.h"

int	is_numeric(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	unsigned int	a;
	unsigned long	a_l;
	char			*endptr;

	if (argc != 2)
		return (printf("Invalid arguments\n"));
	if (!is_numeric(argv[1]))
		return (printf("Invalid arguments\n"));
	a_l = strtoul(argv[1], &endptr, 10);
	if (a_l > UINT_MAX || errno)
		return (printf("Invalid arguments\n"));
	a = (unsigned int)a_l;
	printf("%u in Gray Code is  %u\n", a, gray_code(a));
	return (0);
}
