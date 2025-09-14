#include "../inc/rsb.h"

std::set<int> ft_union(std::set<int> a, std::set<int> b)
{
    std::set<int> result;
    result.insert(a.begin(), a.end());
    result.insert(b.begin(), b.end());
    return result;
}

std::set<int> ft_intersection(std::set<int> a, std::set<int> b)
{
    std::set<int> result;
    for (auto i : a)
        if (b.count(i))
            result.insert(i);
    return result;
}

std::set<int> ft_complement(std::set<int> a, std::set<int> global_set)
{
    std::set<int> result(global_set);
    for (auto i : a)
        result.erase(i);
    return result;
}
std::set<int> evaluate_set_expression(std::string proposition, std::map<char, std::set<int>> var_set_map)
{
    std::stack<std::set<int>> stack;
    std::set<int> global_set;
   
    for (auto i : var_set_map)
        global_set = ft_union(global_set, i.second);
    
    for (auto c : proposition)
    {
        if (isalpha(c))
            stack.push(var_set_map[c]);
        else
        {
            std::set<int> a = stack.top(); stack.pop();
            switch (c)
            {
                case ('|'):
                {
                    std::set<int> b = stack.top(); stack.pop();
                    stack.push(ft_union(a, b));
                    break;
                }
                case ('&'):
                {
                    std::set<int> b = stack.top(); stack.pop();
                    stack.push(ft_intersection(a,b));
                    break;
                }
                case ('!'):
                {
                    stack.push(ft_complement(a, global_set));
                    break;
                }


            }
        }
    }
    return stack.top();

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