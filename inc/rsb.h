#ifndef RSB_H
# define RSB_H
# include <iostream>
# include <string>

unsigned int	adder(unsigned int a, unsigned int b);
unsigned int    multiplier(unsigned int a, unsigned int b);
unsigned int    gray_code(unsigned int a);
bool            eval_formula(std::string proposition);
void            print_truth_table(std::string formula);

#endif