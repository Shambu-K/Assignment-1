#ifndef AI_H
#define AI_H
#include <utility>
#include "Model/board.h"
#define INVALID_COORD std::make_pair((unsigned)DEFAULT_BOARD_SIZE + (unsigned)1, (unsigned)DEFAULT_BOARD_SIZE + (unsigned)1)

class AI
{
    public:
    virtual std::pair<unsigned int, unsigned int> play(OthelloBoard board) = 0;

};

#endif