#include "../inc/rsb.h"

std::vector<int> get_set(std::string argument)
{
	std::stringstream iss(argument);
	int number;
	std::set<int> result;
	while (iss >> number)
		result.insert(number);
	return std::vector<int>(result.begin(), result.end());
}

int	main(int argc, char **argv)
{
	std::vector<int> set;
	std::vector<int> result;
	std::vector<std::vector<int>> sets;

	if (argc < 2)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	std::string proposition(argv[1]);
	try
	{
		int i = 2;
		while (i < argc)
		{
			sets.push_back(get_set(std::string(argv[i])));
			i++;
		}
		result = eval_set(proposition, sets);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Invalid arguments" << '\n';
		return(1);
	}

	// std::vector<int> result = evaluate_set(proposition, sets);
	
	// std::cout << "[ ";
	// for (int i : result)
	// 	std::cout << i << " ";
	// std::cout << "]" << std::endl;
	return (0);
}