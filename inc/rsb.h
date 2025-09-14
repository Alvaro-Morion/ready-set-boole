#ifndef RSB_H
# define RSB_H
# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <set>
# include <limits.h>

unsigned int	                adder(unsigned int a, unsigned int b);
std::string                     conjunctive_normal_form(std::string formula);
bool                            eval_formula(std::string proposition);
std::vector<int>                eval_set(std::string proposition, std::vector<std::vector<int>> sets);
std::string                     extract_variable(std::stack<std::string> &formula);
double                          ft_map(uint16_t x, uint16_t y);
std::string                     get_variables(std::string formula);
unsigned int                    gray_code(unsigned int a);
std::vector<uint16_t>           inverse_map(double x);
unsigned int                    multiplier(unsigned int a, unsigned int b);
std::string                     negation_normal_form(std::string rpn);
void                            print_truth_table(std::string formula);
bool                            sat(std::string formula);
std::string                     substitute_variables(std::string formula, std::string variables, unsigned combination);
std::vector<std::vector<int>>   powerset(std::vector<int> set);

#endif
