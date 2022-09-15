#pragma once

#include <array>
#include <cstdint>
#include <iostream>

#define BOARDSIZE 81

using num = std::uint8_t;
using pos = std::uint8_t;
using board = std::array<pos, BOARDSIZE>;

const pos grids[9][9] = {
    {0, 1, 2, 9, 10, 11, 18, 19, 20},
    {3, 4, 5, 12, 13, 14, 21, 22, 23},
    {6, 7, 8, 15, 16, 17, 24, 25, 26},
    {27, 28, 29, 36, 37, 38, 45, 46, 47},
    {30, 31, 32, 39, 40, 41, 48, 49, 50},
    {33, 34, 35, 42, 43, 44, 51, 52, 53},
    {54, 55, 56, 63, 64, 65, 72, 73, 74},
    {57, 58, 59, 66, 67, 68, 75, 76, 77},
    {60, 61, 62, 69, 70, 71, 78, 79, 80},
};

std::ostream& operator<<(std::ostream& os, board const& b);
std::ostream& operator<<(std::ostream& os, num const& v);

board generate_board();
bool is_placement_legal(board const& b, pos position, num value);

namespace example_boards {

const board b_1 = {
    0, 2, 6,    0, 0, 0,    8, 1, 0,
    3, 0, 0,    7, 0, 8,    0, 0, 6,
    4, 0, 0,    0, 5, 0,    0, 0, 7,

    0, 5, 0,    1, 0, 7,    0, 9, 0,
    0, 0, 3,    9, 0, 5,    1, 0, 0,
    0, 4, 0,    3, 0, 2,    0, 5, 0,

    1, 0, 0,    0, 3, 0,    0, 0, 2,
    5, 0, 0,    2, 0, 4,    0, 0, 9,
    0, 3, 8,    0, 0, 0,    4, 6, 0
};

const board b_1_solution = {
    7, 2, 6,    4, 9, 3,    8, 1, 5,
    3, 1, 5,    7, 2, 8,    9, 4, 6,
    4, 8, 9,    6, 5, 1,    2, 3, 7,

    8, 5, 2,    1, 4, 7,    6, 9, 3,
    6, 7, 3,    9, 8, 5,    1, 2, 4,
    9, 4, 1,    3, 6, 2,    7, 5, 8,

    1, 9, 4,    8, 3, 6,    5, 7, 2,
    5, 6, 7,    2, 1, 4,    3, 8, 9,
    2, 3, 8,    5, 7, 9,    4, 6, 1
};
}
