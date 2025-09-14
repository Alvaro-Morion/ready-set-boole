double ft_map(unsigned x, unsigned y)
{
    unsigned long long value = static_cast<unsigned long long>(x) << sizeof(unsigned)  | y;
    double result = static_cast<double>(value) / (1ULL << 32);
    return result;
}