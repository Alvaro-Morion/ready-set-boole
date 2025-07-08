unsigned int gray_code(unsigned int a)
{
    return a ^ (a >> 1);
}