#include "TowerOfHanoi.hpp"

int TowerOfHanoi::run(int disk, std::vector<int> &source, std::vector<int> &destination, std::vector<int> &auxiliary)
{
    if (disk == 1)
    {
        destination.push_back(source.back());
        source.pop_back();
        return 1;
    }
    int moves = TowerOfHanoi::run(disk - 1, source, auxiliary, destination);
    destination.push_back(source.back());
    source.pop_back();
    moves += 1;

    moves += TowerOfHanoi::run(disk - 1, auxiliary, destination, source);
    return moves;
}