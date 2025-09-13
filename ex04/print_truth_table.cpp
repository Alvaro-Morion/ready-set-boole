#include "../inc/rsb.h"

std::string get_variables(std::string formula)
{
    std::string variables;
    for (std::string::iterator it = formula.begin(); it != formula.end(); it++)
    {
        if (isupper(*it) && variables.find(*it) == std::string::npos)
            variables += *it;
        
    }
    std::sort(variables.begin(), variables.end());
    return variables;
}

std::string substitute_variables(std::string formula, std::string variables, unsigned combination) //O(1)
{
    std::string expresion = formula;
    size_t idx;

    for (std::string::iterator it = expresion.begin(); it != expresion.end(); it++)
    {
        if (isupper(*it))
        {
            idx = variables.find(*it);
            *it = ((combination >> (variables.size() - 1 - idx)) & 1) + '0';
        }
    }
    return expresion;
}

void print_header(std::string variables) //O(n)
{
    int n = variables.size();
    
    for (char c : variables)
        std::cout << " | " << c;
    std::cout << " | = | \n ";
    while(n-- >= 0)
        std::cout << "|---";
    std::cout << "|\n";

}

void print_row(unsigned combination, bool result, size_t max_value)
{
    unsigned n = max_value;
    while (n > 0)
    {
        std::cout << " | " << ((combination >> (n - 1)) & 1);
        n--;
    }
    std::cout << " | " << result << " | \n";
}

void print_truth_table(std::string formula)
{
    std::string variables = get_variables(formula); //O(n)
    unsigned combination;
    std::string new_formula;
    unsigned max_size = 1 << variables.size();
    bool result;
    eval_formula(substitute_variables(formula, variables, 0)); //O(1)
    print_header(variables); //O(n)
    for (combination = 0; combination < max_size; ++combination) //O(2^n)
    {
        new_formula = substitute_variables(formula, variables, combination); //O(1)
        result = eval_formula(new_formula); //O(1)
        print_row(combination, result, variables.size());
    }
    //Total 2*O(n)+ O(1) + O(2^n) = O(2^n)
}