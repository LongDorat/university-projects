#include "TowerOfHanoi.hpp"
#include <iostream>
#include <gtest/gtest.h> 


TEST(TowerOfHanoiTest, TestMoveDisks) {
    TowerOfHanoi hanoi;
    Pole source{"A", {3, 2, 1}};
    Pole destination{"C", {}};
    Pole auxiliary{"B", {}};
    int numberOfMoves = hanoi.run(3, source, destination, auxiliary);
    EXPECT_EQ(numberOfMoves, 7);
}


TEST(TowerOfHanoiTest, TestMoveDisksWithFour) {
    TowerOfHanoi hanoi;
    Pole source{"A", {4, 3, 2, 1}};
    Pole destination{"C", {}};
    Pole auxiliary{"B", {}};
    int numberOfMoves = hanoi.run(4, source, destination, auxiliary);
    EXPECT_EQ(numberOfMoves, 15);
}

TEST(TowerOfHanoiTest, TestMoveManyDisks) {
    TowerOfHanoi hanoi;
    for(int i = 1; i <= 20; ++i) {
        std::cout << "Testing with " << i << " disks..." << std::endl;
        Pole source{"A", {}};
        Pole destination{"C", {}};
        Pole auxiliary{"B", {}};
        for(int j = i; j >= 1; --j) {
            source.disks.push_back(j);
        }
        int numberOfMoves = hanoi.run(i, source, destination, auxiliary);
        EXPECT_EQ(numberOfMoves, (1 << i) - 1); // 2^n - 1
    }
}
