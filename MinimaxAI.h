#ifndef _MINIMAX_H
#define _MINIMAX_H

#include "AI/AI.h"
#include "falcon.h"

static ai othelloAI;

class MinimaxAI : public AI
{
    public:
    std::pair<unsigned int, unsigned int> play(OthelloBoard board) override
    {
        std::pair<unsigned int, unsigned int> resultCoord;
        //all the relevant AI coding

        resultCoord=othelloAI.evaluateMove();
    
              



        return resultCoord;
    }

};




#endif