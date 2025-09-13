#include "../inc/rsb.h"

int	main(int argc, char **argv)
{
	std::vector<int> set;
	std::vector<std::vector<int>> result;
	if (argc == 1)
	{
		std::cout << "Invalid arguments\n";
		return 1;
	}
	for (int i = 1; i < argc; ++i) {
		set.push_back(atoi(argv[i]));
    }
	result = powerset(set);
	//result = {{1}, {}};
	for (std::vector<std::vector<int>>::iterator j = result.begin(); j < result.end(); j++)
	{
		std::cout << "[ ";
		for (std::vector<int>::iterator i = j->begin(); i < j->end(); i++)
			std::cout << *i << " ";
		std::cout << "]" << std::endl;

	}

	return (0);
}
