#include "../inc/rsb.h"

bool sat(std::string formula)
{
    std::string variables = get_variables(formula); //O(n)
    unsigned combination;
    std::string new_formula;
    unsigned max_size = 1 << variables.size();
    
    eval_formula(substitute_variables(formula, variables, 0)); //O(1)
    for (combination = 0; combination < max_size; ++combination) //O(2^n)
    {
        new_formula = substitute_variables(formula, variables, combination); //O(1)
        if(eval_formula(new_formula))
		return (true);
    }
    return (false);
}
