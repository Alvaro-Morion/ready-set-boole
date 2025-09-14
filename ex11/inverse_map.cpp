#include "../inc/rsb.h"

std::vector<uint16_t> inverse_map(double x)
{
    std::vector<uint16_t> result;
    uint32_t value = static_cast<uint32_t>(x * ((1UL << 32) - 1));
    result.push_back(static_cast<uint16_t>(value >> 16));
    result.push_back(static_cast<uint16_t>(value & (1U << 16) - 1));
    return result;
}