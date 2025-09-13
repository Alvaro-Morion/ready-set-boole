# include "../inc/rsb.h"


void new_subset(std::vector<int> set, std::vector<std::vector<int>> &superset)
{
    // std::cout << "Call with vector: [";
    // for (int i : set)
    //     std::cout << i << ", ";
    // std::cout << "]\n";
    
    std::vector<int> subset = set;
    superset.push_back(set);
    //std::cout << "push back: " << level << std::endl;
    for (unsigned i = 0; i < set.size(); i++)
    {
        //std::cout << "Level: " << level << " Index: " << i << std::endl;
        subset = set;
        subset.erase(subset.begin() + i);
        new_subset(subset, superset);
    }
}


std::vector<std::vector<int>> powerset(std::vector<int> set)
{
    std::vector<std::vector<int>> pset;
    new_subset(set, pset);
    return pset;
}