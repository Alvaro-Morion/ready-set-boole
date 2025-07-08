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
	unsigned int	a, b;
	unsigned long	a_l, b_l;
	char			*endptr;

	if (argc != 3)
		return (printf("Invalid arguments\n"));
	if (!is_numeric(argv[1]) || !is_numeric(argv[2]))
		return (printf("Invalid arguments\n"));
	a_l = strtoul(argv[1], &endptr, 10);
	if (a_l > UINT_MAX || errno)
		return (printf("Invalid arguments\n"));
	b_l = strtoul(argv[2], &endptr, 10);
	if (b_l > UINT_MAX || errno)
		return (printf("Invalid arguments\n"));
	a = (unsigned int)a_l;
	b = (unsigned int)b_l;
	printf("%u * %u = %u\n", a, b, multiplier(a, b));
	printf("Correct: %i\n", (a * b == multiplier(a, b)));
	return (0);
}
