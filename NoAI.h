#ifndef _NO_AI_H
#define _NO_AI_H

#include "AI/AI.h"

class NoAI : public AI
{
    public:
    std::pair<unsigned int, unsigned int> play(OthelloBoard board) override
    {
        return INVALID_COORD;
    }
};

#endif