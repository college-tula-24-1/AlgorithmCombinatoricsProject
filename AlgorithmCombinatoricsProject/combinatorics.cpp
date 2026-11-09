#include "combinatorics.h"

void resultPrint(TResult result)
{
    for (auto line : result)
    {
        for (auto element : line)
            std::cout << element << " ";
        std::cout << "\n";
    }
}

TResult permutations(TElements array)
{
    TResult result;
    permute(array, 0, result);
    return result;
}

void permute(TElements& array, int start, TResult& result)
{
    if (start == array.size() - 1)
    {
        result.push_back(array);
        return;
    }

    for (int i{ start }; i < array.size(); i++)
    {
        std::swap(array[start], array[i]);
        permute(array, start + 1, result);
        std::swap(array[start], array[i]);
    }
}

bool nextPermutation(TElements& array)
{
    int i{ (int)array.size() - 2 };
    while (i >= 0 && array[i] >= array[i + 1])
        i--;
    if (i == -1) return false;

    int j{ (int)array.size() - 1 };
    while (array[j] <= array[i])
        j--;

    std::swap(array[i], array[j]);
    std::reverse(array.begin() + i + 1, array.end());

    return true;
}

TResult placements(TElements array, int count)
{
    TResult result;
    std::vector<bool> used(array.size(), false);
    TElements currentPlacement;

    place(array, count, currentPlacement, used, result);

    return result;
}

void place(TElements& array, int placementSize, TElements& currentPlacement, std::vector<bool>& used, TResult& result)
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
            place(array, placementSize, currentPlacement, used, result);
            currentPlacement.pop_back();
            used[i] = false;
        }
    }
}
