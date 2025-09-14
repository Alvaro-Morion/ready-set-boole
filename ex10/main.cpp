#include "../inc/rsb.h"

unsigned get_number(std::string argument)
{
	std::stringstream iss(argument);
	unsigned number;
	if (!(iss >> number) | !iss.eof())
	{
		std::cerr << "invalid number: " << argument << std::endl;
		throw std::exception();
	}
	return number;


}

int	main(int argc, char **argv)
{
	std::vector<int> set;
	std::vector<int> result;
	std::vector<std::vector<int>> sets;

	if (argc != 3)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	try
	{
		unsigned x = get_number(argv[1]);
		unsigned y = get_number(argv[2]);
		std::cout << "Point (" << x << "," << y << ") = " << ft_map(x,y) << std::endl;
	}
	catch (std::exception e)
	{
		return 1;
	}
	return 0;
}