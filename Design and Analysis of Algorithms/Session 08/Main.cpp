#include <iostream>
#include <vector>

#include "RedBlackTree.hpp"

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    std::cin >> n;

    RedBlackTree tree;
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        tree.insertValue(value);
    }

    return 0;
}