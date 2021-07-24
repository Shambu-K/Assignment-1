#ifndef _GREEDY_AI_H
#define _GREEDY_AI_H

#include "AI/AI.h"

class GreedyAI : public AI
{
    public:
    std::pair<unsigned int, unsigned int> play(OthelloBoard board) override
    {
        unsigned int max_Captures = 0;
        std::pair<unsigned int, unsigned int> resultCoord;
        for(auto itr : board.legalMoves)
        {
            if(itr.second.size() > max_Captures)
            {
                resultCoord = itr.first;
            }
        }
        return resultCoord;
    }

};

#endif
