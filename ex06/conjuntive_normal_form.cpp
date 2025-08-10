#include "../inc/rsb.h"

size_t count_and(std::string a)
{
    size_t count = 0;
    for (char c : a)
        if (c == '&')
            count++;
    return count;
}

std::vector<std::string> split_by_and(std::string formula)
{
    std::stack<std::string> operands;
    std::vector<std::string> result;
    std::string a,b;
    for (char c : formula)
    {
        if (isalnum(c))
            operands.push(std::string(1, c));
        if (c == '!')
            operands.push(extract_variable(operands) + "!");
        if (c == '|')
        {
            b = extract_variable(operands);
            a = extract_variable(operands);
            operands.push(a + b + "|");
        }
        if (c == '&')
        {
            b = extract_variable(operands);
            a = extract_variable(operands);
            if (!operands.size()) //Top Level &
            {
                result.push_back(a);
                result.push_back(b);
                return result;
            }
            else
                operands.push(a + b + "&");
        }
    }
    return {};
}

std::string distribute_or(std::string a, std::string b)
{
    size_t a_count, b_count;
    std::string result;

    a_count = count_and(a);
    b_count = count_and(b);
    if (!(a_count + b_count))
        return a + b + "|";
    if (a_count)
    {
        std::vector<std::string> parts = split_by_and(a);
        std::string result;
        for (std::string part : parts)
            result += distribute_or(part, b);
        result.append(std::string(parts.size() - 1, '&'));
        return result;
    }
    if (b_count)
    {
        std::vector<std::string> parts = split_by_and(b);
        std::string result;
        for (std::string part : parts)
            result += distribute_or(a, part);
        result.append(std::string(parts.size() - 1, '&'));
        return result;
    }
    return "";
}

std::string distribute_and(std::string formula)
{
    std::stack<std::string> result;
    std::string a, b;
    int and_count = 0;
    for (char c : formula)
    {
        if (isalnum(c))
            result.push(std::string(1,c));
        else if (c == '&')
        {
            b = extract_variable(result);
            a = extract_variable(result);
            result.push(a + b + "&");
            and_count++;
        }
        else if (c == '|') //Distribute 
        {
            b = extract_variable(result);
            a = extract_variable(result);
            result.push(distribute_or(a, b));
        }
        else if (c == '!')
        {
            a = extract_variable(result);
            result.push(a + "!");
        }
    }
    return result.top();
}

std::string and_to_end(std::string formula)
{
    std::string result;
    int count = 0;
    for (char c : formula)
        if (c == '&')
            count++;
        else
            result.push_back(c);
    result.append(count, '&');
    return result;
}

std::string conjunctive_normal_form(std::string formula)
{
    std::string nnf = negation_normal_form(formula);
    nnf = distribute_and(nnf);
    return and_to_end(distribute_and(nnf));
}