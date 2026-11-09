#include "combinatorics.h"

void placement(TElements& array,
                int placementSize,
                TElements& currentPlacement,
                std::vector<bool>& used,
                TResult& result)
{
    if (currentPlacement.size() == placementSize)
    {
        result.push_back(currentPlacement);
        return;
    }

    for (int i{}; i < array.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            currentPlacement.push_back(array[i]);
            placement(array, placementSize, currentPlacement, used, result);
            currentPlacement.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    TElements array{ 'a', 'b', 'c', 'd'};
    
    TResult result = placements(array, 3);

    for (auto line : result)
    {
        for (auto item : line)
            std::cout << item << " ";
        std::cout << "\n";
    }


}
