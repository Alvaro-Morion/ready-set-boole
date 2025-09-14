#include "../inc/rsb.h"
double ft_map(uint16_t x, uint16_t y)
{
    uint32_t combined = (static_cast<uint32_t>(x) << 16) | y;

    return static_cast<double>(combined) / ((1ULL << 32) - 1);
}