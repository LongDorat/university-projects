#include <iostream>
#include <vector>

#include "TowerOfHanoi.hpp"

int readInput() {
    int disk;
    std::cin >> disk;
    return disk;
}

int main()
{
    freopen("ex02_inp.txt", "r", stdin);
    int disk = readInput();
    std::vector<int> A;
    std::vector<int> B;
    std::vector<int> C;
    for (int i = disk; i >= 1; --i) 
    {
        A.push_back(i);
    }

    TowerOfHanoi hanoi;
    int numberOfMoves = hanoi.run(disk, A, C, B);
    for (int i = C.size() - 1; i >= 0; --i) 
    {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Total moves: " << numberOfMoves << std::endl;
}