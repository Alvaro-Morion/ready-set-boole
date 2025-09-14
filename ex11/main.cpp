#include "../inc/rsb.h"

uint16_t get_number(std::string argument)
{
	std::stringstream iss(argument);
	uint16_t number;
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
		uint16_t x = get_number(argv[1]);
		uint16_t y = get_number(argv[2]);
		double result = ft_map(x,y);
		std::cout << "Point (" << x << "," << y << ") = " << result << std::endl;
		std::vector<uint16_t> inverse = inverse_map(result);
		std::cout << "Value " << result << " = " << "(" << inverse[0] << "," << inverse[1] << ")" << std::endl;
	}
	catch (std::exception e)
	{
		return 1;
	}
	return 0;
}