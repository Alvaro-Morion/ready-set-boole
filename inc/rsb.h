#ifndef RSB_H
# define RSB_H
# include <iostream>
# include <stack>
# include <string>
# include <vector>

unsigned int	adder(unsigned int a, unsigned int b);
std::string     conjunctive_normal_form(std::string formula);
bool            eval_formula(std::string proposition);
std::string     extract_variable(std::stack<std::string> &formula);
std::string     get_variables(std::string formula);
unsigned int    gray_code(unsigned int a);
unsigned int    multiplier(unsigned int a, unsigned int b);
std::string     negation_normal_form(std::string rpn);
void            print_truth_table(std::string formula);
bool		sat(std::string formula);
std::string     substitute_variables(std::string formula, std::string variables, unsigned combination);

#endif
