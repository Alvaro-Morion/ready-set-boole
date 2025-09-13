#include "../inc/rsb.h"

std::set<int> evauate_set_expression(std::string proposition, std::map<char, std::set<int>)
{
    std::stack<std::set<int>> stack;
    //Define global set for negation

}

std::vector<int> eval_set(std::string proposition, std::vector<std::vector<int>> sets)
{
    std::string variables = get_variables(proposition);
    std::map<char, std::set<int>> var_set_map;
    std::set<int> result;
    if (sets.size() != variables.length())
        throw std::exception();
    eval_formula(substitute_variables(proposition, variables, 0)); //Check formula is valid --> throws exception
    unsigned i = 0;
    for (char c : variables)
    {
        var_set_map[c] = std::set<int>(sets[i].begin(), sets[i].end());
        i++;
    }
    result = evaluate_set_expression(proposition, var_set_map);
    return std::vector<int>(result.begin(), result.end());
}