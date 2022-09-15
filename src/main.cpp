#include <iostream>
#include <array>

#include "board.hpp"

int main()
{
    auto b = example_boards::b_1_solution;

    for (pos i = 0; i < BOARDSIZE; ++i) {
        if (!is_placement_legal(b, i, b[i])) {
            return 1;
        }
    }

    return 0;
}


