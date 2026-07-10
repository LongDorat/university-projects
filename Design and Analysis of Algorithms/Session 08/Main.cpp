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
    tree.print();

    tree.insertValue(20);
    tree.print();

    tree.deleteNode(6); // exists in the tree
    tree.print();

    return 0;
}