# include "../inc/rsb.h"


void new_subset(std::vector<int> set, std::vector<int> current, std::vector<std::vector<int>> &superset, unsigned idx = 0)
{
    superset.push_back(current);
    for (unsigned i = idx; i < set.size(); i++)
    {
        current.push_back(set[i]);
        new_subset(set, current, superset, i + 1);
        current.pop_back();
    }
}


std::vector<std::vector<int>> powerset(std::vector<int> set)
{
    std::vector<std::vector<int>> pset;
    std::vector<int> current;
    new_subset(set, current, pset); //O2^n
    return pset;
}