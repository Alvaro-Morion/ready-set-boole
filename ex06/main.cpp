#include "../inc/rsb.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	std::string proposition(argv[1]);
	std::string cnf;
	try
    {
		cnf = conjunctive_normal_form(proposition);
	}
	catch(const std::exception& e)
    {
        std::cerr << "Invalid proposition \n";
    }
	std::cout << cnf << std::endl;
	print_truth_table(proposition + cnf + "=");
	return (0);
}
