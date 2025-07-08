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
	bool result;
	try
	{
		result = eval_formula(proposition);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid proposition" << '\n';
		return(1);
	}
	std::cout << "Result: " << result << std::endl;
	return (0);
}
