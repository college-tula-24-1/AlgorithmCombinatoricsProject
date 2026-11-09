#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<char> TElements;
typedef std::vector<std::vector<char>> TResult;

void resultPrint(TResult result);

// перестановки
TResult permutations(TElements array);
void permute(TElements& array, int start, TResult& result);

bool nextPermutation(TElements& array);

// размещения
TResult placements(TElements array, int count);
void place(TElements& array,
    int placementSize,
    TElements& currentPlacement,
    std::vector<bool>& used,
    TResult& result);


// сочетания
TResult combinations(TElements array, int count);