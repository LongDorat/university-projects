#include <iostream>
#include <vector>

int readInput() {
    int disk;
    std::cin >> disk;
    return disk;
}

int towerOfHanoi(int disk, char source, char destination, char auxiliary) {
    if (disk == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return 1;
    }
    int moves = towerOfHanoi(disk - 1, source, auxiliary, destination);
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
    moves += 1;
    moves += towerOfHanoi(disk - 1, auxiliary, destination, source);
    return moves;
}

int main()
{
    freopen("ex02_inp.txt", "r", stdin);
    int disk = readInput();
    int numberOfMoves = towerOfHanoi(disk, 'A', 'C', 'B');
    std::cout << "Total moves: " << numberOfMoves << std::endl;
}