#pragma once
#include <vector>
class TowerOfHanoi
{
    public:
        int run(int disk, std::vector<int>& source, std::vector<int>& destination, std::vector<int>& auxiliary);
};