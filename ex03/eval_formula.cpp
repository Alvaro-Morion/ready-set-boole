#include "../inc/rsb.h"

static void insert_number(std::stack<bool> *stack, char character)
{
    stack->push(character - '0');
}

static void operate(std::stack<bool> *stack, char character)
{
    bool a, b, result;
    
    if (stack->size())
    {
        b = stack->top();
        stack->pop();
    }
    else
        throw(std::exception());
    
    switch (character)
    {
        case ('!'):
        {
            result = !b;
            break;
        }
        case ('&'):
        {
            if (stack->size())
            {
                a = stack->top();
                stack->pop();
                result = a & b;
            }
            else
                throw(std::exception());
            break;
        }
        case ('^'):
        {
            if (stack->size())
            {
                a = stack->top();
                stack->pop();
                result = a ^ b;
            }
            else
                throw(std::exception());
            break;
        }
        case ('|'):
        {
            if (stack->size())
            {
                a = stack->top();
                stack->pop();
                result = a | b;
            }
            else
                throw(std::exception());
            break;
        }
        case ('='):
        {
            if (stack->size())
            {
                a = stack->top();
                stack->pop();
                result = (a == b);
            }
            else
                throw(std::exception());
            break;
        }
        case ('>'):
        {
            if (stack->size())
            {
                a = stack->top();
                stack->pop();
                result = !(a & !b);
            }
            else
                throw(std::exception());
            break;
        }
    }
    stack->push(result);
}

bool eval_formula(std::string proposition)
{
    std::stack<bool> stack;
    for (std::string::iterator it = proposition.begin(); it != proposition.end(); it++)
    {
        if (*it == '0' || *it == '1')
            insert_number(&stack, *it);
        else if (std::string("!&|^>=").find(*it) != std::string::npos)
            operate(&stack, *it);
    }
    if (stack.size() != 1)
        throw(std::exception());
    return stack.top();
}