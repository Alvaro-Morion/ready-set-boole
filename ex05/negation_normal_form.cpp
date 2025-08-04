#include "../inc/rsb.h"

std::string extract_variable(std::stack<std::string> &formula)
{
    std::string value = formula.top();
    formula.pop();
    return value;
}

std::string remove_implications_xor(std::string formula)
{
    std::stack<std::string> result_stack;
    std::string a, b, result;
    for (char c : formula)
    {
        if (isalnum(c))
            result_stack.push(std::string(1,c));
        else if (c == '^')
        {
            b = extract_variable(result_stack);
            a = extract_variable(result_stack);
            result_stack.push(a + b + "!&" + b + a + "!&|");
        }
        else if (c == '>')
        {
            b = extract_variable(result_stack);
            a = extract_variable(result_stack);
            result_stack.push(a + "!" + b + "|");
        }
        else if (c == '=')
        {
            b = extract_variable(result_stack);
            a = extract_variable(result_stack);
            result_stack.push(a + b + "!|" + b + a + "!|&" );
        }
        else if (std::string("&|").find(c) != std::string::npos)
        {
            b = extract_variable(result_stack);
            a = extract_variable(result_stack);
            result_stack.push(a + b + c);
        }
        else if (c == '!')
        {
            a = extract_variable(result_stack);
            result_stack.push(a + "!");
        }
    }
    while(result_stack.size())
    {
        result.append(result_stack.top());
        result_stack.pop();
    }
    return result;
}

std::string negate(std::string formula)
{
    std::string variables = get_variables(formula);
    for (std::string::iterator it = formula.begin(); it != formula.end(); it++)
    {
        if (isdigit(*it) | (variables.find(*it) != std::string::npos))
            it = formula.insert(it + 1, '!');
        else if (*it == '&')
            formula.replace(it, it + 1, "|");
        else if (*it == '|')
            formula.replace(it, it + 1, "&");
        else if (*it == '!' & *(it - 1) == '!')
        {
            it = formula.erase(it - 1, it + 1);
            it -= 1;
        }
    }
    return formula;
}

std::string negation_normal_form(std::string rpn)
{
    std::stack<std::string> result;
    std::string a, b, tmp;
    eval_formula(substitute_variables(rpn, get_variables(rpn), 0));
    tmp = remove_implications_xor(rpn);
    for (char c : tmp)
    {
        if (isalnum(c))
            result.push(std::string(1, c));
        else if (std::string("&|").find(c) != std::string::npos)
        {
            b = extract_variable(result);
            a = extract_variable(result);
            result.push(a + b + c);
        }
        else if (c == '!')
        {
            a = extract_variable(result);
            result.push(negate(a));
        }
    }
    return result.top();
}

