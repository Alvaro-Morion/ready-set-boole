#include <string>
#include <iostream>
#include "../inc/rsb.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	std::string proposition(argv[1]);
	print_truth_table(proposition);
	return (0);
}
