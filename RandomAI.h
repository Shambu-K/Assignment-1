#ifndef _RANDOM_AI_H
#define _RANDOM_AI_H

#include "AI/AI.h"

class RandomAI : public AI
{
    public:
    std::pair<unsigned int, unsigned int> play(OthelloBoard board) override
    {
        int siz = board.legalMoves.size();
     int i = std::rand()% siz;
     std::vector<std::pair<unsigned int,unsigned int>> coordlist;
     
     for(auto it: board.legalMoves)
     {
         coordlist.push_back(it.first);
     }
        std::pair<unsigned int, unsigned int> resultCoord;
        resultCoord = coordlist[i];
        return resultCoord;
    }

};

#endif