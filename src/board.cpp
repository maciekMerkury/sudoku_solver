#include <iostream>
#include <cassert>

#include "board.hpp"

std::ostream& operator<<(std::ostream& os, num const& v)
{
#ifdef NORMAL_NUM_PRINT
    os << (int)v;
#else
    if (v == 0) {
        os << ' ';
    } else if (v > 0 && v < 10) {
        os << (int)v;
    } else {
        std::cerr << "\031[attempted to print a board with value = " << (int)v << "\0[";
        os << '#';
    }
#endif

    return os;
}

std::ostream& operator<<(std::ostream& os, board const& b) 
{
    os << ' ';
    for (pos i = 0; i < 81; ++i) {
        if (i % 9 == 0) {
            os << "\n ";
        } else if (i % 3 == 0) {
            os << "| ";
        }

        os << b[i] << " ";

        if (i == 26 || i == 53) {
            os << "\n =====================";
        }
    }
    return os;
}

board generate_board()
{
    board b;
    b.fill(1);

    return b;
}

bool is_placement_legal(board const& b, pos position, num value)
{
    void debug_print(int i, int index, int b_i, int value, int position);

    if (!(value > 0 && value < 10)) {
        std::cerr << "value out of bouds = " << (int)value << '\n';
        assert(value > 0 && value < 10);
    }

    const pos column = position % 9; /* 0 - 8 */
    const pos row = (position - column) / 9;

    // check if legal in row
    for (pos i = row * 9; i < row * 9 + 9; ++i) {
        if (b[i] == value) {
            if (i != position) {
#ifdef DEBUG_PRINTS
            std::cout << "row\n";
            debug_print(i, -1, b[i], value, position);
#endif
                return false;
            }
        }
    }

    // check if legal in column
    for (pos i = column; i < 8 * 9 + column; i += 9) {
        if (b[i] == value) {
            if (i != position) {
#ifdef DEBUG_PRINTS
            std::cout << "column\n";
            debug_print(i, -1, b[i], value, position);
#endif
                return false;
            }
        }
    }

    // check if legal in the 3x3 square
    const auto grid_num = column / 3 + (row / 3) * 3;
    const auto square = grids[grid_num];

    pos index;
    for (int i = 0; i < 9; ++i) {
        index = square[i];
        if (index == position)
            continue;

        if (b[index] == value) {
#ifdef DEBUG_PRINTS
            std::cout << "square: " << grid_num << '\n';
            std::cout << "column / 3 = " << column / 3 << "; row / 3 = " << row / 3 << '\n';
            debug_print(i, index, b[index], value, position);
#endif
            return false;
        }
    }

    return true;
}

void debug_print(int i, int index, int b_i, int value, int position)
{
    std::cerr << "at i = " << i;
    if (index >= 0) {
        std::cerr<< ", index = " << index;
    }

    std::cerr  << "; b[i] == " << b_i << "; value == " << value << "; position = " << position << std::endl;
}

